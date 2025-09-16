#include <iostream>
using namespace std;

void fillArray(int arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i+1 << " element: ";
        cin >> arr[i];
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int indFirst(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return -1;
}

int indLast(const int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return -1;
}

void reversePartArray(int arr[], int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    fillArray(arr, SIZE);
    printArray(arr, SIZE);
    int left = indFirst(arr, SIZE);
    int right = indLast(arr, SIZE);
    if (left != -1 && right != -1 && left < right) {
        reversePartArray(arr, left, right);
    }
    printArray(arr, SIZE); // маємо побачити, що частина масиву реверснулася
}
