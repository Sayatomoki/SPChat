#include "account.h"
#include <QtNetwork>

account::account(QTcpSocket *s = NULL, QString i = "", QString p = "", QString t = "", QString m = "")
{
    sock = s;
    userId = i;
    userPwd = p;
    to = t;
    msg = m;
}

QString account::dumps(QString header)
{
    QString a = "{\"header\": ";
    QString c = "\"";
    QString b = "\", ";
    QString result = a + "\""+header + "\", "+"\"userId\": "+"\""+userId+"\", " + "\"userPwd\": " + "\"" + userPwd + "\", " + "\"to\": "+ c + to + "\", " + "\"msg\": " + "\"" + msg + "\" }";
    return result;
}
