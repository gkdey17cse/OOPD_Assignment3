#ifndef STATION_H
#define STATION_H

#include "Line.h"
#include "Platform.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <stdexcept>

template <class T>
class Station {
private:
    T stationID;
    std::vector<Line> lines;
    Platform platform;

public:
    // Constructor
    Station(T id);

    // Add a line to the station
    void addLine(const Line& line);

    // Display all lines associated with the station
    void showLines() const;

    // Schedule a train at the station
    bool scheduleTrain(time_t trainTime, TrainType type);
};

#include "Station.cpp" // Include the implementation for the template class

#endif // STATION_H
