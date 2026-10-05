#include "HealthSystem.h"
#include <iostream>

HealthSystem::HealthSystem()
    : CityComponent("Health System")
{
}

void HealthSystem::processEvent(string eventType, int severity)
{
    cout << "Health System processing event: "
        << eventType
        << " | Severity: "
        << severity
        << endl;
}