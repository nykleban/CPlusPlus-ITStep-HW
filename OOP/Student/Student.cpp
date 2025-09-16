#include <iostream>
#include <string> // Add this header to fix the "to_string" undefined error
using namespace std;

class Student {
private:
   struct PIB {
       string name;
       string surname;
       string pobatkovi;
   } pib;

   struct Birthday {
       int day;
       int month;
       int year;
   } birthday;

   string telephone;

   struct LiveAddress {
       string country;
       string city;
   } liveAddress;

   struct StudyAddress {
       string name;
       string country;
       string city;
       int group;
   } studyAddress;

public:
   void inputStudent() {
       cout << "Enter name: ";
       cin >> pib.name;
       cout << "Enter surname: ";
       cin >> pib.surname;
       cout << "Enter pobatkovi: ";
       cin >> pib.pobatkovi;
       cout << "Enter birthday (day month year): ";
       cin >> birthday.day >> birthday.month >> birthday.year;
       cout << "Enter telephone: ";
       cin >> telephone;
       cout << "Enter live country: ";
       cin >> liveAddress.country;
       cout << "Enter live city: ";
       cin >> liveAddress.city;
       cout << "Enter study name: ";
       cin >> studyAddress.name;
       cout << "Enter study country: ";
       cin >> studyAddress.country;
       cout << "Enter study city: ";
       cin >> studyAddress.city;
       cout << "Enter study group: ";
       cin >> studyAddress.group;
   }
   
   void printStudent() {
       cout << "\nStudent Information:\n";
       cout << "Name: " << pib.name << " " << pib.surname << " " << pib.pobatkovi << "\n";
       cout << "Birthday: " << birthday.day << "/" << birthday.month << "/" << birthday.year << "\n";
       cout << "Telephone: " << telephone << "\n";
       cout << "Live Address: " << liveAddress.city << ", " << liveAddress.country << "\n";
       cout << "Study Address: " << studyAddress.name << ", " << studyAddress.city << ", "
           << studyAddress.country << ", Group " << studyAddress.group << "\n";
   }
   string getPIB() {
       return pib.name + " " + pib.surname + " " + pib.pobatkovi;
   }
   string getBirthday() {
       return to_string(birthday.day) + "/" + to_string(birthday.month) + "/" + to_string(birthday.year);
   }
   string getTelephone() {
       return telephone;
   }
   string getLiveAddress() {
       return liveAddress.city + ", " + liveAddress.country;
   }
   string getStudyAddress() {
       return studyAddress.name + ", " + studyAddress.city + ", " +
           studyAddress.country + ", Group " + to_string(studyAddress.group);
   }
};

int main() {
   Student student;
   student.inputStudent();
   student.printStudent();
   cout << "\n\nPIB: " << student.getPIB() << "\n";
   cout << "Birthday: " << student.getBirthday() << "\n";
   cout << "Telephone: " << student.getTelephone() << "\n";
   cout << "Live Address: " << student.getLiveAddress() << "\n";
   cout << "Study Address: " << student.getStudyAddress() << "\n";
}
