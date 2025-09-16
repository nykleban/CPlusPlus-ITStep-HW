#include <iostream>
#include <iomanip> // Added to fix the 'setw' identifier not found error
using namespace std;
const int SIZE = 100;

template<typename T>
void fillMatrix(T matrix[][SIZE], int size) {
   cout << "Enter elements of the matrix:" << endl;
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           cout << "Element [" << i << "][" << j << "]: ";
           cin >> matrix[i][j];
       }
   }
}

template<typename T>
void printMatrix(T matrix[][SIZE], int size) {
   for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           cout << setw(5) << matrix[i][j];
       }
       cout << endl;
   }
}

template<typename T>
T findMinMaxOnDiagonal(T matrix[][SIZE], int size, bool max_min) {// true - max, false - min
   int value = matrix[0][0];
   for (int i = 0; i < size; i++) {
       if (matrix[i][i] < value && !max_min) value = matrix[i][i];
       if (matrix[i][i] > value && max_min) value = matrix[i][i];
   }
return value;
}


template<typename T>
void sortRows(T matrix[][SIZE], int size) {
   for (int i = 0; i < size; i++) 
       for (int j = 0; j < size - 1; j++) 
           for (int k = 0; k < size - j - 1; k++)  // Внутрішній цикл проходить по елементах рядка
               if (matrix[i][k] > matrix[i][k + 1]) 
				swap(matrix[i][k], matrix[i][k + 1]); 
}

int main() {
   int size;
   cout << "Enter the size of the square matrix: ";
   cin >> size;

   if (size <= 0 || size > SIZE) {
       cout << "Invalid size. Please enter a size between 1 and " << SIZE << "." << endl;
       return 1;
   }

   int matrixInt[SIZE][SIZE];

   fillMatrix(matrixInt, size);
   cout << "Matrix:" << endl;
   printMatrix(matrixInt, size);

   cout << "Min on diagonal: " << findMinMaxOnDiagonal(matrixInt, size, false) << ", Max on diagonal: " 
       << findMinMaxOnDiagonal(matrixInt, size, true) << endl;

   sortRows(matrixInt, size);
   cout << "Matrix after sorting rows:" << endl;
   printMatrix(matrixInt, size);

   return 0;
}
