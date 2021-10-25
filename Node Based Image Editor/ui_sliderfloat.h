/********************************************************************************
** Form generated from reading UI file 'sliderfloat.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERFLOAT_H
#define UI_SLIDERFLOAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sliderFloat
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *sliderFloat)
    {
        if (sliderFloat->objectName().isEmpty())
            sliderFloat->setObjectName(QString::fromUtf8("sliderFloat"));
        sliderFloat->resize(400, 40);
        sliderFloat->setMinimumSize(QSize(0, 40));
        sliderFloat->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(sliderFloat);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(sliderFloat);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(sliderFloat);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        doubleSpinBox = new QDoubleSpinBox(sliderFloat);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setEnabled(false);

        horizontalLayout->addWidget(doubleSpinBox);

        pushButton = new QPushButton(sliderFloat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(sliderFloat);

        QMetaObject::connectSlotsByName(sliderFloat);
    } // setupUi

    void retranslateUi(QWidget *sliderFloat)
    {
        sliderFloat->setWindowTitle(QCoreApplication::translate("sliderFloat", "Form", nullptr));
        label->setText(QCoreApplication::translate("sliderFloat", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("sliderFloat", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sliderFloat: public Ui_sliderFloat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERFLOAT_H
