#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <fstream>
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
#include "Folder.h"
#include "Message.h"
#include "String.h"
#include "TexTQuery.h"
#include "QueryResult.h"
#include "StrVec136.h"
/*
开篇引出：
1.我们的类也同时支持移动和拷贝
2.是窃取资源 不是拷贝资源
3.写法形式与拷贝的差不多，不过是右引用，并且const不同
4.必须确保移后源对象处于销毁无害的。源对象不再指向被移动的资源


二、移动操作、标准库容器和异常
1.通常来说，移动操作不会抛出任何异常，应该通知标准库，不然标准库认为移动我们的类对象可能会抛出异常，并会作出一些额外的工作
2.声明和定义的地方都需要noexcept
3.noexcept的作用
标准库与我们自定义的类型交互的
移动操作可以发生异常
标准库容器能对异常发生时其自身的行为提供保障，如调用push_back时发生异常，vector自身不会改变
1.如果重新分配过程中使用了移动构造函数，发生了异常，让移动源元素已经改变,新空间中未构造的元素可能尚不存在，vector
不能满足自身保持不变的要求
2.但是如果使用了拷贝构造，即使发生异常，释放新分配的内存并返回，vector原元素仍然存在

结合1,2说明总结：
vector如果知道元素类型的移动构造函数不会抛出异常，在重新分配内存的过程中，就使用移动构造函数，否则就使用拷贝构造函数

三、移动赋值运算符

四、移后源对象必须可析构
从一个对象移动数据并不会销毁此对象，但有时在移动操作完成后，源对象会销毁。
所以必须移后源对象必须可析构

还需要
1.对象仍然有效的，指：可以赋予新值或者可以安全地使用而不依赖其当前值。程序不应该依赖移后源对象中的数据

移后源对象必须保持有效的、可析构的状态，但用户不能对其值进行任何假设

五、合成的移动操作
合成的：
1.编译器根本不会为"某些类"合成移动操作，特别是一个类定义了自己的拷贝构造函数 拷贝赋值运算符或者析构函数
2.只有当类没有定义任何自己版本的拷贝控制成员，且类的每个非static数据成员都可以移动时 才会合成（内置类型可以移动，成员为类对象且有对应的移动操作）

合成删除的：
1.移动操作永远不会隐式定义为删除的函数。
2.显式的指定default 并且编译器不能移动所有成员，则定义为删除的

合成的移动操作定义为删除的函数遵循与定义删除的合成拷贝操作类型的原则
1.类成员定义了拷贝构造未定义移动构造，或类成员为定义拷贝构造不能为其合成移动构造
2.类成员的移动构造被定义为删除或不可访问
3.类的析构函数被定义为删除或不可访问的
4.类成员是const的或引用，类的移动赋值运算符为删除，但移动拷贝构造可以

最后一个 移动操作和合成的拷贝控制成员关系
一个类定义了一个移动构造函数和/或一个移动赋值运算符，则该类的合成构造函数和拷贝赋值运算符会被定义为删除的

六、移动右值，拷贝左值
既有拷贝构造又有移动构造，编译器使用普通的函数匹配规则来确定
因为赋值运算符，右值可以用const 左引用引用，或者直接右引用引用，所以右值存在两个匹配

七、没有移动构造函数，右值也被拷贝
即使move也是拷贝构造函数
可以将 int&& 转换为const int&

用拷贝构造函数代替移动构造函数几乎肯定是安全的，因为拷贝构造函数不会改变原对象的值

八、拷贝并交换 赋值运算符和移动操作
结合临时对象和swap创建一个即是移动赋值运算符 也是拷贝赋值运算符

如果传的形参是右值，则调用移动赋值运算符，那么就会销毁原来左侧的值，如果它有的话，就不能获取了

note：五个拷贝控制成员应该看做一个整体。
通常一个类有一个资源成员那么需要拷贝成员，但是拷贝成员额外开销，所以定义移动的就可以避免

九、Message类的移动操作
就是一个概念，使用移动操作是将右侧的移动到左侧后，右侧运算对象称为移后源对象就不会再在原先的floder集合中了
并且减少不必要的消耗

十、移动迭代器
for循环construct很慢，用uninitialized_copy来简单，需使用移动迭代器适配器
定义：一个移动迭代器通过改变给定迭代器的解引用运算符的行为来适配此迭代器
解引用移动迭代器生成一个右值引用

make_move_iterator
移动迭代器支持正常迭代器的操作，可以传给算法

由于移动一个对象可能销毁掉原对象，只有在确信算法在为一个元素赋值或将其传递给一个用户定义的函数后不再访问它时，才能将移动迭代器传递给算法

note:确信move是安全的再使用
*/

class XX {
	int i;
	std::string s;
public:
	XX(){}
	XX(const XX&) { cout << "XX(const XX&)" << endl; }
};
struct hasXX {
	XX mem;
};
XX x, x2 = std::move(x);// 会调用拷贝构造
hasXX hx, hx2 = std::move(hx);

class Y {
public:
	Y(const Y&) { cout << "Y(const Y&)" << endl; }
};

class hasY {
public:
	hasY() = default;
	hasY(hasY&&) = default;
	Y mem;// Y有一个删除的移动构造函数
};
//hasY hy, hy2 = std::move(hy);// 移动构造函数是删除的

StrVec136 getVec(istream& is)
{
	StrVec136 s1;
	s1.push_back("s1s1s1");
	return s1;
}

void fun(int &&ci) {
	cout << " fun(int &&ci)" << endl;

}
void fun(int ci) {
	cout << " fun(int ci)" << endl;

}
int main() {

	int aa;

	// test
	int it = 12;
	const int &ci1 = std::move(it);
	int &&ci2 = std::move(it);
	int ci3 = std::move(it);// 可以用一个左值接收右值引用！
	// ci2 与ci3对于移动 是同等的 会冲突
	fun(it);
	//fun(std::move(it));

	string s0 = "asadfsa";
	string &s1 = s0;
	string &&s2 = std::move(s1);
	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1.size() << endl;
	s1 = "dfffff";
	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;

	StrVec136 stv;
	stv.push_back("osfadf");
	StrVec136 stv2(std::move(stv));
	cout << stv.begin() << endl;
	cout << *stv2.begin() << endl;

	stv2 = std::move(stv2);
	cout << *stv2.begin() << endl;
	
	cout << "---------" << endl;
	StrVec136 svc1, svc2;
	svc1 = svc2;
	//StrVec136 getVec();
	svc2 = getVec(cin);
	
	cout << "---------" << endl;
	//HasPtr hs3("hs3"), hs4("hs4");
	//HasPtr hs5 = hs3;

	HasPtr hs1("hs1"), hs2("hs2");
	//hs1 = hs2;
	//hs1 = std::move(hs2);
	cout << hs1.getPss() << endl;
	//cout << hs2.getPss() << endl;// 处于可析构的状态，仍然有效就可以，但是不能使用 已经删除了源内存,不能访问这个内存的值了，只能访问指向的内存地址

	string *snl = 0;
	cout << snl << endl;// 可以
	//cout << *sn1 << endl;// 错误
	cout << "--------" << endl;
	// 练习
	/*
	13.50
	就是当分配新内存时使用移动构造而不是拷贝
	*/
	String str1("you and me,sdfasdf,adf");
	String str2("me and you");
	String str3("what the fuc");
	vector<String> ve;
	ve.push_back(str1);
	ve.push_back(str2);
	ve.push_back(str3);

	/*
	13.51
	开头就说unique_ptr不能拷贝可以移动，这是移动啊，return返回的表达式是右值
	*/

	/*
	13.52
	= 调用赋值运算符
	若是直接赋值，hp = hp2
	hp2 将调用拷贝构造函数给rhs,rhs再与hp交换，rhs析构
	hp = std::move(hp2)
	将调用移动构造函数给rhs，hp2的值被置为空，rhs与hp交换，rhs析构
	*/
	// 13.53 多了一次赋值，因为交换
	// 13.54
	cout << "13.54" << endl;
	HasPtr hs3("hs3"), hs4("hs4");
	hs3 = std::move(hs4);
	cout << "hs3.pss" << hs3.getPss() << endl;
	//cout << "hs4.pss" << hs4.getPss() << endl;
	std::cin >> aa;
	return 0;
}