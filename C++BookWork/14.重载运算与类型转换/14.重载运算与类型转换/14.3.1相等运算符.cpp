#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
using namespace std;

/*
��ƪ��
Ӧ�ñȽ϶����ÿһ�����ݳ�Ա

���׼��
1.�ж����������Ƿ���ȣ���ȻӦ�ö���operator==����һ����ͨ����������
2.operator==Ӧ���ж����г�Ա
3.�����������д�����
4.�õ���operator==��Ȼ��Ҫ�õ�operator��=��֮��Ȼ
5.�����Ĺ�������һ��Ӧ��ֻҪί�и���һ��

��ί�е��Ǹ�����Ҫ�����Ա������һ������

*/
int main()
{
	int a;

	Sales_data s1("a-b-s",3,23.4);
	Sales_data s2("a-b-c",4, 23.4);
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 + s2) << endl;

	cout << endl;

	StrVec sv1,sv2;
	sv1.push_back("a");
	sv1.push_back("b");
	sv1.push_back("c");
	sv1.push_back("d");
	sv2.push_back("a");
	sv2.push_back("b");
	sv2.push_back("c");
	//sv2.push_back("h");
	cout << (sv1 == sv2) << endl;
	cout << (sv1 != sv2) << endl;

	String st1("aacda"), st2("aada");
	cout << (st1 == st2) << endl;
	cout << (st1 != st2) << endl;

	cout << endl;
	StrBlob sb1,sb2;
	sb1.push_back("a");
	sb1.push_back("b");
	sb1.push_back("c");
	sb2.push_back("a");
	sb2.push_back("b");
	sb2.push_back("c");
	cout << (sb1 == sb2) << endl;

	StrBloPtr sbp1(sb1), sbp2(sb2);
	cout << (sbp1 == sbp2) << endl;

	shared_ptr<vector<string>> sp1 = make_shared<vector<string>>();
	sp1->push_back("a");
	shared_ptr<vector<string>> sp2 = make_shared<vector<string>>();;
	sp2->push_back("a");
	weak_ptr<vector<string>> wptr1(sp1);
	weak_ptr<vector<string>> wptr2(sp1);
	cout << (wptr1.lock()) << endl;
	cout << (wptr2.lock()) << endl;

	Employee ep1("1", "2", "��", 24),ep2("1","2","��",34);
	cout << (ep1 == ep1) << endl;
	cout << (ep1 != ep1) << endl;
	// ��ϰ
	/*
	���
	*/
	/*
	���
	*/
	cin >> a;
	return 0;
}