#include "Foo136.h"

Foo136& Foo136::operator=(const Foo136& rhs)&
{
	cout << "Foo136& Foo136::operator=(const Foo136& rhs)&" << endl;
	return *this;
}
//Foo136& Foo136::operator=(const Foo136& rhs)&&
//{
//	cout << "Foo136& Foo136::operator=(const Foo136& rhs)&&" << endl;
//	return *this;
//}

Foo136 Foo136::someMem() &
{
	cout << "&" << endl;
	sort(data.begin(), data.end());
	return *this;
}
// 这个如果只有一个 const& 那么&会变成const& 为const的this不可改变了
Foo136 Foo136::someMem() const &// 可用于任何类型的Foo但还是const的精确匹配 就是左值
{
	cout << "const &" << endl;
	Foo136 ret(*this);
	sort(ret.data.begin(), ret.data.end());
	//sort(data.begin(), data.end());// 不可
	return ret;
}
Foo136 Foo136::someMem() && // 可用于可改变的右值
{
	cout << "&&" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo136 Foo136::someMem() const &&
{
	cout << "const &&" << endl;
	//sort(data.begin(), data.end());
	//return *this;
	Foo136 ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}

Foo136 Foo136::sorted() &&
{
	cout << "Foo136 Foo136::sorted() &&" << endl;
	return *this;
}
Foo136 Foo136::sorted() const &
{
	cout << "Foo136 Foo136::sorted() const &" << endl;
	Foo136 ret(*this);// 这个是普通引用
	//return ret.sorted();// 还是会调用const &版本 循环
	return *this;
	//return Foo136(*this).sorted();
	//return std::move(ret).sorted();// 还是会调用const &版本,得到const &&还是转换const&
}