#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QtNetwork>
#include <QString>
#include <QObject>

class account : public QObject
{
public:
    QTcpSocket *sock;
    QString userId;
    QString userPwd;
    QString to;
    QString msg;

public:
    account(QTcpSocket *, QString, QString, QString, QString);
    QString dumps(QString);
};

#endif // ACCOUNT_H
