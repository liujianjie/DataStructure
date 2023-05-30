#include "TestHeadAndUsing.h"
#include "FourthEd.h"
void TestHeadAndUsing::TestOutMsg()
{
	using namespace FourthEd;
	cout << "TestOutMsg():" << FourthEd::v1<< endl;
}