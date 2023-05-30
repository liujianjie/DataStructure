#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;
/*
��һ����make_shared();��������ָ��
1.������ʼ��һ������ָ�룬�ͱ���ʼ��Ϊһ����ָ��
2.����ָ��Ĺ��캯����explicit ������˵��������ֱ�ӳ�ʼ���������ø�ֵ��ʼ�� = 
3.��ʼ������ָ�����ָͨ�����ָ��̬�ڴ棬����ָ����deleteɾ���������ǿ��Թ���ָ���������͵���Դ��ָ���ϣ����ṩ�Լ�delete�Ĳ���
****
�������ڵı��ʽ����ʱ�������ʱ�����������ˣ������ǽ������ʱ���󴫸����ββŽ���
����ʱΪ1�����ݸ��βμ���Ϊ2������Ϊ1���βν���Ϊ0
*/

shared_ptr<int> clone(int p) {
	//return new int(p);// ���� ��ʽ����
	return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int> ptr)
{
	cout << *ptr << endl;
}
int main()
{
	int a;
	shared_ptr<int> p1;
	shared_ptr<int> p2(new int(10));// p2ָ��һ��ֵΪ42��int

	//
	//shared_ptr<int> p3 = new int(30);//����
	shared_ptr<int> p4(new int(54));

	// ��Ҫ���ʹ����ͨ������ָ��
	// Э�������������������������Ŀ��������������н�ͬһ���ڴ�󶨵��������������shared_ptr��

	shared_ptr<int> p5(new int(23));
	process(p5);// ����p5�����Ӽ��� ����Ϊ2
	int i = *p5;// ��ȷ ����Ϊ1
	cout << "i"<< i << endl;

	int *x(new int(102));
	//process(x);//error ��ʽ����
	/*
	****
	�������ڵı��ʽ����ʱ�������ʱ�����������ˣ������ǽ������ʱ���󴫸����ββŽ���
	����ʱΪ1�����ݸ��βμ���Ϊ2������Ϊ1���βν���Ϊ0
	*/
	process(shared_ptr<int>(x));// �Ϸ��������ڴ汻�ͷţ���x���ͷ� ���ܷ�����
	int j = *x;//δ����ģ�
	cout << j << endl;// ������ָ�뽻������ָ��������Ͳ�Ҫʹ������ָ������ڴ�ĺã��޷�֪��ʲôʱ������

	// ��Ҫ��get��ʼ����һ������ָ�����Ϊ����ָ�븳ֵ
	/* get����λ��ָ��
	Ϊ�˲���ʹ������ָ���ʹ����������ָ��
	ʹ��get�õ�������ָ����ò�Ҫdelete
	*/
	shared_ptr<int> p6(new int(109));
	int *q1 = p6.get();
	cout << *q1 << endl;
	{
		shared_ptr<int> p7(q1);// ���ü���Ϊ1, p7��p6�Ƕ����ģ���ô�й���
	}// p7�뿪���������ü���Ϊ0����ôɾ����q1ָ�룬����p6��ָ���ڴ�Ҳ�����ˣ�����p6�����ü���Ϊ1���� ָ����ڴ�������
	// ����p6������ʱ���ڴ�ᱻdelete ����
	cout << *p6 << endl;

	// ����shared_ptr����
	shared_ptr<int> p7(new int(12));
	cout << p7.unique() << endl;// unique�Ƿ��ռ
	p7.reset(new int(19));// ��ȷ��p7ָ���¶���,������ԭ��p7���ڴ沢��ָ�����ڴ棬��û��ָ�����ڴ棬��p��λ��

	// ��ϰ 
	// p8���ü���Ϊ1������ʱ����2����ʱ������β�3����ʱ��������2���β�����Ϊ1 û��
	shared_ptr<int> p8(new int(11));
	process(shared_ptr<int>(p8));
	cout << *p8 << endl;

	// p9���ü���Ϊ1��get����ָ�����ʱ������ʱΪ1�����β�Ϊ2����ʱ������ʱΪ1���β�����Ϊ0 ��ôָ��ָ����ڴ�û��
	shared_ptr<int> p9(new int(111));
	process(shared_ptr<int>(p9.get()));
	cout << *p9 << endl;

	// ��
	auto p10 = new int();
	auto sp = make_shared<int>();
	process(sp);// û�д�
	//process(new int());//������ʽ
	//process(p10);������ʽ ͬ��
	process(shared_ptr<int>(p10));// ������ָ�봴����ʱ����ָ�����1�����βμ���2������Ϊ1���β�����Ϊ0
	cout << *p10 << endl;

	//
	auto sp2 = make_shared<int>();
	auto p11 = sp.get();
	delete p11;// ��sp����ָ�������ָ��ɾ���Ļ����ڴ������
	//cout << *sp2 << endl;// �����

	cin >> a;
	return 0;
}
