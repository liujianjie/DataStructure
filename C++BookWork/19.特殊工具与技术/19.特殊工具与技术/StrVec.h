#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class StrVec
{
public:
	StrVec():
		elements(nullptr),first_free(nullptr),cap(nullptr)
	{}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	
	void push_back(const string&);
	size_t size()const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	void reserve(size_t n);
	void resize(size_t n, const string &t = "");

	StrVec(initializer_list<string>);

private:
	static allocator<string> alloc;// 分配元素
	//检查是否超过最大的空间，是就重新分配
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap;
};

