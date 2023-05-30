#include <iostream>

using namespace std;

/**
	第一章的内置类型那些测试
*/
int main()
{
	int getcahr;
	//cout << getcahr << endl;
	//char i = 356;
	//cout << i << endl; 
	//unsigned char  c = 259;
	//cout << (int)c << endl; 去模数值总数256 是的

	//signed char c2 = 2588; // 有符号，则255 最大值 若char占 1字节
	//cout << (int)c2 << endl;

	/*int  i = -10;

	if (i)
		cout << "true" << endl;*/

		/*unsigned u = 30;
	int i = -42;
	cout << u + i << endl;//带符号的为负数先转为无符号类型值 再计算

	unsigned u2 = 10;
	cout << u2 - u << endl;// 无符号是不会是负数的 会去模 应该是和char 上面那个一样，把负数补1 取二进制的数 模int最大的数值 也许是 总和 的模
	*/
	unsigned int  i = -1,i2 = -32;
	cout << i << endl;
	cout << i2 << endl; // 


	cin >> getcahr;
	return -1;//
}