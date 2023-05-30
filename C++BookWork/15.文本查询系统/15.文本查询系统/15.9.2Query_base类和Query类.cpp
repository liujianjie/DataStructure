#include <iostream>
#include <vector>
#include <memory>
#include <regex>

using namespace std;
/*
重要的是Query类的输出运算符
1.将调用指向Query_base的智能指针p，调用rep(),再根据动态内存得到p调用rep();
*/
using namespace regex_constants;
int main()
{
	int a;
	// 练习
	/*
	15.32:Query
	拷贝：q的地址给新的对象，并计数+1
	移动：指针能移动吗？能，给新对象后，自己指向null
	赋值：若有先析构左侧的q，计数-1，再将右侧的给它，再+1
	销毁：销毁q指向的Query_base对象并执行动态的派生类对象再向上析构，再指针计数-1

	Query_base
	15.33: 不ok
	就看它的若是指针引用，看动态对象来执行里面的成员

	若是静态对象就执行合成的拷贝控制函数，也没什么了
	拷贝：就拷贝对象
	移动: 不知道
	赋值：就先销毁再拷贝吗
	销毁：不知道
	*/
	cin >> a;
	return 0;
}
