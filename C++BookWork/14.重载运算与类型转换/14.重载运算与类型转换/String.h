#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& os, const String& st);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
public:
	String():String(""){}
	String(const char *);
	String(const String&);
	String& operator=(const String&);
	~String();
	const char* c_str2()const { return end; }
	const char* c_str()const { return elements; }
	size_t size()const { return end - elements; }
	size_t length()const { return end - elements + 1; }

	// 移动
	String(String &&rhs) noexcept;
	String& operator=(String &&rhs) noexcept;

	// 14.5
	char& operator[](size_t n)
	{
		return elements[n];
	}
	const char& operator[](size_t n) const
	{
		return elements[n];
	}
private:
	static allocator<char> alloc;// 分配元素
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	char *elements;
	char *end;
};
inline
ostream& operator<<(ostream& os, const String& st)
{
	os << st.c_str();
	return os;
}

inline
bool operator==(const String &lhs, const String &rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) != 0) {// 相等返回0
		return false;
	}
	return true;
}
inline
bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
inline
bool operator<(const String &lhs, const String &rhs)
{
	if (strcmp(lhs.c_str(),rhs.c_str()) >= 0) {
		return false;
	}
	return true;// 比完没找到 s1 = s2 s1 > s2情况就为true
}