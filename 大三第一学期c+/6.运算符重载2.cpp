#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix& operator+(Matrix &b)// ����+�����������Ϊ��Ա����
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
// �������뺯��
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
// �����������
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
	cout << "�����һ�������ֵ:"<<endl;
	cin >> mx1;
	cout << "����ڶ��������ֵ:" << endl;
	cin >> mx2;
	Matrix mx3 = mx1 + mx2;
	cout << "��������Ӻ��ֵ:" << endl;
	cout << mx3;
	return 0;
}