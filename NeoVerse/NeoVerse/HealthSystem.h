#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include "CityComponent.h"

class HealthSystem : public CityComponent
{
public:
    HealthSystem();

    void processEvent(string eventType, int severity) override;
};

#endif