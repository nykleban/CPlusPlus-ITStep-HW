#include <iostream>
#include <cstdlib>  
#include <ctime>   
#include <iomanip>
using namespace std;

void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 41 - 20; 
    }
}

void sortArray(int arr[], int size, int where = 1) {
    for (int i = 0; i < size - 1; i++) 
        for (int j = i + 1; j < size; j++) 
            if ((where == 1 && arr[i] < arr[j]) ||
                (where == 0 && arr[i] > arr[j])) 
                    swap(arr[i], arr[j]);
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

int main() {
    srand(time(0));
    int arr[10];
	fillRandom(arr, 10);

    cout << "Original array: ";
    printArray(arr, 10);
    sortArray(arr, 10);

    cout << "Sorted (down): ";
    printArray(arr, 10);
    sortArray(arr, 10, 0); 
    cout << "Sorted (up): ";
    printArray(arr, 10);
}
