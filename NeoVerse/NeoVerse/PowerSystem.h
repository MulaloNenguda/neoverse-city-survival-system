#ifndef POWERSYSTEM_H
#define POWERSYSTEM_H

#include "CityComponent.h"

class PowerSystem : public CityComponent
{
public:
    PowerSystem();

    void processEvent(string eventType, int severity) override;
};

#endif