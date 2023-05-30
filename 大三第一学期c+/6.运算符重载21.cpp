#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix& operator+(Matrix& b)// 重载+运算符，定义为成员函数
	{
		Matrix mx3;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mx3.arr[i][j] = arr[i][j] + b.arr[i][j];
			}
		}
		return mx3;
	}
	int arr[2][3];
};
// 打印矩阵值
void PrintMatrixVlaue(Matrix& mx) 
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mx.arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Matrix mx1, mx2;
	mx1.arr[0][0] = 2;mx1.arr[0][1] = 4;mx1.arr[0][2] = 6;
	mx1.arr[1][0] = 1;mx1.arr[1][1] = 5;mx1.arr[1][2] = 7;
	mx2.arr[0][0] = 8;mx2.arr[0][1] = 6;mx2.arr[0][2] = 4;
	mx2.arr[1][0] = 9;mx2.arr[1][1] = 5;mx2.arr[1][2] = 3;
	cout << "mx1矩阵的值为：" << endl;
	PrintMatrixVlaue(mx1);
	cout << "mx2矩阵的值为：" << endl;
	PrintMatrixVlaue(mx2);
	Matrix mx3 = mx1 + mx2;
	cout << "mx1 mx2两矩阵相加后的值为：" << endl;
	PrintMatrixVlaue(mx3);
	return 0;
}
