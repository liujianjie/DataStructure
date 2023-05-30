#include <iostream>
using namespace std;
/*
思路：
1.先比较x与y，将小的数放在x上
2.再比较y与z
若y<z
	则正好输出x y z
否则
	x > z
		则输出 z x y
	否则
		输出x z y, （因为x < y, y > z)

通过更改输出顺序可以使得从小到大顺序输出，从而达到比较次数较少
最佳情况比较次数为2，最坏为3
*/
void main()
{
	int x, y, z;
	cin >> x >> y >> z;
	if (x > y) { // x 与 y 中最小的数放在x上
		x = x + y;
		y = x - y;
		x = x - y;
	}
	if (y > z) {
		// 更改输出顺序可以使得从小到大顺序输出
		if (x > z) {
			cout << z << " " << x << " " << y << endl;
		}
		else {
			cout << x << " " << z << " " << y << endl;
		}
	}
	else {
		cout << x << " " << y << " " << z << endl;
	}
}