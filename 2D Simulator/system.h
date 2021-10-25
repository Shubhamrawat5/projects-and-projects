#include<bits/stdc++.h>
#include<QImage>
#include<QDebug>
#include<QFileDialog>
#include"qualityFactorDialog.h"
using namespace std;

const float _G = 6.67259e-11;
const float _K = 9e9;

#define SAVE_LOG(fileName) qDebug()<<fileName<<" saved";

float distance(float x1, float y1, float x2, float y2);
int numDigits(int n);
void blur(QImage&img,int radius);
int clamp(int x);
QColor add(QColor x,QColor y);

class particle{
    QString id;
    float ax,ay;
    float vx,vy;
    float x,y;
    float q,m;
    int radius,trajectRadius;
    QColor color;
    QColor**matrix;

    void clearMatrix(){
        for(int i=0;i<2*radius+1;i++) delete[]matrix[i];
        delete[]matrix;
    }
    void createMatrix(){
        matrix=new QColor*[2*radius+1];
        for(int i=0;i<2*radius+1;i++) matrix[i]=new QColor[2*radius+1];
    }
    void setMatrix(){
        matrix[radius][radius]=color;
        int r0=color.red();
        int g0=color.green();
        int b0=color.blue();

        int xr=1,xg=1,xb=1;
        if(r0!=0) xr=ceil(log(r0)/log(radius));
        if(g0!=0) xg=ceil(log(g0)/log(radius));
        if(b0!=0) xb=ceil(log(b0)/log(radius));

        for(int i=0;i<2*radius+1;i++){
            for(int j=0;j<2*radius+1;j++){
                if(i==radius && j==radius) continue;
                float d=sqrt(pow(i-radius,2)+pow(j-radius,2));
                matrix[i][j]=QColor((r0==0)? 0: r0/pow(d,xr),
                                    (g0==0)? 0: g0/pow(d,xg),
                                    (b0==0)? 0: b0/pow(d,xb));
            }
        }
    }
public:
    particle(QString id,float vx=0,float vy=0,float x=0,float y=0,float q=0,float m=0,int radius=5,int trajectRadius=3,QColor color=Qt::white)
        :id(id),ax(0),ay(0),vx(vx),vy(vy),x(x),y(y),q(q),m(m),radius(radius),trajectRadius(trajectRadius),color(color){
        createMatrix();
        setMatrix();
    }
    particle(const particle&p){
        id=p.id;
        ax=p.ax, ay=p.ay;
        vx=p.vx, vy=p.vy;
        x=p.x, y=p.y;
        q=p.q, m=p.m;
        radius=p.radius, trajectRadius=p.trajectRadius;
        color=p.color;
        createMatrix();
        setMatrix();
    }
    void operator=(const particle&p){
        id=p.id;
        ax=p.ax, ay=p.ay;
        vx=p.vx, vy=p.vy;
        x=p.x, y=p.y;
        q=p.q, m=p.m;
        radius=p.radius, trajectRadius=p.trajectRadius;
        color=p.color;
        createMatrix();
        setMatrix();
    }
    ~particle(){
        clearMatrix();
    }
    //getters
    QString Id(){return id;}
    float Ax(){return ax;}
    float Ay(){return ay;}
    float Vx(){return vx;}
    float Vy(){return vy;}
    float X(){return x;}
    float Y(){return y;}
    float Q(){return q;}
    float M(){return m;}
    int Radius(){return radius;}
    int TrajectRadius(){return trajectRadius;}
    QColor Matrix(int x,int y){return matrix[y][x];}
    QColor Color(){return color;}
    //setters
    void setId(QString id){this->id=id;}
    void setAx(float ax){this->ax=ax;}
    void setAy(float ay){this->ay=ay;}
    void setVx(float vx){this->vx=vx;}
    void setVy(float vy){this->vy=vy;}
    void setX(float x){this->x=x;}
    void setY(float y){this->y=y;}
    void setQ(float q){this->q=q;}
    void setM(float m){this->m=m;}
    void setRadius(int radius){
        clearMatrix();
        this->radius=radius;
        createMatrix();
        setMatrix();
    }
    void setTrajectRadius(int trajectRadius){this->trajectRadius=trajectRadius;}
    void setColor(QColor color){
        this->color=color;
        setMatrix();
    }
};

class field{
public:
    virtual float Ax(particle p){return 0;}
    virtual float Ay(particle p){return 0;}
};

class uniformField:public field{
protected:
    float ex,ey;
public:
    uniformField(float ex=0,float ey=0):ex(ex),ey(ey){}
    float Ex(){return ex;}
    float Ey(){return ey;}
    void setEx(float ex){this->ex=ex;}
    void setEy(float ey){this->ey=ey;}
};

class radialField:public field{
protected:
    float cx,cy,k;
public:
    radialField(float cx=0,float cy=0,float k=0):cx(cx),cy(cy),k(k){}
    float Cx(){return cx;}
    float Cy(){return cy;}
    float K(){return k;}
    void setCx(float cx){this->cx=cx;}
    void setCy(float cy){this->cy=cy;}
    void setK(float k){this->k=k;}
    float magnitude(float x,float y){
        return k/(pow(x-cx,2)+pow(y-cy,2));
    }
};

class gravitationalUniformField:public uniformField{
public:
    gravitationalUniformField(float ex=0,float ey=0):uniformField(ex,ey){}
    float Ax(particle p){return ex;}
    float Ay(particle p){return ey;}
};

class gravitationalRadialField:public radialField{
public:
    gravitationalRadialField(float cx=0,float cy=0,float k=0):radialField(cx,cy,k){}
    gravitationalRadialField(particle p):radialField(p.X(),p.Y(),_G*p.M()){}//returns the self generated field by particle
    float Ax(particle p){
        float cos=(p.X()-cx)/distance(p.X(),p.Y(),cx,cy);
        return -cos*magnitude(p.X(),p.Y());
    }
    float Ay(particle p){
        float sin=(p.Y()-cy)/distance(p.X(),p.Y(),cx,cy);
        return -sin*magnitude(p.X(),p.Y());
    }
};

class electricUniformField:public uniformField{
public:
    electricUniformField(float ex=0,float ey=0):uniformField(ex,ey){}
    float Ax(particle p){return ex*p.Q()/p.M();}
    float Ay(particle p){return ey*p.Q()/p.M();}
};

class electricRadialField:public radialField{
public:
    electricRadialField(float cx=0,float cy=0,float k=0):radialField(cx,cy,k){}
    electricRadialField(particle p):radialField(p.X(),p.Y(),_K*p.Q()){}//returns the self generated field by particle
    float Ax(particle p){
        float cos=(p.X()-cx)/distance(p.X(),p.Y(),cx,cy);
        return p.Q()*cos*magnitude(p.X(),p.Y())/p.M();
    }
    float Ay(particle p){
        float sin=(p.Y()-cy)/distance(p.X(),p.Y(),cx,cy);
        return p.Q()*sin*magnitude(p.X(),p.Y())/p.M();
    }
};

typedef radialField RF;
typedef uniformField UF;
typedef gravitationalRadialField GRF;
typedef gravitationalUniformField GUF;
typedef electricRadialField ERF;
typedef electricUniformField EUF;

class System{
    vector<particle*> particles;
    vector<field*> fields;
    vector<QImage*> trajects;
    vector<ofstream> stats;
    float scale;// 1px corresponds to scale meters
    int boundX,boundY;//in px
    int fps;
    int iterations;//per second and must be a multiple of 30(fps)
    int duration;//num of seconds to simulate
    float timeFactor;// 1-realtime
    float dt;// 1/iterations
    float time;
    float visc_k;
    QString name;

    void updateAccn(particle*p){
        p->setAx(0);
        p->setAy(0);
        for(int i=0;i<fields.size();i++){
            p->setAx(p->Ax() + fields[i]->Ax(*p));
            p->setAy(p->Ay() + fields[i]->Ay(*p));
        }
        for(int i=0;i<particles.size();i++){
            if(particles[i]==p) continue;
            GRF gf(*particles[i]);
            ERF ef(*particles[i]);
            p->setAx(p->Ax() + gf.Ax(*p));
            p->setAy(p->Ay() + gf.Ay(*p));
            p->setAx(p->Ax() + ef.Ax(*p));
            p->setAy(p->Ay() + ef.Ay(*p));
        }
        p->setAx(p->Ax() - visc_k*p->Vx()/p->M());
        p->setAy(p->Ay() - visc_k*p->Vy()/p->M());
    }
    void updateBuffer(QImage*buffer){
        for(int y=0;y<boundY;y++){
            for(int x=0;x<boundX;x++) buffer->setPixelColor(x,y,Qt::black);
        }
        for(int i=0;i<particles.size();i++){
            particle*p=particles[i];
            int Y=p->Y()/scale;
            int X=p->X()/scale;
            int R=p->Radius();
            for(int dy=-R;dy<=R;dy++){
                for(int dx=-R;dx<=R;dx++){
                    if(Y+dy<0 || Y+dy>=boundY) continue;
                    if(X+dx<0 || X+dx>=boundX) continue;
                    buffer->setPixelColor(X+dx,boundY-Y-dy-1,add(buffer->pixelColor(X+dx,boundY-Y-dy-1),p->Matrix(R+dx,R+dy)));
                }
            }
        }
        for(int y=0;y<boundY;y++){
            buffer->setPixelColor(0,y,Qt::red);
            buffer->setPixelColor(boundX-1,y,Qt::red);
        }
        for(int x=0;x<boundX;x++){
            buffer->setPixelColor(x,0,Qt::red);
            buffer->setPixelColor(x,boundY-1,Qt::red);
        }
    }
    void updateTraject(int i){
        particle*p=particles[i];
        int x=p->X()/scale;
        int y=p->Y()/scale;
        for(int dy=-p->TrajectRadius();dy<=p->TrajectRadius();dy++){
            for(int dx=-p->TrajectRadius();dx<=p->TrajectRadius();dx++){
                if(x+dx<0 || x+dx>=boundX) continue;
                if(y+dy<0 || y+dy>=boundY) continue;
                trajects[i]->setPixelColor(x+dx,boundY-y-dy-1,p->Color());
            }
        }
    }
public:
    System(QString name="sim",float scale = 1, int boundX = 100, int boundY = 100,int fps = 30, int iterations = 300, int duration = 1, float timeFactor = 1, float visc_k = 0)
            :scale(scale), boundX(boundX), boundY(boundY), fps(fps), iterations(iterations), duration(duration), timeFactor(timeFactor), visc_k(visc_k),name(name)
    {
            dt = ((float)1 / iterations) * timeFactor;
    }
    ~System(){
        clearParticles();
        clearFields();
        clearTrajects();
    }
    //getters
    float Scale(){return scale;}
    int BoundX(){return boundX;}
    int BoundY(){return boundY;}
    int Fps(){return fps;}
    int Iterations(){return iterations;}
    int Duration(){return duration;}
    float TimeFactor(){return timeFactor;}
    float Dt(){return dt;}
    float Time(){return time;}
    float Visc_K(){return visc_k;}
    QString Name(){return name;}
    //setters
    void setScale(float scale){this->scale=scale;}
    void setBoundX(int boundX){this->boundX=boundX;}
    void setBoundY(int boundY){this->boundY=boundY;}
    void setFps(int fps){this->fps=fps;}
    void setIterations(int iterations){
        this->iterations=iterations;
        dt = ((float)1 / iterations) * timeFactor;
    }
    void setDuration(int duration){this->duration=duration;}
    void setTimeFactor(float timeFactor){
        this->timeFactor=timeFactor;
        dt = ((float)1 / iterations) * timeFactor;
    }
    void setVisc_K(float visc_k){this->visc_k=visc_k;}
    void setName(QString name){this->name=name;}

    void clearParticles(){
        for(int i=0;i<particles.size();i++) delete particles[i];
        particles.clear();
    }
    void clearFields(){
        for(int i=0;i<fields.size();i++) delete fields[i];
        fields.clear();
    }
    void clearTrajects(){
        for(int i=0;i<trajects.size();i++) delete trajects[i];
        trajects.clear();
    }
    void addParticle(particle*p){particles.push_back(p);}
    void addField(field*f){fields.push_back(f);}

    void simulate(){
        time = 0;
        QWidget widget;
        QString directoryPath=QFileDialog::getExistingDirectory(&widget,"Select Directory");
        if(directoryPath=="") return;

        qualityFactorDialog dialog;
        if(dialog.exec() == QDialog::Rejected) return;
        int factor=dialog.getValue();

        directoryPath+='/';
        QDir dir;
        dir.mkpath(directoryPath+name);
        QString framePath=directoryPath+name+"/simulation";
        dir.mkdir(framePath);
        framePath+="/frame";
        QString trajectoriesPath=directoryPath+name+"/trajectories";
        dir.mkdir(trajectoriesPath);
        trajectoriesPath+='/';
        QString statsPath=directoryPath+name+"/statistics";
        dir.mkdir(statsPath);
        statsPath+='/';
        QString settingsPath=directoryPath+'/'+name+"/settings.txt";

        ofstream settingsFile(settingsPath.toStdString());
        settingsFile<<"Simulation name = "<<name.toStdString()<<'\n'
                    <<"Scale = "<<QString::number(scale).toStdString()<<'\n'
                    <<"Width = "<<QString::number(boundX).toStdString()<<'\n'
                    <<"Height = "<<QString::number(boundY).toStdString()<<'\n'
                    <<"FPS = "<<QString::number(fps).toStdString()<<'\n'
                    <<"Iterations = "<<QString::number(iterations).toStdString()<<'\n'
                    <<"Duration = "<<QString::number(duration).toStdString()<<'\n'
                    <<"Time Factor = "<<QString::number(timeFactor).toStdString()<<'\n'
                    <<"Viscosity = "<<QString::number(visc_k).toStdString();
        settingsFile.close();
        SAVE_LOG(settingsPath)

        clearTrajects();
        for(int i=0;i<particles.size();i++) trajects.push_back(new QImage(boundX,boundY,QImage::Format_RGB888));
        for(int i=0;i<particles.size();i++){
            QString temp=statsPath+particles[i]->Id()+".txt";
            stats.push_back(ofstream(temp.toStdString()));
            SAVE_LOG(temp)
            stats[i]<<"time x y vx vy ax ay\n";
        }
        for(int i=0;i<particles.size();i++) updateAccn(particles[i]);
        QImage* buffer=new QImage(boundX,boundY,QImage::Format_RGB888);
        int padding=numDigits(duration*fps-1);
        updateBuffer(buffer);
        QString temp=framePath;
        for(int i=0;i<padding;i++) temp+='0';
        buffer->save(temp+".png","",factor);
        for(int i=0;i<stats.size();i++) stats[i]<<time<<' '
                                                <<particles[i]->X()<<' '<<particles[i]->Y()<<' '
                                                <<particles[i]->Vx()<<' '<<particles[i]->Vy()<<' '
                                                <<particles[i]->Ax()<<' '<<particles[i]->Ay()<<'\n';
        SAVE_LOG(temp+".png")
        int frame=1;

        for(int i=1;i<iterations*duration;i++){
            for(int j=0;j<particles.size();j++){
                particle pc=*particles[j];
                particle*p=particles[j];
                time+=dt;

                p->setX(pc.X() + pc.Vx()*dt);
                p->setY(pc.Y() + pc.Vy()*dt);
                p->setVx(pc.Vx() + pc.Ax()*dt);
                p->setVy(pc.Vy() + pc.Ay()*dt);
            }
            for(int j=0;j<particles.size();j++){
                updateAccn(particles[j]);
                updateTraject(j);
            }
            if(i%(iterations/fps)==0){
                updateBuffer(buffer);
                QString fileName=framePath;
                for(int j=0;j<padding-numDigits(frame);j++) fileName+='0';
                fileName+=QString::number(frame)+".png";
                buffer->save(fileName,"",factor);
                SAVE_LOG(fileName)
                frame++;
            }
            for(int i=0;i<stats.size();i++) stats[i]<<time<<' '
                                                    <<particles[i]->X()<<' '<<particles[i]->Y()<<' '
                                                    <<particles[i]->Vx()<<' '<<particles[i]->Vy()<<' '
                                                    <<particles[i]->Ax()<<' '<<particles[i]->Ay()<<'\n';
        }
        for(int i=0;i<trajects.size();i++){
            blur(*trajects[i],2);
            for(int y=0;y<boundY;y++){
                trajects[i]->setPixelColor(0,y,Qt::red);
                trajects[i]->setPixelColor(boundX-1,y,Qt::red);
            }
            for(int x=0;x<boundX;x++){
                trajects[i]->setPixelColor(x,0,Qt::red);
                trajects[i]->setPixelColor(x,boundY-1,Qt::red);
            }
        }
        delete buffer;
        for(int i=0;i<trajects.size();i++){
            trajects[i]->save(trajectoriesPath+particles[i]->Id()+".png","",factor);
            SAVE_LOG(trajectoriesPath+particles[i]->Id()+".png")
        }
        stats.clear();
    }
};
