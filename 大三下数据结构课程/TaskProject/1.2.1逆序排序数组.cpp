#include <iostream>
using namespace std;

int main()
{
	int temp;
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(A) / sizeof(int);
	for (int i = 0; i < n / 2; i++) {
		temp = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

	return 0;
}