#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	void Print() const
	{
		cout << "Point(" << x << ", " << y << ")\n";
	}
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	void operator --()
	{
		this->x--;
		this->y--;
	}
	void operator --(int)
	{
		this->x--;
		this->y--;
	}
	void operator ++()
	{
		this->x++;
		this->y++;
	}
	void operator ++(int)
	{
		this->x++;
		this->y++;
	}
	void operator !()
	{
		this->x = -1 * x;
		this->y = -1 * y;
	}
	bool operator > (const Point& p) const
	{
		double distance1 = sqrt(this->x * this->x + this->y * this->y);
		double distance2 = sqrt(p.x * p.x + p.y * p.y);
		return (distance1 > distance2);
	}
	bool operator < (const Point& p) const
	{
		double distance1 = sqrt(this->x * this->x + this->y * this->y);
		double distance2 = sqrt(p.x * p.x + p.y * p.y);
		return (distance1 < distance2);
	}
};
