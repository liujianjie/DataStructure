#include <iostream>
#include <fstream>

using namespace std;

/*
��Ϊ�豸��д������ʱ�����Բ���ϵͳ����������������Ϊ��һ���豸д�����ṩ��������

����ˢ��
1.������������ main��return
2.����������
3.������endl
4.unitbuf
5.�Թ�����������
*/
void testnull()
{
	cout << "testnull()" << endl;
}
void testnull(ostream* v) 
{
	cout << "testnull(int v)" << endl;
}
int main()
{
	int a;
	cout << "hi" << endl;// ����
	cout << "hi" << flush;//ˢ�»�����
	cout << "hi" << ends;// ���˿��ַ�

	cout << unitbuf;
	cout << "...";
	cout << "asdf";
	cout << "zxvcx";
	cout << nounitbuf;
	cout << "qweq";
	cout << "...";
	// ���������������������ᱻˢ��

	// ��������������
	testnull(nullptr);

	cin.tie(&cout);// cin��cout����
	ostream *old_tie = cin.tie(nullptr);//  cin����˭���������ǻ��ǻ᷵����ǰ������
	cin.tie(&cerr);// cin��cerr����
	cin.tie(old_tie);// cin����cout����
	// ÿ�������ͬʱ������һ����, �������������ʱ������ͬһ��ostream
	cin.tie(&cerr);// ��⿪��ǰ�Ĺ�����




	cin >> a;
	return 0;
}