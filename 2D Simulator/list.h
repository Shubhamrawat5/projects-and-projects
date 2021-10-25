#include<QListWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QLabel>
#include<QSpinBox>
#include<QColorDialog>
#include<QLineEdit>
#include"system.h"

class propertiesWindow:public QDialog{
public:
    propertiesWindow(QString title,QWidget*parent=NULL):QDialog(parent){
        setWindowTitle(title);
        setWindowFlags(Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
        QSS(this);
    }
};

class particlePropertiesWindow:public propertiesWindow{
    Q_OBJECT
    QVBoxLayout*v1;
    QHBoxLayout*hBox[5];
    QLabel*label[8];
    QDoubleSpinBox*doubleSpinBox[6];
    QSpinBox*spinBox[2];
    QPushButton*b1;
    QColorDialog*cd;
public:
    particlePropertiesWindow(QString title,QWidget*parent=NULL):propertiesWindow(title,parent){
        v1=new QVBoxLayout;
        for(int i=0;i<5;i++) hBox[i]=new QHBoxLayout;
        label[0]=new QLabel("x:");
        label[1]=new QLabel("y:");
        label[2]=new QLabel("vx:");
        label[3]=new QLabel("vy:");
        label[4]=new QLabel("q:");
        label[5]=new QLabel("m:");
        label[6]=new QLabel("radius:");
        label[7]=new QLabel("trajectRadius:");
        for(int i=0;i<6;i++){
            doubleSpinBox[i]=new QDoubleSpinBox;
            doubleSpinBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        }
        for(int i=0;i<2;i++){
            spinBox[i]=new QSpinBox;
            spinBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        }
        for(int i=0;i<6;i++){
            doubleSpinBox[i]->setRange(-FLT_MAX,FLT_MAX);
            doubleSpinBox[i]->setDecimals(10);
        }
        for(int i=0;i<2;i++) spinBox[i]->setRange(1,INT_MAX);
        spinBox[0]->setValue(5);
        spinBox[1]->setValue(3);
        b1=new QPushButton("Pick Color");
        cd=new QColorDialog(Qt::white,this);
        cd->setOptions(QColorDialog::NoButtons);

        for(int i=0;i<4;i++){
            hBox[i]->addWidget(label[2*i]);
            if(i!=3) hBox[i]->addWidget(doubleSpinBox[2*i]);
            else hBox[i]->addWidget(spinBox[0]);
            hBox[i]->addWidget(label[2*i+1]);
            if(i!=3) hBox[i]->addWidget(doubleSpinBox[2*i+1]);
            else hBox[i]->addWidget(spinBox[1]);
            hBox[i]->addStretch();
        }
        hBox[4]->addWidget(b1);
        hBox[4]->addStretch();
        for(int i=0;i<5;i++) v1->addLayout(hBox[i]);
        v1->addStretch();
        setLayout(v1);

        connect(b1,SIGNAL(clicked()),cd,SLOT(exec()));
    }
    particle* createParticle(){
        return new particle(windowTitle(),
                            doubleSpinBox[2]->value(),doubleSpinBox[3]->value(),
                            doubleSpinBox[0]->value(),doubleSpinBox[1]->value(),
                            doubleSpinBox[4]->value(),doubleSpinBox[5]->value(),
                            spinBox[0]->value(),spinBox[1]->value(),
                            cd->currentColor());
    }
};

class fieldPropertiesWindow:public propertiesWindow{
public:
    fieldPropertiesWindow(QString title,QWidget*parent=NULL):propertiesWindow(title,parent){}
    virtual field* createField(){return new field;}
};

class radialFieldPropertiesWindow:public fieldPropertiesWindow{
    QVBoxLayout*v1;
    QHBoxLayout*hBox[2];
    QLabel*label[3];
    QDoubleSpinBox*spinBox[3];
public:
    radialFieldPropertiesWindow(QString title,QWidget*parent=NULL):fieldPropertiesWindow(title,parent){
        v1=new QVBoxLayout;
        for(int i=0;i<2;i++) hBox[i]=new QHBoxLayout;
        for(int i=0;i<3;i++){
            spinBox[i]=new QDoubleSpinBox;
            spinBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        }
        label[0]=new QLabel("cx:");
        label[1]=new QLabel("cy:");
        label[2]=new QLabel("k:");
        for(int i=0;i<2;i++) spinBox[i]->setRange(-FLT_MAX,FLT_MAX);
        spinBox[2]->setRange(-FLT_MAX,FLT_MAX);
        for(int i=0;i<3;i++) spinBox[i]->setDecimals(10);

        for(int i=0;i<2;i++){
            hBox[0]->addWidget(label[i]);
            hBox[0]->addWidget(spinBox[i]);
        }
        hBox[1]->addWidget(label[2]);
        hBox[1]->addWidget(spinBox[2]);
        for(int i=0;i<2;i++){
            hBox[i]->addStretch();
            v1->addLayout(hBox[i]);
        }
        v1->addStretch();
        setLayout(v1);
    }
    float getCx(){return spinBox[0]->value();}
    float getCy(){return spinBox[1]->value();}
    float getK(){return spinBox[2]->value();}
};

class gravitationalRadialFieldPropertiesWindow:public radialFieldPropertiesWindow{
public:
    gravitationalRadialFieldPropertiesWindow(QString title,QWidget*parent=NULL):radialFieldPropertiesWindow(title,parent){}
    field * createField(){return new GRF(getCx(),getCy(),getK());}
};

class electricRadialFieldPropertiesWindow:public radialFieldPropertiesWindow{
public:
    electricRadialFieldPropertiesWindow(QString title,QWidget*parent=NULL):radialFieldPropertiesWindow(title,parent){}
    field * createField(){return new ERF(getCx(),getCy(),getK());}
};

class uniformFieldPropertiesWindow:public fieldPropertiesWindow{
    QVBoxLayout*v1;
    QHBoxLayout*h1;
    QLabel*label[2];
    QDoubleSpinBox*spinBox[2];
public:
    uniformFieldPropertiesWindow(QString title,QWidget*parent=NULL):fieldPropertiesWindow(title,parent){
        v1=new QVBoxLayout;
        h1=new QHBoxLayout;
        for(int i=0;i<2;i++){
            spinBox[i]=new QDoubleSpinBox;
            spinBox[i]->setRange(-FLT_MAX,FLT_MAX);
            spinBox[i]->setDecimals(10);
            spinBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        }
        label[0]=new QLabel("ex:");
        label[1]=new QLabel("ey:");
        for(int i=0;i<2;i++){
            h1->addWidget(label[i]);
            h1->addWidget(spinBox[i]);
        }
        h1->addStretch();
        v1->addLayout(h1);
        v1->addStretch();
        setLayout(v1);
    }
    float getEx(){return spinBox[0]->value();}
    float getEy(){return spinBox[1]->value();}
};

class gravitationalUniformFieldPropertiesWindow:public uniformFieldPropertiesWindow{
public:
    gravitationalUniformFieldPropertiesWindow(QString title,QWidget*parent=NULL):uniformFieldPropertiesWindow(title,parent){}
    field* createField(){return new GUF(getEx(),getEy());}
};

class electricUniformFieldPropertiesWindow:public uniformFieldPropertiesWindow{
public:
    electricUniformFieldPropertiesWindow(QString title,QWidget*parent=NULL):uniformFieldPropertiesWindow(title,parent){}
    field* createField(){return new EUF(getEx(),getEy());}
};

class listItem:public QListWidgetItem{
    propertiesWindow*win;
public:
    listItem(const QString&text,QListWidget*parent=NULL):QListWidgetItem(text,parent){
        win=NULL;
    }
    propertiesWindow* getPropertiesWindow(){return win;}
    void setPropertiesWindow(propertiesWindow*win){this->win=win;}
    virtual ~listItem(){
        delete win;
    }
};

class particleListItem:public listItem{
public:
    particleListItem(QListWidget*parent=NULL):listItem("particle"+QString::number(index++),parent){
        setPropertiesWindow(new particlePropertiesWindow(text()));
    }
    static int index;
};

class fieldListItem:public listItem{
public:
    fieldListItem(const QString&text,QListWidget*parent=NULL):listItem(text,parent){}
};

class gravitationalRadialFieldListItem:public fieldListItem{
public:
    gravitationalRadialFieldListItem(QListWidget*parent=NULL):fieldListItem("gravitationalRadialField"+QString::number(index++),parent){
        setPropertiesWindow(new gravitationalRadialFieldPropertiesWindow(text()));
    }
    static int index;
};

class gravitationalUniformFieldListItem:public fieldListItem{
public:
    gravitationalUniformFieldListItem(QListWidget*parent=NULL):fieldListItem("gravitationalUniformField"+QString::number(index++),parent){
        setPropertiesWindow(new gravitationalUniformFieldPropertiesWindow(text()));
    }
    static int index;
};

class electricRadialFieldListItem:public fieldListItem{
public:
    electricRadialFieldListItem(QListWidget*parent=NULL):fieldListItem("electricRadialField"+QString::number(index++),parent){
        setPropertiesWindow(new electricRadialFieldPropertiesWindow(text()));
    }
    static int index;
};

class electricUniformFieldListItem:public fieldListItem{
public:
    electricUniformFieldListItem(QListWidget*parent=NULL):fieldListItem("electricUniformField"+QString::number(index++),parent){
        setPropertiesWindow(new electricUniformFieldPropertiesWindow(text()));
    }
    static int index;
};

class trieNode{
public:
    QChar data;
    unordered_set<listItem*>*ptr;
    trieNode**children;
    trieNode(QChar data):data(data){
        children=new trieNode*[36];
        for(int i=0;i<36;i++) children[i]=NULL;
        ptr=new unordered_set<listItem*>;
    }
    ~trieNode(){
        for(int i=0;i<36;i++) delete children[i];
        delete[]children;
        delete ptr;
    }
};

class trie{
    trieNode*root;
    int index(QChar x){
        if(x.isDigit()) return x.toLatin1()-'0'+26;
        return x.toLatin1()-'a';
    }
    void insertWord(QString word,listItem*item,trieNode*root){
        if(word.isEmpty()){
            root->ptr->insert(item);
            return;
        }
        int ind=index(word[0]);
        if(root->children[ind]==NULL) root->children[ind]=new trieNode(word[0]);
        insertWord(word.mid(1),item,root->children[ind]);
    }
    trieNode*searchWord(QString word,trieNode*root){
        if(word.isEmpty()) return root;
        int ind=index(word[0]);
        if(root->children[ind]==NULL) return NULL;
        return searchWord(word.mid(1),root->children[ind]);
    }
    void setWords(trieNode*root){
        for(auto it=root->ptr->begin();it!=root->ptr->end();it++) (*it)->setHidden(false);
        for(int i=0;i<36;i++) if(root->children[i]) setWords(root->children[i]);
    }
    void removeWord(QString word,listItem*item,trieNode*root){
        if(word.isEmpty()){
            root->ptr->erase(item);
            return;
        }
        int ind=index(word[0]);
        if(root->children[ind]==NULL) return;
        removeWord(word.mid(1),item,root->children[ind]);
        if(root->children[ind]->ptr->size()!=0) return;
        for(int i=0;i<36;i++){
            if(root->children[ind]->children[i]!=NULL) return;
        }
        delete root->children[ind];
        root->children[ind]=NULL;
    }
public:
    trie(){
        root=new trieNode(0);
    }
    ~trie(){
        delete root;
    }
    void insertWord(QString word,listItem*item){
        for(int i=0;i<word.length();i++) insertWord(word.mid(i),item,root);
    }
    void searchWord(QString word,QListWidget*lw){
        word=word.toLower();
        for(int i=0;i<lw->count();i++) lw->item(i)->setHidden(true);
        trieNode*node=searchWord(word,root);
        if(node==NULL) return;
        setWords(node);
    }
    void removeWord(QString word,listItem*item){
        word=word.toLower();
        for(int i=0;i<word.length();i++) removeWord(word.mid(i),item,root);
    }
};

class listWidget:public QWidget{
    QListWidget*lw1;
    QVBoxLayout*v[2];
    QPushButton*b[4];
    QHBoxLayout*h[2];
    QLineEdit*edit1;
    trie searchTrie;
    Q_OBJECT
protected slots:
    virtual void newClicked(){}
    virtual void editClicked(){}
    void deleteClicked(){
        listItem*current=(listItem*)lw1->currentItem();
        searchTrie.removeWord(current->text(),current);
        lw1->removeItemWidget(current);
        delete current;
    }
    void change(QListWidgetItem*current,QListWidgetItem*previous){
        if(current==NULL){
            b[1]->setDisabled(true);
            b[2]->setDisabled(true);
        }else{
            b[1]->setEnabled(true);
            b[2]->setEnabled(true);
        }
    }
    void search(QString word){
        searchTrie.searchWord(word,lw1);
    }
public:
    listWidget(QWidget*parent=NULL):QWidget(parent){
        lw1=new QListWidget(this);
        lw1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        lw1->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        for(int i=0;i<2;i++){
            v[i]=new QVBoxLayout;
            h[i]=new QHBoxLayout;
        }
        b[0]=new QPushButton("New");
        b[1]=new QPushButton("Edit");
        b[1]->setDisabled(true);
        b[2]=new QPushButton("Delete");
        b[2]->setDisabled(true);
        b[3]=new QPushButton("X");
        b[3]->setStyleSheet("QPushButton{padding:4px 10px;background-color:rgb(77,77,77);}"
                            "QPushButton:hover{background-color:rgb(232,17,35);}");
        edit1=new QLineEdit;
        edit1->setPlaceholderText("Search");

        h[0]->addWidget(edit1);
        h[0]->addWidget(b[3]);
        v[0]->addLayout(h[0]);
        v[0]->addWidget(lw1);
        for(int i=0;i<3;i++) v[1]->addWidget(b[i]);
        v[1]->addStretch();
        for(int i=0;i<2;i++) h[1]->addLayout(v[i]);
        setLayout(h[1]);

        connect(b[0],SIGNAL(clicked()),this,SLOT(newClicked()));
        connect(b[1],SIGNAL(clicked()),this,SLOT(editClicked()));
        connect(b[2],SIGNAL(clicked()),this,SLOT(deleteClicked()));
        connect(lw1,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(change(QListWidgetItem*,QListWidgetItem*)));
        connect(edit1,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));
        connect(b[3],SIGNAL(clicked()),edit1,SLOT(clear()));
    }
    ~listWidget(){
        lw1->clear();
    }
    QListWidget* ListWidget(){return lw1;}
    QVBoxLayout* ButtonVBox(){return v[1];}
    QPushButton* NewButton(){return b[0];}
    trie& Trie(){return searchTrie;}
};

class particlesListWidget:public listWidget{
    Q_OBJECT
protected slots:
    void newClicked(){
        listItem*item=new particleListItem;
        ListWidget()->addItem(item);
        Trie().insertWord(item->text(),item);
    }
    void editClicked(){
        particleListItem*current=(particleListItem*)ListWidget()->currentItem();
        if(current) current->getPropertiesWindow()->exec();
    }
public:
    particlesListWidget(QWidget*parent=NULL):listWidget(parent){}
};

class fieldsListWidget:public listWidget{
    Q_OBJECT
    QPushButton*b4,*b5,*b6;
protected slots:
    void editClicked(){
        fieldListItem*current=(fieldListItem*)ListWidget()->currentItem();
        if(current) current->getPropertiesWindow()->exec();
    }
    void newClicked(){
        listItem*item=new gravitationalRadialFieldListItem;
        ListWidget()->addItem(item);
        Trie().insertWord(item->text().toLower(),item);
    }
    void b4Clicked(){
        listItem*item=new gravitationalUniformFieldListItem;
        ListWidget()->addItem(item);
        Trie().insertWord(item->text().toLower(),item);
    }
    void b5Clicked(){
        listItem*item=new electricRadialFieldListItem;
        ListWidget()->addItem(item);
        Trie().insertWord(item->text().toLower(),item);
    }
    void b6Clicked(){
        listItem*item=new electricUniformFieldListItem;
        ListWidget()->addItem(item);
        Trie().insertWord(item->text().toLower(),item);
    }
public:
    fieldsListWidget(QWidget*parent=NULL):listWidget(parent){
        NewButton()->setText("New Gravitational Radial Field");
        b4=new QPushButton("New Gravitational Uniform Field",this);
        b5=new QPushButton("New Electric Radial Field",this);
        b6=new QPushButton("New Electric Uniform Field",this);
        ButtonVBox()->insertWidget(1,b4);
        ButtonVBox()->insertWidget(2,b5);
        ButtonVBox()->insertWidget(3,b6);

        connect(b4,SIGNAL(clicked()),this,SLOT(b4Clicked()));
        connect(b5,SIGNAL(clicked()),this,SLOT(b5Clicked()));
        connect(b6,SIGNAL(clicked()),this,SLOT(b6Clicked()));
    }
};
