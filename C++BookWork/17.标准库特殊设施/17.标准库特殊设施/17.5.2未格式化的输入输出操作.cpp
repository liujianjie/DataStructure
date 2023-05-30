#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	//char ch;
	//while (cin.get(ch))
		//cout.put(ch);
	//while (cin.get(ch)) {
	//	/*cout << "peek:"<< cin.peek() << ",put(ch):";
	//	cout.put(ch);
	//	cout << endl;*/
	//	cin.unget();
	//	cout.put(ch);
	//	cout << endl;
	//}
	//char ch1, ch2, ch3;
	//cin >> ch1 >> ch2 >> ch3;
	//cout << ch1 << ch2 << ch3 << endl;
	//cin.unget();// 让输入流读取上一次最后读入的值
	//char firstChar, secondChar;
	//cin >> firstChar;
	//cout << firstChar << endl;
	//cout << "over:" << endl;

	//cin >> ch1 >> ch2 >> ch3;
	//cout << ch1 << ch2 << ch3 << endl;
	//cin.putback(ch1);// 让输入流读取上一次最后读入的值,是读取参数里的上一次值，不是最后一个
	//cin >> firstChar;
	//cout << firstChar << endl;
	//cout << "over:" << endl;

	// 
	//int ch2;
	//while ((ch2 = cin.get()) != EOF)// 返回int
	//{
	//	cout.put(ch2);
	//}

	// 流
	//char cr1[20];
	//while (cin.get(cr1,10,'z')) {//遇到z结束
	//	cout.write(cr1, 10);
	//	cout << cin.gcount() << endl;
	//}
	//char c[20];
	//cin.get(c, 10, '\n');
	//cout << c << endl;

	//char cr2[20];
	//while (cin.getline(cr2, 10, 'z')) {// 不知道为什么 放在while循环里会结束
	//	cout.write(cr2, 10);
	//	cout << cin.gcount() << endl;
	//}
	//char c1[20];
	//cin.getline(c1, 7,'z');//遇到z结束,输出前面的
	//cout << c1 << endl;

	//char cr3[20];
	//while (cin.read(cr3,10)) {//遇到z结束
	//	cout.write(cr3, 10);
	//	cin.peek();
	//	cout << " gcount :"<< cin.gcount() << endl;
	//}

	//char cr3[20];
	//while (cin.ignore(5,'a') && cin.read(cr3, 10)) {// 不清除ignore
	//	cout.write(cr3, 10);
	//	cin.peek();
	//	cout << " gcount :" << cin.gcount() << endl;
	//}

	// 
	//char ch1;
	//while ((ch1 = cin.get()) != EOF)
	//{
	//	cout.put(ch1);
	//}

	ifstream ist("12.3.1文本查询程序设计.txt");
	char ch3[20];
	while (!ist.eof()) {
	//while (ist.getline(ch3, 20,'\n')) {// 就单独10个字节，该如何循环呢
		ist.getline(ch3, 20, '\n');
		cout << ch3 << endl;
		//cout << "(" << ist.rdstate() << ")" << endl;
	}
	cout << "(" << ist.rdstate() << ")" << endl; // debug: failbit
	//string s1;
	//while (getline(ist, s1)) {
	//	cout << s1 << endl;
	//}
	/*
	练习：
	17.37: 不会 getline 恶心。
	17.38: 
	*/
	cin >> a;
	return 0;
}
