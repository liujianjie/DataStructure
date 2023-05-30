#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class String
{
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

	// �ƶ�
	String(String &&rhs) noexcept;
	String& operator=(String &&rhs) noexcept;
private:
	static allocator<char> alloc;// ����Ԫ��
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	char *elements;
	char *end;
};

