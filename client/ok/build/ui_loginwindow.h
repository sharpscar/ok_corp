/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QLabel *label;
    QLineEdit *idEdit;
    QLineEdit *pwEdit;
    QPushButton *loginButton;
    QLabel *linksLabel;
    QLabel *footerLabel;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 360);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName("gridLayout");
        logoLabel = new QLabel(LoginWindow);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/logo/logo_gs_v2.png")));
        logoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(logoLabel, 0, 0, 1, 1);

        titleLabel = new QLabel(LoginWindow);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(titleLabel, 1, 0, 1, 1);

        label = new QLabel(LoginWindow);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        idEdit = new QLineEdit(LoginWindow);
        idEdit->setObjectName("idEdit");
        idEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idEdit->sizePolicy().hasHeightForWidth());
        idEdit->setSizePolicy(sizePolicy1);
        idEdit->setMinimumSize(QSize(0, 40));
        idEdit->setMaximumSize(QSize(260, 16777215));
        QFont font1;
        font1.setPointSize(12);
        idEdit->setFont(font1);
        idEdit->setAutoFillBackground(false);
        idEdit->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(idEdit, 3, 0, 1, 1);

        pwEdit = new QLineEdit(LoginWindow);
        pwEdit->setObjectName("pwEdit");
        sizePolicy1.setHeightForWidth(pwEdit->sizePolicy().hasHeightForWidth());
        pwEdit->setSizePolicy(sizePolicy1);
        pwEdit->setMinimumSize(QSize(0, 40));
        pwEdit->setMaximumSize(QSize(260, 16777215));
        pwEdit->setFont(font1);
        pwEdit->setAutoFillBackground(false);
        pwEdit->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgb(255, 255, 255);"));
        pwEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(pwEdit, 4, 0, 1, 1);

        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy2);
        loginButton->setMinimumSize(QSize(0, 45));
        loginButton->setMaximumSize(QSize(260, 16777215));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        loginButton->setFont(font2);

        gridLayout->addWidget(loginButton, 5, 0, 1, 1);

        linksLabel = new QLabel(LoginWindow);
        linksLabel->setObjectName("linksLabel");
        linksLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(linksLabel, 6, 0, 1, 1);

        footerLabel = new QLabel(LoginWindow);
        footerLabel->setObjectName("footerLabel");
        footerLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(footerLabel, 7, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
        LoginWindow->setStyleSheet(QCoreApplication::translate("LoginWindow", "\n"
"#LoginWindow {\n"
"    border-radius: 20px;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #1165c0,\n"
"        stop: 1 #000000\n"
"    );\n"
"}\n"
"", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "\352\264\221\354\243\274\352\264\221\354\227\255\354\213\234 \352\264\221\354\202\260\352\265\254\354\262\255\n"
"\353\213\250\354\262\264 \355\206\265\355\225\251 \352\264\200\353\246\254 \354\213\234\354\212\244\355\205\234", nullptr));
        label->setText(QString());
        idEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\354\225\204\354\235\264\353\224\224", nullptr));
        pwEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        loginButton->setStyleSheet(QCoreApplication::translate("LoginWindow", "\n"
"QPushButton#loginButton {\n"
"    background-color: #1a4ca0;\n"
"    color: white;\n"
"    border: 1px solid #0b3a77;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton#loginButton:hover {\n"
"    background-color: #2a5cc0;\n"
"}\n"
"QPushButton#loginButton:pressed {\n"
"    background-color: #0b3a77;\n"
"}\n"
"", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\353\241\234 \352\267\270 \354\235\270", nullptr));
        linksLabel->setText(QCoreApplication::translate("LoginWindow", "\354\225\204\354\235\264\353\224\224\354\260\276\352\270\260   |   \353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260   |   \355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
