#include <iostream>
using namespace std;

void task1() {
    // Find the maximum of two numbers
    int a, b;
    cout << "\nTask 1: Find the maximum of two numbers\nEnter two numbers: ";
    cin >> a >> b;
    int* p1 = &a;
    int* p2 = &b;
    int max = (*p1 > *p2) ? *p1 : *p2;
    cout << "Maximum: " << max << endl;
}

void task2() {
    // Determine the sign of a number
    int num;
    cout << "\nTask 2: Determine the sign of a number\nEnter a number: ";
    cin >> num;
    int* p = &num;
    if (*p > 0)
        cout << "The number is positive\n";
    else if (*p < 0)
        cout << "The number is negative\n";
    else
        cout << "The number is zero\n";
}

void task3() {
    // Swap values of two variables
    int a, b;
    cout << "\nTask 3: Swap values of two variables\nEnter two numbers: ";
    cin >> a >> b;
    int* p1 = &a;
    int* p2 = &b;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "After swap: a = " << a << ", b = " << b << endl;
}

void task4() {
    // Simple calculator using pointers
    char op;
    int a, b;
    cout << "\nTask 4: Simple calculator\nEnter two numbers: ";
    cin >> a >> b;
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;
    int* p1 = &a;
    int* p2 = &b;
    float result;
    float* res = &result;

    switch (op) {
    case '+': *res = *p1 + *p2; break;
    case '-': *res = *p1 - *p2; break;
    case '*': *res = *p1 * *p2; break;
    case '/':
        if (*p2 != 0) *res = *p1 / *p2;
        else {
            cout << "Division by zero!\n";
            return;
        }
        break;
    default:
        cout << "Unknown operation!\n";
        return;
    }

    cout << "Result: " << *res << endl;
}

void task5() {
    // Sum of array elements using pointer arithmetic
    const int SIZE = 5;
    int arr[SIZE];
    cout << "\nTask 5: Sum of array elements\nEnter 5 numbers: ";
    for (int i = 0; i < SIZE; ++i)
        cin >> arr[i];

    int* ptr = arr;
    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
        sum += *(ptr + i);

    cout << "Sum: " << sum << endl;
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}
