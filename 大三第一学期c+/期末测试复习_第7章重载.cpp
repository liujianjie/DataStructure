#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double d1 = 12.12312321412;

	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << d1 << endl;

	return 0;
}