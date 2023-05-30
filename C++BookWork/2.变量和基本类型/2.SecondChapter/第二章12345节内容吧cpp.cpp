#include <iostream>

using namespace std;


int chushi;
string emptyss = "d";

// 2.2.3标识符
char _d;
char d;
char __d__;
char _D;

int main()
{
	int getchar;

	// 2.2.1 初始化 不是 赋值
	int un = 0;
	int un2 = { 0 };
	int un3{ 0 };
	int un4(0);

	long double ld = 3.14435643534;
	//int a{ ld }; // 不行 存在信息丢失隐患
	//int b ={ ld };
	int a = ld;

	//默认初始化 在函数外
	cout << chushi << endl; // 默认为0
	//当在函数体内的 会报错 但可以声明
	int ab;
	//cout << ab << endl;
	//string str = "ddd";
	//cout << emptyss << endl;


	// 2.2.2声明与定义
	extern int i; // 声明 而非定义
	int j;
	/*extern*/ int ii2 = 10;//为定义？不能加extern？ 错了

	cin >> getchar;
	return -1;
}