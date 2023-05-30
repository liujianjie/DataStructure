#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Foo {
public:
	static std::size_t count() { return ctr; }
	void Bar() {
		cout << "原始版本Bar()" << endl;
	}
private:
	static std::size_t ctr;
};

template<>
void Foo<int>::Bar()
{
	cout << "特例化Bar" << endl;
}

template <typename T>
size_t Foo<T>::ctr = 0;