#include <iostream>
#include <initializer_list>
#include <string.h>
#include <string>
#include <exception>
using namespace std;


void error_msg(initializer_list<string> li) 
{
	for (auto beg = li.begin(); beg != li.end(); ++beg) 
	{
		cout << *beg << " ";
	}
	cout << endl;
}
void error_msg(int status,initializer_list<string> li)
{
	cout << status << ":";
	for (const auto &elem :li)
	{
		cout << elem << " ";
	}
}
void foo(int a, ...) 
{
	cout << "foo  ";
}
void foo2(int b...) 
{
	cout << "foo2  ";
}
void foo3(...) 
{
	cout << "foo3  ";
}
//void foo4(int a...int b) {} ������
int main(int argc, char *argv[]) 
{
	int getchar;
	cout << argv[0] << endl;

	// initializer_list Ҳ��һ��ģ�����ͣ�����˵���б�������Ԫ�ص�����
	initializer_list<string> ls;
	initializer_list<int> li;

	//
	string s1 = "sfsa";
	string s2 = "sdfadf";
	int tests1 = 3;

	if (s1 != s2)
		error_msg(43,{"functionX", s1,s2});
	else
		error_msg(0,{ "functionX", "OKAY"});

	// ʡ�Է��β�,Ϊ�˱���C++�������ĳЩ�ر��C��������õ�
	foo(3);
	foo2(5,"D", "S", "D", s1, s2);
	foo3(3, "S", "D", s1, s2);



	cin >> getchar;
	return 0;
}