#include <iostream>
#include "TestExternConst.h"
#include <string>

using namespace std;

int testconstexprval = 20;
int m = 0;
constexpr int n = 42;

int getss()
{
	return 20;
}
int main()
{
	int getchar;

	// 2.4 const
	const int bufsize = 512;
	//bufsize = 100;//error
	int bufsize2 = bufsize; // true 可以赋值

	// Test Extern Const
	//TestExternConst te;
	//cout<< te.gettestconst() <<endl;

	// 2.4.1 const的引用
	int ri = 1024, rri = 32;
	int &ri2 = rri;
	ri2 = 32;
	cout << "ri2 : "<< ri2 << endl;
	const int &rl = ri;//
	//rl = 42;//error 这是因为r1 = 42 是将r1指向的ri值改变为42，而是const引用，不能，不是与const int &r1 = 42相同，这是初始值，后者是改
	//int &r2 = ri; // error

	// 二.初始化对const的引用
	// const 引用
	int testzhi = 45;
	const int &testzimian = 432; //允许
	//testzimian = &testzhi;

	int twoi = 42;
	const int &twori = twoi;// 允许

	double twoval = 234;
	const int &tworis = twoval;// 一个中间临时变量 允许的
	//tworis = 10; error
	twoval = 20;
	cout << tworis << endl;// 得到的是234 因为临时变量没有改变成20

	//test simply 
	int testi = 42;
	int &testri = testi;
	testi = 20;
	cout << testri << endl; // 可以获取为20

	// 2.4.2 指针与const
	const double pi = 3.14;
	//double *ptr = &pi;//error
	const double *ptr = &pi;
	//*ptr = 45.0; error
	//pi = 34.0;

	// 另外的指针的类型必须与其所指对象的类型一致 
	double twodval = 3.14;
	ptr = &twodval;//ptr 是const twodval不是const
	twodval = 34;
	

	double testtransval = 3.14;
	//const int *testtranrval = &testtransval; fal 不知道为什么

	// 二。const指针
	int twovals = 0;
	int *const twoconstvals = &twovals;
	const double twopis = 3.14;
	const double *const twopip = &twopis;// 不可缺少最左边的const

	int testtransvals = 10;
	//twoconstvals = &testtransvals; 不可，因为常量指针
	twovals = 10;
	cout << *twoconstvals << endl;
		//twopis = 40;


	// 2.4.3 顶层指针与底层指针
	int j = 0;
	int *const plj = &j;// 顶层
	const int cj = 43;//顶层
	const int *pj2 = &cj;//底层 指向的对象为const
	const int *const pj3 = pj2;//顶层和底层
	const int &rj = cj;// 底层 用于声明引用的都是底层？ 因为不能常量引用，引用不是一个对象
	j = cj;
	pj2 = pj3;

	//int *pj = pj3;//error p3有底层定义
	pj2 = pj3;
	pj2 = &j; // int* 能转换为const int *
	//int &rjs = cj;//error
	const int &rjs2 = j;

	//2.4.4 constexpr 和 常量表达式
	const int max = 20; // 常量表达式 值不会改变 并且编译过程中就能得到的计算结果的表达式
	const int limit = max + 1;// 是
	int staff = 25;//不是常量表达式 27 字面值是常量表达式，但是staff不是 因为不是const
	const int sz = getss(); //不是 因为不是在编译过程中 是在运行过程中得到的值

	// 二 constexpr变量
	constexpr int inf = 20; // 变成常量表达式了
	//constexpr const int szs = getss();//是常量表达式了 但又没有编译过程的初始值 又不行

	// 三 字面值类型 string 不是，指针 引用是
	//constexpr string str = "dd";//error 不属于字面值
	//constexpr const int *testconstexprp2 = &max; 不可以
	
	// 受到严格限制，0 nullptr 固定存储地址
	constexpr const int *testconstexprp = 0;
	constexpr const int *testconstexprp2 = &testconstexprval;// 固定地址

	//constexpr const int &testconstexprp3 = max;// 也不可以
	constexpr const int &testconstexprp3 = testconstexprval;// 可以

	// 四 指针和constexpr
	const int *points = nullptr;	// p 是一个指向整形常量的指针
	constexpr int *qoints = nullptr;// q是指向一个指向整数的常量指针 与指针指向的对象无关，关键在于constexpr 把它所定义的对象置为了顶层const

	//（2）可以指向非常量或者常量
	
	constexpr const int *pn = &n;// 常量指针，指向整型变量n
	constexpr int *pm = &m; // 常量指针，指向整数m

	cin >> getchar;
	return 0;
}
