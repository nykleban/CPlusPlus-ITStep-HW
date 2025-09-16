#include <iostream>
using namespace std;

void task1() {
    int* a = new int(3);
    float* b = new float(3.5);  // краще вказати f для float
    bool* c = new bool(true);

    float dobutok = (*a) * (*b) * (*c); // *c буде 1 або 0

    cout << "\n--- Task 1: Dynamic Variables ---\n";
    cout << "int: " << *a << "\n";
    cout << "float: " << *b << "\n";
    cout << "bool: " << (*c ? "true" : "false") << "\n";
    cout << "Product: " << dobutok << "\n";

    delete a;
    delete b;
    delete c;
}

int* createArray(int size) {
    return new int[size];
}

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;
}

void printArray(int* arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void task2() {
    srand(time(0)); 
    int size;
    cout << "\n--- Task 2: Dynamic Array ---\n";
    cout << "Enter array size: ";
    cin >> size; 

    int* array = createArray(size);
    fillArray(array, size);
    printArray(array, size);

    delete[] array;
}

int main() {
    task1();
    task2();
    return 0;
}
