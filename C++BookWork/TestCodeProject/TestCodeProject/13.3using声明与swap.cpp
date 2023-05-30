#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include "Foo136.h"
//using namespace std;

void swap(int* i, int *j)
{
	std::cout << "inner swap()" << std::endl;
}

void swap()
{
	//using std::swap;
	//using namespace std;// 这个才不会隐藏
	int *ii = new int(2), *jj = new int(3);
	swap(ii, jj);
}
class Y {
public:
	Y(const Y&) { std::cout << "Y(const Y&)" << std::endl; }
};

class hasY {
public:
	hasY() = default;
	hasY(hasY&&) = default;
	//Y mem;// Y有一个删除的移动构造函数,因为只定义了拷贝构造函数，但没有定义移动构造函数
};
hasY hy, hy2 = std::move(hy);// 移动构造函数是删除的
int main()
{
	int a;
	swap();

	Foo136 f1;
	f1.someMem();
	const Foo136 f2;
	std::move(f2).someMem();
	std::cin >> a;
	return 0;
}
