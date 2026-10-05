#ifndef CITYCOMPONENT_H
#define CITYCOMPONENT_H

#include <string>

using namespace std;

class CityComponent
{
protected:
    string componentName;

public:
    CityComponent(string name);

    string getComponentName();

    virtual void processEvent(string eventType, int severity) = 0;

    virtual ~CityComponent();
};

#endif