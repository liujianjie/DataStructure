#include <iostream>


using namespace std;
int main()
{
	int getchar = 10;
	int anotherval = 20;
	int &refval = getchar;
	//int &refval2;// 不行
	//&refval = anotherval;// 不行 无法重新引用

	// 赋值
	refval = 2; // 此时 getchar 为 2;
	refval = anotherval; // 此时 为赋值

	//int &refval2 = 10;// 不行 10 只是字面值，无法进行引用，引用的必须是对象
	//int &refaval = 0; 字面值为0也不行
	int &refval2 = refval;
	// 引用不能 定义 引用的引用


	cout << &refval2 <<endl; // 输出地址 并不是值
	cout <<&refval <<endl;		// 地址一样，因为 refval2 指向了refval指向的 对象，所以两个对象的地址一样，而地址就是getchar的地址
	cout <<&getchar<<endl;	// 

	// 不能引用不同的内置类型对象
	float floatval = 0.2f;
	//int &refval3 = floatval;
	float &refval3 = floatval;
	
	// 可以在一行定义多个引用
	int &refval4 = getchar, &refval5 = anotherval;

	//cout << getchar <<endl;

	int *p = 0;
	cin>>getchar;
	return 0;
}