#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	int maxLength = 0, tempLength;
	int size = 1;
	cout << "�����������" << endl;
	cin >> size;
	cout << "����������ÿ��ֵ��" << endl;
	float *cinv = new float[size];
	for (int i = 0; i < size; i++) {
		cin >> cinv[i];
		tempLength = to_string((int)cinv[i]).length(); // ��ȥС�����֣����㳤��
		maxLength = maxLength < tempLength ? tempLength : maxLength;// ��һ�������������Ŀ
	}
	maxLength = maxLength + 4; // 3λС������С����
	cout << "��ʽ�������" << endl;
	cout << setprecision(3) << setiosflags(ios::fixed) ;// ����3ΪС����С����ʽ���
	for (int i = 0; i < size; i++) {
		cout.width(maxLength);// ���ó���
		cout.setf(ios::right);// ���ö��뷽ʽ
		cout << cinv[i] << endl;
	}
	return 0;
}