#include "StrVec136.h"


allocator<string> StrVec136::alloc;
StrVec136::StrVec136(const StrVec136& rhs)
{
	cout << "StrVec136::StrVec136(const StrVec136& rhs)" << endl;
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec136& StrVec136::operator=(const StrVec136& rhs)
{
	cout << "StrVec136& StrVec136::operator=(const StrVec136& rhs)" << endl;
	auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
StrVec136::~StrVec136()
{
	free();
}

void StrVec136::push_back(const string& s)
{
	cout << "��ֵvoid StrVec136::push_back(const string& s)" << endl;
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec136::push_back(string &&s)
{
	cout << "��ֵvoid StrVec136::push_back(string &&s)" << endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
// �¿ռ� ��ʼ��λ�úͿ�����β���λ��
pair<string*, string*> StrVec136::alloc_n_copy(const string *b, const string *e)
{
	auto datas = alloc.allocate(e - b);
	return{ datas, uninitialized_copy(b,e,datas) };
}

void StrVec136::free()
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

void StrVec136::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	// �������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	// �ƶ�����
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);
	//auto dest = newdata;// ���ڴ��һ������λ��
	//auto elem = elements;// ���ڴ���һ��Ԫ��
	//for (size_t i = 0; i != size(); ++i) {
	//	alloc.construct(dest++, std::move(*elem++));
	//}
	free();// ֻ����ԭ�����ڴ�
	// �������ݽṹ
	elements = newdata;
	//first_free = dest;
	first_free = last;
	cap = elements + newcapacity;
}
// ��ϰ
void StrVec136::reserve(size_t n)
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
void StrVec136::resize(size_t n, const string &t)
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

StrVec136::StrVec136(initializer_list<string> li)
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

// ��ָ����Ϊ�վͿ��� ʹ�䴦���޺�״̬
StrVec136::StrVec136(StrVec136 &&s) noexcept:
	elements(s.elements),first_free(s.first_free), cap(s.cap)
{
	cout << "StrVec136::StrVec136(StrVec136 &&s) noexcept:" << endl;
	s.elements = s.first_free = s.cap = nullptr;
}
StrVec136& StrVec136::operator=(StrVec136 &&rhs) noexcept
{
	cout << "StrVec136& StrVec136::operator=(StrVec136 &&rhs) noexcept" << endl;
	// �����Ը�ֵ ����ɾ������ø�ֵ ��Ȼ����Ϊ��
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}