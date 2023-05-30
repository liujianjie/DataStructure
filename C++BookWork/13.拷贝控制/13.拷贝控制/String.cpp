#include "String.h"


allocator<char> String::alloc;
String::String(const char *c)
{
	auto e = c;
	while (*e != '\0')
		e++;
	e++;//再加尾后
	auto data = alloc_n_copy(c,e);
	elements = data.first;
	end = data.second;
}
String::String(const String& rhs)
{
	cout << "String::String(const String& rhs);" << endl;
	// 分配右边同等的大小
	auto newdata = alloc_n_copy(rhs.elements, rhs.end);// 好奇这个会转换为迭代器吗？
	elements = newdata.first;
	end = newdata.second;
}
String& String::operator=(const String& rhs)
{
	cout << "String& String::operator=(const String& rhs);" << endl;
	auto newdata = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newdata.first;
	end = newdata.second;
	return *this;
}
String::~String()
{
	free();
}
pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto datas = alloc.allocate(e - b);
	return { datas, uninitialized_copy(b, e, datas) };
}
void String::free()
{
	if (elements) {
		// end指向尾后指针 所以需要前置
		//for (auto q = end; q != elements; ) {
		//	alloc.destroy(--q);
		//}
		//alloc.deallocate(elements, size());
		for_each(elements, end, [](char &c) -> void {
			alloc.destroy(&c);
		});
		alloc.deallocate(elements, end - elements);
	}
}

String::String(String &&rhs) noexcept:
	elements(rhs.elements),end(rhs.end)
{
	cout << "String::String(String &&rhs) noexcept 移动构造函数" << endl;
	rhs.elements = rhs.end = nullptr;
}
String& String::operator=(String &&rhs) noexcept
{
	cout << "String& String::operator=(String &&rhs) 移动赋值运算符" << endl;
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}