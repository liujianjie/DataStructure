#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;
/*
1.异常后程序后面的代码不在执行，所以若自己管理动态内存，delete代码不执行，若智能指针函数结束时还是会执行
2.很多类都定义了析构函数清理对象使用的资源，不是所有类都有这种良好的定义，特别是为c和c++两种语言设计的类，通常需要显式的释放
	就是调用具体的方法来释放
3.使用智能指针管理，来释放一个内存 需要定义一个函数来代替delete。必须能够完成对shared_Ptr中保存的指针进行释放的操作
4.可用lambda也可以用函数自定义删除
*/

void deletefunc(int *p) 
{
	cout << "start deletefunc" << endl;
	delete p;
}
int main()
{
	int a;
	int *p1 = new int(2);
	shared_ptr<int> sp1(p1, deletefunc);
	sp1.reset();

	// 练习
	// 
	int *p2 = new int(3);
	shared_ptr<int> sp2(p2, [](int *p)->void { cout << "lambda" << endl; delete p; });
	sp2.reset();
	cout << *p2 << endl;

	cin >> a;
	return 0;
}
