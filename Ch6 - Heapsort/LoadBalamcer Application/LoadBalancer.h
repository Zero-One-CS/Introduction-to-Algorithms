#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include "PriortyQueue.h"

class LoadBalancer
{
private:
    PriortyQueue<request> requestQueue;
    int systemTime;

public:
    LoadBalancer()
    {
        systemTime = 0;
    };

    int getTime();
    void IncrementTime();
    void AddRequest(request req);
    request getRequest();
    bool isRequestQueueEmpty();
};

// #include "LoadBalancer.cpp"