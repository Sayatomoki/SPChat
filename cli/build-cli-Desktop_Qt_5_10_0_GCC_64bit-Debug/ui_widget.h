/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *hostText;
    QSpinBox *portSpin;
    QPushButton *linkBtn;
    QPushButton *canBtn;
    QPushButton *disBtn;
    QLineEdit *username;
    QLineEdit *userpassword;
    QTextEdit *textEdit;
    QListView *listView;
    QPushButton *loginBtn;
    QPushButton *logoutBtn;
    QPushButton *signUpBtn;
    QLineEdit *sendEdit;
    QPushButton *sendBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1101, 819);
        hostText = new QLineEdit(Widget);
        hostText->setObjectName(QStringLiteral("hostText"));
        hostText->setGeometry(QRect(50, 70, 211, 51));
        portSpin = new QSpinBox(Widget);
        portSpin->setObjectName(QStringLiteral("portSpin"));
        portSpin->setGeometry(QRect(280, 70, 111, 51));
        portSpin->setMaximum(65535);
        linkBtn = new QPushButton(Widget);
        linkBtn->setObjectName(QStringLiteral("linkBtn"));
        linkBtn->setGeometry(QRect(220, 140, 71, 51));
        canBtn = new QPushButton(Widget);
        canBtn->setObjectName(QStringLiteral("canBtn"));
        canBtn->setGeometry(QRect(950, 750, 101, 51));
        disBtn = new QPushButton(Widget);
        disBtn->setObjectName(QStringLiteral("disBtn"));
        disBtn->setEnabled(false);
        disBtn->setGeometry(QRect(300, 140, 91, 51));
        username = new QLineEdit(Widget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(560, 60, 241, 45));
        userpassword = new QLineEdit(Widget);
        userpassword->setObjectName(QStringLiteral("userpassword"));
        userpassword->setGeometry(QRect(560, 120, 241, 45));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 230, 671, 501));
        listView = new QListView(Widget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(775, 230, 271, 501));
        loginBtn = new QPushButton(Widget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(830, 30, 163, 51));
        logoutBtn = new QPushButton(Widget);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        logoutBtn->setEnabled(false);
        logoutBtn->setGeometry(QRect(830, 90, 163, 51));
        signUpBtn = new QPushButton(Widget);
        signUpBtn->setObjectName(QStringLiteral("signUpBtn"));
        signUpBtn->setGeometry(QRect(830, 150, 163, 51));
        sendEdit = new QLineEdit(Widget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(70, 750, 671, 45));
        sendBtn = new QPushButton(Widget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(780, 750, 163, 51));

        retranslateUi(Widget);
        QObject::connect(canBtn, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        linkBtn->setText(QApplication::translate("Widget", "link", nullptr));
        canBtn->setText(QApplication::translate("Widget", "cancel", nullptr));
        disBtn->setText(QApplication::translate("Widget", "discon", nullptr));
        loginBtn->setText(QApplication::translate("Widget", "login", nullptr));
        logoutBtn->setText(QApplication::translate("Widget", "logout", nullptr));
        signUpBtn->setText(QApplication::translate("Widget", "sign up", nullptr));
        sendBtn->setText(QApplication::translate("Widget", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
