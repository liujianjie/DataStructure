#include <iostream>
#include <fstream>

using namespace std;

// ��ϰ8.1
istream& peightone(istream& i1) 
{
	int v1;
	while (i1 >> v1 && !i1.eof()) {
		if (i1.bad()) {
			cerr << "run exception" << endl;
		}
		if (i1.fail()) {
			cerr << "Data wrong,please try again" << endl;
			i1.clear();//�ָ�
			i1.ignore(100, '\n');
			continue;
		}
		cout << v1 << endl;
	}
	i1.clear();
	return i1;
}
int main()
{
	int a;
	int ival;
	cout << cin.good() << endl;
	cout << cin.rdstate() << endl;
	//cin >> ival;
	cout << cin.bad() << endl;
	cout << cin.rdstate() << endl;

	// ��������״̬
	auto old_state = cin.rdstate();
	cin.clear();
	//cin >> ival;
	cin.setstate(old_state);// ��û���ָ����˳���
	//cin >> ival;
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);

	// ��ϰ
	peightone(cin);

	while (cin >> a) {

	}
	cin >> a;
	return 0;
}