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
	void someMem() &&;// �����ڿɸı����ֵ
	void someMem() const &;// �������κ����͵�Foo������const�ľ�ȷƥ�� ������ֵ��& ��const &&����ת��Ϊ�����,�ǵģ�����ֻҪдһ���Ϳ�

	void someMem() &;
	void someMem() const &&;

	//Foo136 sorted() && ;
	//Foo136 sorted() const &;
	vector<int> data;
private:
};
