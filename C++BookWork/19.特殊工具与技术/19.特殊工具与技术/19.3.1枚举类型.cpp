#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

enum color { red, yellow, green };
//enum stoplight{red,yellow,green};// 重复定义成员
enum class peppers{red,yellow,green};

enum class inTypes {
	charTyp, shortType, intType
};
enum class inTypes2 {
	charTyp2 = 8, shortType2 = 16, intType2 = 16,
	longTyp2 = 32, long_longType = 64
};

// 不限定没有默认
enum intValues:unsigned long long{
	charTyp = 255, shortTyp = 63552,intType = 2222,
	longTyp = 213213213UL,
	long_longTyp = 221321321ULL
};

enum intValues2 : unsigned long long;
enum class open_modes;

enum class intValues3;
//enum intValues3;
enum intValues4 : int;
//enum intValues4 : long;// 不能改变

enum Tokens{INLINE = 128,VIRTUAL = 129};
void ff(Tokens) { cout << "void ff(Tokens)" << endl; }
void ff(int){ cout << "void ff(int)" << endl; }

//void newf(Tokens) { cout << "void newf(Tokens)" << endl; }
void newf(unsigned char){ cout << "void newf(unsigned char)" << endl; }
void newf(int) { cout << "void newf(int)" << endl; }

//enum Xianding : short{
//	xiandingval = 18446744073709551615ULL
//};
enum class Xianding2 {
	xiandingval2 = 18446744073709551615ULL
}; 


// 20190907 
//enum class newview : int;
//enum class newview {
//	long_longTyp2 = 22132132112321321312
//};
enum  newview : unsigned long long;
enum  newview : unsigned long long{
	long_longTyp2 = 2213213211232132421ULL
};
int main()
{
	newview nw1 = newview::long_longTyp2;
	int a;
	/*
	1.限定作用默认int，不限定没有默认类型，但是潜在认为能容纳枚举成员最大的
	2.为限定和不限定指定某个类型，枚举成员不能超过范围，若超过不会自动提升，会报错
	3.限定作用域，必须显示指定成员，因为枚举成员的范围在枚举内
	*/
	//Xianding x = xiandingval;
	Xianding2 x2 = Xianding2::xiandingval2;

	Tokens curTok = INLINE;
	ff(128);
	ff(INLINE);// 本可以调用ff(int)但是ff(tokens)更精确匹配
	ff(curTok);

	// 不限定作用域成员可以转换为整形，得精确匹配
	unsigned char uc = VIRTUAL;
	newf(VIRTUAL);
	newf(uc);
	color eyes = green;// 
	//peppers p = green;// 作用域

	color hair = color::red;
	peppers p2 = peppers::red;

	constexpr inTypes val1 = inTypes::shortType;

	//
	//inTypes i1 = 2;
	inTypes i2 = inTypes::intType;

	int i = color::red;
	int j = color::yellow;
	cout << i << endl;
	cout << j << endl;

	//
	unsigned long long ui = intValues::long_longTyp;
	cout << ui << endl;


	// test 20190908
	unsigned int test1 = -2;
	cout << test1 << endl;

	cout << "hello world" << endl;

	//int byte - size = 1;
	/*
	练习：无
	*/
	cin >> a;
	return 0;
}
