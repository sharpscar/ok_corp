/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *linksLabel;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *sch_btn;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_3;
    QStackedWidget *main_sw;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(931, 645);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-10, -10, 941, 91));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 80, 153);\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 25, 101, 41));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/gwangsan_logo.png);\n"
"\n"
""));
        linksLabel = new QLabel(groupBox);
        linksLabel->setObjectName("linksLabel");
        linksLabel->setGeometry(QRect(730, 43, 181, 24));
        QFont font;
        font.setBold(true);
        linksLabel->setFont(font);
        linksLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 38, 311, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(710, 37, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/icon_bell.png);"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(-10, 80, 191, 461));
        groupBox_2->setStyleSheet(QString::fromUtf8("\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0,\n"
"    x2: 0, y2: 1,\n"
"    stop: 0 #093666,\n"
"    stop: 1 #041A30\n"
");\n"
""));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 180, 50));
        QFont font2;
        font2.setPointSize(13);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 64, 180, 50));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        sch_btn = new QPushButton(groupBox_2);
        sch_btn->setObjectName("sch_btn");
        sch_btn->setGeometry(QRect(10, 118, 180, 50));
        sch_btn->setFont(font2);
        sch_btn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 172, 180, 50));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 226, 180, 50));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 280, 180, 50));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 334, 180, 50));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 387, 180, 50));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #0D4C91;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0050a0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #002147;\n"
"}\n"
""));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(-10, 534, 941, 111));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/background_bottom.png);\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0,\n"
"    x2: 1, y2: 0,\n"
"    stop: 0 #002147,\n"
"    stop: 1 #004080\n"
");\n"
""));
        main_sw = new QStackedWidget(centralwidget);
        main_sw->setObjectName("main_sw");
        main_sw->setGeometry(QRect(200, 90, 701, 421));
        page = new QWidget();
        page->setObjectName("page");
        main_sw->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        main_sw->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        main_sw->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\352\264\221\354\202\260\352\265\254\354\262\255 \355\206\265\355\225\251\352\264\200\353\246\254", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        linksLabel->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224   |   \353\241\234\352\267\270\354\225\204\354\233\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\352\264\221\354\202\260\352\265\254\354\262\255 \355\206\265\355\225\251\352\264\200\353\246\254 \354\213\234\354\212\244\355\205\234", nullptr));
        label_3->setText(QString());
        groupBox_2->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        sch_btn->setText(QCoreApplication::translate("MainWindow", "\355\226\211\354\202\254\352\264\200\353\246\254", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_3->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
