#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Foo136 {

public:
	Foo136 &operator=(const Foo136&) &;// 只能向可修改的左值赋值
	 //Foo136 &operator=(const Foo136&) &&;
	Foo136() = default;


	//Foo136 someMem() & const;// 错
	Foo136 someMem() &&;// 可用于可改变的右值
	Foo136 someMem() const &;// 可用于任何类型的Foo但还是const的精确匹配 就是左值，& ，const &&都会转换为这个吧,是的，所以只要写一个就可

	Foo136 someMem() &;
	Foo136 someMem() const &&;

	Foo136 sorted() && ;
	Foo136 sorted() const &;
	vector<int> data;
private:
};
