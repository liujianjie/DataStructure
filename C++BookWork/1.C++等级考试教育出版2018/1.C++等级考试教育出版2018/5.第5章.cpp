#include <iostream>
using namespace std;
void hon(int n, char x,char y, char z) {
	if (n > 0) {
		hon(n-1, x, z, y );
		cout << "MOVE" << n << " : " << x << "->" << z << endl;
		hon(n - 1, y, x, z);
	}
}
int main() 
{
	int a;
	hon(4, 'A', 'B', 'C');

	cin >> a;
	return 0;
}