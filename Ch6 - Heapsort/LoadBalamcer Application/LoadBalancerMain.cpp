#include "request.cpp"
#include "webServer.cpp"
#include "LoadBalancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

const int NUMWEBSERVERS = 5;

request createRandomRequest()
{
    stringstream ips, ipd;
    request r;
    ips << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
    ipd << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);

    r.source = ips.str();
    r.destination = ipd.str();
    r.processTime = rand() % 500;

    return r;
}

int main()
{
    srand(time(0));
    LoadBalancer lb;
    for (int i = 0; i < 10; i++)
    {
        lb.AddRequest(createRandomRequest());
    }

    webServer webServersArray[NUMWEBSERVERS];

    for (int i = 0; i < NUMWEBSERVERS; i++)
    {
        webServersArray[i] = webServer('A' + i);
        webServersArray[i].AddRequest(lb.getRequest(), lb.getTime());
    }

    while (lb.getTime() < 10000)
    {
        int currTime = lb.getTime();
        if (webServersArray[currTime % NUMWEBSERVERS].isRequestComplete(currTime))
        {
            request r = webServersArray[currTime % NUMWEBSERVERS].getRequest();
            cout << "At" << currTime << " " << webServersArray[currTime % NUMWEBSERVERS].getServerName() << ": " << r.source << " Processed Request From " << r.source << "TO" << r.destination << endl;
            webServersArray[currTime % NUMWEBSERVERS].AddRequest(lb.getRequest(), currTime);
        }

        if (rand() % 10 == 0)
        {
            lb.AddRequest(createRandomRequest());
        }

        lb.IncrementTime();
    }
}