#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct carNumber {
    int intNumber;
    char textNumber[9];
    bool isNumber;
};

struct Car {
    string color;
    string model;
    carNumber number;
};

void enterNumber(Car& car) {
    cout << "Enter number type (1 — number, 2 — text): ";
    int type;
    cin >> type;

    if (type == 1) {
        car.number.isNumber = true;
        while (true) {
            cout << "Enter 5-digit number: ";
            cin >> car.number.intNumber;
            if (car.number.intNumber >= 10000 && car.number.intNumber < 100000)
                break;
            else
                cout << "Invalid number. Try again.\n";
        }
    }
    else {
        car.number.isNumber = false;
        cout << "Enter word (max 8 characters): ";
        cin >> car.number.textNumber;
    }
}

void inputCar(Car& car) {
    cout << "Enter car color: ";
    cin >> car.color;

    cout << "Enter car model: ";
    cin >> car.model;

    enterNumber(car);
}

void printCar(Car a, int i) {
    cout << "\n\t=== Car [" << i + 1 << "] ===\n";
    cout << "Color: " << a.color << endl;
    cout << "Model: " << a.model << endl;
    cout << "Number: ";
    if (a.number.isNumber)
        cout << a.number.intNumber;
    else
        cout << a.number.textNumber;
    cout << endl;
}

void editCar(Car& car, int i) {
    printCar(car, i);
    cout << "What to edit? (1 - color, 2 - model, 3 - number): ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "New color: ";
        cin >> car.color;
        break;
    case 2:
        cout << "New model: ";
        cin >> car.model;
        break;
    case 3:
        enterNumber(car);
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }
    int choiceToEdit;
    cout << "Do you want to edit another one? (1 - yes, 2 - no) : ";
    cin >> choiceToEdit;
    if (choiceToEdit == 1)  editCar(car, i);    else cout << "Editing finished." << endl;
}

void searchByNumber(Car cars[], int size) {
    cout << "Enter number to search (digits or word): ";
    string input;
    cin >> input;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if(cars[i].number.isNumber) {
            if (to_string(cars[i].number.intNumber) == input) {
                printCar(cars[i], i);
                found = true;
                }
        }
        else {
            if (input == string(cars[i].number.textNumber)) {
                printCar(cars[i], i);
                found = true;
                }
            }

    }

    if (!found) {
        cout << "Car not found.\n";
    }
}

int main() {
    const int carCount = 15;
    Car cars[carCount] = {
        {"Red", "Toyota", {12345, "", true}},
        {"Blue", "Honda", {0, "FASTCAR", false}},
        {"Black", "BMW", {54321, "", true}},
        {"White", "Mercedes", {0, "LUXURY", false}},
        {"Green", "Ford", {67890, "", true}},
        {"Silver", "Chevrolet", {0, "SPEEDY", false}},
        {"Yellow", "Nissan", {11223, "", true}},
        {"Gray", "Kia", {0, "FAMILY", false}},
        {"Orange", "Hyundai", {99887, "", true}},
        {"Brown", "Mazda", {0, "ROADRUN", false}}
    };

    int currentSize = 10;

    while (true) {
        cout << "\nWhat do you want to do?\n";
        cout << "1 - Print all cars\n2 - Add new car\n3 - Edit car\n4 - Find by number\n0 - Exit\n";
        int action;
        cin >> action;

        if (action == 0) break;

        switch (action) {
        case 1:
            for (int i = 0; i < currentSize; i++)
                printCar(cars[i], i);
            break;

        case 2:
            if (currentSize < carCount) {
                inputCar(cars[currentSize]);
                currentSize++;
            }
            else {
                cout << "Car array is full.\n";
            }
            break;

        case 3:
            int carNumber;
            cout << "Enter car index to edit (1-" << currentSize << "): ";
            cin >> carNumber;
            if (carNumber >= 1 && carNumber <= currentSize) {
                editCar(cars[carNumber - 1], carNumber - 1);
            }
            else {
                cout << "Invalid index.\n";
            }
            break;

        case 4:
            searchByNumber(cars, currentSize);
            break;
        default:
			cout << "Invalid action.\n";
            break;
        }
    }

    return 0;
}
