#include <iostream>
using namespace std;

// 1
int countEven(int a, int b) {
    int count = 0;
    if (a % 2 == 0) count++;
    if (b % 2 == 0) count++;
    return count;
}

// 2
int countEven(int a, int b, int c) {
    int count = 0;
    if (a % 2 == 0) count++;
    if (b % 2 == 0) count++;
    if (c % 2 == 0) count++;
    return count;
}

// 3
int countEven(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) 
        if (arr[i] % 2 == 0) 
            count++;

    return count;
}

// 4
int countEven(const int arr[][3], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            if (arr[i][j] % 2 == 0) 
                count++;
    return count;
}

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    cout << "Even numbers among " << a << " and " << b << ": " << countEven(a, b) << endl;

    int c;
    cout << "Enter 3 numbers: ";
    cin >> a >> b >> c;
    cout << "Even numbers among " << a << ", " << b << ", and " << c << ": " << countEven(a, b, c) << endl;

	const int size1D = 6;
    int arr1D[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < size1D; i++)
    {
        cout << arr1D[i] << " ";
    }cout << endl;
    cout << "Even numbers in the one-dimensional array: " << countEven(arr1D, size1D) << endl;

    const int rows = 2;
    const int cols = 3;
    int arr2D[rows][cols] = {{1, 2, 3}, {4, 5, 6}};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr2D[i][j] << " ";
		}
		cout << endl;
	}
    cout << "Even numbers in the two-dimensional array: " << countEven(arr2D, rows, cols) << endl;

    return 0;
}
