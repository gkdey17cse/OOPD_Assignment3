#ifndef PLATFORM_H
#define PLATFORM_H

#include <ctime>
#include <iostream>
#include <stdexcept>

enum TrainType {
    STOPPAGE,
    THROUGH
};

class Platform {
private:
    time_t lastTrainTime;
    TrainType lastTrainType;

    // Helper function to check if scheduling is allowed
    bool isScheduleAllowed(time_t newTrainTime, TrainType type);

public:
    // Constructor
    Platform();

    // Schedule a train
    bool scheduleTrain(time_t trainTime, TrainType type);
};

#endif // PLATFORM_H
