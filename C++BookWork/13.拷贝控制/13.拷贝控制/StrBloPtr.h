
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
public:
	StrBloPtr() : curr(0) {}
	StrBloPtr(StrBlob &a, size_t sz = 0):
		wptr(a.data), curr(sz){}
	~StrBloPtr();

	string& deref() const;// ������ ֻҪ�����������Ķ���ͻ���õķ�����*thisҲ��
	StrBloPtr& incr();// ǰ׺����
	size_t curr;// �������еĵ�ǰλ��

	weak_ptr<vector<string>> getWptr()
	{
		return wptr;
	}
private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;
	// ����һ��weak_ptr����ζ�ŵײ�vector���ܱ�����
	weak_ptr<vector<string>> wptr;

};
#endif; // !STRBLOPTR_H
