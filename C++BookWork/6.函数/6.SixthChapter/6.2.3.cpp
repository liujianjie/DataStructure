#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void fcn(const int i) {}
void fcn(int i);// 可以这样，但是不能void fcn(int i){} 因为上面已经定义了，并且有了主体。

// const string s1，可以接受const对象的string，以及不是const对象的string，但是如果为 string&s1 则只能接收不是const的string
void find_char(const string &s1, char c, string::size_type &ctr) {

}
void reset( int &i) 
{
	i = 9;
}
void reset(int *i)
{
	*i = 9;
}

void print(const int* a) {
	//cout << *a << "print(const int *a)" << endl;
}
/*
与第一个同样的意思，不可再定义，但可声明 重新
void print(const int[]) {}
void print(const int[10]) {}*/

// 标记
// 1.c风格字符串数组
void print(const char *cp) {
	if (cp)
		while (*cp)
			cout << *cp++;
}
// 2。标准库规范，数组本身不带标准化规范 只是启发 用了函数而已
void print(const int *beg, const int *end) {
	// 输出beg到end之间 不含end的所有元素
	while (beg != end) {
		cout << *beg << "no zero??" << endl;// 输出当前元素并将指针向前移动一个位置
		beg++;
	}

}
// 3.表示数组大小的形参
void print(const int ia[], size_t size) 
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << "size_t size" << endl;
	}
}

void prints(int (&arr)[10]) {

}

// 等价定义，看起来是一个二维数组，实际上形参是指向含有10个整数的数组的指针
void printtwo(int martix[][3], int rowsize) 
{
	for (auto p = martix; p != martix + 3; ++p)
	{
		for (auto q = *p; q != *p+3; ++q) 
		{
			cout << *q << " printwo";
		}
	}
}
// matrix指向二维数组的首元素，该数组的元素由3个整数构成的数组
void printtwos(int (*martix)[3], int rowsize)
{
	// 这个只会输出 1 2 3
	/*for (auto q = *martix; q != *martix + 3; ++q)
	{
		cout << *q << " printwo";
	}*/
	// 这个会全部输出，因为这个martix是指向二维数组的首元素指针，然后给p，p具有指向二维数组指针的其它元素行
	// 再将p指向一行元素的首指针给予q，q既指向p的首指针，*p是指向头指针位置，*q是指向值，既*q其实是 **q
	for (auto p = martix; p != martix + 3; ++p)
	{
		cout << "*p = " << *p << endl;
		for (auto q = *p; q != *p + 3; ++q)
		{
			cout << *q << " printwo";
		}
	}
}
int main(int argc, char *argv[])
{
	int gethcar;
	int i = 0;
	const int ci = i;
	string::size_type ctr = 0;
	reset(&i);
	//reset(&ci);// 不能指向const int 的指针初始化int*
	reset(i);
	//reset(ci);	// 不能把普通引用绑定到const对象ci上
	//reset(42);	// 不能把普通引用绑定到字面值上
	//reset(ctr);// 类型不匹配ctr是无符号类型

	find_char("Hello_world", '0', ctr);

	// 6.2.4数组形参
	int sixtwoi = 0, j[] = { 0,1 ,2,3,4,5,6 };
	print(&sixtwoi);
	print(j);// j转换成int*并指向 j[0],数组的大小对函数的调用没有影响

	// warning 和使用其它数组的代码一样，以数组作为形参的函数也必须确保使用数组时不会越界

	// 3种技术 保证使用数组不会越界
	// 1.使用标记指定数组长度,就需要数组本身有结束标记 ，像c风格字符串在字符数组中最后一个字符后面跟着一个空字符
	const char cs1[] = "sdfs";
	const char *cs2[] = {"sdfs","dfdsf"
};
	print(cs1);

	cout << endl;

	// 2.使用标准库规范 传递首元素 和尾后元素的指针sixtwoi
	print(begin(j), end(j));
	
	// 3.显式传递一个表示  数组大小  的形参，在c程序和过去的c++程序中常常使用这种方法
	// 记住 是数组大小的形参
	print(j, end(j) - begin(j));

	// 二。数组形参和const

	// 三。数组引用形参
	//void print(int(&arr)[10])// 这样需要指定大小，int &arr[10]是不正确的，为将arr声明为了引用的数组
	// int (&arr)[10]正确，arr是具有10个整数的整型数组的引用
	int threek[10] = {0,1,2,3,4,5,6,7,8,9};
	//prints(&sixtwoi);// 错误：实参不是含有10个整数的数组
	//prints(j);//错误，实参不是含有10个整数的数组
	prints(threek);
	// 数组引用必须规范大小才可，在后面p578会讲到如何处理任意大小

	// 四。传递多维数组
	int fourarray[3][3] = { {1,2,3 },{ 4,5,6 },{7,8,9 }};
	printtwos(fourarray,3);

	// 
	cin >> gethcar;
	return 0;
}