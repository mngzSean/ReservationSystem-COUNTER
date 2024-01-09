#include "ApiDevice.h"

void ApiDevice::requestCount()
{
    setPath("/Device/counter");
    requestGet();
}

void ApiDevice::requestIssue()
{
    setPath("/Device/counter/issue");
    requestPost();
}

void ApiDevice::handle(QByteArray data)
{
    QString answer = data;
    emit replyCount(answer.toInt());
}
