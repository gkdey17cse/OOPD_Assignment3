#include <iostream>
#include <ctime>
#include <string>
#include <limits> // For input stream validation
#include "Station.h"
#include "Line.h"
#include "Platform.h"

using namespace std;

// Helper function to display train types as strings
string getTrainTypeName(TrainType type) {
    return (type == STOPPAGE) ? "Stoppage" : "Through";
}

// Function to display all station details
template <typename T>
void displayStationDetails(const Station<T>& station, const string& stationName) {
    cout << stationName << " has the following lines: ";
    station.showLines();
}

// Function to validate integer input
int getValidatedIntInput(const string& prompt, int minVal, int maxVal) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail() || input < minVal || input > maxVal) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between " << minVal << " and " << maxVal << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any extra input
            return input;
        }
    }
}

// Function to add a new line to a station
template <typename T>
void addNewLineToStation(Station<T>& station, const string& stationName) {
    cout << "Enter the name of the new line to add to " << stationName << ": ";
    string lineName;
    getline(cin, lineName);

    try {
        if (lineName.empty()) {
            throw invalid_argument("Line name cannot be empty.");
        }
        station.addLine(Line(lineName));
        cout << "Successfully added line: " << lineName << " to " << stationName << ".\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Function to schedule a train at a station
template <typename T>
void scheduleTrainAtStation(Station<T>& station, const string& stationName) {
    int trainTypeChoice = getValidatedIntInput("Enter train type (1 for Stoppage, 2 for Through): ", 1, 2);
    TrainType trainType = (trainTypeChoice == 1) ? STOPPAGE : THROUGH;

    int minutesFromNow = getValidatedIntInput("Enter minutes from now to schedule the train: ", 0, 1440); // 0 to 24 hours

    time_t currentTime = time(nullptr);
    time_t scheduledTime = currentTime + minutesFromNow * 60;

    try {
        if (station.scheduleTrain(scheduledTime, trainType)) {
            cout << "Train successfully scheduled at " << stationName << " as a "
                 << getTrainTypeName(trainType) << " train.\n";
        } else {
            cout << "Failed to schedule train at " << stationName << ".\n";
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    // Create and initialize stations
    Station<int> station1(101);
    station1.addLine(Line("Red Line"));
    station1.addLine(Line("Blue Line"));

    Station<string> station2("HWH");
    station2.addLine(Line("Green Line"));
    station2.addLine(Line("Purple Line"));

    // Display initial station details
    cout << "Initial station details:\n";
    displayStationDetails(station1, "Station 1 (ID: 101)");
    displayStationDetails(station2, "Station 2 (ID: HWH)");

    // Interactive menu for operations
    bool exitProgram = false;

    while (!exitProgram) {
        int choice = getValidatedIntInput("\nSelect an option:\n"
                                          "1. Add a new line to a station\n"
                                          "2. Schedule a train at a station\n"
                                          "3. Display station details\n"
                                          "4. Exit\n"
                                          "Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: {
                int stationChoice = getValidatedIntInput("Select station (1 for Station 1, 2 for Station 2): ", 1, 2);
                if (stationChoice == 1) {
                    addNewLineToStation(station1, "Station 1 (ID: 101)");
                } else if (stationChoice == 2) {
                    addNewLineToStation(station2, "Station 2 (ID: HWH)");
                }
                break;
            }
            case 2: {
                int stationChoice = getValidatedIntInput("Select station (1 for Station 1, 2 for Station 2): ", 1, 2);
                if (stationChoice == 1) {
                    scheduleTrainAtStation(station1, "Station 1 (ID: 101)");
                } else if (stationChoice == 2) {
                    scheduleTrainAtStation(station2, "Station 2 (ID: HWH)");
                }
                break;
            }
            case 3:
                displayStationDetails(station1, "Station 1 (ID: 101)");
                displayStationDetails(station2, "Station 2 (ID: HWH)");
                break;
            case 4:
                exitProgram = true;
                cout << "Exiting the program. Goodbye!\n";
                break;
        }
    }

    return 0;
}
