#pragma once
#include <memory>
#include <vector>
#include <string>

// 哇，终于发现错误了，书上的代码是BlobPtr，我的是BloPtr不同呀，我靠！！！！浪费好多时间呀，下午弄了好久好久
// 前置声明
template <typename T> class BloPtr;

//template <typename T>
//	bool operator == (const Blob<T>&, const Blob<T>&);
template<typename T> class Blob
{
	friend class BloPtr<T>;
	//friend bool operator==<T>
	//	(const Blob<T>&, const Blob<T>&);
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

private:
	shared_ptr < vector<T>> data;
	void check(size_type i, const string &msg)const;
};

template <typename T> 
class BloPtr{
public:
	BloPtr() : curr(0) {}
	BloPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }

	T& operator*() const
	{
		auto p = check(curr, "*error");
		return (*p)[curr];
	}
	// 返回指针
	T* operator->() const
	{
		// 实际工作委托& 与this->是两部分，->返回指针，所以用&
		return &this->operator*();
	}
	// 14.6
	// 前置版本
	BloPtr& operator++();// 省略了BloPtr<T>，在类内可以省，在外面定义不能省
	BloPtr& operator--();

	// 后置
	BloPtr& operator++(int);
	BloPtr& operator--(int);

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>>
		check(size_t, const string&)const;
	// 保存一个weak_ptr，意味着底层vector可能被销毁
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template <typename T>
BloPtr<T>& BloPtr<T>::operator++()
{
	check(curr, "error");
	++curr;
	return *this;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator--()
{
	--curr;
	check(curr, "error");
	return *this;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator++(int)
{
	// 无需检查，而是算是委托给前置去检查
	BloPtr ret = *this;
	++*this;// 委托
	return ret;
}
template <typename T>
BloPtr<T>& BloPtr<T>::operator--(int)
{
	BloPtr ret = *this;
	--*this;// 委托
	return ret;
}

template <typename T>
shared_ptr<vector<T>> BloPtr<T>::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();// vector还在吗
	if (!ret)
		throw runtime_error("不存在");
	if (i >= ret->size())
		throw runtime_error("越界");
	return ret;
}

//template <typename T>
//inline
//bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
//{
//	if (lhs.size() == rhs.size()) {
//		for (auto p1 = lhs.data->begin(), p2 = (*rhs.data).begin(); p1 != lhs.data->end(), p2 != (*rhs.data).end(); p1++, p2++)
//		{
//			if (*p1 != *p2)
//				return false;
//		}
//	}
//	else {
//		return false;
//	}
//	return true;
//}

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

