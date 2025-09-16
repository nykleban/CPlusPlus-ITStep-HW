

using namespace std;
#include <iostream>

template<typename T>
void printArray(const T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

//1
    template<typename T>
    void sortArraySelection(T arr[], int size, bool direction = true) {
        for (int i = 0; i < size - 1; i++) {
            int index = i;
            for (int j = i + 1; j < size; j++) {
                if (direction) {
                    if (arr[j] < arr[index]) {index = j;}
                } else {
                    if (arr[j] > arr[index]) { index = j; }
                }
            }
            if (index != i) {swap(arr[i], arr[index]);}
        }
    }

    //2
    template<typename T>
    void sortArrayBubbleByHalf(T arr[], int size) {
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size / 2 - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        for (int i = size / 2; i < size - 1; i++) {
            for (int j = size / 2; j < size - i + size / 2 - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    //3
	void randomArray(int arr[], int size, int min, int max) {
		for (int i = 0; i < size; i++) {
            arr[i] = rand() % 41 - 20;
		}
	}
	template<typename T>
    int findNegativeElement(T arr[], int size, bool first = true) {
		int left = -1;
        for (int i = 0; i < size; i++)
        {
			if (arr[i] < 0)
			{
				left=i;
                if (first)
                    break;
			}
        }
        return left;
    }
	void sortArrayWithIndex(int arr[], int start, int end) {
		for (int i = start+1; i < end-2; i++) {
			for (int j = i + 1; j < end-1; j++) {
				if (arr[j] < arr[i]) {
					swap(arr[i], arr[j]);
				}
			}
		}
	}



int main()
{
	cout << "-----  Task1  -----" << endl;
	int arr[] { 10, -2, 13, -44, 85 };
	cout << "Array before sorting: " << endl;
    printArray(arr, size(arr));

	cout << "Array after sorting 'true': " << endl;
    sortArraySelection(arr, size(arr), true);
	printArray(arr, size(arr));

    cout << "Array after sorting 'false': " << endl;
    sortArraySelection(arr, size(arr), false);
    printArray(arr, size(arr));

	cout << "-----  Task2  -----" << endl;
	int arr2[] { 10, -2, 13, -44, 85, -8};
	cout << "Array before sorting: " << endl;
	printArray(arr2, size(arr2));

	cout << "Array after sorting 'true': " << endl;
	sortArrayBubbleByHalf(arr2, size(arr2));
	printArray(arr2, size(arr2));

	cout << "-----  Task3  -----" << endl;
    int arr3[]{ 10, -2, 13, -44, 85, -8 , 10, 15,-2,3,4};
	cout << "First negative element: " << findNegativeElement(arr3, size(arr3), true) << endl;
	cout << "Last negative element: " << findNegativeElement(arr3, size(arr3), false) << endl;
	cout << "Array before sorting: " << endl;
	printArray(arr3, size(arr3));
	int start = findNegativeElement(arr3, size(arr3), true);
	int end = findNegativeElement(arr3, size(arr3), false);
	if (start != -1 && end != -1) {
		sortArrayWithIndex(arr3, start, end + 1);
	}
	cout << "Array after sorting: " << endl;
	printArray(arr3, size(arr3));
}
