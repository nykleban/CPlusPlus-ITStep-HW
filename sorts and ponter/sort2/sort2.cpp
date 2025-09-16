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

int findNegative(int arr[], int size, bool left) { //right = false, left = true
    if (left) {
        for (int i = 0; i < size; i++)
            if (arr[i] < 0)
                return i+1;
    }
    else if (!left) {
        for (int i = size - 1; i >= 0; i--)
            if (arr[i] < 0)
                return i-1;
    }
    else
        return -1;
}

void sortArray(int arr[], int size, int start, int end) {

    if (start == -1 || end == -1 || start >= end)
        return;

    for (int i = start; i < end; i++) 
        for (int j = i + 1; j <= end; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

int main() {
    srand(time(0));
    int arr[15];
    fillRandom(arr, 15);
    int start = findNegative(arr, 15, true);
    int end = findNegative(arr, 15, false);

    cout << "Original array: ";
    printArray(arr, 15);

    if (start != -1 && end != -1) {
        sortArray(arr, 15, start, end);
        cout << "Sorted (up) between first and last negative: ";
    }
    else {
        cout << "No negative numbers found or only one negative number. Array unchanged: ";
    }

    printArray(arr, 15);
}