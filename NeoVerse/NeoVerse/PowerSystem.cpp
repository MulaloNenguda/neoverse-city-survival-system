#include "PowerSystem.h"
#include <iostream>

PowerSystem::PowerSystem()
    : CityComponent("Power System")
{
}

void PowerSystem::processEvent(string eventType, int severity)
{
    cout << "Power System processing event: "
        << eventType
        << " | Severity: "
        << severity
        << endl;
}