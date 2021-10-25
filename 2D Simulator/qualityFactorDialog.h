#include"sliderint.h"
#include<QDialog>
#include<QVBoxLayout>
#include<QDialogButtonBox>

void QSS(QWidget*widget);

class qualityFactorDialog:public QDialog{
    Q_OBJECT
    sliderInt*slider1;
    QVBoxLayout*v1;
    QDialogButtonBox*b1;
    QHBoxLayout*h1;
public:
    qualityFactorDialog(QWidget*parent=NULL):QDialog(parent){
        setWindowTitle("Quality Factor");
        setWindowFlags(Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
        v1=new QVBoxLayout;
        slider1=new sliderInt;
        slider1->setText("Quality Factor:");
        slider1->setRange(0,100);
        slider1->setDefaultValue(100);
        h1=new QHBoxLayout;
        b1=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

        h1->addStretch();
        h1->addWidget(b1);
        v1->addWidget(slider1);
        v1->addLayout(h1);
        v1->addStretch();
        setLayout(v1);

        connect(b1,SIGNAL(accepted()),this,SLOT(accept()));
        connect(b1,SIGNAL(rejected()),this,SLOT(reject()));

        QSS(this);
    }
    int getValue(){
        return slider1->getValue();
    }
};
