#include "StrBloPtr.h"


StrBloPtr::~StrBloPtr()
{
}
string& StrBloPtr::deref() const
{
	//cout << "deref" << endl;
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
	
	//return (*check(curr, "dereference"))[curr];
}
// 前缀递增
StrBloPtr& StrBloPtr::incr() 
{
	// 如果已经是尾后不能递增了
	check(curr, "dereference past end");
	++curr;
	return *this;// 会调用deref()吗 不会，只是让当前对象等于递增后的对象
}
shared_ptr<vector<string>> StrBloPtr::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();// vector还在吗
	if (!ret)
		throw runtime_error("不存在");
	if(i >= ret->size())
		throw runtime_error("越界");
	return ret;
}

 bool eq(const StrBloPtr& s1, const StrBloPtr& s2)
{
	auto w1 = s1.wptr.lock(), w2 = s2.wptr.lock();
	if (w1 != w2) {
		//throw new exception("two strbloptr not eq");
		return false;
	}
	else {// 是指向同一个vector 再看下标相等与否，下标相等代表指向同一个位置
		// !w2是返回默认的值吧，一直为false
		return (!w2 || s1.curr == s2.curr);// !w2是说end存不存在吧，若存在retrunfalse，不存在returntrue
	}
}

 bool nteq(const StrBloPtr& s1, const StrBloPtr& s2)
{
	return !eq(s1,s2);
}