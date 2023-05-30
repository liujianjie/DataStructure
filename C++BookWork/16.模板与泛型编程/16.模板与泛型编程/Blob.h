#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <vector>
#include <string>
using namespace std;

// 前置声明
template <typename T> class BloPtr;

// 运算符==中参数所需要的
template <typename T> class Blob;
template <typename T>
	bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T> class Blob
{
	friend class BloPtr<T>;
	friend bool operator==<T>
		(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	Blob();
	Blob(initializer_list<T> il);
	~Blob();
	
	size_type size()const { return data->size(); };
	bool empty() const { return data->empty(); };
	void push_back(const T& t) const { data->push_back(t); };
	void push_back(T &&t) { data->push_back(std::move(t)); };

	void pop_back();

	T& front();
	T& back();

	T& front() const;
	T& back() const;

	T& operator[](size_type n);

	// 成员模板
	template<typename It> Blob(It b, It e);

private:
	shared_ptr < vector<T>> data;
	void check(size_type i, const string &msg)const;
};

template <typename T>
inline
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	if (lhs.size() == rhs.size()) {
		for (auto p1 = lhs.data->begin(), p2 = (*rhs.data).begin(); p1 != lhs.data->end(), p2 != (*rhs.data).end(); p1++, p2++)
		{
			if (*p1 != *p2)
				return false;
		}
	}
	else {
		return false;
	}
	return true;
}

template <typename T>
Blob<T>::Blob() :
	data(make_shared<vector<T>>())
{
}

template <typename T>
Blob<T>::~Blob()
{
}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) :
	data(make_shared<vector<T>>(il)) {// 用智能指针
	cout << "Blob(initializer_list<T> il)" << endl;
}
template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop");
	data->pop_back();
}
template <typename T>
T& Blob<T>::front()
{
	check(0, "front");
	return data->front();
}
template <typename T>
T& Blob<T>::back()
{
	check(0, "back");
	return data->back();
}
template <typename T>
T& Blob<T>::front() const
{
	check(0, "front");
	return data->front();
}
template <typename T>
T& Blob<T>::back() const
{
	check(0, "back");
	return data->back();
}

template <typename T>
void Blob<T>::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}
template <typename T>
T& Blob<T>::operator[](size_type n)
{
	cout << "T& Blob<T>::operator[](size_t n) " << endl;
	check(n, "太大的n");
	return (*data)[n];
}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e):
	data(make_shared<vector<T>>(b,e))
{

}

#endif // !STRBLOB_H

/*Blob(const Blob<T>& b) {
cout << "Blob(const Blob& b)" << endl;
}
Blob& operator=(const Blob<T>& b) {
cout << "Blob& operator=(const Blob<T>& b) {" << endl;
return *this;
}
Blob(const Blob<T>&& b) {
cout << "Blob(const Blob<T>&& b) {" << endl;
}
Blob& operator=(const Blob<T>&& b) {
cout << "Blob& operator=(const Blob<T>&& b) {" << endl;
return *this;
}*/