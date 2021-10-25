/********************************************************************************
** Form generated from reading UI file 'sliderint.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERINT_H
#define UI_SLIDERINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sliderInt
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *sliderInt)
    {
        if (sliderInt->objectName().isEmpty())
            sliderInt->setObjectName(QString::fromUtf8("sliderInt"));
        sliderInt->resize(496, 40);
        sliderInt->setMinimumSize(QSize(0, 40));
        sliderInt->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(sliderInt);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(sliderInt);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(sliderInt);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(sliderInt);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(sliderInt);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("padding: 20px;"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(sliderInt);

        QMetaObject::connectSlotsByName(sliderInt);
    } // setupUi

    void retranslateUi(QWidget *sliderInt)
    {
        sliderInt->setWindowTitle(QCoreApplication::translate("sliderInt", "Form", nullptr));
        label->setText(QCoreApplication::translate("sliderInt", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("sliderInt", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sliderInt: public Ui_sliderInt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERINT_H
