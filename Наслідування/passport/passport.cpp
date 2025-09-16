using namespace std;
#include <iostream>
#include <string>

class Passport
{
private:
	string name;
	string surname;
	int age;
	
public:
	Passport() : name(""), surname(""), age(0) {}
	Passport(string name, string surname, int age)
		: name(name), surname(surname), age(age) {
	}
	void Print() const
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
	}
};
class ForeignPassport : public Passport
{
private:
	string passport_number;
	string* visas;
	int visa_count;
public:
	ForeignPassport() : Passport(), passport_number(""), visas(nullptr), visa_count(0) {}
	ForeignPassport(string name, string surname, int age, string passport_number, string* visas, int visa_count)
		: Passport(name, surname, age), passport_number(passport_number), visa_count(visa_count) {
		if (visa_count > 0) {
			this->visas = new string[visa_count];
			for (int i = 0; i < visa_count; ++i) {
				this->visas[i] = visas[i];
			}
		}
		else {
			this->visas = nullptr;
		}
	}
	void Print() const
	{
		cout << "-------- Foreign Passport --------" << endl;
		Passport::Print();
		cout << "Passport Number: " << passport_number << endl;
		if (visa_count > 0) {
			cout << "Visas: ";
			for (int i = 0; i < visa_count; ++i) {
				cout << visas[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "No visas." << endl;
		}
	}
	void AddVisa(const string& visa)
	{
		string* temp = new string[visa_count + 1];
		for (int i = 0; i < visa_count; ++i) {
			temp[i] = visas[i];
		}
		temp[visa_count] = visa;
		delete[] visas;
		visas = temp;
		visa_count++;
	}
};


int main()
{
	Passport passport("John", "Doe", 30);
	passport.Print();
	cout << endl;
	string visas[] = { "USA", "Canada", "UK" };
	ForeignPassport foreign_passport("Jane", "Smith", 28, "987654321", visas, 3);
	ForeignPassport foreign_passport2;
	foreign_passport.Print();
	foreign_passport2.Print();
	foreign_passport.AddVisa("France");
	foreign_passport.Print();
}

