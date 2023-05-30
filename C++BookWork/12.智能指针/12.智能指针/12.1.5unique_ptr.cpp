#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
//#include <>
using namespace std;
/*
1.ֱ�ӳ�ʼ����ʽ��ֻ��һ��unique_ptrָ��һ����������
2.û��make_shared��׼����
3.��֧����ͨ�Ŀ�����ֵ����
4.���ǽ�Ҫɾ��unique_ptrʱ���������������߸�ֵ����
5.��unique_ptr����ɾ������Ҫָ��ɾ��������
*/
unique_ptr<int> clone(int p)
{
	return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
	unique_ptr<int> ret(new int(p));
	return ret;
}
void deletefun(int *p)
{
	cout << "deletefun" << endl;
	delete p;
}
int main()
{
	int a;
	unique_ptr<string> p1(new string("Stegosaurus"));
	//unique_ptr<string> p2(p1);// ����
	//unique_ptr<string> p3;
	//p3 = p1;

	// ��������release����reset ת�ƣ���ֻ����һ��ָ���������
	unique_ptr<string> p2(p1.release());
	unique_ptr<string> p3(new string("Trex"));
	// 
	p2.reset(p3.release());//reset�ͷ���p2ԭ��ָ����ڴ�
	cout << *p2 << endl;

	unique_ptr<string> p4(new string("Steg"));
	//p4.release();// p4�����ˣ����ǲ����ͷ��ڴ棬������p4ָ�룬�����ͷ�����
	//cout << *p4 << endl;
	auto p5 = p4.release();
	cout << *p5 << endl;
	delete p5;

	// ��unique_ptr����ɾ����
	int *pp = new int(43);
	unique_ptr<int, decltype(deletefun)*> p6(pp, deletefun);
	p6.reset();

	// ��ϰ
	unique_ptr<int> p7(new int(3));
	//unique_ptr<int> p8(p7);
	//unique_ptr<int> p9 = p8;

	// 
	int p8 = 12,*p9 = &p8;
	shared_ptr<int> sp2(p9);
	cout << *sp2 << endl;

	int ix = 1025, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);
	IntP p11(pi);
	IntP p22(pi2);
	IntP p33(&ix);
	IntP p44(new int(2019));
	IntP p55(p22.get());
	cout << *p22 << endl;
	cout << *p55 << endl;

	// ��Ϊ��һ��shared_ptrrelease��ָ����ڴ���ͷ��ˣ���������shared_ptrָ��ͬһ���ڴ�

	cin >> a;
	return 0;
}
