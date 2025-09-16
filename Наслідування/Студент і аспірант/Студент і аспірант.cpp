#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
    int course;
    string faculty;

public:
    Student() : name(""), age(0), course(0), faculty("") {}
    Student(string name, int age, int course, string faculty)
        : name(name), age(age), course(course), faculty(faculty) {
    }

    void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
        cout << "Faculty: " << faculty << endl;
    }
};

class Aspirant : public Student
{
private:
    string candidate_thesis;

public:
    Aspirant() : Student(), candidate_thesis("no thesis") {}

    Aspirant(string name, int age, int course, string faculty, string candidate_thesis)
        : Student(name, age, course, faculty), candidate_thesis(candidate_thesis) {
    }

    void Print() const
    {
        cout << "-------- Aspirant --------" << endl;
        Student::Print();
        cout << "Candidate thesis: " << candidate_thesis << endl;
    }
};

int main()
{
    Student student("John Doe", 20, 2, "Computer Science");
    student.Print();
    cout << endl;

    Aspirant aspirant("Jane Smith", 25, 4, "Mathematics", "Quantum Computing");
    Aspirant aspirant2;
    aspirant.Print();
    aspirant2.Print();

}
