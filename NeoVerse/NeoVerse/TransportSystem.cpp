#include "TransportSystem.h"
#include <iostream>

TransportSystem::TransportSystem()
    : CityComponent("Transport System")
{
}

void TransportSystem::processEvent(string eventType, int severity)
{
    cout << "Transport System processing event: "
        << eventType
        << " | Severity: "
        << severity
        << endl;
}