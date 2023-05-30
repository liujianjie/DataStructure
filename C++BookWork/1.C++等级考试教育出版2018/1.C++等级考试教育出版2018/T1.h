#pragma once

#include <iostream>
using namespace std;
class T1
{
public:
	T1();
	~T1();

	void say();

	void say(int) const;
	
	static int val1;
	int val2;
	static void fanwenval1();
};
inline void T1::say()
{
	cout << "T1::say();" << endl;
}
