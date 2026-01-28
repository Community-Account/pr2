#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int tno, const char tname[], const char src[],
          const char dest[], const char time[]) {
        trainNumber = tno;
        strcpy(trainName, tname);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int tno) { trainNumber = tno; }
    void setTrainName(const char tname[]) { strcpy(trainName, tname); }
    void setSource(const char src[]) { strcpy(source, src); }
    void setDestination(const char dest[]) { strcpy(destination, dest); }
    void setTrainTime(const char time[]) { strcpy(trainTime, time); }

    int getTrainNumber() { return trainNumber; }
    const char* getTrainName() { return trainName; }
    const char* getSource() { return source; }
    const char* getDestination() { return destination; }
    const char* getTrainTime() { return trainTime; }

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
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTrain Time: " << trainTime << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

int main() {
    Train t1;
    t1.inputTrainDetails();
    t1.displayTrainDetails();

    Train t2(101, "Express", "Delhi", "Mumbai", "10:30");
    t2.displayTrainDetails();

    cout << "\nTotal Train Objects: "
         << Train::getTrainCount() << endl;

    return 0;
}
