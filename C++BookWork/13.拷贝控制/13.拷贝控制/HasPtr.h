#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//class HasPtr {
//public:
	// 以前的
	/*HasPtr(const string &s = string()) :
		pss(new string(s)), i(0) {
	}
	HasPtr(const HasPtr& hp);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();*/
	// 13.2.1
//	HasPtr(const string &s = string()) :
//		pss(new string(s)), i(0) {
//	}
//	//HasPtr(const HasPtr& hp):pss(new string(*hp.pss)),i(hp.i){ }
//	HasPtr& operator=(const HasPtr&);
//	~HasPtr() { delete pss; }
//	string& getPss() {
//		return *pss;
//	}
//private:
//	std::string *pss;
//	int i;
//};

// 13.2.1像指针
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& h1, const HasPtr& h2);
public:
	HasPtr(const string &s = string()) :
		pss(new string(s)), i(0),use(new size_t(1)) {}
	HasPtr(const HasPtr& hp):pss(hp.pss),i(hp.i),use(hp.use){ 
		++*use;
	}
	~HasPtr() { 
		if (--*use == 0) {
			delete use;
			delete pss;
		}
	}
	string& getPss() const{
		return *pss;
	}

	size_t& getUse() const {
		return *use;
	}
	// 移动构造
	HasPtr(HasPtr &&p) noexcept;
	// 移动赋值运算符
	HasPtr& operator=(HasPtr &&rhs) noexcept;
	// 拷贝并交换，拷贝不管是移动拷贝还是构造拷贝都可以
	//HasPtr& operator=(HasPtr rhs)
	//{
	//	cout << "HasPtr& operator=(HasPtr rhs)" << endl;
	//	swap(*this, rhs);
	//	return *this;
	//}
	// 练习13.53
	// 拷贝赋值运算符
	//HasPtr& operator=(const HasPtr&);
	// 这也是拷贝赋值。拷贝并交换
	//HasPtr& operator=(HasPtr rhs);
private:
	std::string *pss;
	int i;
	std::size_t* use;
};
// 13.31
inline
bool operator<(const HasPtr& h1, const HasPtr& h2) {
	return h1.pss->size() < h2.pss->size();
	//return *h1.pss < *h2.pss;
}
inline
void swap(HasPtr &lhs, HasPtr &rhs) {
	//lhs.swap(rhs);
	cout << "swap(HasPtr &lhs, HasPtr &rhs)" << endl;
	using std::swap;
	swap(lhs.pss, rhs.pss);
	swap(lhs.i, rhs.i);
	swap(lhs.use, rhs.use);
}
