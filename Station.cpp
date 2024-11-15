#ifndef STATION_CPP
#define STATION_CPP

#include "Station.h"

// Constructor
template <class T>
Station<T>::Station(T id) : stationID(id) {}

// Add a line to the station
template <class T>
void Station<T>::addLine(const Line& line) {
    lines.push_back(line);
}

// Display all lines associated with the station
template <class T>
void Station<T>::showLines() const {
    std::cout << "Station " << stationID << " has lines: ";
    for (const auto& line : lines) {
        std::cout << line.getLineName() << " ";
    }
    std::cout << std::endl;
}

// Schedule a train at the station
template <class T>
bool Station<T>::scheduleTrain(time_t trainTime, TrainType type) {
    try {
        return platform.scheduleTrain(trainTime, type);
    } catch (const std::exception& e) {
        std::cerr << "Error scheduling train: " << e.what() << std::endl;
        return false;
    }
}

#endif // STATION_CPP
