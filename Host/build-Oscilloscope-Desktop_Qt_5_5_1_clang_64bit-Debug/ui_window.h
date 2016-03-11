/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *actionConnect_to_Serial;
    QWidget *centralWidget;
    QTabWidget *channel_Settings;
    QWidget *channel_1;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *channel_2;
    QPushButton *pushButton_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QWidget *channel_3;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_6;
    QWidget *channel_4;
    QPushButton *pushButton_4;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_10;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuSetup;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(1169, 638);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window->sizePolicy().hasHeightForWidth());
        Window->setSizePolicy(sizePolicy);
        Window->setMinimumSize(QSize(1169, 638));
        Window->setMaximumSize(QSize(1169, 638));
        actionConnect_to_Serial = new QAction(Window);
        actionConnect_to_Serial->setObjectName(QStringLiteral("actionConnect_to_Serial"));
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        channel_Settings = new QTabWidget(centralWidget);
        channel_Settings->setObjectName(QStringLiteral("channel_Settings"));
        channel_Settings->setGeometry(QRect(20, 30, 251, 131));
        channel_Settings->setToolTipDuration(-1);
        channel_Settings->setTabPosition(QTabWidget::North);
        channel_Settings->setTabShape(QTabWidget::Triangular);
        channel_Settings->setMovable(true);
        channel_1 = new QWidget();
        channel_1->setObjectName(QStringLiteral("channel_1"));
        pushButton = new QPushButton(channel_1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 231, 24));
        doubleSpinBox = new QDoubleSpinBox(channel_1);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(170, 40, 67, 25));
        label_2 = new QLabel(channel_1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 141, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(channel_1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 141, 21));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_2 = new QDoubleSpinBox(channel_1);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(170, 70, 67, 25));
        channel_Settings->addTab(channel_1, QString());
        channel_2 = new QWidget();
        channel_2->setObjectName(QStringLiteral("channel_2"));
        pushButton_2 = new QPushButton(channel_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 231, 24));
        doubleSpinBox_3 = new QDoubleSpinBox(channel_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(170, 40, 67, 25));
        label_4 = new QLabel(channel_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 70, 141, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(channel_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 40, 141, 21));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_4 = new QDoubleSpinBox(channel_2);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(170, 70, 67, 25));
        channel_Settings->addTab(channel_2, QString());
        channel_3 = new QWidget();
        channel_3->setObjectName(QStringLiteral("channel_3"));
        pushButton_3 = new QPushButton(channel_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 231, 24));
        doubleSpinBox_5 = new QDoubleSpinBox(channel_3);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(170, 40, 67, 25));
        label_6 = new QLabel(channel_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 70, 141, 21));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(channel_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 40, 141, 21));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_6 = new QDoubleSpinBox(channel_3);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(170, 70, 67, 25));
        channel_Settings->addTab(channel_3, QString());
        channel_4 = new QWidget();
        channel_4->setObjectName(QStringLiteral("channel_4"));
        pushButton_4 = new QPushButton(channel_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 231, 24));
        doubleSpinBox_7 = new QDoubleSpinBox(channel_4);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(170, 40, 67, 25));
        label_8 = new QLabel(channel_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 70, 141, 21));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(channel_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 40, 141, 21));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_8 = new QDoubleSpinBox(channel_4);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(170, 70, 67, 25));
        channel_Settings->addTab(channel_4, QString());
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 251, 16));
        label_3->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(280, 10, 21, 601));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 170, 251, 16));
        label_10->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 190, 251, 421));
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1169, 22));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QStringLiteral("menuSetup"));
        Window->setMenuBar(menuBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window->setStatusBar(statusBar);

        menuBar->addAction(menuSetup->menuAction());
        menuSetup->addAction(actionConnect_to_Serial);

        retranslateUi(Window);

        channel_Settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Oscilloscope", 0));
        actionConnect_to_Serial->setText(QApplication::translate("Window", "Connect to Serial", 0));
        pushButton->setText(QApplication::translate("Window", "Activate", 0));
        label_2->setText(QApplication::translate("Window", "Time Base (s)", 0));
        label->setText(QApplication::translate("Window", "Vertical Resolution (V)", 0));
        channel_Settings->setTabText(channel_Settings->indexOf(channel_1), QApplication::translate("Window", "Ch 1", 0));
        channel_Settings->setTabToolTip(channel_Settings->indexOf(channel_1), QApplication::translate("Window", "Settings for Channel 1", 0));
        pushButton_2->setText(QApplication::translate("Window", "Activate", 0));
        label_4->setText(QApplication::translate("Window", "Time Base (s)", 0));
        label_5->setText(QApplication::translate("Window", "Vertical Resolution (V)", 0));
        channel_Settings->setTabText(channel_Settings->indexOf(channel_2), QApplication::translate("Window", "Ch 2", 0));
        pushButton_3->setText(QApplication::translate("Window", "Activate", 0));
        label_6->setText(QApplication::translate("Window", "Time Base (s)", 0));
        label_7->setText(QApplication::translate("Window", "Vertical Resolution (V)", 0));
        channel_Settings->setTabText(channel_Settings->indexOf(channel_3), QApplication::translate("Window", "Ch 3", 0));
        pushButton_4->setText(QApplication::translate("Window", "Activate", 0));
        label_8->setText(QApplication::translate("Window", "Time Base (s)", 0));
        label_9->setText(QApplication::translate("Window", "Vertical Resolution (V)", 0));
        channel_Settings->setTabText(channel_Settings->indexOf(channel_4), QApplication::translate("Window", "Ch 4", 0));
        channel_Settings->setTabToolTip(channel_Settings->indexOf(channel_4), QApplication::translate("Window", "Settings for Channel 2", 0));
        label_3->setText(QApplication::translate("Window", "Channel Settings", 0));
        label_10->setText(QApplication::translate("Window", "Measurements", 0));
        menuSetup->setTitle(QApplication::translate("Window", "Setup", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
