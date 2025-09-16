
#include <iostream>
#include <string>

using namespace std;

void countryCapital() {
    int country;
    cout << "Enter the number of the country (1-5): ";
    cin >> country;

    switch (country) {
        case 1:
            cout << "Ukraine: Kyiv" << endl;
            break;
        case 2:
            cout << "France: Paris" << endl;
            break;
        case 3:
            cout << "Germany: Berlin" << endl;
            break;
        case 4:
            cout << "Italy: Rome" << endl;
            break;
        case 5:
            cout << "Spain: Madrid" << endl;
            break;
        default:
            cout << "Invalid country number!" << endl;
    }
}

void dayOfWeek() {
    int day;
    cout << "Enter the day of the week (1-7): ";
    cin >> day;

    switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "It's a budniy day." << endl;
            break;
        case 6:
        case 7:
            cout << "It's a vyhidnyi day." << endl;
            break;
        default:
            cout << "Invalid day number!" << endl;
    }
}

void shipCourse() {
    enum Course { NORTH = 1, SOUTH, WEST, EAST };
    int course;
    cout << "Enter the current course of the ship (1 - north, 2 - south, 3 - west, 4 - east): ";
    cin >> course;

    switch (course) {
    case NORTH:
        cout << "New course: south" << endl;
        break;
    case SOUTH:
        cout << "New course: north" << endl;
        break;
    case WEST:
        cout << "New course: east" << endl;
        break;
    case EAST:
        cout << "New course: west" << endl;
        break;
    default:
        cout << "Invalid course!" << endl;
    }
}

void animalClass() {
    int animal;
    cout << "Enter the number of the animal (1-7): ";
    cin >> animal;

    switch (animal) {
        case 1:
            cout << "Giraffe: Herbivore" << endl;
            break;
        case 2:
            cout << "Eagle: Predator" << endl;
            break;
        case 3:
            cout << "Lion: Predator" << endl;
            break;
        case 4:
            cout << "Elephant: Herbivore" << endl;
            break;
        case 5:
            cout << "Wolf: Predator" << endl;
            break;
        case 6:
            cout << "Cow: Herbivore" << endl;
            break;
        case 7:
            cout << "Tiger: Predator" << endl;
            break;
        default:
            cout << "Invalid animal number!" << endl;
    }
    if (animal == 1 || animal == 4 || animal == 6) 
        cout << "Travoidna animal" << endl;
    else if (animal == 2 || animal == 3 || animal == 5 || animal == 7) 
        cout << "Predator animal" << endl;
}

int main() {
  countryCapital();
  dayOfWeek();
  shipCourse();
  animalClass();
  return 0;
}
