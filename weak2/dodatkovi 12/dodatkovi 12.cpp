#include <iostream>
using namespace std;

void program7() {
    cout << "Task 7" << endl;
    int sum = 0;
    for (int i = 0; i < 50; ++i) {
        if (i % 4 == 0) {
            sum += i;
        }
    }
    cout << "Sum using \"for\" loop: " << sum << endl;

    sum = 0;
    int i = 0;
    while (i < 50) {
        if (i % 4 == 0) {
            sum += i;
        }
        ++i;
    }
    cout << "Sum using \"while\" loop: " << sum << endl;
}

void program8() {
    cout << "Task 8" << endl;
    int number;
    cout << "Enter a number: ";
    cin >> number;
    for (int i = 0; i <= number; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

void program9() {
    cout << "Task 9" << endl;
    int start, end;
    cout << "Enter the range (two numbers): ";
    cin >> start >> end;
    if (start > end) {
        swap(start, end);
    }

    cout << "All numbers in the range: ";
    for (int i = start; i <= end; ++i) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Even numbers in the range: ";
    for (int i = start; i <= end; ++i) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Odd numbers in the range: ";
    for (int i = start; i <= end; ++i) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Numbers divisible by 7 in the range: ";
    for (int i = start; i <= end; ++i) {
        if (i % 7 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void program10() {
    cout << "Task 10" << endl;
    int start, end, sum = 0;
    cout << "Enter the range (two numbers): ";
    cin >> start >> end;
    if (start > end) {
        swap(start, end);
    }
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    cout << "Sum of all numbers in the range: " << sum << endl;
}

void program11() {
    cout << "Task 11" << endl;
    int number, sum = 0;
    cout << "Enter numbers (0 to stop): ";
    while (true) {
        cin >> number;
        if (number == 0) {
            break;
        }
        sum += number;
    }
    cout << "Sum: " << sum << endl;
}

int main() {
    program7();
    program8();
    program9();
    program10();
    program11();
    return 0;
}