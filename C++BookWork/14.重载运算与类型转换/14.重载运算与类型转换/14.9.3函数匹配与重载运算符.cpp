#include <iostream>
#include "String.h"
#include <map>
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
引出：
重载的运算符也是重载的函数。所以通用的函数匹配规则同样适用于判断在给定的表达式中用内置运算符还是重载的运算符
1.当运算符函数出现在表达式中，候选函数集的规模要比使用调用运算符调用函数时更大。
就是：a + b比 a.operator(b)与 operator(a,b)调用的函数要多

复杂的说：
1.a + b不确定是调用成员函数还是非成员函数
2.若+运算符定义为成员函数和非成员函数，这两个是不会重载的，因为调用方式不同
3.成员函数：指针，类型对象，引用来调用，非成员：只能使用函数名
所以：
a+b:可能调用： a.operator(b)
				operator(a,b)
				或内置运算符
而
a.operator(b)
operator(a,b)只调用当前函数

前提是需要有转换构造函数与类型转换函数就会出现多个匹配。
*/
class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0){}
	operator int() const { 
		cout << "operator int() const " << endl;
		return val; 
	}
	//int operator+(const SmallInt& ) const {
	//	return 2;
	//}
private:
	std::size_t val;
};
SmallInt operator+(const SmallInt&, const SmallInt&) {
	cout << "SmallInt operator+(const SmallInt&, const SmallInt&) " << endl;
	SmallInt sl;
	return sl;
}

struct LongDouble {
	//friend LongDouble operator+(LongDouble&, double);
	LongDouble operator+(const SmallInt&)
	{
		cout << "LongDouble operator+(const SmallInt&)" << endl;
		LongDouble l;
		return l;
	}
};
LongDouble operator+(LongDouble&, double)
{
	cout << "LongDouble operator+(LongDouble&, double)" << endl;
	LongDouble l;
	return l;
}
int main()
{
	int a;
	SmallInt s1, s2;
	//SmallInt s3 = s1 + s2;// 出现二个，因为两个都是同一类型对象，出现两个重载+运算符
	//int val1 = s1 + 0;// 出现3个，因为第二个运算对象是int，可以将s1转换为int再使用内置，因为定义了转换构造，smallInt转int
	//SmallInt val1 = s1 + 0;// 也是3个，因为定义了类型转换，int转smallInt

	SmallInt si;
	LongDouble ld;
	//ld = si + ld;// si中没有这样的运算对象
	ld = ld + si;
	ld = ld + double(si);// 必须显示才有

	SmallInt s12;
	//double d1 = s12 + 3.15;爱你的相对性
	// 练习
	/*
	14.52: ok 必须显示转换才会调用转换运算符
	14.53：不合法，s1类型转换int，再内置转为double计算，或 double转换构造为small，计算完再类型转换为int
	，解决方法，把small中转换构造去掉就行，让其执行内置类型计算
	*/
	cin >> a;
	return 0;
}