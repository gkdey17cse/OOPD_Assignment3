#include <iostream>
#include <ctime>
#include "Station.h"
#include "Line.h"
#include "Platform.h"

using namespace std;

int main()
{
    // Creating two stations: one with an integer ID and another with a string ID
    Station<int> station1(101);
    station1.addLine(Line("Red Line"));
    station1.addLine(Line("Blue Line"));

    Station<string> station2("NDLS");
    station2.addLine(Line("Green Line"));

    // Displaying the lines for each station
    cout << "Available lines at the stations:" << endl;
    station1.showLines();
    station2.showLines();

    time_t currentTime = time(0);

    while (true)
    {
        int stationChoice;
        cout << "\nChoose station (1 for station 101, 2 for station NDLS): ";
        cin >> stationChoice;

        while (stationChoice != 1 && stationChoice != 2)
        {
            cout << "Invalid input. Choose station (1 for station 101, 2 for station NDLS): ";
            cin >> stationChoice;
        }

        // Selecting the appropriate station based on the user's choice
        Station<int> *selectedStationInt = (stationChoice == 1) ? &station1 : nullptr;
        Station<string> *selectedStationStr = (stationChoice == 2) ? &station2 : nullptr;

        int trainTypeChoice;
        cout << "Enter train type (1 for Stoppage, 2 for Through): ";
        cin >> trainTypeChoice;

        while (trainTypeChoice != 1 && trainTypeChoice != 2)
        {
            cout << "Invalid input. Enter train type (1 for Stoppage, 2 for Through): ";
            cin >> trainTypeChoice;
        }

        TrainType type = (trainTypeChoice == 1) ? STOPPAGE : THROUGH;

        int minutesFromNow;
        cout << "Enter minutes from now to schedule the train: ";
        cin >> minutesFromNow;

        time_t scheduledTime = currentTime + minutesFromNow * 60;

        // Scheduling the train
        try
        {
            if (selectedStationInt)
            {
                if (selectedStationInt->scheduleTrain(scheduledTime, type))
                {
                    cout << "Train scheduled successfully at Station 101.\n";
                }
            }
            else if (selectedStationStr)
            {
                if (selectedStationStr->scheduleTrain(scheduledTime, type))
                {
                    cout << "Train scheduled successfully at Station NDLS.\n";
                }
            }
            else
            {
                throw runtime_error("Invalid station choice.");
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }

        // Asking if the user wants to continue
        char continueChoice;
        cout << "Do you want to schedule another train? (y/n): ";
        cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y')
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
