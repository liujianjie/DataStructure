#include "TestExternConst.h"

#include <iostream>
using namespace std;
//extern const int testconst;

TestExternConst::~TestExternConst()
{
}

int TestExternConst::gettestconst() 
{

	return testconsts;
}
