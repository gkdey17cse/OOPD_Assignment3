#include "Platform.h"

// Constructor
Platform::Platform() : lastTrainTime(0), lastTrainType(STOPPAGE) {}

// Helper function to check if scheduling is allowed
bool Platform::isScheduleAllowed(time_t newTrainTime, TrainType type) {
    if (lastTrainTime == 0) {
        return true; // No prior train scheduled
    }

    double diffMinutes = difftime(newTrainTime, lastTrainTime) / 60.0;

    if (lastTrainType == STOPPAGE) {
        if (diffMinutes < 30.0) {
            throw std::runtime_error("Error: Stoppage requires at least a 30-minute gap.");
        }
    } else if (lastTrainType == THROUGH) {
        if (diffMinutes < 10.0) {
            throw std::runtime_error("Error: Through train requires at least a 10-minute gap.");
        }
    }

    return true;
}

// Schedule a train
bool Platform::scheduleTrain(time_t trainTime, TrainType type) {
    try {
        if (isScheduleAllowed(trainTime, type)) {
            lastTrainTime = trainTime;
            lastTrainType = type;
            std::cout << "Train scheduled successfully at " << ctime(&trainTime);
            return true;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return false;
}
