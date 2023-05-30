#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;
//list array deque forward_list 没有 只有vector和string
int main()
{
	int a;
	vector<int> v1;
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;
	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		v1.push_back(ix);
	}
	cout << "i1:size:" << v1.size()
		<< "capacity:" << v1.capacity() << endl;
	// 小了什么也不做
	v1.reserve(15);
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;
	v1.reserve(50);
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;
	while (v1.size() != v1.capacity())
		v1.push_back(0);
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;
	//刚好用完vector的预留空间，不会自动增长，需要再加一个
	v1.push_back(0);
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;
	v1.shrink_to_fit();
	cout << "v1:size:" << v1.size()
		<< "capcity:" << v1.capacity() << endl;// 请求成功就退回内存
	cout << v1.max_size() << endl;
	
	list<int> li1;
	array<int, 10> ar1;
	deque<int> de1;
	//de1.re
	forward_list<int> f1;
	//f1.reser
	cin >> a;
	return 0;
}