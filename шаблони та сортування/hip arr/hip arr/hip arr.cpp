#include <iostream>
#include <iomanip>
using namespace std;

void FillArr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 90 + 10;
		}
	}
}void ShowArr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}
void Fill(int* arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		arr[i] = rand() % 10;
	}
}

//task 1
int** AddRowInStart(int** arr, int& row, int col)
{
	int** temp = new int* [row + 1];
	temp[0] = new int[col];
	for (int j = 0; j < col; j++)	temp[0][j] = 1;
	
	for (int i = 0; i < row; i++)	temp[i + 1] = arr[i];

	delete[]arr;
	row++;
	arr = temp;
	return arr;
}
//task 2
int** DelRowInStart(int** arr, int& row, int col)
{
	int** temp = new int* [row - 1];
	for (int i = 0; i < row - 1; i++)	temp[i] = arr[i + 1];

	delete[]arr[0];
	delete[]arr;
	row--;
	arr = temp;
	return arr;
}
//task 3
int** DelRowInPos(int** arr, int& row, int col, int pos)
{
	int** temp = new int* [row - 1];
	for (int i = 0; i < pos; i++)	temp[i] = arr[i];
	delete[]arr[pos];
	for (int i = pos; i < row - 1; i++)	  temp[i] = arr[i + 1];

	delete[]arr;
	row--;
	arr = temp;
	return arr;
}
//task 4
int** AddColInPos(int** arr, int row, int& col, int pos)
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++)	temp[i] = new int[col + 1];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < pos; j++)
			temp[i][j] = arr[i][j];

	for (int i = 0; i < row; i++)
		temp[i][pos] = 4;
	
	for (int i = 0; i < row; i++)
		for (int j = pos + 1; j < col + 1; j++)
			temp[i][j] = arr[i][j - 1];

	for (int i = 0; i < row; i++)	delete[]arr[i];

	delete[]arr;
	col++;
	arr = temp;
	return arr;
}
//task 5
int** AddColInStart(int** arr, int row, int& col)
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++)	temp[i] = new int[col + 1];

	for (int i = 0; i < row; i++)	temp[i][0] = 5;

	for (int i = 0; i < row; i++)
		for (int j = 1; j < col + 1; j++)
			temp[i][j] = arr[i][j - 1];


	for (int i = 0; i < row; i++)	delete[]arr[i];

	delete[]arr;
	col++;
	arr = temp;
	return arr;
}

int main()
{
	int row = 5;
	int col = 6;

	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	FillArr(arr, row, col);
	ShowArr(arr, row, col);

	//треба всі підписати
	cout << "AddRowInStart" << endl;
	arr = AddRowInStart(arr, row, col);
	ShowArr(arr, row, col);
	cout << "DelRowInStart" << endl;
	arr = DelRowInStart(arr, row, col);
	ShowArr(arr, row, col);
	cout << "DelRowInPos" << endl;
	arr = DelRowInPos(arr, row, col, 2);
	ShowArr(arr, row, col);
	cout << "AddColInPos" << endl;
	arr = AddColInPos(arr, row, col, 2);
	ShowArr(arr, row, col);
	cout << "AddColInStart" << endl;
	arr = AddColInStart(arr, row, col);
	ShowArr(arr, row, col);

	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
