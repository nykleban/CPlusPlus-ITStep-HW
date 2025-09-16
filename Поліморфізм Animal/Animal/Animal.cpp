using namespace std;
#include <string>
#include <iostream>
#include <Windows.h>

class Animal
{
protected:
	string type;
	int speed;
	int weight;
	string living_environment;
	bool is_endangered;  // чи вимираючий вид
public:
	Animal() : type("Unknown"), speed(0), weight(0), living_environment("Unknown"), is_endangered(false) {}
	Animal(string t, int s, int w, string le, bool ie)
		: type(t), speed(s), weight(w), living_environment(le), is_endangered(ie) {
	}
	void virtual Show() {
		cout << "Type: " << type << endl;
		cout << "Speed: " << speed << " km/h" << endl;
		cout << "Weight: " << weight << " kg" << endl;
		cout << "Living Environment: " << living_environment << endl;
		cout << "Is Endangered: " << (is_endangered ? "Yes" : "No") << endl;
	}
	void virtual Move() {
		cout << type << " is moving at " << speed << " km/h." << endl;
	}
	void virtual Say() {
		cout << "=== now ANIMAL is saying.... ===" << endl;

        Beep(659, 460);
        Beep(784, 340);
        Beep(659, 230);
        Beep(659, 110);
        Beep(880, 230);
        Beep(659, 230);
        Beep(587, 230);
        Beep(659, 460);
        Beep(988, 340);
        Beep(659, 230);
        Beep(659, 110);
        Beep(1047, 230);
        Beep(988, 230);
        Beep(784, 230);
        Beep(659, 230);
        Beep(988, 230);
        Beep(1318, 230);
        Beep(659, 110);
        Beep(587, 230);
        Beep(587, 110);
        Beep(494, 230);
        Beep(740, 230);
        Beep(659, 460);

    }
	void virtual Eat() {
		cout << type << " is eating." << endl;
	}
	void DoAll() {
		cout << "\t--- there start animal ---" << endl;
		Show();
		Move();
		Say();
		Eat();
		cout << "\t--- there end animal---" << endl << endl;
	}
};

class Bird : public Animal
{
protected:
	string wings_color;
	bool can_fly;  
public:
	Bird() : Animal(), wings_color("Unknown"), can_fly(true) {}
	Bird(string t, int s, int w, string le, bool ie, string wc,
	bool cf ) : Animal(t, s, w, le, ie), wings_color(wc), can_fly(cf) {}
	void virtual Show() override {
		Animal::Show();
		cout << "This is a bird." << endl;
		can_fly ? cout << "It can fly." << endl : cout << "It cannot fly." << endl;
	}
	void virtual Move() override {
		cout << type <<" is flying(for BIRD) at " << speed << " km / h." << endl;
	}
	void virtual Say() override {
		cout << "=== now BIRD is saying.... ===" << endl;

		Beep(200, 444);
		Beep(265, 444);
		Beep(265, 222);
		Beep(295, 222);
		Beep(265, 222);
		Beep(245, 222);
		Beep(220, 444);
		Beep(220, 444);
		Beep(220, 444);
		Beep(295, 444);
		Beep(295, 222);
		Beep(330, 222);
		Beep(295, 222);
		Beep(265, 222);
		Beep(245, 444);
		Beep(200, 444);
		Beep(200, 444);
		Beep(330, 444);
		Beep(330, 222);
		Beep(345, 222);
		Beep(330, 222);
		Beep(300, 222);
		Beep(265, 444);
		Beep(220, 444);
		Beep(200, 444);
		Beep(220, 444);
		Beep(300, 444);
		Beep(245, 444);
		Beep(265, 888);
	}
	void virtual Eat() override {
		cout << "The bird is pecking at seeds." << endl;
	}
};
class Reptile : public Animal
{
protected:
	string skin_type;  // тип шкіри (наприклад, луската)
	bool is_venomous;  // чи є отруйним
public:
	Reptile() :Animal(), skin_type("Scaly"), is_venomous(false) {}
	Reptile(string t, int s, int w, string le, bool ie, string st, bool iv)
		: Animal(t, s, w, le, ie), skin_type(st), is_venomous(iv) {}
	void virtual Show() override {
		Animal::Show();
		cout << "Skin Type: " << skin_type << endl;
		cout << "Is venomous: " << (is_venomous ? "Yes" : "No") << endl;
	}
	void virtual Move() override {
		cout << type << " is slithering or crawling.(for REPTILE) at " << speed << " km/h." << endl;
	}
	void virtual Say() override {
		cout << "=== now REPTILE is saying.... ===" << endl;
		Beep(130, 100);
		Beep(262, 100);
		Beep(330, 100);
		Beep(392, 100);
		Beep(523, 100);
		Beep(660, 100);
		Beep(784, 300);
		Beep(660, 300);

		Beep(146, 100);
		Beep(262, 100);
		Beep(311, 100);
		Beep(415, 100);
		Beep(523, 100);
		Beep(622, 100);
		Beep(831, 300);
		Beep(622, 300);

		Beep(155, 100);
		Beep(294, 100);
		Beep(349, 100);
		Beep(466, 100);
		Beep(588, 100);
		Beep(699, 100);
		Beep(933, 300);

		Beep(933, 100);
		Beep(933, 100);
		Beep(933, 100);
		Beep(1047, 400);
	}
	void virtual Eat() override {
		cout << "The reptile is catching its prey." << endl;
	}
};

class Fish : public Animal
{
protected:
	string scale_color;  // колір луски
	bool is_saltwater;   // чи є морською рибою
public:
	Fish() : Animal(), scale_color("Unknown"), is_saltwater(false) {}
	Fish(string t, int s, int w, string le, bool ie, string sc, bool isw)
		: Animal(t, s, w, le, ie), scale_color(sc), is_saltwater(isw) {
	}
	void virtual Show() override {
		Animal::Show();
		cout << "Scale Color: " << scale_color << endl;
		cout << "Is saltwater: " << (is_saltwater ? "Yes" : "No") << endl;
	}
	void virtual Move() override {
		cout << type << " is swimming(for FISH) at " << speed << " km/h." << endl;
	}
	void virtual Say() override {
		cout << "=== now FISH is saying.... ===" << endl;
		Beep(659, 130);
		Beep(622, 130);
		Beep(659, 130);
		Beep(622, 130);
		Beep(659, 130);
		Beep(94, 130); 
		Beep(587, 130);
		Beep(523, 130);
		Beep(440, 130);
		Beep(262, 130);
		Beep(330, 130);
		Beep(440, 130);
		Beep(494, 130);
		Beep(330, 130);
		Beep(415, 130);
		Beep(494, 130);
		Beep(523, 130);
		Beep(330, 130);

		Beep(659, 130);
		Beep(622, 130);
		Beep(659, 130);
		Beep(622, 130);
		Beep(659, 130);
		Beep(494, 130);
		Beep(587, 130);
		Beep(523, 130);
		Beep(440, 130);
		Beep(262, 130);
		Beep(330, 130);
		Beep(440, 130);
		Beep(494, 130);
		Beep(330, 130);
		Beep(523, 130);
		Beep(494, 130);
		Beep(440, 120);
	}
	void virtual Eat() override {
		cout << "The fish is nibbling on algae." << endl;
	}
};
class Kolibri : public Bird
{

public:
    Kolibri() : Bird("Kolibri", 50, 0, "Tropical and subtropical regions", 
	false, "Bright and colorful", true) {}
	Kolibri(string w_color) : Bird("Kolibri", 50, 0, "Tropical and subtropical regions",
		false, w_color, true) {}
	

	void Show() override {
		cout << endl;
		cout << "------------ Kolibri ----------------" << endl;
		Bird::Show();
	}
	void Move() override {
		cout << type << " is hovering at " << speed << " km/h." << endl;
	}
	void Say() override {
		cout << "=== now KOLIBRI is saying.... ===" << endl;
		Beep(523, 100);
		Beep(587, 100);
		Beep(659, 100);
		Beep(587, 100);
		Beep(523, 100);
	}
	void Eat() override {
		cout << "The kolibri is sipping nectar from flowers." << endl;
	}
};

class Crocodile : public Reptile 
{
	public:
	Crocodile() : Reptile("Crocodile", 25, 500, "Swamps and rivers", false, "Scaly", true) {}
	Crocodile(string t, int s, int w, string le, bool ie, string st, bool iv)
		: Reptile(t, s, w, le, ie, st, iv) {}
	void Show() override {
		cout << endl;
		cout << "------------ Crocodile ----------------" << endl;
		Reptile::Show();
	}
	void Move() override {
		cout << type << " is swimming stealthily at " << speed << " km/h." << endl;
	}
	void Say() override {
		cout << "=== now CROCODILE is saying.... ===" << endl;
		Beep(659, 460);
		Beep(784, 340);
		Beep(659, 230);
		Beep(659, 110);
		Beep(880, 230);
		Beep(659, 230);
		Beep(587, 230);
		Beep(659, 460);
		Beep(988, 340);
		Beep(659, 230);
		Beep(659, 110);
		Beep(1047, 230);
		Beep(659, 460);
		Beep(784, 340);
		Beep(659, 230);
		Beep(659, 110);
		Beep(880, 230);
		Beep(659, 230);
		Beep(587, 230);
		Beep(659, 460);
		Beep(988, 340);
		Beep(659, 230);
		Beep(659, 110);
		Beep(1047, 230);
	}
	void Eat() override {
		cout << "The crocodile is snapping at its prey." << endl;
	}
};

class Okun : public Fish {
public:
	Okun() : Fish("Okun", 10, 1, "Freshwater lakes and rivers", false, "Green", false) {}
	Okun(string t, int s, int w, string le, bool ie, string sc, bool isw)
		: Fish(t, s, w, le, ie, sc, isw) {
	}
	void Show() override {
		cout << endl;
		cout << "------------ Okun` ----------------" << endl;
		Fish::Show();
	}
	void Move() override {
		cout << type << " is swimming gracefully at " << speed << " km/h." << endl;
	}
	void Say() override {
		cout << "=== now OKUN` is saying.... ===" << endl;
		Beep(440, 100);
		Beep(194, 100);
		Beep(523, 100);
		Beep(420, 100);
		Beep(494, 100);
		Beep(523, 100);
		Beep(440, 100);
		Beep(294, 100);
		Beep(523, 100);
		Beep(440, 100);
		Beep(194, 100);
		Beep(523, 100);
		Beep(420, 100);
		Beep(494, 100);
		Beep(523, 100);
		Beep(440, 100);
		Beep(294, 100);
		Beep(523, 100);
	}
	void Eat() override {
		cout << "The okun is hunting small fish." << endl;
	}
};


int main()
{
	Animal lion("Lion", 80, 190, "Savannah", true);

	Bird eagle("Eagle", 160, 6, "Mountains", false, "Brown", true);

	Reptile snake("Snake", 20, 5, "Desert", false, "Scaly", true);

	Fish salmon("Salmon", 15, 4, "Freshwater", false, "Silver", false);

	Kolibri kolibri1;

	Kolibri kolibri2("Green");

	Crocodile crocodile1;

	Okun okun1;

	Animal* animals[] = { &lion, &eagle, &snake, &salmon, &kolibri1, &kolibri2, &crocodile1, &okun1 };
	for (Animal* animal : animals) {
		animal->DoAll();
	}
}
