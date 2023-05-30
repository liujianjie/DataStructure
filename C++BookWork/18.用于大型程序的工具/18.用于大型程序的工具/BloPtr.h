
#ifndef STRBLOPTR_H
#define STRBLOPTR_H

#include <iostream>
#include <memory>
#include <vector>
#include "Blob.h"
using namespace std;

template <typename T> class BloPtr
{
public:
	BloPtr() : curr(0) {}
	BloPtr(Blob<T> &a, size_t sz = 0) try :
		wptr(a.data), curr(sz) {}
	catch (const std::bad_alloc& e)
	{
		cout << "(const std::bad_alloc& e):" << e.what() << endl;
	}
				
	T& operator*() const
	{
		auto p = check(curr, "*error");
		return (*p)[curr];
	}
	// 返回指针
	T* operator->() const
	{
		// 实际工作委托& 与this->是两部分，->返回指针，所以用&
		return &this->operator*();
	}
	// 14.6
	// 前置版本
	BloPtr& operator++();// 省略了BloPtr<T>，在类内可以省，在外面定义不能省
	BloPtr& operator--();

	// 后置
	BloPtr& operator++(int);
	BloPtr& operator--(int);

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>> 
		check(size_t, const string&)const;
	// 保存一个weak_ptr，意味着底层vector可能被销毁
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template <typename T>
BloPtr<T>& BloPtr<T>::operator++()
{
	check(curr, "error");
	++curr;
	return *this;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator--()
{
	--curr;
	check(curr, "error");
	return *this;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator++(int)
{
	// 无需检查，而是算是委托给前置去检查
	BloPtr ret = *this;
	++*this;// 委托
	return ret;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator--(int)
{
	BloPtr ret = *this;
	--*this;// 委托
	return ret;
}

template <typename T>
shared_ptr<vector<T>> BloPtr<T>::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();// vector还在吗
	if (!ret)
		throw runtime_error("不存在");
	if (i >= ret->size())
		throw runtime_error("越界");
	return ret;
}
#endif; // !STRBLOPTR_H
