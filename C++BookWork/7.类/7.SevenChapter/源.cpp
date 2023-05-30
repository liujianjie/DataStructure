#include <iostream>
#include <string>
#include "T1.h"
#include "Sales_data.h"
#include "Screens.h"
#include "Screen.h"
#include "XX.h"
#include "NoDefault.h"
#include "Data.h"
#include "Debug.h"
#include "Account.h"

using namespace std;
// 不能在h文件中声明和定义分离 或者放在一起在h文件的全局中
Screen::poss verifys(Screen::poss);
Screen::poss verifys(Screen::poss po) {
	return po * 2;
}
void Screen::setHeight(poss var)
{
	// var: 参数
	// height：类的成员
	// verify: 全局函数
	height = verifys(var);
}
int main() 
{
	int b;

	//Sales_data total; // 保存当前求和结果的变量
	//Sales_data trans; // 保存下一条交易数据的变量

	Screens myscreen;
	char ch = myscreen.get();
	const Screens myscreen2;
	char ch2 = myscreen.get(0, 0);
	//myscreen2.some_member2();// const 成员只能调用const成员函数
	cout << ch << "---"<< ch2;

	// 7.3.2
	myscreen.move(4, 0).set('#');

	myscreen.move(4, 0);
	myscreen.set('#');

	Screens temp = myscreen.move(4, 0);
	temp.set('#');

	//myscreen.display().set('*'); 不可 常量引用

	Screens myScreen(5, 3);
	const Screens blank(5, 3);
	myScreen.set('#').display(cout);
	blank.display(cout);

	dofriend();
	T1 *t1 = new T1();
	//t1->say();
	cout << t1->a << endl;;
	// 7.3.3 类类型 error
	Screens myscreen3(3, 1);
	myscreen3.dummy_fcn(3);
	cout << myscreen3.getCursor() << endl;

	Screen sc;
	sc.setHeight(100);
	cout << sc.height << endl;

	XX x1(2);
	cout << "x1.i = " << x1.i << "x1.j = " << x1.j << endl;

	Sales_data sl1("7.5.3");
	cout << sl1.getBookNo() << endl;

	//Sales_data s12(cin);

	NoDefault no;

	// 7.5.3 二
	Sales_data obj();// 是一个函数

	// 7.5.4
	string null_book = "9-999-99999-9";
	//sl1.combine(null_book);
	
	//print(cout , sl1);
	 
	//sl1.combine("9-999-99999-9");// 只允许一步
	//sl1.combine(string("9-999-99999-9"));
	//sl1.combine(Sales_data("9-999-99999-9"));

	//sl1.combine(cin);// 输入一个实例 创建一个临时对象
	sl1.combine(Sales_data("12", 3, 4));// 显示

	// 7.5.4 四 explicit是影响不能隐式初始化
	Sales_data item1(null_book);// 直接初始化 因为不是隐式，并且声明explicit也无影响
	//Sales_data item2 = null_book;// 拷贝初始化也是隐式

	// 7.5.4 五 explicit 不阻止显示的强制进行转换
	item1.combine(Sales_data(null_book));
	//item1.combine(static_cast<Sales_data>(cin));
	B bb;

	// 7.5.5 聚合类
	Data val1 = { 0, "anna" };
	cout << val1.s << endl;
	//Data val1 = { "anna", 0 };
	Data val2 = { 0 };
	cout << val2.s << endl;
	//Data val1 = { 0, "anna" ,0};

	// 7.5.5 二
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
	{
		cerr << "print appropriate error messages" << endl;
	}
	constexpr Debug prod(false);
	if (prod.any()) {
		cerr << "print an error message" << endl;
	}

	double r;
	r = Account::rate();
	cout << r << endl;

	Account ac1;
	Account *ac2 = &ac1;
	r = ac1.rate();
	cout << r << endl;
	ac2->rate(4);
	r = ac2->rate();
	cout << r << endl;
	cin >> b;
	return 0;
}
class Link_screen {
	Screens window;
	Link_screen *next;
	Link_screen *prev;
};