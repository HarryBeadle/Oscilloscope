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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *actionConnect_to_Serial;
    QWidget *centralWidget;
    QFrame *line;
    QCustomPlot *customPlot;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *triggerSpinBox;
    QFrame *line_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *freqLabel_2;
    QLCDNumber *freqNumber;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
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
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(280, 10, 21, 601));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(300, 10, 861, 601));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(150, 90, 121, 24));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 90, 121, 24));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 220, 251, 24));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 150, 271, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 40, 271, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 10, 251, 24));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 250, 251, 24));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 251, 21));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 160, 271, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 171, 21));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        triggerSpinBox = new QDoubleSpinBox(centralWidget);
        triggerSpinBox->setObjectName(QStringLiteral("triggerSpinBox"));
        triggerSpinBox->setGeometry(QRect(200, 120, 67, 25));
        triggerSpinBox->setMaximum(3.3);
        triggerSpinBox->setSingleStep(0.01);
        triggerSpinBox->setValue(1.65);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 280, 271, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 300, 271, 21));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 330, 111, 21));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        freqLabel_2 = new QLabel(centralWidget);
        freqLabel_2->setObjectName(QStringLiteral("freqLabel_2"));
        freqLabel_2->setGeometry(QRect(240, 330, 21, 21));
        freqLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        freqNumber = new QLCDNumber(centralWidget);
        freqNumber->setObjectName(QStringLiteral("freqNumber"));
        freqNumber->setGeometry(QRect(160, 330, 64, 23));
        freqNumber->setDigitCount(4);
        freqNumber->setSegmentStyle(QLCDNumber::Flat);
        freqNumber->setProperty("value", QVariant(16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 190, 71, 21));
        label_6->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 190, 181, 24));
        Window->setCentralWidget(centralWidget);
        freqNumber->raise();
        line->raise();
        customPlot->raise();
        pushButton_5->raise();
        pushButton->raise();
        pushButton_2->raise();
        line_2->raise();
        line_3->raise();
        pushButton_6->raise();
        pushButton_3->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        triggerSpinBox->raise();
        line_4->raise();
        label_4->raise();
        label_5->raise();
        freqLabel_2->raise();
        label_6->raise();
        lineEdit->raise();
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1169, 22));
        Window->setMenuBar(menuBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window->setStatusBar(statusBar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Oscilloscope", 0));
        actionConnect_to_Serial->setText(QApplication::translate("Window", "Connect to Serial", 0));
        pushButton_5->setText(QApplication::translate("Window", "Run", 0));
        pushButton->setText(QApplication::translate("Window", "Single", 0));
        pushButton_2->setText(QApplication::translate("Window", "Export as CSV", 0));
        pushButton_6->setText(QApplication::translate("Window", "Connect to Device", 0));
        pushButton_3->setText(QApplication::translate("Window", "Export as PNG", 0));
        label->setText(QApplication::translate("Window", "Triggering and Running", 0));
        label_2->setText(QApplication::translate("Window", "Exporting", 0));
        label_3->setText(QApplication::translate("Window", "Trigger Level (Volts)", 0));
        label_4->setText(QApplication::translate("Window", "Measurements", 0));
        label_5->setText(QApplication::translate("Window", "Frequency", 0));
        freqLabel_2->setText(QApplication::translate("Window", "Hz", 0));
        label_6->setText(QApplication::translate("Window", "Filename:", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
