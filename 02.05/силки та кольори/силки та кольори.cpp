#include <iostream>
#include <iomanip>
using namespace std;

void task1() {
    int a = 4, b = 2, c = 5;
    int& refA = a;
    int& refB = b;
    int& refC = c;

    int dobutok = refA * refB * refC;
    double average = (refA + refB + refC) / 3.0;
    int minVal = refA;

    if (refB < minVal) minVal = refB;
    if (refC < minVal) minVal = refC;

    cout << "\n--- Task 1: References ---\n";
    cout << "Values: " << refA << ", " << refB << ", " << refC << "\n";
    cout << "Dobutok: " << dobutok << "\n";
    cout << "Average: " << average << "\n";
    cout << "Minimum: " << minVal << "\n";
}

void negative2zero(int* arr, int size) {
	for (int i = 0; i < size; i++) 
		if (*(arr+i) < 0)   *(arr + i) = 0;
}

void task2() {
    int arr[] = { 5, -3, 8, -1, 0, 4 };
	int size = 6;

    cout << "\n--- Task 2: Replace Negatives ---\n";
    cout << "Before: ";
    for (int i = 0; i < size; i++) 
        cout << setw(3) << arr[i];

    cout << "\nAfter:  ";
    negative2zero(arr, size);
    for (int i = 0; i < size; i++)
        cout << setw(3) << arr[i];
    cout << endl;
}

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void printMatrix(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << setw(4) << matrix[i][j];
        cout << "\n";
    }
}

void task3() {
	int a = 5, b = 10;
	cout << "\n--- Task 3: Swap Values ---\n";
	cout << "Before swap: a = " << a << ", b = " << b << "\n";
	swapValues(a, b);
	cout << "After swap: a = " << a << ", b = " << b << "\n";
	int const rows = 3, cols = 4;
	int matrix[rows][cols] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 }
	};
	cout << "\nMatrix before swap:\n";
    printMatrix(matrix, rows, cols);
	int col1 = 0, col2 = 1;

	cout << "\nMatrix after swap:\n";
    for (int i = 0; i < rows; i++)
    {
        swapValues(matrix[i][col1], matrix[i][col2]);
    }
    printMatrix(matrix, rows, cols);
}

int main() {
	task1();
	task2();
	task3();
	return 0;
}
