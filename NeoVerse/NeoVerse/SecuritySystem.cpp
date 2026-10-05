#include "SecuritySystem.h"
#include <iostream>

SecuritySystem::SecuritySystem()
    : CityComponent("Security System")
{
}

void SecuritySystem::processEvent(string eventType, int severity)
{
    cout << "Security System processing event: "
        << eventType
        << " | Severity: "
        << severity
        << endl;
}