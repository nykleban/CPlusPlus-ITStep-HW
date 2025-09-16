using namespace std;
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	cout << "*** Matrix int type ***" << endl;
	srand(time(0));
	const int M = 7;
	const int N = 5;
	int matrix[M][N];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 41 - 20;
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << " --- Task 1 ---" << endl;
	int countNotNull = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] != 0)
			{
				countNotNull++;
			}
		}
	}
	cout << "Count of not null elements: " << countNotNull << endl;
	cout << endl;

	cout << " --- Task 2 ---" << endl;
	int countNull = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 0)
			{
				countNull++;
			}
		}
	}
	cout << "Count of null elements: " << countNull << endl;
	cout << endl;

	cout << " --- Task 3 ---" << endl;
	int countDo12 = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(matrix[i][j]) < 12)
			{
				countDo12++;
			}
		}
	}
	cout << "Count of elements that are less than |12|: " << countDo12 << endl;
	cout << endl;

	cout << " --- Task 4 ---" << endl;
	int countPositive = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] > 0)
			{
				countPositive++;
			}
		}
	}
	cout << "Count of positive elements: " << countPositive << endl;
	cout << endl;

	cout << " --- Task 7 ---" << endl;
	int count13_6_1 = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] % 6 == 1)
			{
				count13_6_1++;
			}
		}
	}
	cout << "Count of elements that are divided by 6 = 1: " << count13_6_1 << endl;
	cout << endl;

	cout << " --- Task 8-9 ---" << endl;
	int min = 0;
	int max = 0;
	min = matrix[0][0];
	max = matrix[0][0];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (min > matrix[i][j]) min = matrix[i][j];
			if (max < matrix[i][j]) max = matrix[i][j];
		}
	}
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << endl;
	cout << endl;
	cout << "*** New matrix float type ***" << endl;
	const int M1 = 3;
	const int N1 = 3;
	double matrixFloat[M1][N1];
	for (int i = 0; i < M1; i++) {
		for (int j = 0; j < N1; j++)
		{
			matrixFloat[i][j] = (rand() % 201 - 100) / 10.0;
            cout << setw(10) << matrixFloat[i][j] ;
		}
		cout << endl;
	}
	cout << endl;

    cout << " --- Task 5 ---" << endl;
    double dobPositiveF = 1;
    for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			if (matrixFloat[i][j] > 0)	dobPositiveF *= matrixFloat[i][j];
    cout << "Dobutok of positive elements: " << dobPositiveF << endl;
    cout << endl;

    cout << " --- Task 6 ---" << endl;
    double dobNegativeF = 1.;
    for (int i = 0; i < M1; i++)
		for (int j = 0; j < N1; j++)
			if (matrixFloat[i][j] < 0)	dobNegativeF *= matrixFloat[i][j];
    cout << "Dobutok of negative elements: " << dobNegativeF << endl;
    cout << endl;

    cout << " --- Task 10 ---" << endl;
    double sum = 0;
    for (int i = 0; i < M1; i++)  
		for (int j = 0; j < N1; j++)
			if (matrixFloat[i][j] < 0)	sum += matrixFloat[i][j];
    cout << "Sum of negative elements: " << sum << endl;
    cout << endl;

}