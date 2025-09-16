#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "I\n\tlove\n\t\tyou\n\t\t\tC++!\n\n";
    cout << "\t…:::RESUME:::…\n\n";
    cout << "Name:\t\t\tNazar\n";
    cout << "Surname:\t\tKleban\n";
    cout << "Last name:\t\tYuriyovych\n\n";
    cout << "Date of birth:\t\t03.07.2007\n";
    cout << "City:\t\t\tOstroh\n";
    cout << "Age:\t\t\t17\n\n";
    cout << "Hobby:\t\t\tC++\n";
    cout << "::……………………...................……::\n\n";
    cout << "\x1b[31mEvery " << "\x1b[33mhunter " << "\x1b[32mwants " << "\x1b[36mto " << "\x1b[34mknow " << "\x1b[35mwhere " << "\x1b[37mthe " << "\x1b[91mpheasant " << "\x1b[95mis." << "\x1b[0m" << endl;
    cout << endl;
    cout << "Tel.: 222-22-22" << endl;
    cout << setw(5) << "222" << "|" << setw(5) << "222" << "|" << endl;
    cout << setw(5) << " 22" << "|" << setw(5) << " 22" << "|" << endl;
    cout << setw(5) << " 22" << "|" << setw(5) << " 22" << "|" << endl;
    cout << "i t.d." << endl;
    return 0;
}
