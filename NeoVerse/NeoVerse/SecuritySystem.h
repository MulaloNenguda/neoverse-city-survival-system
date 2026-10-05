#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "CityComponent.h"

class SecuritySystem : public CityComponent
{
public:
    SecuritySystem();

    void processEvent(string eventType, int severity) override;
};

#endif