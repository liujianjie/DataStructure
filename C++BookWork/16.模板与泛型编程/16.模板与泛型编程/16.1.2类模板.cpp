#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include "Sales_data.h"
//#include "BlobAndBloPtr.h"
#include "TestMod.h"
#include "Blob.h"
#include "BloPtr.h"
#include "Foo.h"
#include "Screens.h"
#include "Screen.h"

using namespace std;

/*
��ϰ��������
Blob<int> b0 ({ 1,2,3,4,5 });
Blob<int> b1 = b0;
Blob<int> b2(b1);
Blob<int> b4 = Blob<int>({ 1,2,3,4,5 });// ��֪��Ϊʲôû�п�������ִ��
Blob<int> b3;
b3 = b2;
b3 = Blob<int>({ 1,2,3,4,5 });// �ȹ����ٿ�����ֵ
b3 = { 1,2,3,4,5 };// �ȹ����ٿ�����ֵ
*/
/*
1.��ϰ16.15 ������������������==�������ô�����ģ��������ڲ���������һ��ģ�������һ��ģ��
*/
template<typename T> using twin = pair<T, T>;

template<typename T> using partNo = pair<T, unsigned>;

int main()
{
	int a;
	// 1.ʵ������ģ��
	//Blob<int> ia;
	//Blob<int> ia2 = { 0,1,2,3 };

	//Blob<string> names;
	//Blob<double> prices;

	// ��ģ��������������ģ������

	// 5.��ģ��ĳ�Ա����
	// 6.	Check��Ԫ�ط��ʳ�Ա
	// 7.	Blob���캯��
	//Blob<string> articles = { "a","an","the" };

	//// 8.	��ģ���Ա������ʵ����
	//Blob<int> squares = { 0,1,2,3 };
	//for (size_t i = 0; i != squares.size(); ++i)
	//	squares[i] = i * i;
	// 9.��
	Blob<int> bb1({ 1,2,3,4,5 });
	//Blob<double> bb2({ 1,2,3,4,5 });
	// 10.��Ԫ
	BloPtr<int> bp1(bb1);
	bp1++;
	//BloPtr<double> bp2(bb1);// ��ƥ��

	//11
	typedef Blob<string> StrBlob;

	twin<string> authors;// pair<string,string>

	partNo<string> books;
	partNo<int> cars;
	//partNo<int, int> car2;// ����ָ���ڶ�����Ա

	// 12
	Foo<int> fi;
	auto ct = Foo<int>::count();
	ct = fi.count();
	//ct = Foo::count;

	// ��Ԫģ��
	//Pal2<C1> t1;
	//t1.printC1();

	////Pal2<double> t2;
	////t2.printC1(); //���ɷ���

	//Pal3<int> t3;
	//t3.printC1();//��������ʵ����

	//Pal2<int> t4;
	//t4.printPal1();

	//t3.printPal1();// �ڲ���double

	//C2 t5;
	//t5.printPal1();// ����

	C3 t6;
	t6.printPal1();// �Լ�ģ�������ʵ��

	cout << "Test :16.14" << endl;
	//Screens<3, 3> sc1('g');
	//cout << sc1.get() << endl;

	//Screen<5, 5> sc3('a');
	//cin >> sc3;
	//cout << sc3;

	Screens<6, 6> sc4;
	cin >> sc4;
	cout << sc4;

	// ��ϰ
	/*
	16.9:����ģ�壬������ʾ����ʽ�����ҿ��Է�����ģ�������������ģ����ͼֻ����ʾָ������
	16.10:ʵ�������г�Ա
	16.11���������ڣ����ü���ģ������б��������ǵ�������������Ҫ����
	16.12: ûɶ��ʵ��
	16.13��һ��һ�Ѻù�ϵ����Ȼ��ͬ���͵ĶԱ� ����
	16.14:ok
	16.15:ok
	16.16:�ȷ���
	*/

	cin >> a;
	return 0;
}