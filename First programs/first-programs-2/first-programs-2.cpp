#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //1
    double a, b, c;
    cout << "Task 1: Determine the type of triangle\n";
    cout << "Enter side a: ";
    cin >> a;
    cout << "Enter side b: ";
    cin >> b;
    cout << "Enter side c: ";
    cin >> c;

    if (a == b && b == c) {
        cout << "The triangle is pravil`nyi.\n";
    }
    else if (a == b || b == c || a == c) {
        cout << "The triangle is rivnobedrenyi.\n";
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        cout << "The triangle is priamokutnyi.\n";
    }
    else {
        cout << "The triangle is dovilnyi.\n";
    }

    //2
    double brickWidth, brickHeight, brickDepth;
    double holeWidth, holeHeight;
    cout << "Task 2: Determine if the brick fits through the hole\n";
    cout << "Enter the brick width: ";
    cin >> brickWidth;
    cout << "Enter the brick height: ";
    cin >> brickHeight;
    cout << "Enter the hole width: ";
    cin >> holeWidth;
    cout << "Enter the hole height: ";
    cin >> holeHeight;

    if (brickWidth <= holeWidth && brickHeight <= holeHeight) {
        cout << "The brick fits through the hole.\n";
    }
    else {
        cout << "The brick does not fit through the hole.\n";
    }

    //3
    int num1, num2, num3;
    cout << "Task 3: Determine if there are positive numbers among three given numbers\n";
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;
    cout << "Enter number 3: ";
    cin >> num3;

    if (num1 > 0 || num2 > 0 || num3 > 0) {
        cout << "There is at least one positive number.\n";
    }
    else {
        cout << "There are no positive numbers.\n";
    }

    //4
    int number;
    cout << "Task 4: Determine if a number lies outside the intervals [2, 5] and [-1, 1]\n";
    cout << "Enter a number: ";
    cin >> number;

    if ((number < 2 || number > 5) && (number < -1 || number > 1)) {
        cout << "The number lies outside the intervals [2, 5] and [-1, 1].\n";
    }
    else {
        cout << "The number does not lie outside the intervals [2, 5] and [-1, 1].\n";
    }

    //5
    int n1, n2, n3;
    cout << "Task 5: Determine if three numbers are equal\n";
    cout << "Enter number 1: ";
    cin >> n1;
    cout << "Enter number 2: ";
    cin >> n2;
    cout << "Enter number 3: ";
    cin >> n3;

    if (n1 == n2 && n2 == n3) {
        cout << "All three numbers are equal.\n";
    }
    else {
        cout << "The numbers are not all equal.\n";
    }

    //1
    double rectWidth, rectHeight;
    cout << "1: Determine if a rectangle is a square\n";
    cout << "Enter the width of the rectangle: ";
    cin >> rectWidth;
    cout << "Enter the height of the rectangle: ";
    cin >> rectHeight;

    if (rectWidth == rectHeight) {
        cout << "The rectangle is a square.\n";
    }
    else {
        cout << "The rectangle is not a square.\n";
    }

    //2
    int age;
    cout << "2: Determine if a child can attend school or kindergarten based on age\n";
    cout << "Enter the child's age: ";
    cin >> age;

    if (age >= 6 && age <= 17) {
        cout << "The child can attend school.\n";
    }
    else if (age >= 1 && age < 6) {
        cout << "The child can attend kindergarten.\n";
    }
    else {
        cout << "The child is too young for kindergarten or too old for school.\n";
    }

    //3
    int numA, numB, numC;
    cout << "3: Determine if exactly two out of three numbers are negative\n";
    cout << "Enter number A: ";
    cin >> numA;
    cout << "Enter number B: ";
    cin >> numB;
    cout << "Enter number C: ";
    cin >> numC;

    int negativeCount = (numA < 0 ? 1 : 0) + (numB < 0 ? 1 : 0) + (numC < 0 ? 1 : 0);
    if (negativeCount == 2) {
        cout << "Exactly two numbers are negative.\n";
    }
    else {
        cout << "There are not exactly two negative numbers.\n";
    }

    //4
    int num;
    cout << "4: Determine if a number belongs to the intervals [2, 5] or [-1, 1]\n";
    cout << "Enter a number: ";
    cin >> num;

    if ((num >= 2 && num <= 5) || (num >= -1 && num <= 1)) {
        cout << "The number belongs to the intervals [2, 5] or [-1, 1].\n";
    }
    else {
        cout << "The number does not belong to the intervals [2, 5] or [-1, 1].\n";
    }

    //5
    int numX, numY, numZ;
    cout << "5: Determine if exactly two out of three numbers are equal\n";
    cout << "Enter number X: ";
    cin >> numX;
    cout << "Enter number Y: ";
    cin >> numY;
    cout << "Enter number Z: ";
    cin >> numZ;

    if ((numX == numY && numX != numZ) || (numX == numZ && numX != numY) || (numY == numZ && numY != numX))  {
        cout << "Exactly two numbers are equal.\n";
    }
    else {
        cout << "There are not exactly two equal numbers.\n";
    }

    //6
    int odd1, odd2, odd3;
    cout << "6: Determine if all three numbers are odd\n";
    cout << "Enter number 1: ";
    cin >> odd1;
    cout << "Enter number 2: ";
    cin >> odd2;
    cout << "Enter number 3: ";
    cin >> odd3;

    if (odd1 % 2 != 0 && odd2 % 2 != 0 && odd3 % 2 != 0) {
        cout << "All three numbers are odd.\n";
    }
    else {
        cout << "Not all three numbers are odd.\n";
    }

    //7
    int swapA, swapB;
    cout << "7: Swap two numbers if they are different\n";
    cout << "Enter number A: ";
    cin >> swapA;
    cout << "Enter number B: ";
    cin >> swapB;

    if (swapA != swapB) {
        swap(swapA, swapB);
        cout << "Numbers swapped: " << swapA << " " << swapB << "\n";
    }
    else {
        cout << "Numbers are the same, no swap needed.\n";
    }

    //8
    int numberA;
    cout << "8: Determine the sum of digits of a number and print the first and last digit\n";
    cout << "Enter a number between 101 and 999: ";
    cin >> numberA;

    int sum = 0, firstDigit = numberA / 100, lastDigit = numberA % 10;
    int temp = numberA;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    cout << "Sum of digits: " << sum << "\n";
    cout << "First and last digit: " << firstDigit << "  " << lastDigit << "\n";

    //9
    int hours, minutes, seconds;
    cout << "9: Determine if the given time is valid\n";
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;

    if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60) {
        cout << "The time is valid.\n";
    }
    else {
        cout << "The time is not valid.\n";
    }

    //10
    int hour;
    cout << "10: Print greeting based on the hour of the day\n";
    cout << "Enter the hour: ";
    cin >> hour;

    if (hour >= 0 && hour < 6) {
        cout << "Good night\n";
    }
    else if (hour >= 6 && hour < 12) {
        cout << "Good morning\n";
    }
    else if (hour >= 12 && hour < 18) {
        cout << "Good day\n";
    }
    else if (hour >= 18 && hour < 24) {
        cout << "Good evening\n";
    }
    else {
        cout << "Invalid hour\n";
    }

    //11
    int min1, min2, min3;
    cout << "11: Find the minimum of three numbers\n";
    cout << "Enter number 1: ";
    cin >> min1;
    cout << "Enter number 2: ";
    cin >> min2;
    cout << "Enter number 3: ";
    cin >> min3;
    int min;
    if (min1 <= min2 && min1 <= min3) {
        min = min1;
    } else if (min2 <= min1 && min2 <= min3) {
        min = min2;
    } else {
        min = min3;
    }
    cout << "The minimum number is: " << min << "\n";

    return 0;
}
