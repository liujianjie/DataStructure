#include "StrVec.h"


allocator<string> StrVec::alloc;
//StrVec::StrVec()
//{
//}
StrVec::StrVec(const StrVec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec& StrVec::operator=(const StrVec& rhs) 
{
	auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

// 新空间 开始的位置和拷贝的尾后的位置
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto datas = alloc.allocate(e - b);
	return{ datas, uninitialized_copy(b,e,datas) };
}

void StrVec::free()
{
	if (elements) {
		//for (auto p = first_free; p != elements; )
		//{
		//	alloc.destroy(--p);
		//}
		cout << "free()" << endl;
		// 练习 我也不知道怎么说，for_each 不知道会不会逆序的删除。这个删除内存，不会操作指针
		for_each(elements, first_free, []( string &s) -> void {
				alloc.destroy(&s); 
		});
		alloc.deallocate(elements,cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 移动数据
	auto dest = newdata;// 新内存第一个可用位置
	auto elem = elements;// 旧内存下一个元素
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();// 只销毁原来的内存
	// 更新数据结构
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
// 练习
void StrVec::reserve(size_t n)
{
	// 先
	if (n > capacity()) {
		auto newcapacity = n;
		// 分配新内存
		auto newdata = alloc.allocate(newcapacity);
		// 移动数据
		auto dest = newdata;// 新内存第一个可用位置
		auto elem = elements;// 旧内存下一个元素
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();// 只销毁原来的内存
			   // 更新数据结构
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
void StrVec::resize(size_t n, const string &t)
{
	// 不用重新分配直接给默认值
	if (n <= capacity()) {
		for (size_t i = 0; i < (capacity() - n); i++) {
			alloc.construct(first_free++, t);
		}
	}
	// 需要重新分配
	if (n > capacity()) {
		auto newcapacity = n;
		// 分配新内存
		auto newdata = alloc.allocate(newcapacity);
		// 移动数据
		auto dest = newdata;// 新内存第一个可用位置
		auto elem = elements;// 旧内存下一个元素
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		// 新元素将用默认值补上 记住用dest是因为新空间
		for (size_t i = size(); i < n - size(); i++) {
			alloc.construct(dest++, t);
		}
		free();// 只销毁原来的内存
			   // 更新数据结构
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}

StrVec::StrVec(initializer_list<string> li)
{
	auto newdata = alloc.allocate(li.size());
	elements = newdata;
	auto dest = newdata;
	// 构造
	for (string s : li) {
		alloc.construct(dest++,s);
	}
	first_free = cap = dest;
}