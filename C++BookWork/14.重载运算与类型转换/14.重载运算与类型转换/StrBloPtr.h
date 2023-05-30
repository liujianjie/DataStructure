
#ifndef STRBLOPTR_H
#define STRBLOPTR_H

#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"
using namespace std;

class StrBloPtr
{
	friend bool eq(const StrBloPtr& s1, const StrBloPtr& s2);
	friend bool nteq(const StrBloPtr& s1, const StrBloPtr& s2);
	friend bool operator==(const StrBloPtr &lhs, const StrBloPtr &rhs);
	friend bool operator<(const StrBloPtr &lhs, const StrBloPtr &rhs);
public:
	StrBloPtr() : curr(0) {}
	StrBloPtr(StrBlob &a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	~StrBloPtr();

	string& deref() const;// 解引用 只要解引用这个类的对象就会调用的方法吗？*this也会
	StrBloPtr& incr();// 前缀递增
	size_t curr;// 在数组中的当前位置

	weak_ptr<vector<string>> getWptr()
	{
		return wptr;
	}
	weak_ptr<vector<string>> getWptr() const
	{
		return wptr;
	}
	// 14.5
	string& operator[](size_t n)
	{
		return (*(wptr.lock()))[n];
	}
	const string& operator[](size_t n) const
	{
		return (*(wptr.lock()))[n];
	}
	// 14.6
	// 前置版本
	StrBloPtr& operator++();
	StrBloPtr& operator--();
	// 后置
	StrBloPtr& operator++(int);
	StrBloPtr& operator--(int);

	// 14.29
	StrBloPtr& operator+=(size_t n)
	{
		check(curr + n, "operator+= error");
		curr = curr + n;
		return *this;
	}
	StrBloPtr& operator-=(size_t n)
	{
		check(curr - n, "operator-= error");
		curr = curr - n;
		return *this;
	}
	// 14.7
	std::string& operator*() const
	{
		auto p = check(curr, "*error");
		return (*p)[curr];
	}
	// 返回指针
	std::string* operator->() const
	{
		// 实际工作委托& 与this->是两部分，->返回指针，所以用&
		return &this->operator*();
	}

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;
	// 保存一个weak_ptr，意味着底层vector可能被销毁
	weak_ptr<vector<string>> wptr;

};
inline
bool operator==(const StrBloPtr &lhs, const StrBloPtr &rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		return false;
	}
	return true;
}
inline
bool operator!=(const StrBloPtr &lhs, const StrBloPtr &rhs)
{
	return !(lhs == rhs);
}
inline
bool operator<(const StrBloPtr &lhs, const StrBloPtr &rhs)
{
	auto data1 = lhs.wptr.lock();
	auto data2 = rhs.wptr.lock();
	if (data1 == data2) {
		return false;
	}
	if (data1->size() < data2->size()) {
		for (auto p1 = data1->begin(), p2 = data2->begin(); p1 != data1->end(); p1++, p2++)
		{
			if ((*p1 > *p2) == 1) {
				return false;
			}
		}
		// 遍历所有循环 若都没有找出 第一个大于第二个的 就是小的了
		return true;
	}
	if (data1->size() >= data2->size()) {
		for (auto p1 = data1->begin(), p2 = data2->begin(); p2 != data2->end(); p1++, p2++)
		{
			if ((*p1 < *p2) == 1) {
				return true;
			}
		}
		// 遍历每一对后，都没找到第一个小于第二个的，就是大的了
		return false;
	}
}
// 练习14.28
inline
StrBloPtr operator+(const StrBloPtr &lhs, size_t n)
{
	StrBloPtr temp = lhs;
	temp += n;
	return temp;
}
inline
StrBloPtr operator-(const StrBloPtr &lhs, size_t n)
{
	StrBloPtr temp = lhs;
	temp -= n;
	return temp;
}

#endif; // !STRBLOPTR_H
