#include <iostream>
#include <string>
#include "Phone.h"
#include "Record.h"
#include "Account.h"
using namespace std;

 #pragma warning(disable:4996);
void print(const char *cp) {
	cout << "print(const char *cp)" << endl;
}

void print(const int *beg, const int *end) 
{
	cout << "print(const int *beg,const int *end)" << endl;
}
void print(const int ia[], size_t size) {
	cout << "print(const int ia[],size_t size)" << endl;
}

int lookup(char &r) 
{
	return 0;
}
int lookup(string &p)
{
	return 0;
}
int lookup(int &name)
{
	return 0;
}
// note: 形参一样，但是返回值不一样的不是重载
//char lookup(int &c) 
//{
//
//}

Record lookup(Phone) { Record r; return r; }
//Record lookup(const Phone) { Record r; return r; }

Record lookup(Phone*) { Record r; return r; }
//Record lookup(Phone* const) { Record r; return r; } 也不行。


Record lookup(Phone&) { Record r; return r; }
Record lookup(const Phone&) { Record r; return r; }// 新函数
Record lookup(Account*) { Record r; return r; }// 新函数
Record lookup(const Phone*) { Record r; return r; }// 新函数

const string &shorterString(const string &s1, const string &s2) 
{
	return s1.size() <= s2.size() ? s1 : s2;
}

// 
string &shorterString(string &s1, string &s2) 
{
	auto& r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

// 6.4.1
string read();
//void prints(const string &);
//void prints(double);
void footBars(int ival)
{
	bool read = false;
	// error 因为bool read，所以不行的
	//string s = read();
	//void prints(int);
	// error 因为了里面的覆盖了外面的prints，不能string
	//prints("Value: ");
	//prints(ival);
	//prints(3.14);
}
// 将上面3个放在同一个作用域表示都可见
//void printt(const string&);
//void printt(double);
//void printt(int);
void fooBar2(int ival)
{
	//printt("Value:");
	//printt(ival);
	//printt(3.14);
}
typedef string::size_type sz;// 
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ')// (, int i);一旦某个参数有了默认参数 它后面的也必须是默认参数，否则不可以
{
	string s;
	return s;

}
string screen2(sz, sz, char = ' ');

// 默认实参声明 不能修改一个已经存在的默认值
//string screen2(sz,sz,char = '*');//重复声明

// 有点不懂，明明都是默认实参，却不能把char放在后面？好吧 char不是默认实参？

/*
	1.好吧，我发现问题所在了，编译器报错是因为第三个参数char 不是默认实参
	2.但是，上面定义了screen2的默认实参，是可行的
	3.所以不能像上面那个一样修改一个已经存在的默认值，只能修改不是默认实参的参数
*/
string screen2(sz, sz = 3, char);
/*
string screen2(sz = 2, sz = 1, char);这一组是不行的sz = 3不能再声明，只能再添加默认值
*/
string screen2(sz = 2, sz, char);

sz wd = 80;
char def = ' ';
sz ht() {
	return 2;
}

string screen3(sz  s1 = ht(), sz s2 = wd, char ch = def) {
	cout<< s1 <<" "<< s2 << " "<<ch;
	return " need return window value or error";
}
void f2();
int main() 
{
	int getchar;
	int j[2] = {0,1};
	print("hello world"); // 调用print(const char*)
	print(j, end(j) - begin(j));
	print(begin(j), end(j));	// 函数重载一定程度上减轻程序员起名字、记名字的负担
	
								
	// 定义重载函数
	int a1;
	lookup(a1);

	// 判断两个形参的类型是否相异
	// 有时候两个形参列表看起来不一样，但实际上是相同的
	//Record lookup(const Account &acct);
	//Record lookup(const Account &); 只是省略了形参的名字

	/*typedef Phone Telno; Telno是Phone的别名
	Recorde lookup(const Phone&);
	Recorde lookup(const Telno&);*/

	// 顶层const不影响传入函数的对象
	
	// 如果形参是某种类型的指针或者引用，可以区分其指向是常量对象还是非常量对象可以实现函数重载
	// 1.当传入常量形参时，不能变化成其它类型，所以只能匹配常量形参
	// 2.当传入非常量形参时，可以变化成常量形参，因此那4个会都可以匹配无常量的对象或对象指针，但是220页 会讲优先匹配
	
	// const_cast 和重载
	
	// 调用重载的函数

	// 6.4.1重载与作用域
	
	// 6.5.1默认实参
	
	// 调用具有默认实参的函数，参数可以省略也可以重新用户自定义值
	// 1.省略即是调用这个默认参数
	/*string window;
	window = screen();
	window = screen(66);
	window = screen(66, 256);
	window = screen(66, 256, '#');*/
	// 2.默认实参只填补尾部参数，只能省略尾部的参数
	//screen(,,'?');//error
	// ? 先转为int，然后再转为string,就是说参数只从从左到右匹配
	//screen('?');//true ,调用screen('?',80,' ')

	// 二：默认实参声明：screen2

	// 三：默认实参初始值
	// 1.局部变量不能作为默认实参。只要表达式的类型能够转换成形参所需的类型，该表达式就能作为默认实参

	/*sz wd = 80;
	char def = ' ';
	sz ht();*/

	//string screen3(sz = ht(), sz = wd, char = def);
	// 记住screen3需要return值 因为window需要接收，不然会报错
	string window = screen3();//调用screen3(ht(),80,' ')

	f2();



	cin >> getchar;
}
void f2() 
{
	def = '*';// 改变了默认实参的值？
	sz wd = 100;// 隐藏了外层定义的wd，但是没有改变默认值，不影响外层wd
	string window = screen3();// screen(ht(),80,'*');
}
