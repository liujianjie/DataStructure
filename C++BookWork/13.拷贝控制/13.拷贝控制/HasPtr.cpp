#include "HasPtr.h"


// 应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是ps本身的位置
//HasPtr::HasPtr(const HasPtr& hp):
//	pss(new string(*hp.pss)),
//	i(hp.i)
//{
//}
//
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	i = rhs.i;
//	//pss = rhs.pss;// 应该拷贝到ps指向的位置？只是不好的
//	pss = new string(*rhs.pss);
//	return *this;
//}
// 练习13.22 
//HasPtr::HasPtr(const HasPtr& hp) :
//	pss(new string(*hp.pss)),
//	i(hp.i)
//{
//}
//
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	auto new_ptr = rhs;
//	delete pss;
//	pss = new_ptr.pss;// 指针了？
//	i = new_ptr.i;
//	return *this;
//}
//HasPtr::~HasPtr(){}

// 13.2.1 像值
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	auto temp = new string(*rhs.pss);
//	delete pss;
//	i = rhs.i;
//	pss = temp;
//	return *this;
//}
//13.2.2像指针
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	++(*rhs.use);
//	if (--*use == 0) {
//		delete use;
//		delete pss;
//	}
//	i = rhs.i;
//	use = rhs.use;
//	pss = rhs.pss;
//	return *this;
//}
// 移动构造
HasPtr::HasPtr(HasPtr &&p) noexcept:pss(p.pss), i(p.i), use(p.use)
{
	cout << "HasPtr(HasPtr &&p) noexcept:pss(p.pss), i(p.i)移动构造函数 " << endl;
	p.pss = 0;// 不会影响左边的数据，因为是指针只是指向那个内存，现在不指向了而已
	p.use = new size_t(1);// 只剩下自己
}
// 13.3 在赋值运算符中使用swap
// 参数调用拷贝构造，所以这是个右侧对象的副本
//HasPtr& HasPtr::operator=(HasPtr rhs)
//{
//	cout << "rhs.pss" << rhs.getPss() << endl;
//	cout << "rhs.use" << rhs.getUse() << endl;
//	cout << "HasPtr& operator=(HasPtr rhs)" << endl;
//	// rhs指向本对象曾经的内存，this指向右侧的内存
//	//swap(rhs);
//	swap(*this, rhs);
//	return *this;
//	// 当结束时，rhs销毁就会删除左侧运算对象的值，并且释放内存。
//}
// 
//HasPtr& HasPtr::operator=(const HasPtr &rhs)
//{
//	++(*rhs.use);
//	if (--*use == 0) {
//		delete use;
//		delete pss;
//	}
//	i = rhs.i;
//	use = rhs.use;
//	pss = rhs.pss;
//	return *this;
//}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
	cout << "HasPtr& HasPtr::operator=(HasPtr &&rhs) 移动赋值运算符 " << endl;
	if (this != &rhs) {
		i = rhs.i;
		use = rhs.use;
		pss = rhs.pss;
		rhs.i = 0;
		rhs.pss = nullptr;
		rhs.use = nullptr;
	}
	return *this;
}