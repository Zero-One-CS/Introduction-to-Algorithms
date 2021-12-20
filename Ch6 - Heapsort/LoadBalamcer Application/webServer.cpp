#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webServer
{
private:
    request r;
    int requestStartTime;
    char serverName;

public:
    webServer()
    {
        requestStartTime = 0;
        serverName = ' ';
    }

    webServer(char C)
    {
        serverName = C;
        requestStartTime = 0;
    }

    void AddRequest(request req, int currTime)
    {
        r = req;
        requestStartTime = currTime;
    }

    request getRequest()
    {
        return r;
    }

    char getServerName()
    {
        return serverName;
    }

    bool isRequestComplete(int currTime)
    {
        return (currTime >= (requestStartTime + r.processTime));
    }
};
