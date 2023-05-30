#include <iostream>
using namespace std;

void Say(int i);
int main()
{
	Say(2);
	return 0;
}

void Say(int i) {
	cout << "Say()" << endl;
}