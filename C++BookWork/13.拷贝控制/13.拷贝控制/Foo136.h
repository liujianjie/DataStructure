#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Foo136 {

public:
	Foo136 &operator=(const Foo136&) &;// ֻ������޸ĵ���ֵ��ֵ
	 //Foo136 &operator=(const Foo136&) &&;
	Foo136() = default;


	//Foo136 someMem() & const;// ��
	Foo136 someMem() &&;// �����ڿɸı����ֵ
	Foo136 someMem() const &;// �������κ����͵�Foo������const�ľ�ȷƥ�� ������ֵ��& ��const &&����ת��Ϊ�����,�ǵģ�����ֻҪдһ���Ϳ�

	Foo136 someMem() &;
	Foo136 someMem() const &&;

	Foo136 sorted() && ;
	Foo136 sorted() const &;
	vector<int> data;
private:
};
