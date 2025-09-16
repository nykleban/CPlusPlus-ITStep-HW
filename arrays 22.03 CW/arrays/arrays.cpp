using namespace std;
#include <iostream>
#include <cmath>

int main()
{
	cout << "------------------1-----------------" << endl;
	const int size1 = 10;
	int dob = 1;
	int arr1[size1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}cout << endl;
	for (int i = 0; i < size1; i++)
	{
		dob *= arr1[i]; 
	}
	cout << "Dobutok = " << dob << endl;

	cout << "------------------2-----------------" << endl;
	const int size2 = 7;
	int countP = 0, countM = 0;
	int arr2[size2] = { 10, -12, 32, 14, 35, 46, 50 };
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}cout << endl;
	for (int i = 0; i < size1; i++)
	{
		if (arr2[i] < 0) countM++;	
		if (arr2[i] > 0) countP++;
	}
	cout << "Count of positive numbers = " << countP << endl;
	cout << "Count of negative numbers = " << countM << endl;
	cout << "------------------3-----------------" << endl;
	const long size3 = 7;
	int arr3[size3] = { 10, -12, 32, 14, 35, 46, 50 };
	int sumParnych = 0;
	for (int i = 0; i < size3; i++)
	{
		cout << arr3[i] << " ";
	}cout << endl;
	for (int i = 0; i < size3; i++)
	{
		if (arr3[i] % 2 == 0) sumParnych += arr3[i]; //3
	}
	cout << "Sum of even numbers = " << sumParnych << endl;
	cout << "-------------------4----------------" << endl;
	const int size4 = 30;
	long arr4[size4];
	for (int i = 0; i < size4; i++)
	{
		arr4[i] = pow(2, i);
		cout << arr4[i] << " ";
	}cout << endl;
	cout << "-----------------5------------------" << endl;
	const int size5 = 10;
	int arr5[size5] = { 11, 32, -43, -4, -75, 6, 7, 8, -9, 10 };
	for (int i = 0; i < size5; i++)
	{
		cout << arr5[i] << " ";
	}cout << endl;
	for (int i = 0; i < size5; i++)
	{
		if (arr5[i] < 0) arr5[i] = arr5[i] * ( - 1);
	}
	for (int i = 0; i < size5; i++)
	{
		cout << arr5[i] << " ";
	}cout << endl;
}
