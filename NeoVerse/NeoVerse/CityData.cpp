#include "CityData.h"
#include <iostream>

void CityData::addSensorReading(double reading)
{
    dailySensorReadings.push_back(reading);
}

void CityData::removeSensorReading(int position)
{
    if (position >= 0 && position < dailySensorReadings.size())
    {
        dailySensorReadings.erase(dailySensorReadings.begin() + position);
    }
}

void CityData::displaySensorReadings()
{
    cout << "\nDaily Sensor Readings:\n";

    for (int i = 0; i < dailySensorReadings.size(); i++)
    {
        cout << "Reading " << i + 1 << ": "
            << dailySensorReadings[i] << endl;
    }
}

void CityData::addCityLog(string log)
{
    historicalCityLogs.push_back(log);
}

void CityData::removeOldestCityLog()
{
    if (!historicalCityLogs.empty())
    {
        historicalCityLogs.pop_front();
    }
}

void CityData::displayCityLogs()
{
    cout << "\nHistorical City Logs:\n";

    for (list<string>::iterator it = historicalCityLogs.begin();
        it != historicalCityLogs.end();
        ++it)
    {
        cout << *it << endl;
    }
}

vector<double> CityData::getSensorReadings()
{
    return dailySensorReadings;
}

list<string> CityData::getCityLogs()
{
    return historicalCityLogs;
}