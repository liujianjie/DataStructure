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

// �¿ռ� ��ʼ��λ�úͿ�����β���λ��
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
		// ��ϰ ��Ҳ��֪����ô˵��for_each ��֪���᲻�������ɾ�������ɾ���ڴ棬�������ָ��
		for_each(elements, first_free, []( string &s) -> void {
				alloc.destroy(&s); 
		});
		alloc.deallocate(elements,cap - elements);
	}
}

void StrVec::reallocate()
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
void StrVec::reserve(size_t n)
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
void StrVec::resize(size_t n, const string &t)
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

StrVec::StrVec(initializer_list<string> li)
{
	auto newdata = alloc.allocate(li.size());
	elements = newdata;
	auto dest = newdata;
	// ����
	for (string s : li) {
		alloc.construct(dest++,s);
	}
	first_free = cap = dest;
}