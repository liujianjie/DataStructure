#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
fstream 读写
ifstream 读
ofstream 写

一个ifstream对象需关闭后才能与另一个关联
但是可以有多个ifstream对象关联一个文件
*/

void instead_of(istream& is1,ostream& os1) 
{

}
int main()
{
	int a;
	fstream fs1("file1.txt");
	ofstream of1;
	if (fs1)
		cout << "fs1.opend()" << endl;
	if (of1)
		cout << "of1.opend()" << endl;

	// 可用fstream代替iostream&
	instead_of(fs1, fs1);

	// 成员函数open和close
	ifstream fs2("file2.txt");
	ofstream of2;
	of2.open("file3.txt");;

	if (fs2) {
		cout << "fs2.opend()" << endl;
	}
	if (of2) {
		cout << "of2.opend()" << endl;
	}
	// fs2未关闭就再open会有错
	fs2.close();
	fs2.open("file4.txt");
	cout << fs2.fail() << endl;
	if (fs2) {
		cout << fs2.good() << endl;
		cout << "fs2.opend()" << endl;
	}
	ifstream fs3("file4.txt");
	if (fs3) {
		cout << "fs3.opend()" << endl;
	}

	// 自动构造和西沟
	vector<string> v1{"file5.txt","file6.txt","file7.txt"};
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		ifstream fs4(*beg);
		if (fs4) {
			cout << "fs4.opend()" << endl;
		}
		else {
			cout << "open faile" << endl;
		}
	}
	ifstream if5("filein.txt");
	vector<string> v2;
	string str1;
	while (if5 >> str1) {
		v2.push_back(str1);
	}
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	ofstream of5("out1.txt");
	vector<string> v3{"word","vector","alholic","night"};
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		of5 << *beg<<" ";
	}
	of5 << endl;// 会缓冲


	cin >> a;
	return 0;
}