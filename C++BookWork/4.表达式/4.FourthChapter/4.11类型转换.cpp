#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 隐式类型 转换
	int ival = 3.541 + 3;
	// 算术运算符就算了。要点：整形提升，无符号类型的运算对象

	// 4.11.2 其它隐式类型转换
	// 1.数组转换为指针
	// 2.转成bool类型
	// 3.转换为常量
	/// 类类型定义的转换
	string s, t = "a value";

	// 4.11.3 显式转换
	// 1.static_cast 只要底层不包含const都可以使用，底层const 引用的对象 或 指向对象是const
	double slope = static_cast<double>(10 / 3);
	cout << slope << endl;

	int tests0 = slope;
	int testsl = static_cast<int>(slope);// 将大的数据类型给小的数据类型 不会提示损失精度信息了

	// 对于编译器无法自动执行的类型转换有用
	int fetd = 10;
	void* fetdp = &fetd;
	int *fetdpsc = static_cast<int*>(fetdp);
	cout << *fetdpsc << endl;
	double *fetdpsc2 = static_cast<double*>(fetdp);// 必须确保转换后的类型就是指针所指的类型，不然 产生未定义的行为
	cout << *fetdpsc2 << endl;

	// 2.const_cast 去除常量性
	char twoneed = 'a';
	const char  *twochar1 = &twoneed;
	char twoc1 = 'A';
	// char *twocharp =  这个怎么不行了 西八
	const char *twocharp =  const_cast<char*>(twochar1);// 正确，但是通过twocharp写值未定义行为？ 使用了未初始化的局部变量“twochar1”，因为没有初始值
	//去除了常量性，可以进行写操作
	twochar1 = 0;
	twochar1 = &twoc1;
	cout << *twochar1 << endl;
	cout << *twocharp << endl;// twochar1 改不了不影响twocharp
	
	// 不能写值，因为twocharp 未初始化。当twochar1 未给予0 可以char *twocharp = 赋值时
	/*twocharp = &twoc1;
	cout << *twocharp << endl;*/

	const char *twochar2 = &twoc1;
	// error  这个只能改变类型
	//char *twocharq2 = static_cast<char*>(twochar2);
	static_cast<string>(twochar2);
	//const_cast<string>(twochar2);// error 这个只能改变常量属性

	// 3.reinterpret_cast 为运算对象的位模式提供较低层次上的重新解释 危险的，因为所指的真实对象不是本身了
	int threeint1 = 10;
	int *threeip = 0; //会抛出异常
	//int *threeip = &threeint1;
	char *threepc = reinterpret_cast<char*>(threeip);
	//string threestr(threepc); //严重错误。编译器不知道 threepc实则指向的是int类型
	//cout << *threepc << endl;
	//string threestr(10); 直接给值是可以查找错误的

	// 旧式的强制类型转换
	char *jiushipc = (char*)threeip;// 相当reinterpret_cast<char*>
	//string threestr2(jiushipc); //严重错误。编译器不知道 threepc实则指向的是int类型，但是这个没有。。
	getchar();
	return 0;
}