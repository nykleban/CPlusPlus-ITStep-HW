#include <iostream>
using namespace std;

bool isSimple(int n) {
	if (n < 2) return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void printSimpleNumbers(int left, int right) {
	for (int i = left; i <= right; i++) {
		if (isSimple(i)) {
			cout << i << " ";
		}
	}
}

int main()
{
	int a, b;
	cout << "Enter 2 numbers: ";
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	cout << "Simple numbers between " << a << " and " << b << ": ";
	printSimpleNumbers(a, b);
}
