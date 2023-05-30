
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

	string& deref() const;// ������ ֻҪ�����������Ķ���ͻ���õķ�����*thisҲ��
	StrBloPtr& incr();// ǰ׺����
	size_t curr;// �������еĵ�ǰλ��

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
	// ǰ�ð汾
	StrBloPtr& operator++();
	StrBloPtr& operator--();
	// ����
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
	// ����ָ��
	std::string* operator->() const
	{
		// ʵ�ʹ���ί��& ��this->�������֣�->����ָ�룬������&
		return &this->operator*();
	}

private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;
	// ����һ��weak_ptr����ζ�ŵײ�vector���ܱ�����
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
		// ��������ѭ�� ����û���ҳ� ��һ�����ڵڶ����� ����С����
		return true;
	}
	if (data1->size() >= data2->size()) {
		for (auto p1 = data1->begin(), p2 = data2->begin(); p2 != data2->end(); p1++, p2++)
		{
			if ((*p1 < *p2) == 1) {
				return true;
			}
		}
		// ����ÿһ�Ժ󣬶�û�ҵ���һ��С�ڵڶ����ģ����Ǵ����
		return false;
	}
}
// ��ϰ14.28
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
