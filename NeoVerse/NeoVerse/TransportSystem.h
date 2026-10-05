#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include "CityComponent.h"

class TransportSystem : public CityComponent
{
public:
    TransportSystem();

    void processEvent(string eventType, int severity) override;
};

#endif