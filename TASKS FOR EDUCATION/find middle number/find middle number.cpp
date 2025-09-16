using namespace std;
#include <iostream>

int main()
{
	cout << "Enter numbers: ";
	int count = 0;
	int* numbers = new int[count];
	while (numbers[count] != 0 ) {
		count++;
		cin >> numbers[count];
	}
	int max = numbers[0];
	int min = numbers[0];
	for (int i = 0; i < count; i++)
	{
		if (max < numbers[i]) max = numbers[i]; 
		if (min > numbers[i]) min = numbers[i]; 
		cout << numbers[i] << " ";
	}
	int avarage = (max+min) / 2;
	int riznycia = 1000;
	int average_index = 0;
	for (int i = 0; i < count ; i++)
	{
		int current_riznycia = abs(numbers[i] - avarage);
		if (numbers[i] == avarage) {
			cout << "\nMiddle number is: " << numbers[i];
			break;
		}
		if (current_riznycia < riznycia) { 
			riznycia = current_riznycia; 
			average_index = i;
		}
	}
	cout << "\nMiddle number is: " << numbers[average_index] << endl;
	
}
