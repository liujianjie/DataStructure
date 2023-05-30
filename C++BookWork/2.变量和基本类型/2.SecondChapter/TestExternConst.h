#pragma once

#include <iostream>
using namespace std;

//extern const int testconsts = 10;//√ª”–”√
const int testconsts = 10;
class TestExternConst
{
public:

	TestExternConst() 
	{
		cout << testconsts << endl;
	}
	~TestExternConst();
	int gettestconst();
};

