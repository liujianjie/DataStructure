#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class StrVec
{
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
public:
	template <typename ...Args>
	void emplace_back(Args&&...);

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
	
	// 14.4
	StrVec &operator=(std::initializer_list<std::string>);
	void printStrVec();

	// 14.5
	string& operator[](size_t n) 
	{
		return elements[n];
	}
	const string& operator[](size_t n)const
	{
		return elements[n];
	}
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
template <typename ...Args>
inline
void StrVec::emplace_back(Args&&... arg)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(arg)...);
}
inline
bool operator==(const StrVec &lhs,const StrVec &rhs)
{
	if (lhs.size() == rhs.size()) {
		for (auto p1 = lhs.elements,p2 = rhs.elements; p1 != lhs.first_free;p1++,p2++) {
			//cout << "p1 :" << *p1 << ", p2:" << *p2 << endl;
			if (*p1 != *p2) {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}
inline
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
inline
bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() < rhs.size()) {
		// 以长度短的为
		for (auto p1 = lhs.elements, p2 = rhs.elements; p1 != lhs.first_free; p1++, p2++) {
			// 若找的过程中 有一个比p2大 那么就不是小于
			if ((*p1 > *p2) == 1) {
				return false;
			}
		}
		// 遍历所有循环 若都没有找出 第一个大于第二个的 就是小的了
		return true;
	}
	else if (lhs.size() >= rhs.size()) {
		// 以长度短的为 aaaab aaac
		for (auto p1 = lhs.elements, p2 = rhs.elements; p2 != rhs.first_free; p1++, p2++) {
			if ((*p1 < *p2) == 1) {
				return true;
			}
		}
		// 遍历每一对后，都没找到第一个小于第二个的，就是大的了
		return false;
	}
}