#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct PIB {
    string name;
    string surname;
    string pobatkovi;

    PIB(string n = "-", string s = "-", string p = "-")
        : name(n), surname(s), pobatkovi(p) {
    }
};

struct telephones {
    string homeTelephone;
    string mobileTelephone;

    telephones(string home = "-", string mobile = "-")
        : homeTelephone(home), mobileTelephone(mobile) {
    }
};

class Abonent {
    PIB pib;
    telephones tel;
    string description;

public:
    Abonent() : Abonent(PIB(), telephones(), "-") {}

    Abonent(const PIB& pib1) : Abonent(pib1, telephones(), "-") {}

    Abonent(const PIB& pib1, const telephones& tel1) : Abonent(pib1, tel1, "-") {}

    Abonent(const PIB& pib1, const telephones& tel1, const string& des)
        : pib(pib1), tel(tel1), description(des) {
    }

    const PIB& getPIB() { return pib; }
    const telephones& getTelephones() { return tel; }
    const string& getDescription() { return description; }
};

class PhoneBook {
private:
    Abonent* abonents;
    static int countAbonent;

public:
    PhoneBook() : abonents(nullptr) {}

    ~PhoneBook() {
        delete[] abonents;
    }

    int getCountAbonent() const {
        return countAbonent;
    }

    void Add(const Abonent& a) {
        Abonent* newAbonents = new Abonent[countAbonent + 1];
        for (int i = 0; i < countAbonent; i++) {
            newAbonents[i] = abonents[i];
        }
        newAbonents[countAbonent] = a;
        delete[] abonents;
        abonents = newAbonents;
        countAbonent++;
    }

    void Delete(const string& phone) {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getTelephones().mobileTelephone == phone ||
                abonents[i].getTelephones().homeTelephone == phone) {

                for (int j = i; j < countAbonent - 1; j++) {
                    abonents[j] = abonents[j + 1];
                }
                countAbonent--;
                break;
            }
        }

        Abonent* newAbonents = new Abonent[countAbonent];
        for (int i = 0; i < countAbonent; i++) {
            newAbonents[i] = abonents[i];
        }
        delete[] abonents;
        abonents = newAbonents;
    }

    void SearchByName(const string& name) const {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getPIB().name == name) {
                cout << "Found: " << abonents[i].getPIB().name << " "
                    << abonents[i].getPIB().surname << " "
                    << abonents[i].getPIB().pobatkovi << endl;
            }
        }
    }

    void SearchByPhone(const string& phone) const {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getTelephones().mobileTelephone == phone ||
                abonents[i].getTelephones().homeTelephone == phone) {

                cout << "Found: " << abonents[i].getPIB().name << " "
                    << abonents[i].getPIB().surname << " "
                    << abonents[i].getPIB().pobatkovi << endl;
            }
        }
    }

    void ShowAll() const {
        for (int i = 0; i < countAbonent; i++) {
            const PIB& p = abonents[i].getPIB();
            const telephones& t = abonents[i].getTelephones();

            cout << "Abonent " << i + 1 << ": " << p.name << " " << p.surname << " " << p.pobatkovi << "\n"
                << "Home Phone: " << t.homeTelephone << "\n"
                << "Mobile Phone: " << t.mobileTelephone << "\n"
                << "Description: " << abonents[i].getDescription() << "\n\n";
        }
    }
};

// Ініціалізація статичної змінної
int PhoneBook::countAbonent = 0;

int main() {
    PhoneBook book;


    Abonent abonent1(PIB("Nazar", "Kleban", "Yuriiovych"),
        telephones("123456789", "0969080278"), "It's me");
    //запис у файл
	ofstream outFile("abonents.txt");
	if (outFile.is_open()) {
		outFile << abonent1.getPIB().name << " "
			<< abonent1.getPIB().surname << " "
			<< abonent1.getPIB().pobatkovi << "\n"
			<< abonent1.getTelephones().homeTelephone << "\n"
			<< abonent1.getTelephones().mobileTelephone << "\n"
			<< abonent1.getDescription() << "\n";
		outFile.close();
	}
	else {
		cout << "Unable to open file for writing.\n";
	}
	//читання з файлу
	ifstream inFile("abonents.txt");
	if (inFile.is_open()) {
		string name, surname, pobatkovi, homePhone, mobilePhone, description;
		inFile >> name >> surname >> pobatkovi;
		inFile >> homePhone >> mobilePhone;
		inFile.ignore(); // Пропускаємо символ нового рядка
		getline(inFile, description);
		PIB pib(name, surname, pobatkovi);
		telephones tel(homePhone, mobilePhone);
		Abonent abonentFromFile(pib, tel, description);
		cout << "Abonent from file:\n"<<"PIB: " << abonentFromFile.getPIB().name << " "
			<< abonentFromFile.getPIB().surname << " "
			<< abonentFromFile.getPIB().pobatkovi << "\n"
			<< "Home Phone: " << abonentFromFile.getTelephones().homeTelephone << "\n"
			<< "Mobile Phone: " << abonentFromFile.getTelephones().mobileTelephone << "\n"
                
			<< "Description: " << abonentFromFile.getDescription() << "\n";
		inFile.close();
	}
    else
    {
		cout << "Unable to open file for reading.\n";
    }

    Abonent abonent2(PIB("Ivan", "Petrenko", "Mykolayovych"),
        telephones("12121212", "0984526341"), "Nazar's friend");

    book.Add(abonent1);
    book.Add(abonent2);
	cout << "\nCount of abonents: " << book.getCountAbonent() << endl << endl;
    book.ShowAll();

    cout << "=== Search by name ===\n";
    book.SearchByName("Ivan");

    cout << "=== Search by phone ===\n";
    book.SearchByPhone("0969080278");

    cout << "=== Delete one ===\n";
    book.Delete("0969080278");

    book.ShowAll();
	cout << "\nCount of abonents: " << book.getCountAbonent() << endl<<endl;
}
