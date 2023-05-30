#include <iostream>
#include <string>
#include <iterator>
#include <cstring>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::begin;
using std::end;
using std::strlen;
using std::strcmp;
using std::strcat;
using std::strcpy;

constexpr int getsize() 
{
	return 1;
}

 int getsize2()
{
	return 1;
}

int main() 
{
	int right = 2;
	cout << (right >> (-30)) << endl;
	int getchar;
	// 3.5.1定义和初始化内置数组
	int cnt = 42;
	constexpr unsigned int sd = 42;
	//int onearr[cnt];// 错误 cnt 不是常量表达式
	int onearr2[42];// 字面值是常量
	int *onearr3[sd];// 是常量 含有整型指针的数组
	string onearr4[getsize()];// 只有当函数设置为constexpr才有效
	//string onearr5[getsize2()];// 不可
	//auto onearr5[1];// 不可存在auto关键字
	//string &onearr6 = onearr4; 不可引用
	cout << onearr2[2] << endl;// 未定义的值
	// 二 显式初始化数组元素
	const unsigned twosz = 10;
	int twoarr1[twosz] = { 0, 1, 2 };
	int twoarr2[] = { 0, 2, 3 };
	int twoarr3[5] = { 0, 1, 2 };//剩下两个0 0 
	string twoarr4[3] = { "hi","bye" };
	//int twoarr5[2] = { 0, 1, 2 };//error 

	// 三字符数组的特殊性
	char threea1[] = { 'c','+','\0' };
	char threea2[] = "C++";// 自动添加字符串结束的空字符
	//char threea3[6] = "Daniel";// erorr没有足够的空间

	// 不允许拷贝和赋值
	int foura[] = { 0, 1, 2 };// 含有3个整数的
	//int foura2[] = foura;// Error
	//int foura2[] = {foura};
	//int foura3[] = foura;// 不允许初始化 也不能 赋值

	// five 理解复杂的数组声明
	int *fivea1[10]; // 这个是可以存放10个整形指针的数组
	//int &fivearef2[10];error 不存在引用的数组
	// 从内到外来读
	// fivea2 指向一个含有10个整形的数组
	int(*fivea2)[10] = &twoarr1;// 指向的数组可以不用列表初始化 但是必须大小为10
	// fivea3 引用一个含有10个整形的数组
	int(&fivea3)[10] = twoarr1;//

	//多个修饰符 意思是：引用一个可以存放10个整形指针的数组
	int *(&fivea4)[10] = fivea1;

	cout << onearr2[1] << endl;

	// 3.5.2访问数组的元素 下标为size_t类型cstddef 文件中
	unsigned int ftwoscore[11] = {};
	unsigned int grade;
	//while (cin >> grade) 
	//{
	//	++ftwoscore[grade / 10];// auto inde = grade / 10; ftwosocre[inde] = ftwoscore[inde] + 1;
	//}
	for (auto i : ftwoscore)
		cout << i;
	cout << endl;

	// 3.5.3指针和数组
	int fthreearr1[] = { 87,1,2,3,4 };
	cout << *(&fthreearr1[0])<<"3"<< endl;
	int fthreetarr[10] = {};
	cout << *(&fthreetarr[11]) << "3" << endl;// 超过的未定义值 可以访问。。
	int *fthreep = &fthreearr1[0];
	int *fthreep2 = fthreearr1;// 指向数组首元素的指针
	//auto
	auto fthreearr2(fthreearr1);// 是一个整形指针，指向第一个元素
	cout << *fthreearr2 << endl;

	// 用decltype 不同 不是指针
	decltype(fthreearr1) fthreearr3 = {87,1};// 与fthreearr1 维度一样 值自己定义，但如果超过了未定义的值
	cout << fthreearr3[3] << endl;// 第一个值 fthreearr3得到地址获取为一个指针对象 再*解引用得到值

	// 二 指针也是迭代器
	int fttarr1[] = {0,1,2,3,4,5};
	int *fttp = fttarr1;
	int *ftte = &fttarr1[6];
	while (fttp != ftte) 
	{
		cout << *fttp;
		fttp++;
	}
	cout << endl;

	int *fttp2 = begin(fttarr1);
	int *ftte2 = end(fttarr1);

	while (fttp2 != ftte2) 
	{
		cout << *fttp2;
		*fttp2++;
	}
	cout << endl;

	// 三.指针运算
	int fttharr1[] = { 1,2,3 ,4,5};
	int *ftthip1 = fttharr1;
	int *ftthip2 = ftthip1 + 4;// 指向最后一个 fttharr1[4] 等价为（fttharr1 + 4）;
	int *ftthip3 = fttharr1 + 5;// 指向尾后元素超出范围仅仅是未定义
	cout << *ftthip1 << endl;
	cout << *ftthip2 << endl;
	cout <<"*ftthip3" << *ftthip3 << endl;
	cout << "*ftthip3" << fttharr1[5] << endl;
	int *ftthip4 = fttharr1 + 5;
	auto ftthe = end(fttharr1) - begin(fttharr1);
	cout << ftthe << endl;

	//能用关系运算符进行比较
	constexpr size_t sz2 = 5;
	int *ftthb2 = fttharr1, *ftthe2 = fttharr1 + sz2;
	while (ftthb2 < ftthe2) {
		cout << *ftthb2;
		++ftthb2;
	}
	cout << endl;
	int *ftthnullptr = 0;
	cout << ftthnullptr + 0 << endl;

	// 四 解引用 和 指针运算的交互
	int ftfarr1[] = { 0,2,3 };
	int last = *(ftfarr1 + 1);//等价 ftfarr1[2]
	cout << last << endl;
	last = *ftfarr1 + 1;
	cout << last << endl;//不同

	//五：指针和下标
	int ffarr1[] = { 10,2,3,4,6,7 };
	int ffi = ffarr1[2]; // ffarr1[2]得到（ia+2）所指的元素
	int *ffp = ffarr1;//
	int ffi2 = *(ffp + 2);//等价于ffarr1[2]
	cout << ffi << endl;
	cout << ffi2 << endl;

	int *ffp2 = &ffarr1[2];
	int ffj = ffp2[1];//等价 *(p+1) 即指向了 ffarr1[3];
	int ffk = ffp2[-2];//等价 *(p-2) 即指向了 ffarr1[-1]; 负的下标为第一个元素

	cout << ffj <<endl;
	cout << ffk << endl;

	// 3.5.4C风格字符串
	char ffourca[] = { 'c','+','+','\0'};
	cout << strlen(ffourca) << endl;// 若没有空字符到也不会出很大的错，只是长度错了，

	// 比较字符串
	const char ffourca2[] = "A String Examplez";
	const char ffourca3[] = "A String Examples";
	 char ffourca4[50] = "A String Examplez";//不能为const
	 char ffourca5[] = "A String Examples";
	 string str1 = "A String Examplez";//不能为const
	 string str2 = "A String Examples";
	cout << strcmp(ffourca2, ffourca3) << endl;

	// 目标字符串的大小由调度者指定
	//strcat(str1, str2); //不行。。
	cout << ffourca4 << endl;
	//strcpy(str1, str2);
	cout << ffourca4 << endl;

	// 3.5.5与旧代码的接口
	// 一：混用string对象和c风格字符串
	string ffiveones("hello");
	//char *ffiveones2 = ffiveones;//error
	const char *ffiveones3 = ffiveones.c_str();//true
	cout << ffiveones3 << endl;
	ffiveones = "hellos";
	cout << ffiveones3 << endl;//会变

	// 二 使用数组初始化Vector对象
	int ffivetwo[] = { 0,1,2,3,4,5 };
	vector<int> ffivevec(begin(ffivetwo), end(ffivetwo));
	vector<int> ffivesubvec(&ffivetwo[1], &ffivetwo[4]);
	for (auto a:ffivesubvec) {
		cout << a << endl;
	}

	// 3.6多维数组
	int tsixia[3][4];
	int tsixia2[10][20][30];
	//int tsixival;//未定义
	string tsixstr;//隐式转换
	cout << tsixstr << endl;

	//二 多维数组的初始化
	int tsixtia[3][4] = { {0,1,2,3,},{4,5,6,7},{ 4,5,6,7 } };
	int tsixtia2[3][4] = { 0,1,2,3, 4,5,6,7  };

	int (&tsixtia3)[4] = tsixtia2[1];
	for (auto a: tsixtia3) {
		cout << a;
	}
	cout << endl;
	for (size_t i = 0; i != 3; ++i) 
	{
		for (size_t j = 0; j != 4; ++j) {
			cout << tsixtia[i][j];
		}
	}
	cout << endl;

	// important 用范围for
	for (const auto &row : tsixtia) 
	{
		for (auto col : row) 
		{
			cout << col;
		}
	}
	cout << endl;

	for ( auto &row : tsixtia)
	{
		for (auto &col : row)
		{
			cout << col;
		}
	}
	cout << endl;

	int df = 0;
	for (const auto row : tsixtia)
	{
		cout << row << " ";
		cout << &tsixtia[df];
		/*for (auto col : row)
		{
			cout << col;
		}*/
	}
	cout << endl;

	// 3.指针与多维数组
	int(*dwp)[4] = tsixtia;
	dwp = &tsixtia[2];
	/*cout << dwp <<"test"<< endl;
	cout << dwp+1 << "test" << endl;
	cout << *dwp << "test" << endl;
	cout << *(dwp+1) << "test" << endl;
	cout << *dwp + 2 << "test" << endl;
	cout << **dwp << "test" << endl;
	cout << *(*dwp) << "test" << endl;
	cout << (*dwp) + 2 << "(*p) + 1" << endl;
	cout << "\n\n" << endl;*/
	for (auto p = tsixtia; p != tsixtia + 3; ++p) {
		/*cout << "\n" << endl;
		cout << p << "test2" << endl;
		cout << p+1 << "test2" << endl;
		cout << *p << "test2" << endl;
		cout << *(p + 1) << "test2" << endl;
		cout << *p + 1 << "test2" << endl;
		cout << **p << "test2" << endl;
		*/
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q ;
	}
	cout << endl;

	for (auto p = begin(tsixtia); p != end(tsixtia); ++p)
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q;
	cout << endl;

	//
	using int_array = int[4];
	typedef int int_array[4];
	for (int_array *p = tsixtia; p != tsixtia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q;
	cout << endl;

	/*for (auto a : tsixtia2) {
		cout << a;

	}
	cout << endl;*/
	cin >> getchar;
	return 0;
}