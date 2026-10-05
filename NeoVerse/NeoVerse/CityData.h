#ifndef CITYDATA_H
#define CITYDATA_H

#include <vector>
#include <list>
#include <string>

using namespace std;

class CityData
{
private:
    vector<double> dailySensorReadings;
    list<string> historicalCityLogs;

public:
    void addSensorReading(double reading);
    void removeSensorReading(int position);
    void displaySensorReadings();

    void addCityLog(string log);
    void removeOldestCityLog();
    void displayCityLogs();

    vector<double> getSensorReadings();
    list<string> getCityLogs();
};

#endif