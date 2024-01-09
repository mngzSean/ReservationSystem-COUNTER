#ifndef APIRESPONSE_H
#define APIRESPONSE_H

#include <QObject>
#include <QStringList>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class ApiHandler : public QObject
{
    Q_OBJECT
private:
    QUrl url;
    QNetworkAccessManager manager;
protected:
    void setPath(QString path);
    void requestGet();
    void requestPost();
    void requestPost(const QByteArray& data);
    virtual void handle(QString path, QByteArray data) = 0;
public:
    ApiHandler();
    virtual ~ApiHandler() {}
private slots:
    void response(QNetworkReply* reply);
};

#endif // APIRESPONSE_H
