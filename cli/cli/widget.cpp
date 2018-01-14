#include "widget.h"
#include "ui_widget.h"
#include "account.h"
#include <QtNetwork>
#include <QMessageBox>

QTcpSocket *s;
account* user = new account(NULL, "", "", "", "");

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_linkBtn_clicked()
{
    s = new QTcpSocket;
    s->connectToHost(QHostAddress(ui->hostText->text()), ui->portSpin->value());
    s->bind(ui->portSpin->value());
    ui->disBtn->setEnabled(true);
    ui->linkBtn->setEnabled(false);
}

void Widget::on_disBtn_clicked()
{
    s->close();
    ui->linkBtn->setEnabled(true);
    ui->disBtn->setEnabled(false);
}

void Widget::on_loginBtn_clicked()
{
//    account* user = new account(s, ui->username->text(), ui->userpassword->text(), "123", "456");
//    ui->sendEdit->setText(user->dumps("header"));
    if (s->isOpen())
    {
        user->sock = s;
        user->userId = ui->username->text();
        user->userPwd = ui->userpassword->text();
    }
    ui->logoutBtn->setEnabled(true);
    ui->loginBtn->setEnabled(false);
    QString h = "login";
//    QMessageBox(this, "about", user->dumps(h));
    user->sock->write(user->dumps(h).toLocal8Bit());

}

void Widget::on_logoutBtn_clicked()
{
    if (user->sock->isOpen())
    {
        ui->loginBtn->setEnabled(true);
        ui->logoutBtn->setEnabled(false);
        user->sock->close();
    }
}

void Widget::on_signUpBtn_clicked()
{
    if (s->isOpen())
    {
        user->sock = s;
        user->userId = ui->username->text();
        user->userPwd = ui->userpassword->text();
    }
    QString h = "signUp";
    user->sock->write(user->dumps(h).toLocal8Bit());
}
