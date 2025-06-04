/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QStackedWidget *stackedWidget;
    QWidget *sch_page_1;
    QTableWidget *tw_schedule;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *le_org;
    QLabel *label_6;
    QLineEdit *le_dong;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *le_start;
    QLabel *label_8;
    QLineEdit *le_end;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *le_manager;
    QLabel *label_12;
    QLineEdit *le_man_phone;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *s_name;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QTextEdit *s_detail;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QPushButton *insert_btn;
    QCheckBox *checkBox;
    QPushButton *s_update_btn;
    QPushButton *cancel_btn;
    QPushButton *s_delete_btn;
    QWidget *sch_page_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *s_day_le;
    QLabel *label_9;
    QTimeEdit *s_timeEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *e_day_le;
    QLabel *label_10;
    QTimeEdit *e_timeEdit;
    QPushButton *reg_sch_btn;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *event_name_le;
    QLabel *label_4;
    QTextEdit *event_info_le;

    void setupUi(QWidget *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName("Schedule");
        Schedule->resize(902, 688);
        stackedWidget = new QStackedWidget(Schedule);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(60, -190, 821, 851));
        sch_page_1 = new QWidget();
        sch_page_1->setObjectName("sch_page_1");
        tw_schedule = new QTableWidget(sch_page_1);
        tw_schedule->setObjectName("tw_schedule");
        tw_schedule->setGeometry(QRect(40, 60, 771, 291));
        QFont font;
        font.setBold(false);
        tw_schedule->setFont(font);
        groupBox_2 = new QGroupBox(sch_page_1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(370, 380, 443, 413));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        le_org = new QLineEdit(groupBox_2);
        le_org->setObjectName("le_org");

        horizontalLayout_3->addWidget(le_org);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        le_dong = new QLineEdit(groupBox_2);
        le_dong->setObjectName("le_dong");

        horizontalLayout_3->addWidget(le_dong);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        le_start = new QLineEdit(groupBox_2);
        le_start->setObjectName("le_start");

        horizontalLayout_4->addWidget(le_start);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        le_end = new QLineEdit(groupBox_2);
        le_end->setObjectName("le_end");

        horizontalLayout_4->addWidget(le_end);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");

        horizontalLayout_6->addWidget(label_11);

        le_manager = new QLineEdit(groupBox_2);
        le_manager->setObjectName("le_manager");

        horizontalLayout_6->addWidget(le_manager);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");

        horizontalLayout_6->addWidget(label_12);

        le_man_phone = new QLineEdit(groupBox_2);
        le_man_phone->setObjectName("le_man_phone");

        horizontalLayout_6->addWidget(le_man_phone);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        horizontalLayout_8->addWidget(label_13);

        s_name = new QLineEdit(groupBox_2);
        s_name->setObjectName("s_name");

        horizontalLayout_8->addWidget(s_name);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");

        horizontalLayout_9->addWidget(label_14);

        s_detail = new QTextEdit(groupBox_2);
        s_detail->setObjectName("s_detail");

        horizontalLayout_9->addWidget(s_detail);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");

        horizontalLayout_10->addWidget(label_15);

        insert_btn = new QPushButton(groupBox_2);
        insert_btn->setObjectName("insert_btn");

        horizontalLayout_10->addWidget(insert_btn);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");

        horizontalLayout_10->addWidget(checkBox);

        s_update_btn = new QPushButton(groupBox_2);
        s_update_btn->setObjectName("s_update_btn");

        horizontalLayout_10->addWidget(s_update_btn);

        cancel_btn = new QPushButton(groupBox_2);
        cancel_btn->setObjectName("cancel_btn");

        horizontalLayout_10->addWidget(cancel_btn);

        s_delete_btn = new QPushButton(groupBox_2);
        s_delete_btn->setObjectName("s_delete_btn");

        horizontalLayout_10->addWidget(s_delete_btn);


        verticalLayout_5->addLayout(horizontalLayout_10);

        stackedWidget->addWidget(sch_page_1);
        sch_page_2 = new QWidget();
        sch_page_2->setObjectName("sch_page_2");
        groupBox = new QGroupBox(sch_page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 350, 331, 151));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        s_day_le = new QLineEdit(groupBox);
        s_day_le->setObjectName("s_day_le");

        horizontalLayout->addWidget(s_day_le);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);

        s_timeEdit = new QTimeEdit(groupBox);
        s_timeEdit->setObjectName("s_timeEdit");

        horizontalLayout->addWidget(s_timeEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        e_day_le = new QLineEdit(groupBox);
        e_day_le->setObjectName("e_day_le");

        horizontalLayout_2->addWidget(e_day_le);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");

        horizontalLayout_2->addWidget(label_10);

        e_timeEdit = new QTimeEdit(groupBox);
        e_timeEdit->setObjectName("e_timeEdit");

        horizontalLayout_2->addWidget(e_timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        reg_sch_btn = new QPushButton(groupBox);
        reg_sch_btn->setObjectName("reg_sch_btn");

        verticalLayout_2->addWidget(reg_sch_btn);

        verticalLayoutWidget_2 = new QWidget(sch_page_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(430, 80, 291, 221));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(sch_page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 80, 291, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(sch_page_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(430, 350, 311, 241));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        event_name_le = new QLineEdit(verticalLayoutWidget_3);
        event_name_le->setObjectName("event_name_le");

        verticalLayout_4->addWidget(event_name_le);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        event_info_le = new QTextEdit(verticalLayoutWidget_3);
        event_info_le->setObjectName("event_info_le");

        verticalLayout_4->addWidget(event_info_le);

        stackedWidget->addWidget(sch_page_2);

        retranslateUi(Schedule);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QWidget *Schedule)
    {
        Schedule->setWindowTitle(QCoreApplication::translate("Schedule", "Form", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Schedule", "GroupBox", nullptr));
        label_5->setText(QCoreApplication::translate("Schedule", "\353\213\250\354\262\264\353\252\205", nullptr));
        label_6->setText(QCoreApplication::translate("Schedule", "\354\206\214\354\206\215\353\217\231", nullptr));
        label_7->setText(QCoreApplication::translate("Schedule", "\354\213\234\354\236\221\354\235\274", nullptr));
        label_8->setText(QCoreApplication::translate("Schedule", "\354\242\205\353\243\214\354\235\274", nullptr));
        label_11->setText(QCoreApplication::translate("Schedule", "\353\213\264\353\213\271\354\236\220", nullptr));
        label_12->setText(QCoreApplication::translate("Schedule", "\353\213\264\353\213\271 \354\227\260\353\235\275\354\262\230", nullptr));
        label_13->setText(QCoreApplication::translate("Schedule", "\355\226\211\354\202\254\353\252\205", nullptr));
        label_14->setText(QCoreApplication::translate("Schedule", "\355\226\211\354\202\254 \354\203\201\354\204\270", nullptr));
        label_15->setText(QCoreApplication::translate("Schedule", "\352\263\265\352\260\234\354\227\254\353\266\200", nullptr));
        insert_btn->setText(QCoreApplication::translate("Schedule", " \354\236\205\353\240\245", nullptr));
        checkBox->setText(QString());
        s_update_btn->setText(QCoreApplication::translate("Schedule", "\354\210\230\354\240\225", nullptr));
        cancel_btn->setText(QCoreApplication::translate("Schedule", "\354\267\250\354\206\214", nullptr));
        s_delete_btn->setText(QCoreApplication::translate("Schedule", "\354\202\255\354\240\234", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Schedule", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("Schedule", "\354\213\234\354\236\221\354\235\274", nullptr));
        label_9->setText(QCoreApplication::translate("Schedule", "\354\213\234\352\260\204", nullptr));
        label_2->setText(QCoreApplication::translate("Schedule", "\354\242\205\353\243\214\354\235\274", nullptr));
        label_10->setText(QCoreApplication::translate("Schedule", "\354\213\234\352\260\204", nullptr));
        reg_sch_btn->setText(QCoreApplication::translate("Schedule", "\354\235\274\354\240\225\353\223\261\353\241\235", nullptr));
        label_3->setText(QCoreApplication::translate("Schedule", "\355\226\211\354\202\254 \354\240\234\353\252\251", nullptr));
        label_4->setText(QCoreApplication::translate("Schedule", "\355\226\211\354\202\254 \352\260\234\354\232\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
