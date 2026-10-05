#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

#include "Engineer.h"
#include "CityData.h"
#include "Event.h"
#include "PowerSystem.h"
#include "TransportSystem.h"
#include "HealthSystem.h"
#include "SecuritySystem.h"

using namespace std;

// Engineer File Handling

void saveEngineers(vector<Engineer>& engineers)
{
    ofstream file("engineers.dat");

    if (file.is_open())
    {
        for (vector<Engineer>::iterator it = engineers.begin();
            it != engineers.end();
            ++it)
        {
            file << it->getEngineerID() << "|"
                << it->getUsername() << "|"
                << it->getEncryptedPassword() << "|"
                << it->getClearanceLevel() << endl;
        }

        file.close();
    }
}

void loadEngineers(vector<Engineer>& engineers)
{
    ifstream file("engineers.dat");

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            string id;
            string username;
            string encryptedPassword;
            string clearance;

            stringstream data(line);

            getline(data, id, '|');
            getline(data, username, '|');
            getline(data, encryptedPassword, '|');
            getline(data, clearance, '|');

            if (!id.empty())
            {
                engineers.push_back(
                    Engineer(id, username, encryptedPassword,
                        clearance, true)
                );
            }
        }

        file.close();
    }
}

// Event File Handling

void saveEvents(vector<Event>& events)
{
    ofstream file("events.dat");

    if (file.is_open())
    {
        for (vector<Event>::iterator it = events.begin();
            it != events.end();
            ++it)
        {
            file << it->getEventType() << "|"
                << it->getSeverity() << endl;
        }

        file.close();
    }
}

void loadEvents(vector<Event>& events)
{
    ifstream file("events.dat");

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            string eventType;
            string severityText;

            stringstream data(line);

            getline(data, eventType, '|');
            getline(data, severityText, '|');

            if (!eventType.empty() && !severityText.empty())
            {
                int severity = stoi(severityText);

                events.push_back(
                    Event(eventType, severity)
                );
            }
        }

        file.close();
    }
}

// City Data File Handling

void saveCityData(CityData& cityData)
{
    ofstream file("city_logs.dat");

    if (file.is_open())
    {
        vector<double> readings = cityData.getSensorReadings();

        for (vector<double>::iterator it = readings.begin();
            it != readings.end();
            ++it)
        {
            file << "SENSOR|" << *it << endl;
        }

        list<string> logs = cityData.getCityLogs();

        for (list<string>::iterator it = logs.begin();
            it != logs.end();
            ++it)
        {
            file << "LOG|" << *it << endl;
        }

        file.close();
    }
}

void loadCityData(CityData& cityData)
{
    ifstream file("city_logs.dat");

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            string dataType;
            string value;

            stringstream data(line);

            getline(data, dataType, '|');
            getline(data, value);

            if (dataType == "SENSOR")
            {
                if (!value.empty())
                {
                    double reading = stod(value);
                    cityData.addSensorReading(reading);
                }
            }
            else if (dataType == "LOG")
            {
                if (!value.empty())
                {
                    cityData.addCityLog(value);
                }
            }
        }

        file.close();
    }
}

// Log Export

void exportLogs(CityData& cityData)
{
    ofstream file("city_logs.txt");

    if (file.is_open())
    {
        vector<double> readings = cityData.getSensorReadings();

        file << "NEOVERSE CITY LOG EXPORT" << endl;
        file << "=========================" << endl;

        file << "\nSensor Readings:" << endl;

        for (vector<double>::iterator it = readings.begin();
            it != readings.end();
            ++it)
        {
            file << *it << endl;
        }

        file << "\nHistorical City Logs:" << endl;

        list<string> logs = cityData.getCityLogs();

        for (list<string>::iterator it = logs.begin();
            it != logs.end();
            ++it)
        {
            file << *it << endl;
        }

        file.close();
    }
}

// Configuration File

void saveConfig(string cityName)
{
    ofstream file("config.txt");

    if (file.is_open())
    {
        file << "CityName=" << cityName << endl;

        file.close();
    }
}

string loadConfig()
{
    ifstream file("config.txt");

    string cityName = "NeoVerse";

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            if (line.find("CityName=") == 0)
            {
                cityName = line.substr(9);
            }
        }

        file.close();
    }

    return cityName;
}

int main()
{
    // Engineer login

    vector<Engineer> engineers;

    loadEngineers(engineers);

    // Required engineer accounts

    Engineer requiredEngineer1(
        "ENG001",
        "engineer1",
        "password123",
        "High"
    );

    Engineer requiredEngineer2(
        "ENG002",
        "engineer2",
        "city456",
        "Medium"
    );

    // Check whether Engineer 1 exists

    bool engineer1Exists = false;

    for (vector<Engineer>::iterator it = engineers.begin();
        it != engineers.end();
        ++it)
    {
        if (it->getEngineerID() == "ENG001")
        {
            engineer1Exists = true;

            if (it->getUsername() != "engineer1" ||
                it->getEncryptedPassword() !=
                requiredEngineer1.getEncryptedPassword() ||
                it->getClearanceLevel() != "High")
            {
                *it = requiredEngineer1;
            }

            break;
        }
    }

    // Add Engineer 1 if missing

    if (!engineer1Exists)
    {
        engineers.push_back(requiredEngineer1);
    }

    // Check whether Engineer 2 exists

    bool engineer2Exists = false;

    for (vector<Engineer>::iterator it = engineers.begin();
        it != engineers.end();
        ++it)
    {
        if (it->getEngineerID() == "ENG002")
        {
            engineer2Exists = true;

            if (it->getUsername() != "engineer2" ||
                it->getEncryptedPassword() !=
                requiredEngineer2.getEncryptedPassword() ||
                it->getClearanceLevel() != "Medium")
            {
                *it = requiredEngineer2;
            }

            break;
        }
    }

    // Add Engineer 2 if missing

    if (!engineer2Exists)
    {
        engineers.push_back(requiredEngineer2);
    }

    // Save the engineer records

    saveEngineers(engineers);

    string username;
    string password;

    cout << "========================================" << endl;
    cout << "       NEOVERSE CITY SURVIVAL SYSTEM" << endl;
    cout << "========================================" << endl;

    cout << "\nEngineer Login" << endl;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    // Search for the engineer using the STL algorithm

    vector<Engineer>::iterator engineerIt =
        find_if(
            engineers.begin(),
            engineers.end(),
            [username, password](Engineer& engineer)
            {
                return engineer.getUsername() == username &&
                    engineer.checkPassword(password);
            }
        );

    if (engineerIt == engineers.end())
    {
        cout << "\nLogin failed. Access denied." << endl;
        return 0;
    }

    cout << "\nLogin successful." << endl;

    cout << "Engineer ID: "
        << engineerIt->getEngineerID() << endl;

    cout << "Clearance Level: "
        << engineerIt->getClearanceLevel() << endl;

    // City Data

    CityData cityData;

    loadCityData(cityData);

    if (cityData.getSensorReadings().empty())
    {
        cityData.addSensorReading(72.5);
        cityData.addSensorReading(81.3);
        cityData.addSensorReading(65.7);
        cityData.addSensorReading(91.8);
        cityData.addSensorReading(77.4);
    }

    if (cityData.getCityLogs().empty())
    {
        cityData.addCityLog("Power consumption increased.");
        cityData.addCityLog("Traffic density is normal.");
        cityData.addCityLog("Health system operating normally.");
        cityData.addCityLog("Security alert received.");
    }

    cout << "\n========================================" << endl;
    cout << "           CITY DATA MANAGEMENT" << endl;
    cout << "========================================" << endl;

    cityData.displaySensorReadings();
    cityData.displayCityLogs();

    // Insertion and removal of outdated data

    cout << "\nTesting city data operations..." << endl;

    cityData.addSensorReading(50.0);

    cout << "New sensor reading added." << endl;

    cityData.removeSensorReading(
        cityData.getSensorReadings().size() - 1
    );

    cout << "Outdated sensor reading removed." << endl;

    cityData.addCityLog("Temporary historical log added.");

    cout << "New city log added." << endl;

    cityData.removeOldestCityLog();

    cout << "Oldest city log removed." << endl;

    // Event Queue and Emergency Stack

    vector<Event> savedEvents;

    loadEvents(savedEvents);

    if (savedEvents.empty())
    {
        savedEvents.push_back(Event("Power Failure", 3));
        savedEvents.push_back(Event("Traffic Accident", 2));
        savedEvents.push_back(Event("Medical Emergency", 3));
        savedEvents.push_back(Event("Security Breach", 4));
        savedEvents.push_back(Event("Power Failure", 3));
    }

    // Critical events

    int criticalEvents =
        count_if(
            savedEvents.begin(),
            savedEvents.end(),
            [](Event event)
            {
                return event.getSeverity() >= 4;
            }
        );

    cout << "\n========================================" << endl;
    cout << "          EVENT PRIORITISATION" << endl;
    cout << "========================================" << endl;

    cout << "Critical events requiring priority attention: "
        << criticalEvents << endl;

    // Queue

    queue<Event> eventQueue;

    for (vector<Event>::iterator it = savedEvents.begin();
        it != savedEvents.end();
        ++it)
    {
        eventQueue.push(*it);
    }

    cout << "\n========================================" << endl;
    cout << "              EVENT QUEUE" << endl;
    cout << "========================================" << endl;

    int totalEventsProcessed = 0;

    while (!eventQueue.empty())
    {
        Event currentEvent = eventQueue.front();

        cout << "Processing event: "
            << currentEvent.getEventType()
            << " | Severity: "
            << currentEvent.getSeverity()
            << endl;

        totalEventsProcessed++;

        eventQueue.pop();
    }

    // Stack

    stack<EmergencyEvent> emergencyStack;

    emergencyStack.push(
        EmergencyEvent("Power Failure", 3)
    );

    emergencyStack.push(
        EmergencyEvent("Medical Emergency", 4)
    );

    emergencyStack.push(
        EmergencyEvent("Security Breach", 5)
    );

    emergencyStack.push(
        EmergencyEvent("Power Failure", 4)
    );

    cout << "\n========================================" << endl;
    cout << "           EMERGENCY STACK" << endl;
    cout << "========================================" << endl;

    vector<string> emergencyTypes;

    while (!emergencyStack.empty())
    {
        EmergencyEvent emergency = emergencyStack.top();

        cout << "Handling emergency: "
            << emergency.getEmergencyType()
            << " | Severity: "
            << emergency.getSeverity()
            << endl;

        emergencyTypes.push_back(
            emergency.getEmergencyType()
        );

        emergencyStack.pop();
    }

    // Object-Oriented City Components

    cout << "\n========================================" << endl;
    cout << "         CITY COMPONENT SYSTEMS" << endl;
    cout << "========================================" << endl;

    PowerSystem powerSystem;
    TransportSystem transportSystem;
    HealthSystem healthSystem;
    SecuritySystem securitySystem;

    vector<CityComponent*> cityComponents;

    cityComponents.push_back(&powerSystem);
    cityComponents.push_back(&transportSystem);
    cityComponents.push_back(&healthSystem);
    cityComponents.push_back(&securitySystem);

    for (vector<CityComponent*>::iterator it = cityComponents.begin();
        it != cityComponents.end();
        ++it)
    {
        (*it)->processEvent("System Alert", 2);
    }

    // STL Algorithms

    cout << "\n========================================" << endl;
    cout << "             STL ALGORITHMS" << endl;
    cout << "========================================" << endl;

    vector<double> sensorData =
        cityData.getSensorReadings();

    // sort

    sort(sensorData.begin(), sensorData.end());

    cout << "\nSorted sensor data:" << endl;

    for (vector<double>::iterator it = sensorData.begin();
        it != sensorData.end();
        ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // find

    double searchValue = 81.3;

    vector<double>::iterator foundValue =
        find(
            sensorData.begin(),
            sensorData.end(),
            searchValue
        );

    if (foundValue != sensorData.end())
    {
        cout << "Sensor value "
            << searchValue
            << " was found." << endl;
    }
    else
    {
        cout << "Sensor value "
            << searchValue
            << " was not found." << endl;
    }

    // min

    vector<double>::iterator minimum =
        min_element(
            sensorData.begin(),
            sensorData.end()
        );

    // max

    vector<double>::iterator maximum =
        max_element(
            sensorData.begin(),
            sensorData.end()
        );

    cout << "Lowest sensor value: "
        << *minimum << endl;

    cout << "Highest sensor value: "
        << *maximum << endl;

    // count_if

    int criticalAlerts =
        count_if(
            sensorData.begin(),
            sensorData.end(),
            [](double value)
            {
                return value >= 90.0;
            }
        );

    cout << "Critical sensor alerts: "
        << criticalAlerts << endl;

    // System Reports and Analytics

    cout << "\n========================================" << endl;
    cout << "          SYSTEM REPORTS" << endl;
    cout << "========================================" << endl;

    cout << "\nTotal events processed: "
        << totalEventsProcessed << endl;

    // Most common emergency type

    string mostCommonEmergency = "";
    int highestEmergencyCount = 0;

    for (vector<string>::iterator outer =
        emergencyTypes.begin();
        outer != emergencyTypes.end();
        ++outer)
    {
        int currentCount =
            count(
                emergencyTypes.begin(),
                emergencyTypes.end(),
                *outer
            );

        if (currentCount > highestEmergencyCount)
        {
            highestEmergencyCount = currentCount;
            mostCommonEmergency = *outer;
        }
    }

    cout << "Most common emergency type: "
        << mostCommonEmergency << endl;

    // Average response time

    vector<double> responseTimes;

    responseTimes.push_back(8.0);
    responseTimes.push_back(12.0);
    responseTimes.push_back(6.0);
    responseTimes.push_back(10.0);
    responseTimes.push_back(9.0);

    double totalResponseTime = 0;

    for (vector<double>::iterator it =
        responseTimes.begin();
        it != responseTimes.end();
        ++it)
    {
        totalResponseTime += *it;
    }

    double averageResponseTime =
        totalResponseTime / responseTimes.size();

    cout << "Average response time: "
        << averageResponseTime
        << " minutes" << endl;

    // System load summary

    cout << "\nSystem Load Summary:" << endl;
    cout << "Power System: Normal" << endl;
    cout << "Transport System: Normal" << endl;
    cout << "Health System: Normal" << endl;
    cout << "Security System: Elevated" << endl;

    // File Handling and Persistence

    string cityName = loadConfig();

    cout << "\n========================================" << endl;
    cout << "          FILE PERSISTENCE" << endl;
    cout << "========================================" << endl;

    cout << "City: "
        << cityName << endl;

    saveEngineers(engineers);
    saveEvents(savedEvents);
    saveCityData(cityData);
    saveConfig(cityName);

    // Export logs to a separate text file

    exportLogs(cityData);

    cout << "\nSystem data has been saved." << endl;

    cout << "City logs have been exported to city_logs.txt."
        << endl;

    cout << "\nNeoVerse simulation completed successfully."
        << endl;

    return 0;
}