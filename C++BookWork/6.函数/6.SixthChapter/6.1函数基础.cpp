#include <iostream>

using namespace std;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
// 显示的定义空形参列表
void fact2(void) {}

// 局部静态对象
size_t count_calls() 
{
	static size_t ctr = 0;// 调用结束后，这个值依然有效？
	return ++ctr;
}
int main() 
{
	int getchar;
	//int zhi = fact(4);
	//cout << zhi << endl;
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << "\t" << endl;

	cin >> getchar;
	return 0;
}