#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
每个流都有一个关联的文件模式，用来指出如何使用文件
*/

int main()
{
	int a;
	fstream fs1("file1.txt");// 默认以in模式打开

	// ofstream默认out，只要out了就会默认指定trunc除非显示指定app和in
	ofstream out1("file2.txt");// out trunc
	ofstream out2("file3.txt", ofstream::out);// out trunc
	ofstream out3("file4.txt", ofstream::out | ofstream::trunc);// out trunc

	ofstream out4("file4.txt", ofstream::app);
	ofstream out5("file5.txt", ofstream::out | ofstream::app);

	// 每次open时都会确定文件模式
	ofstream out6;
	out6.open("file6.txt");
	out6.close();
	out6.open("file7.txt",ofstream::app);
	out6.close();

	ofstream of5("out1.txt", ofstream::app);
	vector<string> v3{ "word","vector","alholic","night" };
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		of5 << *beg << " ";
	}
	of5 << endl;// 会缓冲

	cin >> a;
	return 0;
}