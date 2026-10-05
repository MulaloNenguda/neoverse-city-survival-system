#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class Event
{
private:
    string eventType;
    int severity;

public:
    Event(string type, int level)
    {
        eventType = type;
        severity = level;
    }

    string getEventType()
    {
        return eventType;
    }

    int getSeverity()
    {
        return severity;
    }
};

class EmergencyEvent
{
private:
    string emergencyType;
    int severity;

public:
    EmergencyEvent(string type, int level)
    {
        emergencyType = type;
        severity = level;
    }

    string getEmergencyType()
    {
        return emergencyType;
    }

    int getSeverity()
    {
        return severity;
    }
};

#endif