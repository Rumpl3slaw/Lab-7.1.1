#include <iostream>
#include <iomanip>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -8;
	int High = 42;

	int rowCount = 8;
	int colCount = 7;

	int** a = new int* [rowCount];
	for (int i = 0;i < rowCount;i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	cout << "Matrytsya:" << endl;
	Print(a, rowCount, colCount);
	cout << endl;
	cout << endl;

	int S = 0;
	int k = 0;
	Calc(a,rowCount,colCount,S,k);
	cout << "Kil`kist` elementiv:";
	cout << k;

	cout << endl;

	cout << "Suma elementiv:";
	cout << S;


}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0;i < rowCount;i++)
		for (int j = 0;j < colCount;j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	for (int i = 0;i < rowCount;i++)
	{
		for (int j = 0;j < colCount;j++)
			cout << setw(4) << a[i][j];
		    cout << endl;
	}
	cout << endl;
}
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for(int i=0;i<rowCount;i++)
		for(int j=0;j<colCount;j++)
			if (a[i][j] > 0 || !(i % 2 == 0 && j % 2 == 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}
