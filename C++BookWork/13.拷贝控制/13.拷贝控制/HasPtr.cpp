#include "HasPtr.h"


// Ӧ�ö�̬����һ���µ�string���������󿽱���psָ���λ�ã�������ps�����λ��
//HasPtr::HasPtr(const HasPtr& hp):
//	pss(new string(*hp.pss)),
//	i(hp.i)
//{
//}
//
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	i = rhs.i;
//	//pss = rhs.pss;// Ӧ�ÿ�����psָ���λ�ã�ֻ�ǲ��õ�
//	pss = new string(*rhs.pss);
//	return *this;
//}
// ��ϰ13.22 
//HasPtr::HasPtr(const HasPtr& hp) :
//	pss(new string(*hp.pss)),
//	i(hp.i)
//{
//}
//
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	auto new_ptr = rhs;
//	delete pss;
//	pss = new_ptr.pss;// ָ���ˣ�
//	i = new_ptr.i;
//	return *this;
//}
//HasPtr::~HasPtr(){}

// 13.2.1 ��ֵ
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	auto temp = new string(*rhs.pss);
//	delete pss;
//	i = rhs.i;
//	pss = temp;
//	return *this;
//}
//13.2.2��ָ��
//HasPtr& HasPtr::operator=(const HasPtr& rhs)
//{
//	++(*rhs.use);
//	if (--*use == 0) {
//		delete use;
//		delete pss;
//	}
//	i = rhs.i;
//	use = rhs.use;
//	pss = rhs.pss;
//	return *this;
//}
// �ƶ�����
HasPtr::HasPtr(HasPtr &&p) noexcept:pss(p.pss), i(p.i), use(p.use)
{
	cout << "HasPtr(HasPtr &&p) noexcept:pss(p.pss), i(p.i)�ƶ����캯�� " << endl;
	p.pss = 0;// ����Ӱ����ߵ����ݣ���Ϊ��ָ��ֻ��ָ���Ǹ��ڴ棬���ڲ�ָ���˶���
	p.use = new size_t(1);// ֻʣ���Լ�
}
// 13.3 �ڸ�ֵ�������ʹ��swap
// �������ÿ������죬�������Ǹ��Ҳ����ĸ���
//HasPtr& HasPtr::operator=(HasPtr rhs)
//{
//	cout << "rhs.pss" << rhs.getPss() << endl;
//	cout << "rhs.use" << rhs.getUse() << endl;
//	cout << "HasPtr& operator=(HasPtr rhs)" << endl;
//	// rhsָ�򱾶����������ڴ棬thisָ���Ҳ���ڴ�
//	//swap(rhs);
//	swap(*this, rhs);
//	return *this;
//	// ������ʱ��rhs���پͻ�ɾ�������������ֵ�������ͷ��ڴ档
//}
// 
//HasPtr& HasPtr::operator=(const HasPtr &rhs)
//{
//	++(*rhs.use);
//	if (--*use == 0) {
//		delete use;
//		delete pss;
//	}
//	i = rhs.i;
//	use = rhs.use;
//	pss = rhs.pss;
//	return *this;
//}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
{
	cout << "HasPtr& HasPtr::operator=(HasPtr &&rhs) �ƶ���ֵ����� " << endl;
	if (this != &rhs) {
		i = rhs.i;
		use = rhs.use;
		pss = rhs.pss;
		rhs.i = 0;
		rhs.pss = nullptr;
		rhs.use = nullptr;
	}
	return *this;
}