
using namespace std;
#include <iostream>

void program1() {
	cout << "Task 1" << endl;
	int number;
	cout << "Enter the number: ";
	cin >> number;
	int sum = 0, count = 0, zerocount = 0;
	float avarege = 0;
	while (number != 0)
	{
		if (number % 10 == 0)
		{
			zerocount++;
		}
		sum += number % 10;
		number /= 10;
		count++;
	}
	avarege = (float)sum / count;
	cout << "Sum: " << sum << endl;
	cout << "Zero count: " << zerocount << endl;
	cout << "Avarege: " << avarege << endl;
}


void program2() {
	cout << "Task 2" << endl;
	int size;
	cout << "Enter the size of each cell: ";
	cin >> size;

	for (int i = 0; i < 8 * size; ++i) {
		for (int j = 0; j < 8 * size; ++j) {
			if ((i / size + j / size) % 2 == 0) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}

int main()
{
	program1();
	program2();
  return 0;
}
