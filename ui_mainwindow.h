/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *videoWidget;
    QWidget *widget;
    QPushButton *BtnAdd;
    QPushButton *BtnPlay;
    QPushButton *Btn_Pause;
    QPushButton *BtnStop;
    QPushButton *BtnFullScr;
    QPushButton *Btnsound;
    QSlider *sliderVolume;
    QWidget *widget_2;
    QLabel *LabCurMedia;
    QSlider *sliderPosition;
    QLabel *LabRatio;
    QPushButton *BtnBack;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(614, 446);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 481, 301));
        videoWidget = new QWidget(groupBox);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->setGeometry(QRect(-1, -1, 481, 301));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 330, 601, 71));
        BtnAdd = new QPushButton(widget);
        BtnAdd->setObjectName(QStringLiteral("BtnAdd"));
        BtnAdd->setGeometry(QRect(0, 0, 80, 60));
        BtnPlay = new QPushButton(widget);
        BtnPlay->setObjectName(QStringLiteral("BtnPlay"));
        BtnPlay->setGeometry(QRect(80, 0, 80, 60));
        Btn_Pause = new QPushButton(widget);
        Btn_Pause->setObjectName(QStringLiteral("Btn_Pause"));
        Btn_Pause->setGeometry(QRect(160, 0, 80, 60));
        BtnStop = new QPushButton(widget);
        BtnStop->setObjectName(QStringLiteral("BtnStop"));
        BtnStop->setGeometry(QRect(240, 0, 80, 60));
        BtnFullScr = new QPushButton(widget);
        BtnFullScr->setObjectName(QStringLiteral("BtnFullScr"));
        BtnFullScr->setGeometry(QRect(320, 0, 80, 60));
        Btnsound = new QPushButton(widget);
        Btnsound->setObjectName(QStringLiteral("Btnsound"));
        Btnsound->setGeometry(QRect(400, 0, 80, 60));
        sliderVolume = new QSlider(widget);
        sliderVolume->setObjectName(QStringLiteral("sliderVolume"));
        sliderVolume->setGeometry(QRect(480, 20, 121, 22));
        sliderVolume->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 410, 511, 21));
        LabCurMedia = new QLabel(widget_2);
        LabCurMedia->setObjectName(QStringLiteral("LabCurMedia"));
        LabCurMedia->setGeometry(QRect(10, 10, 54, 12));
        sliderPosition = new QSlider(widget_2);
        sliderPosition->setObjectName(QStringLiteral("sliderPosition"));
        sliderPosition->setGeometry(QRect(70, 0, 371, 22));
        sliderPosition->setOrientation(Qt::Horizontal);
        LabRatio = new QLabel(widget_2);
        LabRatio->setObjectName(QStringLiteral("LabRatio"));
        LabRatio->setGeometry(QRect(450, 0, 54, 12));
        BtnBack = new QPushButton(centralwidget);
        BtnBack->setObjectName(QStringLiteral("BtnBack"));
        BtnBack->setGeometry(QRect(520, 30, 75, 23));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QString());
        BtnAdd->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        BtnPlay->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", 0));
        Btn_Pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        BtnStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        BtnFullScr->setText(QApplication::translate("MainWindow", "\345\205\250\345\261\217", 0));
        Btnsound->setText(QApplication::translate("MainWindow", "PushButton", 0));
        LabCurMedia->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LabRatio->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        BtnBack->setText(QApplication::translate("MainWindow", "back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
