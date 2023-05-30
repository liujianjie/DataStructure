#include <iostream>

using namespace std;
int main() 
{
	int getchar;

	// 2.5.1 类型别名
	typedef double wages;
	typedef wages base, *wagesp;//wagesp 是double*的同义词

	using Wages = double;
	wages hourly, weekly;

	// 二 指针、常量和类型别名
	int ccs = 0, uu = 0;
	//int const *testps = &ccs;// 这是指向对象为常量的指针
	const int* testps = &ccs;// 不是常量指针 
	testps = &uu;
	//*testps = 10;

	typedef char *pstring;
	// 书上说 pstring是指向字符的指针，const是修饰符，所以就为常量指针。。
	const pstring cstr = 0;//cstr是指向char的常量指针？？ pstring 是 char*的同义词 想不到呢 不知道怎么变得
	const pstring *otherpoints; // otherpoints是指针,它的对象是指向char的常量指针，是指针的指针
								//cstr = &c;//好吧
	char *const pointconst = 0;
	const char *const pointconst2 = 0;
	otherpoints = &cstr;
	otherpoints = &pointconst;
	//otherpoints = &pointconst2;//不行 因为otherpoints没有这个底层const

	char cchar = 'd';
	//cstr = &cchar; 不可 因为常量指针

	// test 换位置
	pstring const  cstr2 = 0;//cstr是指向char的常量指针？？ pstring 是 char*的同义词 想不到呢 不知道怎么变得
	pstring const  *otherpoints2; // otherpoints是指针,它的对象是指向char的常量指针，是指针的指针
								//cstr = &c;//好吧

	// 还是常量指针。。
	//cstr2 = &cchar;
	otherpoints = &cstr2;
	otherpoints2 = &cstr;
	otherpoints2 = &pointconst;

	// 2.5.2auto类型说明符
	int item1 = 10;
	float item2 = 30.0;
	auto item = item1 + item2;
	cout << item << endl;

	// (2)
	auto autois = 0, *autop = &autois;
	//auto autosz = 0, autopi = 3.14;//错，一个int 一个 float

	// 二。复合类型
	int autoj = 0, &autor = autoj;
	auto autoa = autor;//为autor引用的对象为类型

	

	// (2)会忽略顶层const 但底层const会保留下来
	 int autoi = 0;
	const int ci = autoi, &cr = ci;
	auto b = ci; // 忽略顶层 b是一个整数
	auto c = cr; // 忽略 c是整数
	auto d = &autoi;// d 是一个整型指针
	auto e = &ci; // e是一个指向整数常量的指针 没有消掉底层const

	// （3）如果想推断出的const为顶层const 明确指出就行
	const auto f = ci;

	// (4)可将引用的类型设为auto 与原来的初始化规则相同 适用
	auto &g = ci;
	//auto &h = 42;//error 因为不是const 引用
	const auto &j = 42;//true

	//(6) 一条语句类型保持一致，& *只从属于某个申明符
	auto k = ci, &l = autoi;// 整数  整数引用
	auto &m = ci, *p = &ci;// 常量引用 指向整型常量的指针
	//auto &n = autoi,  *p2 = &ci;//error i是int &ci是const int

	// 2.5.3 decltype类型指示符
	const int deci = 0, &decj = deci;
	decltype(deci) decx = 0; // decx的type为const int
	decltype(decj) decy = decx;// decy 是constint& 
	decltype(decj) z = 48;		//error:z是一个引用，必须初始化

	// 二。decltype 和 引用
	// 可以用表达式 返回表达式
	int twodeci = 42, *twodecp = &twodeci, &twodecr = twodeci;
	decltype(twodeci + 0) twodecb;
	decltype(*twodecp) twodecc = twodeci;// error twodecc是int& 并不是指针
	const decltype(*twodecp) twodecc2 = twodeci;// 前缀const忽视掉了吗？

	const int& test3 = 54;

	// (2)decltype 与表达式密切相关
	decltype((twodeci)) twodecd = twodeci; // error,twodecd是int& 必须初始化
	decltype(twodeci) twodece;//int

	twodecc = 45;
	twodecc2 = 60;
	twodecd = 90;

	cout << twodeci << endl;
	cin >> getchar;
	return 0;
}