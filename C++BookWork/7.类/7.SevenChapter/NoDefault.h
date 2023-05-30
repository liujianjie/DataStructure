#pragma once

#include <string>
using namespace std;
class NoDefault
{
public:
	NoDefault();
	~NoDefault();

	NoDefault(const std::string&);

	int num1;
	int num2;
};

struct A {
	NoDefault my_mem;
};
//A a;
struct B {
	B() {}
	NoDefault b_member;
};