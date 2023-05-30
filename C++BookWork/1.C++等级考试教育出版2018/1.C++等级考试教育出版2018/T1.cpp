#include "T1.h"

int T1::val1 = 10;

void T1::fanwenval1() 
{
	//cout << val2 << endl;
	cout << "val1:" << val1 << endl;
}

void T1::say(int) const
{
	cout << "say(int)" << val1 << endl;
}

T1::T1()
{
}


T1::~T1()
{
}

