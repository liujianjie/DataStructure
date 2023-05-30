#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"

using namespace std;



/*
���壺��һ����Ա�������ɲ��˺Ž��������ɣ�û�з���ֵ

���ã��ͷŶ���ʹ�õ���Դ�����ٶ���ķ�static���ݳ�Ա

��һ����Ա�������ɲ��˺Ž��������ɣ�û�з���ֵ�������ܲ���

���ܱ����أ�ֻ��һ��

����ִ�к����壬Ȼ�����ٳ�Ա���ǳ�ʼ��˳����������ٵ�

�����ڳ�ʼ���б�Ķ������Ƴ�Ա������٣�������������ʽ��

��������ڳ�Ա�����ͣ������͵ĳ�Ա��Ҫִ�г�Ա�Լ�����������

��������û����������������˵��������

������Ҫ��ʾ����һ��ָ�룬����ָ���������ͣ����������������Զ�����

ʲôʱ��������
1.�뿪������
2.�������٣����Ա������
3.���������٣���Ԫ�ر�����
4.��̬����Ķ���deleteʱ
5.��ʱ���󣬱��ʽ����

����������������ֱ�����ٳ�Ա����Ա��������������֮�������������׶��б����ٵģ��������������ٹ����У���������������Ϊ
��Ա���ٲ���֮�����һ���ֶ����е�
*/
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}

struct X {
	X() 
	{
		cout << "X();" << endl; 
	}
	X(const string& st):str(st) 
	{ 
		cout << "X(const string& st):str(st);" << endl; 
	}

	X(const X&) 
	{
		cout << "X(const X&):"<<str << endl;
	}
	X& operator=(const X& rhs) 
	{ 
		str = rhs.str; 
		cout << "X& operator=(const X& rhs)" << endl; 
		return *this;
	}
	~X() 
	{ 
		cout << "~X():" << str << endl; 
	}
	string str;
};
void testKaobei(X x1) {
	cout << "testKaobei(X x1);" << endl;
}
// ���ò��´��
void testKaobei2(X& x1) {
	cout << "testKaobei2(X& x1);" << endl;
}
// ��������ΪΪ������
X testKaobei3(X& x1)
{
	cout << "testkaobei3(X& x1);" << endl;
	return x1;
}
X& testKaobei4(X& x1)
{
	cout << "testkaobei4(X& x1);" << endl;
	return x1;
}
int main() {

	int a;
	{
		Sales_data *p = new Sales_data;
		auto p2 = make_shared<Sales_data>();
		Sales_data item(*p);
		vector<Sales_data> vec;
		vec.push_back(*p2);
		delete p;
	}
	cout << "-----------------" << endl;
	auto p1 = make_shared<int>(42);
	weak_ptr<int> wp1(p1);// wp������p��p���ü���δ�ı�
	//wp1.reset();// �����������ͷ�
	//cout << (wp1.lock()) << endl; 
	/*
	p2 item vec ������ʽ1
	p ������ʽ4
	*/
	// ��ϰ
	/*
	��һ��StrBlob��������ʱ�ᷢ��ʲô��StrBlobPtr�أ�
	data��Ա������ָ�룬���Ի�ִ���������ָ��������������ж����ü�����1���Ƿ�Ϊ0 �Ǿ�ɾ����
	StrBlobPtr��֪���᲻��ִ���ͷ���ָ��ָ�����Դ
	*/
	// 
	Sales_data *s1 = new Sales_data();
	Sales_data s2;
	fcn(s1, s2);
	// 3�Σ�ָ�벻���Զ���accum��item1,item2����������

	// ��ϰ
	// 123 ���ù��죬��ִ�п�������
	X x1 = X("123");


	testKaobei(x1);
	testKaobei2(x1);
	testKaobei3(x1);
	testKaobei4(x1);
	X x2;
	x2 = x1;// ���ÿ�����ֵ
	X *x3 = new X("13421");//�ƹ�������ʼ����ֱ�ӳ�ʼ��
	delete x3;// ����
	cin >> a;
	return 0;
}