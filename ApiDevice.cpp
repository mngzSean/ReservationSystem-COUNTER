#include "ApiDevice.h"

#define REQUEST_COUNT "/Device/counter"
#define REQUEST_ISSUE "/Device/counter/issue"

void ApiDevice::requestCount()
{
    setPath(REQUEST_COUNT);
    requestGet();
}

void ApiDevice::requestIssue()
{
    setPath(REQUEST_ISSUE);
    requestPost();
}

void ApiDevice::handle(QString path, QByteArray data)
{
    if(path == REQUEST_COUNT)
    {
        QString answer = data;
        emit replyCount(answer.toInt());
    }
    else if(path == REQUEST_ISSUE)
    {
        // 발급을 했을 때 다음 번호를 응답으로 전달
        QString answer = data;
        emit replyCount(answer.toInt());
    }
}
