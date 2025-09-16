using namespace std;
#include <iostream>

void program1() {
    cout << "Task 1" << endl;
    int i = 1;
    while (i < 101) {
        cout << i << "\t";
        i++;
    }
    cout << endl;
    cout << endl;
}

void program2() {
    cout << "Task 2" << endl;
    int i = 2;
    while (i < 201) {
        if (i % 2 == 0)
            cout << i << "\t";
        i++;
    }
    cout << endl;
    cout << endl;
}

void program3() {
    cout << "Task 3" << endl;
    int number, sum = 0;
    cout << "Enter numbers (0 to stop): ";
    while (true) {
        cin >> number;
        if (number == 0) {
            break;
        }
        if (number % 2 == 0) {
            sum += number;
        }
    }
    cout << "Sum even of them: " << sum << endl;
}

void program4() {
    cout << "Task 4" << endl;
    int count = 0, number, sum = 0;
    while (count < 10) {
        cout << "Enter number " << count + 1 << ": ";
        cin >> number;
        sum += number;
        count++;
    }
    float average = (float)sum / 10;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}

void program5() {
    cout << "Task 5" << endl;
    int n, count = 0, sum = 0;
    cout << "Enter the value of n: ";
    cin >> n;
    int i = 1;
    do {
        cout << "Odd number: " << i << ", Square: " << i * i << endl;
        sum += i * i;
        i += 2;
        count++;
    } while (count < n);
    cout << "Sum of squares of first " << n << " odd numbers: " << sum << endl;
}

void program6() {
    cout << "Task 6" << endl;
    int i = 100;
    do {
        cout << i << " ";
        i--;
    } while (i > 0);
    cout << endl;
}

void program7() {
    cout << "Task 7" << endl;
    int count = 0, number, sum = 0;
    do {
        cout << "Enter number " << count + 1 << ": ";
        cin >> number;
        sum += number;
        count++;
    } while (count < 7);
    cout << "Sum of the seven numbers: " << sum << endl;
}

void program8() {
    cout << "Task 8" << endl;
    int i = 14;
    while (i <= 123) {
        cout << i << " ";
        i++;
    }
    cout << endl;
}

void program9() {
    cout << "Task 9" << endl;
    int i = 1;
    while (i <= 100) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;
}

int main() {
    program1();
    program2();
    program3();
    program4();
    program5();
    program6();
    program7();
    program8();
    program9();
    return 0;
}
