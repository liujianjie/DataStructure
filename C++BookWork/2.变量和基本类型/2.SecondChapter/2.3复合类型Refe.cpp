#include <iostream>


using namespace std;
int main()
{
	int getchar = 10;
	int anotherval = 20;
	int &refval = getchar;
	//int &refval2;// ����
	//&refval = anotherval;// ���� �޷���������

	// ��ֵ
	refval = 2; // ��ʱ getchar Ϊ 2;
	refval = anotherval; // ��ʱ Ϊ��ֵ

	//int &refval2 = 10;// ���� 10 ֻ������ֵ���޷��������ã����õı����Ƕ���
	//int &refaval = 0; ����ֵΪ0Ҳ����
	int &refval2 = refval;
	// ���ò��� ���� ���õ�����


	cout << &refval2 <<endl; // �����ַ ������ֵ
	cout <<&refval <<endl;		// ��ַһ������Ϊ refval2 ָ����refvalָ��� ����������������ĵ�ַһ��������ַ����getchar�ĵ�ַ
	cout <<&getchar<<endl;	// 

	// �������ò�ͬ���������Ͷ���
	float floatval = 0.2f;
	//int &refval3 = floatval;
	float &refval3 = floatval;
	
	// ������һ�ж���������
	int &refval4 = getchar, &refval5 = anotherval;

	//cout << getchar <<endl;

	int *p = 0;
	cin>>getchar;
	return 0;
}