#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
	cout << "void foo(const T &t, const Args& ... rest)" << endl;
	cout << sizeof...(Args) << endl;// ���Ͳ���
	cout << sizeof...(rest) << endl;// ��������
}
int main()
{
	int a;

	int i = 0; double d = 3.14; string s = "how now borwn cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	/*
	��ϰ��
	��Ŀ�����Ͳ�������Ŀ�ͺ�����������Ŀ��һ����
	*/
	cin >> a;
	return 0;
}


