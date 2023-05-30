#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;

/*
�ڳ������ö�����ŵĶ���
�ڳ�������ʱ�����Ķ���
��new��ʵ������

δɾ�� ����ڴ�й©
ɾ�˵������� ��Ƿ�

shared_ptr������ָ��ָ��ͬһ������
unique_ptr��ռһ������
weak_ptr ��������������
ͷ�ļ� memory��
*/

void Foo() 
{
	shared_ptr<string> s = make_shared<string>("12");// ��������ʱ�Զ�����
}
shared_ptr<string> Foo2()
{
	shared_ptr<string> s = make_shared<string>("12");// ��������ʱ�Զ�����
	return s;// �������� ָ����ڴ治���ͷţ�return ��1���뿪 -1û�б�
}
int main()
{
	int a;
	string str = "hi";
	shared_ptr<string> p1(new string("21"));
	shared_ptr<list<int>> p2;//�յ�
	
	if (p1 && p1->empty()) {
		//*p1 = "hi";// ָ���µ� ����
		*p1 = str;
	}
	cout << p1 << endl;
	cout << p1.get() << endl;
	cout << p1.use_count() << endl;
	cout << p1.unique() << endl;

	// make_shared����
	// ָ��һ��ֵΪ42��int��shared_ptr
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10,'9');
	// ָ��һ��ֵ��ʼ����int ֵΪ0
	shared_ptr<int> p5 = make_shared<int>();

	auto p6 = make_shared<vector<int>>();

	// shared_ptr�Ŀ����븳ֵ
	auto p7 = make_shared<int>(42);
	auto q1(p7);//q1��p7ָ����ͬ�Ķ���// �����p7�ļ����� ���ü�����,��ô����˵ q1�����ü���=p7�����ü�������˼��
	cout << p7.use_count() << endl;

	auto p8 = make_shared<int>(30);
	p8 = p7;
	/*
	p8ָ��p7ָ���ָ��
	����p7���ü���
	�ݼ�p8ԭ�������ü���Ϊ0
	����p8ԭ����ָ��Ķ��� �Զ��ͷ�
	*/
	cout << p8.use_count() << endl;

	// ��������

	// �Զ��ͷŶ�̬����

	// ʹ�ö�̬�����ڵ���Դ����
	// ԭvector�͸���vector�е�Ԫ�����໥����ģ����й��� ���� shared_ptr,������ֻ�����һ�������ɾ�� ��ЩԪ�زſ���ɾ��

	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.data->size() << endl;
	}
	string st = "dd";
	b1.check(1, st);
	b1.pop_back();
	cout << b1.data->size() << endl;
	
	// ��ϰ
	// 12.3��Ҫ�ѡ�����Ҫ������strblob�Ĳ��˶���
	// 12.4��Ϊsize_type���������޷��ţ�������ʱ���úܴ���������Χ
	// 12.5 ��Ȼ�͵ô���һ��vector<string>���鷳
	cin >> a;
	return 0;
}
