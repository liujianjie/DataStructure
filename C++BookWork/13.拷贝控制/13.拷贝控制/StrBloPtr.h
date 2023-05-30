
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

	string& deref() const;// 解引用 只要解引用这个类的对象就会调用的方法吗？*this也会
	StrBloPtr& incr();// 前缀递增
	size_t curr;// 在数组中的当前位置

	weak_ptr<vector<string>> getWptr()
	{
		return wptr;
	}
private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;
	// 保存一个weak_ptr，意味着底层vector可能被销毁
	weak_ptr<vector<string>> wptr;

};
#endif; // !STRBLOPTR_H
