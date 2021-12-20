#ifndef LOADBALANCER_H
#include "LoadBalancer.h"
#endif

int LoadBalancer ::getTime()
{
    return systemTime;
}

void LoadBalancer ::IncrementTime()
{
    systemTime++;
}

void LoadBalancer ::AddRequest(request req)
{
    requestQueue.enqueue(req);
    IncrementTime();
}

request LoadBalancer ::getRequest()
{
    IncrementTime();
    request r;
    if (!isRequestQueueEmpty())
    {
        r = requestQueue.dequeue();
    }
    return r;
}

bool LoadBalancer ::isRequestQueueEmpty()
{
    return requestQueue.isEmpty();
}