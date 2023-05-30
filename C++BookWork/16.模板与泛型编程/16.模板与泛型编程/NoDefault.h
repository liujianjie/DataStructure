#pragma once
#include <iostream>
using namespace std;
class NoDefault
{
public:
	NoDefault(int s):val(s) {}
	~NoDefault();
	int val;
};

