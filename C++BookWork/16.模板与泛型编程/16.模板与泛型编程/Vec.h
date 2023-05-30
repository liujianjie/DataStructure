#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class Vec
{
public:
	template<class TT>
	friend ostream& operator<<(ostream &os, const Vec<TT> &s);

	template <typename ...Args>
	void emplace_back(Args&&...);

	Vec():
		elements(nullptr),first_free(nullptr),cap(nullptr)
	{}
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	~Vec();
	
	void push_back(const T&);
	size_t size()const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; }

	void reserve(size_t n);
	void resize(size_t n, const string &t = "");

	Vec(initializer_list<T>);
	
	// 14.4
	Vec &operator=(std::initializer_list<T> il) {
		auto data = alloc_n_copy(il.begin(), il.end());
		free();
		elements = data.first;
		first_free = cap = data.second;
		return *this;
	}
	void printVec();

	// 14.5
	T& operator[](size_t n)
	{
		return elements[n];
	}
	const T& operator[](size_t n)const
	{
		return elements[n];
	}
private:
	static allocator<T> alloc;// ����Ԫ��
	//����Ƿ񳬹����Ŀռ䣬�Ǿ����·���
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};
template <typename T>
allocator<T> Vec<T>::alloc;

template<class TT>
ostream& operator<<(ostream &os, const Vec<TT> &s)
{
	for (auto x : s)
		cout << x;
	return os;
}
template <typename T>
template <typename ...Args>
void Vec<T>::emplace_back(Args&&... arg)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(arg)...);
}


template <typename T>
Vec<T>::Vec(const Vec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
template <typename T>
Vec<T>::~Vec()
{
	free();
}
template <typename T>
void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

// �¿ռ� ��ʼ��λ�úͿ�����β���λ��
template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto datas = alloc.allocate(e - b);
	return{ datas, uninitialized_copy(b,e,datas) };
}
template <typename T>
void Vec<T>::free()
{
	if (elements) {
		//for (auto p = first_free; p != elements; )
		//{
		//	alloc.destroy(--p);
		//}
		cout << "free()" << endl;
		// ��ϰ ��Ҳ��֪����ô˵��for_each ��֪���᲻�������ɾ�������ɾ���ڴ棬�������ָ��
		for_each(elements, first_free, [](T &s) -> void {
			alloc.destroy(&s);
		});
		alloc.deallocate(elements, cap - elements);
	}
}
template <typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	// �������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	// �ƶ�����
	auto dest = newdata;// ���ڴ��һ������λ��
	auto elem = elements;// ���ڴ���һ��Ԫ��
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();// ֻ����ԭ�����ڴ�
		   // �������ݽṹ
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
// ��ϰ
template <typename T>
void Vec<T>::reserve(size_t n)
{
	// ��
	if (n > capacity()) {
		auto newcapacity = n;
		// �������ڴ�
		auto newdata = alloc.allocate(newcapacity);
		// �ƶ�����
		auto dest = newdata;// ���ڴ��һ������λ��
		auto elem = elements;// ���ڴ���һ��Ԫ��
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();// ֻ����ԭ�����ڴ�
			   // �������ݽṹ
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
template <typename T>
void Vec<T>::resize(size_t n, const string &t)
{
	// �������·���ֱ�Ӹ�Ĭ��ֵ
	if (n <= capacity()) {
		for (size_t i = 0; i < (capacity() - n); i++) {
			alloc.construct(first_free++, t);
		}
	}
	// ��Ҫ���·���
	if (n > capacity()) {
		auto newcapacity = n;
		// �������ڴ�
		auto newdata = alloc.allocate(newcapacity);
		// �ƶ�����
		auto dest = newdata;// ���ڴ��һ������λ��
		auto elem = elements;// ���ڴ���һ��Ԫ��
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		// ��Ԫ�ؽ���Ĭ��ֵ���� ��ס��dest����Ϊ�¿ռ�
		for (size_t i = size(); i < n - size(); i++) {
			alloc.construct(dest++, t);
		}
		free();// ֻ����ԭ�����ڴ�
			   // �������ݽṹ
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
template <typename T>
Vec<T>::Vec(initializer_list<T> li)
{
	auto newdata = alloc.allocate(li.size());
	elements = newdata;
	auto dest = newdata;
	// ����
	for (string s : li) {
		alloc.construct(dest++, s);
	}
	first_free = cap = dest;
}
// ��ͬ���� ����������ֵ
//template <typename T>
//Vec<T> &Vec<T>::operator=(std::initializer_list<std::string> il)
//{
//	auto data = alloc_n_copy(il.begin(), il.end());
//	free();
//	elements = data.first;
//	first_free = cap = data.second;
//	return *this;
//}
template <typename T>
void Vec<T>::printVec()
{
	for (auto p1 = elements; p1 != first_free; p1++) {
		cout << *p1 << endl;
	}
}