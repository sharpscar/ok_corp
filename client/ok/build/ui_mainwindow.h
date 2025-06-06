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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableWidget *tw_schedule;
    QWidget *page_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *s_day_le;
    QLabel *label_9;
    QTimeEdit *s_timeEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *e_day_le;
    QLabel *label_16;
    QTimeEdit *e_timeEdit;
    QPushButton *reg_sch_btn;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_17;
    QLineEdit *event_name_le;
    QLabel *label_18;
    QTextEdit *event_info_le;
    QGroupBox *groupBox_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(931, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-10, -10, 961, 51));
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
        groupBox_2->setGeometry(QRect(-10, 80, 191, 511));
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
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 118, 180, 50));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
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
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(190, 20, 761, 511));
        stackedWidget = new QStackedWidget(groupBox_4);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, -40, 741, 629));
        page = new QWidget();
        page->setObjectName("page");
        tw_schedule = new QTableWidget(page);
        tw_schedule->setObjectName("tw_schedule");
        tw_schedule->setGeometry(QRect(0, 50, 701, 171));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(90, 270, 251, 191));
        verticalLayout_2 = new QVBoxLayout(groupBox_6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        s_day_le = new QLineEdit(groupBox_6);
        s_day_le->setObjectName("s_day_le");

        horizontalLayout->addWidget(s_day_le);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);

        s_timeEdit = new QTimeEdit(groupBox_6);
        s_timeEdit->setObjectName("s_timeEdit");

        horizontalLayout->addWidget(s_timeEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName("label_10");

        horizontalLayout_2->addWidget(label_10);

        e_day_le = new QLineEdit(groupBox_6);
        e_day_le->setObjectName("e_day_le");

        horizontalLayout_2->addWidget(e_day_le);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName("label_16");

        horizontalLayout_2->addWidget(label_16);

        e_timeEdit = new QTimeEdit(groupBox_6);
        e_timeEdit->setObjectName("e_timeEdit");

        horizontalLayout_2->addWidget(e_timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        reg_sch_btn = new QPushButton(groupBox_6);
        reg_sch_btn->setObjectName("reg_sch_btn");

        verticalLayout_2->addWidget(reg_sch_btn);

        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(380, 80, 251, 171));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 80, 241, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(page_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(380, 270, 251, 221));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName("label_17");

        verticalLayout_4->addWidget(label_17);

        event_name_le = new QLineEdit(verticalLayoutWidget_3);
        event_name_le->setObjectName("event_name_le");

        verticalLayout_4->addWidget(event_name_le);

        label_18 = new QLabel(verticalLayoutWidget_3);
        label_18->setObjectName("label_18");

        verticalLayout_4->addWidget(label_18);

        event_info_le = new QTextEdit(verticalLayoutWidget_3);
        event_info_le->setObjectName("event_info_le");

        verticalLayout_4->addWidget(event_info_le);

        stackedWidget->addWidget(page_2);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 680, 941, 111));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/background_bottom.png);\n"
"background: qlineargradient(\n"
"    x1: 0, y1: 0,\n"
"    x2: 1, y2: 0,\n"
"    stop: 0 #002147,\n"
"    stop: 1 #004080\n"
");\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


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
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\355\226\211\354\202\254\352\264\200\353\246\254", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\354\213\234\354\236\221\354\235\274", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\354\213\234\352\260\204", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\354\242\205\353\243\214\354\235\274", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\354\213\234\352\260\204", nullptr));
        reg_sch_btn->setText(QCoreApplication::translate("MainWindow", "\354\235\274\354\240\225\353\223\261\353\241\235", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\355\226\211\354\202\254 \354\240\234\353\252\251", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\355\226\211\354\202\254 \352\260\234\354\232\224", nullptr));
        groupBox_3->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
