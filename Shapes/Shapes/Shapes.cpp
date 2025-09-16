using namespace std;
#include <iostream>

class Shape {
protected:
    string name;
public:
    Shape() :name{ "unknown shape" } {}
    Shape(string n) :name{ n } {}
    virtual void Show()const = 0;
    virtual void GetArea()const = 0;
};

class Priamokutnik :public Shape {
private:
    double a, b;
public:
    Priamokutnik() :Shape("Priamokutnik"), a{ 0 }, b{ 0 } {}
    Priamokutnik(double aa, double bb) :Shape("priamokutnik"), a{ aa }, b{ bb } {}
    void Show()const override {
        cout << "===== Priamokutnik =====" << endl;
        cout << "Name: " << name << endl;
        cout << "Sides: a=" << a << ", b=" << b << endl;
    }
    void GetArea()const override {
        cout << "Area: " << a * b << endl;
        cout << "========================" << endl;
    }
};

class Circle :public Shape {
private:
    double r;
public:
    Circle() :Shape("Circle"), r{ 0 } {}
    Circle(double rr) :Shape("Circle"), r{ rr } {}
    void Show()const override {
        cout << "======== Circle ========" << endl;
        cout << "Name: " << name << endl;
        cout << "Radius: r=" << r << endl;
    }
    void GetArea()const override {
        cout << "Area: " << 3.14 * r * r << endl;
        cout << "========================" << endl;
    }
};

class Triangle :public Shape {
protected:
    double a, b, c;
public:
    Triangle() :Shape("Triangle"), a{ 0 }, b{ 0 }, c{ 0 } {}
    Triangle(double aa, double bb, double cc) :Shape("Triangle"), a{ aa }, b{ bb }, c{ cc } {}
    void Show()const override {
        cout << "======== Triangle ========" << endl;
        cout << "Name: " << name << endl;
        cout << "Sides: a=" << a << ", b=" << b << ", c=" << c << endl;
    }
    void GetArea()const override {
        double s = (a + b + c) / 2;
        cout << "Area: " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
        cout << "==========================" << endl;
    }
};

class PriamokutniyTriangle :public Triangle {
public:
    PriamokutniyTriangle() :Triangle(3, 4, 5) {}
    PriamokutniyTriangle(double aa, double bb, double cc) :Triangle(aa, bb, cc) {}
    void Show()const override {
        cout << "=== Priamokutniy Triangle ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Sides: a=" << a << ", b=" << b << ", c(gipotenuza)=" << c << endl;
    }
    void GetArea()const override {
        cout << "Area (right triangle): " << (a * b) / 2 << endl;
        cout << "==========================" << endl;
    }
};

class Trapecia :public Shape {
private:
    double a, b, h;
public:
    Trapecia() :Shape("Trapecia"), a{ 0 }, b{ 0 }, h{ 0 } {}
    Trapecia(double aa, double bb, double hh) :Shape("Trapecia"), a{ aa }, b{ bb }, h{ hh } {}
    void Show()const override {
        cout << "======== Trapecia ========" << endl;
        cout << "Name: " << name << endl;
        cout << "Sides: a=" << a << ", b=" << b << ", height=" << h << endl;
    }
    void GetArea()const override {
        cout << "Area: " << ((a + b) / 2) * h << endl;
        cout << "==========================" << endl;
    }
};
void TestShape(Shape& s) {
    s.Show();
    s.GetArea();
}

void TestShape(const Shape& s) {
    s.Show();
    s.GetArea();
}

int main() {
    Shape* shapes[5]{
        new Priamokutnik(4, 5),
        new Circle(3),
        new Triangle(3, 4, 5),
        new PriamokutniyTriangle(3, 4, 5),
        new Trapecia(3, 4, 5)
    };

    for (int i = 0; i < 5; ++i) {
        TestShape(*shapes[i]);
        cout << endl << endl;
    }

    for (int i = 0; i < 5; ++i) {
        delete shapes[i];
    }
}
