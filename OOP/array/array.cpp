using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

class Array {
private:
	long* arr;
	int size;
public:
	Array(int size)
	{
		this->size = size;
		arr = new long[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0; 
		}
	}
	Array() : size(0), arr(nullptr) {}

	explicit Array(Array& other) {
		size = other.size;
		arr = new long[size];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	void fillArray() const{
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 41-20;
		}
	}
	void printArray() const {
		for (int i = 0; i < size; i++) {
			cout << setw(5)<< arr[i] << " ";
		}
		cout << std::endl;
	}
	 void addElement(long value) {
		long* newArr = new long[size + 1];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		newArr[size] = value;
		delete[] arr;
		arr = newArr;
		size++;
	}
	 void removeElementByValue(long value) {
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (arr[i] == value) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			long* newArr = new long[size - 1];
			for (int i = 0; i < index; i++) {
					newArr[i] = arr[i];
			}
			for (int i = index + 1; i < size; i++) {
				newArr[i - 1] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			size--;
		}
	}
	void sortByAsc() const {
		for (int i = 0; i < size - 1; i++) 
			for (int j = i + 1; j < size; j++) 
				if (arr[i] > arr[j]) 
					swap(arr[i], arr[j]);
	}

	~Array() {
		delete[] arr;
	}

	operator int() {
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return {sum};
	}

	operator string() {
		string result;
		for (int i = 0; i < size; i++) {
			result += to_string(arr[i]) + " ";
		}
		return result;
	}
};


#include <cstdlib> // Include this for srand and rand functions

int main()
{
   srand(time(0)); 
   Array myArray(7);
   myArray.fillArray();
   cout << "\nPrint array: ";
   myArray.printArray();
  /* myArray.addElement(5000);
   cout << "\nAfter adding 5000: ";
   myArray.printArray();
   myArray.removeElementByValue(5000);
   cout << "\nAfter removing 5000: ";
   myArray.printArray();
   myArray.sortByAsc();
   cout << "\nSorted array: ";
   myArray.printArray();
   Array copiedArray(myArray);
   cout << "\nCopied array: ";
   copiedArray.printArray();*/
   cout << "\nSum of elements: " << (int)myArray << endl;
   cout << "\nArray as string: " << (string)myArray << endl;

}
