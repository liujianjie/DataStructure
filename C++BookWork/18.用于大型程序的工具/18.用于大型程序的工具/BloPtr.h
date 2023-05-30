
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
	// ����ָ��
	T* operator->() const
	{
		// ʵ�ʹ���ί��& ��this->�������֣�->����ָ�룬������&
		return &this->operator*();
	}
	// 14.6
	// ǰ�ð汾
	BloPtr& operator++();// ʡ����BloPtr<T>�������ڿ���ʡ�������涨�岻��ʡ
	BloPtr& operator--();

	// ����
	BloPtr& operator++(int);
	BloPtr& operator--(int);

private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<T>> 
		check(size_t, const string&)const;
	// ����һ��weak_ptr����ζ�ŵײ�vector���ܱ�����
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
	// �����飬��������ί�и�ǰ��ȥ���
	BloPtr ret = *this;
	++*this;// ί��
	return ret;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator--(int)
{
	BloPtr ret = *this;
	--*this;// ί��
	return ret;
}

template <typename T>
shared_ptr<vector<T>> BloPtr<T>::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();// vector������
	if (!ret)
		throw runtime_error("������");
	if (i >= ret->size())
		throw runtime_error("Խ��");
	return ret;
}
#endif; // !STRBLOPTR_H
