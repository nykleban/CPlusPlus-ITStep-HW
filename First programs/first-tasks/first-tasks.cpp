#include <iostream>
using namespace std;
int main() {
    //1
    cout << "1. Enter three numbers and display their values and their sum." << endl;
    int a, b, c;
    cout << "Enter three numbers: "<<endl;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b ;
    cout << "Enter third number: ";
    cin >> c;
    cout << "Entered numbers: " << a << ", " << b << ", " << c << endl;
    cout << "Sum: " << a + b + c << endl << endl;

    //2
    cout << "2. Calculation average mean of two numbers." << endl;
    double x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Average: " << (x + y) / 2 << endl << endl;

    //3
    cout << "3. Convert kilometers to meters." << endl;
    double km;
    cout << "Enter the number of kilometers: ";
    cin >> km;
    cout << "This is " << km * 1000 << " meters." << endl << endl;

    //4
    cout << "4. Calculation of the cost of purchase." << endl;
    const double price1 = 15, price2 = 20;
    int q1, q2;
    cout << "Enter the quantity of purchased goods (2 items): " << endl;
    cout << "Enter first count: ";
    cin >> q1;
    cout << "Enter second count: ";
    cin >> q2;
    double totalCost = price1 * q1 + price2 * q2 ;
    cout << "Total purchase cost: " << totalCost << " UAH." << endl << endl;

    //5
    cout << "5. Calculation of the square of a number." << endl;
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Square of the number: " << num * num << endl << endl;

    //6
    cout << "6. Convert days to minutes." << endl;
    int days;
    const int MINUTES_IN_DAY = 1440;
    cout << "Enter the number of days: ";
    cin >> days;
    cout << "This is " << days * MINUTES_IN_DAY << " minutes." << endl;
}
