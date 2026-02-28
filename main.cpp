#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    int vehicleNo;
    string type;
    string cate_gory;
    Vehicle* next;

    Vehicle(int num, string t, string c) {
        vehicleNo = num;
        type = t;
        cate_gory = c;
        next = NULL;
    }
};
class TrafficSignal {
private:
    Vehicle* front;
    Vehicle* rear;
    int count;

public:
    TrafficSignal() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void vehicleArrives() {
        int number;
        string type;
        string cate_gory;

        cout << "Enter Vehicle Number: ";
        cin >> number;
        cin.ignore();

        cout << "Enter Vehicle Type (Car/Bike/Truck/Bus): ";
        getline(cin, type);

        cout << "Enter Vehicle Category (2-wheeler/4-wheeler/Heavy Vehicle): ";
        getline(cin, cate_gory);

        Vehicle* newVehicle = new Vehicle(number, type, cate_gory);

        if (front == NULL) {
            front = newVehicle;
            rear = newVehicle;
        }
        else {
            rear->next = newVehicle;
            rear = newVehicle;
        }

        count++;
        cout << "Vehicle added successfully.\n";
    }

    void greenSignal() {
        if (front == NULL) {
            cout << "No vehicles waiting.\n";
            return;
        }

        Vehicle* temp = front;

        cout << "Vehicle Passed: "
             << temp->vehicleNo << " ("
             << temp->type << ", "
             << temp->cate_gory << ")\n";

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        count--;
    }

    void displayVehicles() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        Vehicle* temp = front;

        cout << "\nVehicles in Queue:\n";
        while (temp != NULL) {
            cout << "Vehicle Number: " << temp->vehicleNo
                 << " | Type: " << temp->type
                 << " | Category: " << temp->cate_gory << endl;
            temp = temp->next;
        }

        cout << "Total Vehicles Waiting: " << count << endl;
    }

    ~TrafficSignal() {
        while (front != NULL) {
            Vehicle* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    TrafficSignal signal;
    int choice;

    do {
        cout << "\nTraffic Signal System\n";
        cout << "1. Vehicle Arrives\n";
        cout << "2. Green Signal\n";
        cout << "3. Display Vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                signal.vehicleArrives();
                break;
            case 2:
                signal.greenSignal();
                break;
            case 3:
                signal.displayVehicles();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}
