#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix& operator+(Matrix &b)// 重载+运算符，定义为成员函数
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
// 重载输入函数
istream& operator>>(istream& ci, Matrix& mx)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> mx.arr[i][j];
		}
	}
	return ci;
}
// 重载输出函数
ostream& operator<<(ostream& cou, Matrix& mx) 
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cou << mx.arr[i][j] << " ";
		}
		cou << endl;
	}
	return cou;
}
int main()
{
	Matrix mx1, mx2;
	cout << "输入第一个矩阵的值:"<<endl;
	cin >> mx1;
	cout << "输入第二个矩阵的值:" << endl;
	cin >> mx2;
	Matrix mx3 = mx1 + mx2;
	cout << "两矩阵相加后的值:" << endl;
	cout << mx3;
	return 0;
}