#include <iostream>
#include "TestExternConst.h"
#include <string>

using namespace std;

int testconstexprval = 20;
int m = 0;
constexpr int n = 42;

int getss()
{
	return 20;
}
int main()
{
	int getchar;

	// 2.4 const
	const int bufsize = 512;
	//bufsize = 100;//error
	int bufsize2 = bufsize; // true ���Ը�ֵ

	// Test Extern Const
	//TestExternConst te;
	//cout<< te.gettestconst() <<endl;

	// 2.4.1 const������
	int ri = 1024, rri = 32;
	int &ri2 = rri;
	ri2 = 32;
	cout << "ri2 : "<< ri2 << endl;
	const int &rl = ri;//
	//rl = 42;//error ������Ϊr1 = 42 �ǽ�r1ָ���riֵ�ı�Ϊ42������const���ã����ܣ�������const int &r1 = 42��ͬ�����ǳ�ʼֵ�������Ǹ�
	//int &r2 = ri; // error

	// ��.��ʼ����const������
	// const ����
	int testzhi = 45;
	const int &testzimian = 432; //����
	//testzimian = &testzhi;

	int twoi = 42;
	const int &twori = twoi;// ����

	double twoval = 234;
	const int &tworis = twoval;// һ���м���ʱ���� �����
	//tworis = 10; error
	twoval = 20;
	cout << tworis << endl;// �õ�����234 ��Ϊ��ʱ����û�иı��20

	//test simply 
	int testi = 42;
	int &testri = testi;
	testi = 20;
	cout << testri << endl; // ���Ի�ȡΪ20

	// 2.4.2 ָ����const
	const double pi = 3.14;
	//double *ptr = &pi;//error
	const double *ptr = &pi;
	//*ptr = 45.0; error
	//pi = 34.0;

	// �����ָ������ͱ���������ָ���������һ�� 
	double twodval = 3.14;
	ptr = &twodval;//ptr ��const twodval����const
	twodval = 34;
	

	double testtransval = 3.14;
	//const int *testtranrval = &testtransval; fal ��֪��Ϊʲô

	// ����constָ��
	int twovals = 0;
	int *const twoconstvals = &twovals;
	const double twopis = 3.14;
	const double *const twopip = &twopis;// ����ȱ������ߵ�const

	int testtransvals = 10;
	//twoconstvals = &testtransvals; ���ɣ���Ϊ����ָ��
	twovals = 10;
	cout << *twoconstvals << endl;
		//twopis = 40;


	// 2.4.3 ����ָ����ײ�ָ��
	int j = 0;
	int *const plj = &j;// ����
	const int cj = 43;//����
	const int *pj2 = &cj;//�ײ� ָ��Ķ���Ϊconst
	const int *const pj3 = pj2;//����͵ײ�
	const int &rj = cj;// �ײ� �����������õĶ��ǵײ㣿 ��Ϊ���ܳ������ã����ò���һ������
	j = cj;
	pj2 = pj3;

	//int *pj = pj3;//error p3�еײ㶨��
	pj2 = pj3;
	pj2 = &j; // int* ��ת��Ϊconst int *
	//int &rjs = cj;//error
	const int &rjs2 = j;

	//2.4.4 constexpr �� �������ʽ
	const int max = 20; // �������ʽ ֵ����ı� ���ұ�������о��ܵõ��ļ������ı��ʽ
	const int limit = max + 1;// ��
	int staff = 25;//���ǳ������ʽ 27 ����ֵ�ǳ������ʽ������staff���� ��Ϊ����const
	const int sz = getss(); //���� ��Ϊ�����ڱ�������� �������й����еõ���ֵ

	// �� constexpr����
	constexpr int inf = 20; // ��ɳ������ʽ��
	//constexpr const int szs = getss();//�ǳ������ʽ�� ����û�б�����̵ĳ�ʼֵ �ֲ���

	// �� ����ֵ���� string ���ǣ�ָ�� ������
	//constexpr string str = "dd";//error ����������ֵ
	//constexpr const int *testconstexprp2 = &max; ������
	
	// �ܵ��ϸ����ƣ�0 nullptr �̶��洢��ַ
	constexpr const int *testconstexprp = 0;
	constexpr const int *testconstexprp2 = &testconstexprval;// �̶���ַ

	//constexpr const int &testconstexprp3 = max;// Ҳ������
	constexpr const int &testconstexprp3 = testconstexprval;// ����

	// �� ָ���constexpr
	const int *points = nullptr;	// p ��һ��ָ�����γ�����ָ��
	constexpr int *qoints = nullptr;// q��ָ��һ��ָ�������ĳ���ָ�� ��ָ��ָ��Ķ����޹أ��ؼ�����constexpr ����������Ķ�����Ϊ�˶���const

	//��2������ָ��ǳ������߳���
	
	constexpr const int *pn = &n;// ����ָ�룬ָ�����ͱ���n
	constexpr int *pm = &m; // ����ָ�룬ָ������m

	cin >> getchar;
	return 0;
}
