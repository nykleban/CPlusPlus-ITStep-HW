#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>  // Add this include for setw
using namespace std;

const int SIZE = 5;

void fillMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) 
        for (int j = 0; j < SIZE; j++) 
            matrix[i][j] = rand() % 101;
}

void printMatrix(const int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void sumMatrix(const int  a[][SIZE], const int b[][SIZE], int c[][SIZE]) {
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++) 
			c[i][j] = a[i][j] + b[i][j];

}

void multiplyMatrix(int a[][SIZE], int number) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] *= number;
}


int main()
{
    const int row = 5 ;
    const int col = 5 ;
	int matrix1[row][col];
	int matrix2[row][col];
	fillMatrix(matrix1);
	fillMatrix(matrix2);
	cout << "Matrix 1:" << endl;
	printMatrix(matrix1); cout << endl;
	cout << "Matrix 2:" << endl;
	printMatrix(matrix2); cout << endl;

	int sumOfMatrixex[row][col];
	cout << "Sum of matrices:" << endl;
    sumMatrix(matrix1, matrix2, sumOfMatrixex);
	printMatrix(sumOfMatrixex); cout << endl;
	
    int number;
	cout << "Enter a number to multiply the matrix: ";
    cin >> number;
	cout << "Matrix 1 multiplied by " << number << ":" << endl;
	multiplyMatrix(matrix1, number);
	printMatrix(matrix1); cout << endl;
}
