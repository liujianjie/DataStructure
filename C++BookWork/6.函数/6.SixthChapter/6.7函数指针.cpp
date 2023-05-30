#include <iostream>

using namespace std;

bool lengthCompare(const string &s1, const string &s2) {
	if (s1.size() < s2.size()) {
		return false;
	}
	else {
		return true;
	}
}
void ff(int *){}
void ff(unsigned int){}


// 参数不能定义函数类型的形参，但是形参可以是指向函数的指针，看起来是函数类型，其实是指针
void useBigger(const string &s1, const string &s2, bool pf(const string&, const string&)){}
//等价的声明
void useBigger(const string &s1, const string &s2, bool(*pf)(const string&, const string&));
//string ss1 = "sdf", ss2 = "aasdf";
//void useBigger(const string &s1, const string &s2, lengthCompare(ss1,ss2) {}// 不可。

// 使用类型别名
// Func 与func2是函数类型
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2;

// Funcp 与funcp2是函数指针 ，因为decltype返回函数类型，所以func2与funcp2并不会自动转换成指针类型
typedef bool (*Funcp)(const string&, const string&);
typedef decltype(lengthCompare) *Funcp2;
void useBigger(const string &s1, const string &s2, Func);//函数类型自动转换成指针
void useBigger(const string &s1, const string &s2, Funcp2);



int main() {
	int g;
	bool(*pf)(const string &s1, const string &s2);// 未初始化? 只是声明这个指针指向函数的指针，参数是const string 引用，返回值是bool类型
	// 括号不能少，不然为pf的函数，该函数返回bool*
	// 二：使用函数指针 赋值？
	pf = lengthCompare;//pf指向 那个函数。lengthCompare作为一个值使用时，自动地转换成指针
	pf = &lengthCompare;// 等价

	// 还能直接使用指向函数的指针调用该函数，无需提前解引用指针 使用？
	bool b1 = pf("hello", "goodbye");// 调用 lengthCompare函数
	cout << b1 << endl;
	bool b2 = (*pf)("hello", "goodbye");// 一个等价的调用
	cout << b2 << endl;
	bool b3 = lengthCompare("sdfsdf", "sa");//另一个等价的调用
	cout << b3 << endl;
	// 在指向不同函数类型的指针间不存在转换规则，意思就是pf指针定义的函数类型 不能再指向其它的函数类型
	// 即使返回值是byte可以转换成int 也不行 算术的不适用。
	// 可以为nullptr 和  0
	string::size_type sumlength(const string&, const string&);
	bool cstringCompare(const char*, const char*);
	pf = 0;
	//pf = sumlength; // 返回类型不匹配
	//pf = cstringCompare;// 新参类型不匹配
	pf = lengthCompare;

	int(*pf2)(const int &a1, const int &a2);
	short test1(const int&a1, const int &a2);
	//pf2 = test1;

	// 3.重载函数的指针 也要指定好是哪一个函数，即形参与返回值都得对应


	//void(*pf3)(int) = ff;//error
	//double(*pf4)(int *) = ff;//error
	void(*pf4)(int *) = ff;//true

	// 三：函数指针形参


	// 也可以直接把函数作为实参使用，此时它会自动转换成指针：不能当做形参
	string s1 = "j",s2 = " d";
	useBigger(s1, s2, lengthCompare);

	// 四。返回指向函数的指针
	// 与函数形参不一样，需要指定指针形式，不能是函数类型
	// 用using声明一个返回函数指针的函数
	using F = int(int*, int);	// F是函数类型，不是类型
	using PF = int(*)(int *, int);// PF是指针类型
	PF f1(int);
	//F  f12(int); // error:F是函数类型，f1不能返回一个函数
	F  *f1(int);

	// 也能用下面的形式直接声明f1;
	int(*f1(int))(int *, int);// 从内向外的顺序阅读，f1有形参列表，所以f1是个函数，f1前面有* 所以f1返回一个指针，指针的类型也包含形参列表，所以指针指向函数，该函数的返回类型是int

	// 尾置返回类型的方式
	auto fi(int) -> int(*)(int*, int);

	// 将auto和decltype用于函数指针类型
	// 如果知道要返回哪个函数，
	string::size_type sumlength2(const string&, const string&);
	string::size_type largerlength(const string&, const string&);

	// 注意 decltype只是函数类型，不是函数指针
	decltype(sumlength2) *getfcns(const string&);

	cin >> g;
	return 0;
}