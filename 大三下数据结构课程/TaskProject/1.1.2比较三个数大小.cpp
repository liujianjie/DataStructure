#include <iostream>
using namespace std;
/*
˼·��
1.�ȱȽ�x��y����С��������x��
2.�ٱȽ�y��z
��y<z
	���������x y z
����
	x > z
		����� z x y
	����
		���x z y, ����Ϊx < y, y > z)

ͨ���������˳�����ʹ�ô�С����˳��������Ӷ��ﵽ�Ƚϴ�������
�������Ƚϴ���Ϊ2���Ϊ3
*/
void main()
{
	int x, y, z;
	cin >> x >> y >> z;
	if (x > y) { // x �� y ����С��������x��
		x = x + y;
		y = x - y;
		x = x - y;
	}
	if (y > z) {
		// �������˳�����ʹ�ô�С����˳�����
		if (x > z) {
			cout << z << " " << x << " " << y << endl;
		}
		else {
			cout << x << " " << z << " " << y << endl;
		}
	}
	else {
		cout << x << " " << y << " " << z << endl;
	}
}