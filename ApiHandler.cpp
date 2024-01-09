#include "ApiHandler.h"
#include "ApiDevice.h"

ApiHandler::ApiHandler() : url("http://localhost:5175"), manager(this)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ApiHandler::response);
}

void ApiHandler::setPath(QString path)
{
    url.setPath(path);
}

void ApiHandler::requestGet()
{
    manager.get(QNetworkRequest(url));
}

void ApiHandler::requestPost()
{
    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");
    manager.post(request, "{}");
}

void ApiHandler::requestPost(const QByteArray& data)
{
    manager.post(QNetworkRequest(url), data);
}

void ApiHandler::response(QNetworkReply* reply)
{
    handle(reply->readAll());
}
