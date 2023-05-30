#include <iostream>
#include <fstream>

using namespace std;

// 练习8.1
istream& peightone(istream& i1) 
{
	int v1;
	while (i1 >> v1 && !i1.eof()) {
		if (i1.bad()) {
			cerr << "run exception" << endl;
		}
		if (i1.fail()) {
			cerr << "Data wrong,please try again" << endl;
			i1.clear();//恢复
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

	// 管理条件状态
	auto old_state = cin.rdstate();
	cin.clear();
	//cin >> ival;
	cin.setstate(old_state);// 还没到恢复就退出了
	//cin >> ival;
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);

	// 练习
	peightone(cin);

	while (cin >> a) {

	}
	cin >> a;
	return 0;
}