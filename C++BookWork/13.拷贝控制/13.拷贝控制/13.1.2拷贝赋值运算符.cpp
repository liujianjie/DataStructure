#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"
#include "StrBloPtr.h"

using namespace std;



/*
定义：是用同类型的另一个对象给当前对象赋值时，但是不是初始化，是已经定义过了的后再用同类型的另一个对象 赋值，也是用=赋值运算符

写法：
重载=运算符，一个返回类型和一个参数列表
返回一个指向其左侧运算对象的引用(*this)
参数列表是一个与其所在类相同类型，是引用并且是const，右侧运算对象作为显式参数传递

赋值运算符定义：是重载=运算符，是在类的一个成员函数，返回一个指向其左侧运算对象的引用

*/
int main() {

	int a;
	
	// 练习
	/*13.6，是重载=运算符，是在类的一个成员函数，返回一个指向其左侧运算对象的引用 将同类型对象赋给左侧运算对象
	当=时
	将右侧运算对象非static的成员拷贝到左侧运算对象中
	当我们没有定义的时候
	*/
	/*
	13.7
	调用合成的拷贝构造函数呀
	*/
	// 拷贝赋值strblob 会有一个新的
	StrBlob sbb1, sbb2;
	//shared_ptr < vector<string>> data = make_shared < vector<string>>();
	sbb2.data = make_shared < vector<string>>();
	(*sbb2.data).push_back("1");
	(*sbb2.data).push_back("2");
	(*sbb2.data).push_back("3");
	cout << (*sbb2.data).size() << endl;
	sbb1 = sbb2;
	cout << (*sbb1.data).size() << endl;
	cout << "多少人共享了：" << sbb1.data.use_count() << endl;
	cout << "多少人共享了：" << sbb2.data.use_count() << endl;

	// 拷贝赋值StrBloPtr 还是只有一个应该是地址
	StrBlob sbb3, sbb4;
	sbb4.data = make_shared < vector<string>>();
	(*sbb4.data).push_back("1");
	(*sbb4.data).push_back("2");
	(*sbb4.data).push_back("3");
	StrBloPtr sbp1, sbp2(sbb4);
	sbp1 = sbp2;
	cout << "sbb4:" << sbb4.data.use_count() << endl;
	cout << "strbloptr:" << sbp1.getWptr().use_count() << endl;
	cout << "strbloptr:" << sbp2.getWptr().use_count() << endl;
	cout << "sbp1:" << (sbp1.getWptr().lock()->size()) << endl;
	cout << "sbp2:" << (sbp1.getWptr().lock()->size()) << endl;
	cin >> a;
	return 0;
}