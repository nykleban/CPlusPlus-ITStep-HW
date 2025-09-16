#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>  
#include <fstream>
using namespace std;


void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
struct Point
{
    int x;
    int y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
};

class Shape
{
    protected:
        string type;
public:
	Shape() : type("Shape") {}
	virtual void Print() = 0;
    virtual void Save(ofstream& file) = 0;
};

class Line : public Shape
{
private:
    Point start;
    Point end;
public:
    Line() : Shape(), start(), end(10, 0) { type = "Line"; }
    Line(int x1, int y1, int x2,int y2) : Shape(), start(x1,y1), end(x2,y1) { type = "Line"; }

    void Print() override { 
            gotoxy(start.x, start.y-1);
            cout << "-- Line --" << endl;
        for (int i = start.x; i < end.x; i++)
        {
            gotoxy(i, start.y);
            cout << "*";
        }
        cout << endl;
    }
    void Save(ofstream& file) override {
        if (file.is_open()) {
            file << type << " "
                << start.x << " " << start.y << " "
                << end.x << " " << end.y << "\n";
        }
    }
};

class MyRectangle : public Shape {
private:
    Point topLeftCorner;
    int height;
    int width;
public:
	MyRectangle() : Shape(), topLeftCorner(0,0), height(5), width(5) { type = "Rectangle"; }
	MyRectangle(int x, int y, int h, int w) : Shape(), topLeftCorner(x, y), height(h), width(w) { type = "Rectangle"; }
    void Print() override {
        gotoxy(topLeftCorner.x, topLeftCorner.y - 1);
        cout << "-- Rectangle --" << endl;
        for (int i = 0; i < height; i++) {
            gotoxy(topLeftCorner.x, topLeftCorner.y + i);
            for (int j = 0; j < width; j++) {
               
                    cout << "*";
                
                
            }
            cout << endl;
        }
	}
    void Save(ofstream& file) override {
        if (file.is_open()) {
            file << type << " "
                << topLeftCorner.x << " " << topLeftCorner.y << " "
                << height << " " << width << "\n";
        }
    }
};

class MyPolyline : public Shape {
private:
    Point* points;
	int numPoints;
public:
    MyPolyline()
    {
		points = nullptr;
		numPoints = 0;
    }
	MyPolyline(Point* pts, int n) : points(pts), numPoints(n) { type = "Polyline"; }
    ~MyPolyline() {
        if(points!=nullptr)
		delete[] points;
    }
    void Print() override {
        gotoxy(points[0].x-2, points[0].y-2);
        cout << "-- Polyline --" << endl;
        //Copilot написав цей метод
        for (int i = 0; i < numPoints - 1; i++) {
            int x1 = points[i].x;
            int y1 = points[i].y;
            int x2 = points[i + 1].x;
            int y2 = points[i + 1].y;
            // Simple Bresenham's line algorithm
            int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
            int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
            int err = dx + dy, e2;
            while (true) {
                gotoxy(x1, y1);
                cout << "*";
                if (x1 == x2 && y1 == y2) break;
                e2 = 2 * err;
                if (e2 >= dy) { err += dy; x1 += sx; }
                if (e2 <= dx) { err += dx; y1 += sy; }
            }
        }
        cout << endl;
	}
    void Save(ofstream& file) override {
        if (file.is_open()) {
            file << type << " " << numPoints;
            for (int i = 0; i < numPoints; i++) {
                file << " " << points[i].x << " " << points[i].y;
            }
            file << "\n";
        }
    }
};




int main()
{
    ofstream file("shapes.txt"); // відкрили один раз

    Shape* shape1 = new Line(3, 6, 20, 6);
    shape1->Save(file);
    shape1->Print();
    delete shape1;

    Shape* shape2 = new MyRectangle(10, 10, 5, 10);
    shape2->Save(file);
    shape2->Print();
    delete shape2;

    Point pts[4] = { {20,5}, {25,10}, {30,5}, {35,10} };
    Shape* shape3 = new MyPolyline(pts, 4);
    shape3->Save(file);
    shape3->Print();
    delete shape3;

    file.close();

}
