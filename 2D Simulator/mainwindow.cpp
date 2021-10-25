#include "mainwindow.h"

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow((y1 - y2), 2));
}

int numDigits(int n){
    if(n==0) return 1;
    int ans=0;
    while(n!=0){
        ans++;
        n/=10;
    }
    return ans;
}

void blur(QImage&img,int radius=1){
    int width = img.width(), height = img.height();
    QImage img1(width,height,img.format());
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = 0, g = 0, b = 0;
            int num = 0;
            for (int di = -radius; di <= radius; di++) {
                for (int dj = -radius; dj <= radius; dj++) {
                    if (i + di < 0 || i + di >= height) continue;
                    if (j + dj < 0 || j + dj >= width) continue;
                    QColor c=img.pixelColor(j+dj,i+di);
                    r += c.red();
                    g += c.green();
                    b += c.blue();
                    num++;
                }
            }
            r /= num;
            g /= num;
            b /= num;
            img1.setPixelColor(j,i,QColor(r,g,b,img.pixelColor(j,i).alpha()));
        }
    }
    img=img1;
}

int clamp(int x){
    if(x<0) return 0;
    if(x>255) return 255;
    return x;
}

QColor add(QColor x,QColor y){
    int r=x.red()+y.red();
    int g=x.green()+y.green();
    int b=x.blue()+y.blue();
    return QColor(clamp(r),clamp(g),clamp(b));
}

void QSS(QWidget*widget){
    widget->setStyleSheet("QWidget{background-color: rgb(30,30,30);color:rgb(231,231,231);font: 800 11pt ""Calibri"";border: 0px;}"
                          "QWidget#centralwidget{background-color: rgb(37,37,37);}"
                          "QGroupBox{padding: 20px 0px;background-color: rgb(30,30,30);}"
                          "QGroupBox::title{subcontrol-position: top center;}"
                          "QLineEdit{background:rgb(60,60,60);padding: 3px;font: 11pt ""Calibri"";}"
                          "QLineEdit:focus{border: 1px solid rgb(0,127,212);}"
                          "QSpinBox{background:rgb(60,60,60);padding: 5px;font: 11pt ""Calibri"";}"
                          "QSpinBox:focus{border: 1px solid rgb(0,127,212);}"
                          "QDoubleSpinBox{background:rgb(60,60,60);padding: 3px;font: 11pt ""Calibri"";}"
                          "QDoubleSpinBox:focus{border: 1px solid rgb(0,127,212);}"
                          "QPushButton{background-color:rgb(14,99,156);color: white;padding: 10px;}"
                          "QPushButton:disabled{background-color:rgb(77,77,77);}"
                          "QPushButton:hover{background-color:rgb(17,119,187);}"
                          "QTabWidget::pane{border: 0px;}"
                          "QTabBar::tab{background: rgb(45,45,45);}"
                          "QTabBar::tab::selected{background: rgb(30,30,30);}"
                          "QListWidget::item{padding:7px;}"
                          "QScrollBar::add-line{border:none;background:none}"
                          "QScrollBar::sub-line{border:none;background:none}"
                          "QScrollBar{background:solid rgb(30,30,30);border:2px solid rgb(57,57,57);}"
                          "QScrollBar::handle{background:rgb(66,66,66);}"
                          "QScrollBar::handle::hover{background:rgb(79,79,79);}"
                          "QScrollBar::add-page{background:none;}"
                          "QScrollBar::sub-page{background:none;}");
}

int particleListItem::index=0;
int gravitationalRadialFieldListItem::index=0;
int gravitationalUniformFieldListItem::index=0;
int electricRadialFieldListItem::index=0;
int electricUniformFieldListItem::index=0;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->doubleSpinBox->setRange(FLT_MIN,FLT_MAX);
    ui->doubleSpinBox_2->setRange(FLT_MIN,FLT_MAX);
    ui->doubleSpinBox_3->setRange(FLT_MIN,FLT_MAX);

    ui->doubleSpinBox->setDecimals(10);
    ui->doubleSpinBox_2->setDecimals(10);
    ui->doubleSpinBox_2->setDecimals(10);

    QSS(this);

    ui->doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    //Simulate button clicked
    sys.setName(ui->lineEdit->text());
    sys.setScale(ui->doubleSpinBox->value());
    sys.setBoundX(ui->spinBox->value());
    sys.setBoundY(ui->spinBox_2->value());
    sys.setFps(ui->spinBox_5->value());
    sys.setIterations(ui->spinBox_3->value());
    sys.setDuration(ui->spinBox_4->value());
    sys.setTimeFactor(ui->doubleSpinBox_2->value());
    sys.setVisc_K(ui->doubleSpinBox_3->value());

    int numParticles=ui->widget->ListWidget()->count();
    int numFields=ui->widget_2->ListWidget()->count();

    sys.clearParticles();
    sys.clearFields();

    for(int i=0;i<numParticles;i++){
        particlePropertiesWindow*p=(particlePropertiesWindow*)((particleListItem*)ui->widget->ListWidget()->item(i))->getPropertiesWindow();
        sys.addParticle(p->createParticle());
    }
    for(int i=0;i<numFields;i++){
        fieldPropertiesWindow*f=(fieldPropertiesWindow*)(((fieldListItem*)ui->widget_2->ListWidget()->item(i))->getPropertiesWindow());
        sys.addField(f->createField());
    }
    sys.simulate();
}
