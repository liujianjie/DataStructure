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
// ǰ׺����
StrBloPtr& StrBloPtr::incr() 
{
	// ����Ѿ���β���ܵ�����
	check(curr, "dereference past end");
	++curr;
	return *this;// �����deref()�� ���ᣬֻ���õ�ǰ������ڵ�����Ķ���
}
shared_ptr<vector<string>> StrBloPtr::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();// vector������
	if (!ret)
		throw runtime_error("������");
	if(i >= ret->size())
		throw runtime_error("Խ��");
	return ret;
}

 bool eq(const StrBloPtr& s1, const StrBloPtr& s2)
{
	auto w1 = s1.wptr.lock(), w2 = s2.wptr.lock();
	if (w1 != w2) {
		//throw new exception("two strbloptr not eq");
		return false;
	}
	else {// ��ָ��ͬһ��vector �ٿ��±��������±���ȴ���ָ��ͬһ��λ��
		// !w2�Ƿ���Ĭ�ϵ�ֵ�ɣ�һֱΪfalse
		return (!w2 || s1.curr == s2.curr);// !w2��˵end�治���ڰɣ�������retrunfalse��������returntrue
	}
}

 bool nteq(const StrBloPtr& s1, const StrBloPtr& s2)
{
	return !eq(s1,s2);
}