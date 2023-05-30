#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#include <functional>
class Test1 {
public:
	Test1() = default;
	Test1(const Test1&) {
		cout << "Test1(const Test1)" << endl;
	}
	Test1(const string& s) {
		cout << "Test1(const string& s)" << endl;
	}
};

int main()
{
	int a;
	Test1 t2 = Test1("sdfsd");// 这个奇怪，直接构造对象,不会发生拷贝构造
	Test1 t1("sdfsdf");// 也是直接构造对象，应该是函数问题，不会发生拷贝构造
	Test1 t3 = string("sdfsd");
	Test1 t4(t1);// 显示调用拷贝构造函数 接受一个t1对象
	Test1 t5 = t2;// 隐式调用拷贝构造函数
	cout << "------" << endl;
	vector<Test1> ve1;
	ve1.push_back(string("sdfd"));
	ve1.push_back(t3);
	//ve1.push_back(t1);
	cin >> a;
	return 0;
}
