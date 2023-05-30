#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;

vector<int>* twelvesix()
{
	return new vector<int>();
}
vector<int>* cinfun()
{
	vector<int>* ve = twelvesix();// ��̬�ڴ�
	int val;
	while (cin >> val && val != -1) {
		(*ve).push_back(val);
	}
	return ve;
}
void outfun()
{
	vector<int>* ve = cinfun();
	for (const auto &i : *ve) {
		cout << i << endl;
	}
	delete ve;// �ͷ���twelvesix cinfun outfun������vector��̬�ڴ棬����ָ�붼�ں�������ʱɾ��
}


shared_ptr<vector<int>> twelvesix2()
{
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>>  cinfun2()
{
	shared_ptr<vector<int>> ve = twelvesix2();// ��̬�ڴ�
	int val;
	while (cin >> val && val != -1) {
		(*ve).push_back(val);
	}
	return ve;
}
void outfun2()
{
	shared_ptr<vector<int>> ve = cinfun2();
	for (const auto &i : *ve) {
		cout << i << endl;
	}
	// ve�뿪������ָ����ڴ�ᱻ�Զ��ͷ�
}

bool b()
{
	int* p = new int;
	return p;
}
/*
new ��delete
������������󿽱� ��ֵ�����ٲ������κ�Ĭ�϶���

��̬�ڴ�Ĺ������׳���
1.�ڴ�й©�����ڴ�ܶ�δdelete
2.ʹ���Ѿ��ͷŵ��Ķ���
3.ͬһ���ڴ��ͷ�����
*/
int main()
{
	int a;

	// �ڶѿռ��� �ڴ���������
	int *p1 = new int;// p1ָ��һ����̬�����δ��ʼ������������
	// ��̬����Ķ���Ĭ���������Ĭ�ϳ�ʼ���� 
	// �������ͻ�������͵Ķ����ֵ����δ����ģ������Ͷ�����Ĭ�Ϲ��캯����ʼ����string����
	string *pstr = new string;// ��ʼ��Ϊ�յ�string
	int *p2 = new int;// p2ָ��һ��δ��ʼ����int

	// ������ֱ�ӳ�ʼ�� �б��ʼ������ͳ�Ĺ��췽ʽ
	int *p3 = new int(10);
	string *pstr2 = new string(10, '9');
	vector<int> *pv1 = new vector<int>{ 1,2,3 };

	//ֵ��ʼ����������֮���һ������
	string *pstr3 = new string();// ��Ĭ�Ϲ��캯����Ĭ�ϳ�ʼ��һ��
	int *p4 = new int();// �������� ������Ĭ�ϳ�ʼ��Ϊδ���壬ֵ��ʼ�����ö����ֵ

	//auto�ƶ����ͣ�ֻ�е�һ��ʼ����ʱ�ſ���
	auto p5 = new auto(4);
	//auto p6 = new auto{12, 32};

	// ��̬�����const���� ����ָ��const��ָ��
	const int *p7 = new const int;// δ���� Ҳ���ԣ�14��
	const string *p8 = new const string;// ��ʽ��ʼ��

	// ��λnew ����������new���ݶ���Ĳ���
	int *p9 = new (nothrow) int;

	// �ͷŶ�̬�ڴ� ���ڴ�黹��ϵͳ���������������ٸ�����ָ��ָ��Ķ����ͷŶ�Ӧ���ڴ�
	delete p9;// ָ��Ŀ����ǿ�ָ�� ���� ��̬����Ķ���

	// ָ��ֵ��delete ɾ���Ķ����ָ�� ���� ��̬������ڴ棬�����ɾ��ͬһ��ָ��ֵ����new������ڴ棬δ����
	// ����ͨ��������ȴ�Ǵ����
	int i1, *p10 = &i1, *p11 = nullptr;
	double *pd1 = new double(33), *pd2 = pd1;
	//delete i1;
	//delete p10;// �ֲ�����
	delete pd1;
	//delete pd2;// �ظ�ɾ�� �����ڴ��Ѿ��ͷŲ���
	delete p11;//����

	// const �����ֵ���ܸı䣬�����������������
	const int *p12 = new int(34);
	//*p12 = 43;
	delete p12;
	int *p13 = new int(34);
	*p13 = 43;

	// ����ָ�����Ķ�̬����ֱ������ʽ�ͷ�֮ǰ���Ǵ��ڵ� 
	/*
	������ʹ����������ĺ��������ˣ�ָ������� ����ָ����ֵ���ڴ治�����ٲ����Զ��ͷ�
	*/

	// ����ָ��
	int *p14 = new int(22);
	delete p14;
	//cout << *p14 << endl; ���Ǳ������Ѿ��ͷ��˵Ķ�̬�ڴ�ĵ�ַ����ָ�룬����δ��ʼ��ָ������ȱ��
	// ������λnullptr
	p14 = nullptr;

	// ���ǿ����ж��ָ��ָ��ͬһ�ڴ棬ɾ����һָ���ͷ��ڴ棬�ٸ�Ϊnullptrʹ�䰲ȫ����������ָ��ȴ����δ�����
	int *p15 = new int(12);
	int *p16 = p15;// ָ����ͬ���ڴ�
	delete p15;// p
	p15 = nullptr;// ָ��p���ٰ󶨵��κζ���,��p16����ΪnullptrΪ����ָ�룬Ҳ��Ҫָ��nullptr

	// test
	int *p17 = new int(12);
	int &pref1 = *p17;
	cout << p17 << endl;
	delete p17;
	p17 = nullptr;
	cout << p17 << endl;
	cout << &pref1 << endl;
	cout << pref1 << endl;// ����ָ����ڴ�Ϊδ���壬���ǻ���ָ���Ǹ���ַ

	// ��ϰ
	//outfun();

	// 
	//outfun2();
	// ���ᱨ������֣�p��һ����ַ������*p?����ַ����ת��Ϊbool�ɣ�
	cout << b() << endl;

	cout << ((bool)-1) << endl;// ֻҪ����0�Ķ���ת��Ϊtrue

	//
	int *p20 = new int(42), *r = new int(199);
	r = p20;// ��rָ����p20ָͬ����ڴ�
	cout << *r << endl;

	auto p21 = make_shared<int>(42), r2 = make_shared<int>(100);
	r2 = p21;
	/*��p21�����ü�������
		r2�����õݼ�Ϊ0 ���������ڴ�
		r2ָ��p21ָ����ڴ���
	*/
	cout << *r2 << endl;
	cout << p21.use_count() << endl;
		

	// test
	int *p19 = new int;// δ�����
	cout << *p19 << endl;// ֵ��δȷ��
	cout << p19 << endl;// ���ǵ�ַ������


	cin >> a;
	return 0;
}
