#include <iostream>

using namespace std;


int chushi;
string emptyss = "d";

// 2.2.3��ʶ��
char _d;
char d;
char __d__;
char _D;

int main()
{
	int getchar;

	// 2.2.1 ��ʼ�� ���� ��ֵ
	int un = 0;
	int un2 = { 0 };
	int un3{ 0 };
	int un4(0);

	long double ld = 3.14435643534;
	//int a{ ld }; // ���� ������Ϣ��ʧ����
	//int b ={ ld };
	int a = ld;

	//Ĭ�ϳ�ʼ�� �ں�����
	cout << chushi << endl; // Ĭ��Ϊ0
	//���ں������ڵ� �ᱨ�� ����������
	int ab;
	//cout << ab << endl;
	//string str = "ddd";
	//cout << emptyss << endl;


	// 2.2.2�����붨��
	extern int i; // ���� ���Ƕ���
	int j;
	/*extern*/ int ii2 = 10;//Ϊ���壿���ܼ�extern�� ����

	cin >> getchar;
	return -1;
}