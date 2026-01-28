#include <iostream>
#include <cstring>
using namespace std;

/* ---------------- Train Class ---------------- */
class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber() {
        return trainNumber;
    }
};

/* ---------------- RailwaySystem Class ---------------- */
class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains() {
        for (int i = 0; i < totalTrains; i++) {
            cout << "\nTrain " << i + 1 << " details:" << endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain details:" << endl;
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "\nTrain with number " << number << " not found!" << endl;
    }
};

/* ---------------- Main Function ---------------- */
int main() {
    RailwaySystem rs;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3: {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            rs.searchTrainByNumber(num);
            break;
        }

        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
