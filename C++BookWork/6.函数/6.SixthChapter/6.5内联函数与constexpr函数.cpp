#include <iostream>
#include <string>
#include <cassert>
#include "Account.h"
#include "Record.h"
// butû����
//#define NOEBUG
using namespace std;

// һ��������������Ϊ����������Ҫ����ʵ�Σ���Ҫ�ڵ��õ㱣���ڼĴ���������ʱ�ָ�����Ҫת��һ����λ��ִ��
// ������������˼Ϊ�ڵ��õ���������չ��
inline const string&
shorterString(const string &s1,const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
// �ؼ��֣�inline�������Ż���ģ��С������ֱ�ӡ�Ƶ�����õĺ������ܶ��������֧�������ݹ麯��

// ����constexpr��������ʽ��Ϊ������������constexpr�����ĵ����滻������ֵ��
// 1constexpr���ڳ������ʽ�ĺ�����1.�����ķ��������Լ��β����Ͷ��N������ֵ���ͣ�2.����ֻ��һ��return���
// 2ִ�г�ʼ������ʱ���������Ѷ�constexpr�����ĵ����滻������ֵ��Ϊ���ڱ��������չ����constexpr��������ʽ��ָ��Ϊ��������
// 3.����constexpr�����ķ���ֵ����һ������
// 4.constexpr�����п�Ժ�п���䡢���ͱ�����using���������ǲ��������

int testreturn() {
	return 2;
	return 3;
}
// 1
int i = 2;
constexpr int new_sz()
{
	//if(i){}
	//3
	//return 2;
	return 42;
}
constexpr int new_sz2(int s)
{
	return s;
}
// ����constexpr��������ֵ����һ��������
constexpr size_t scale(size_t cnt) {
	return new_sz() * cnt;
}

int s;
int getintval() {

	return s;
}

//void assert(){
//
//	cout << "assert function" << endl;
//}

void print(const int ia[], size_t size) {
#ifndef NOEBUG
	//
	cerr << __func__ << "��array size is" << size << endl;
#endif
}

void f() {
	cout << "f()" << endl;
}
void f(int) {
	cout << "f(int)" << endl;
}
void f(int, int) {
	cout << "f(int,int)" << endl;
}
void f(double, double = 3.14) {
	cout << "f(double,double)" << endl;
}

int main() {
	int g;

	constexpr int foo = new_sz();//�ڱ���ʱ��֤new_sz�������ص��ǳ������ʽ������չ�������� 2.
	int i1 = getintval();
	//constexpr int foo2 = new_sz2(i1);// ���ǳ���ֵ

	//4.
	int arr[scale(2)];//��ȷ��ʵ���ǳ������ʽ������Ҳ�ǳ������ʽ
	int i2 = 2;
	scale(i);
	//int a2[scale(i)];// ���ǳ���

	// ����������constexpr��Ժ�ж�����壬���Ҷ��������ȫһ��

	// 6.5.3���԰��� һ��assertԤ�����
	cout << "start debug()" << endl;
	assert(1 < 2);// Ϊ��ʱʲôҲ������
	//assert(3 < 2);// Ϊ��ʱ�������Ϣ����ֹ�����ִ��
	cout << "end debug()" << endl;

	//��Ҫ��assert�������� ����û����
	int assert = 3;
	assert(1 < 2);

	// ����NOEBUG Ԥ�������
	// ��������NOEBUG assert ʲôҲ����������û����ѽ������

	//assert(3 < 2);

	// �������Լ��ĵ�ʽ����
	#ifndef NOEBUG
	//__func__  �����������һ���ֲ���̬���������ڴ�ź��������֡�
	cerr << __func__ << "��array size is" << 3 << endl;
	#endif
	// �Լ����������Ϣ�����Ҳ�����ֹ
	#ifndef NOEBUG
	assert(1 < 2);
		cerr << "Error: " << __FILE__
			<< " : IN FUNCTION " << __func__
			<< " at line " << __LINE__ << endl
			<< "	compiled on " << __DATE__
			<< " AT " << __TIME__ << endl
			<< "	word read was \"" << 3
			<< "\":length too short" << endl;
	#endif
	cout << "end debug" << endl;
	// 6.6����ƥ��

	f(2.56);// 
	// ������ ����
	//f(42, 2.56);
	
	// 6.6.1ʵ������ת��
	// 5����

	// ��������ƥ���constʵ��
	Record lookup(Account &);
	Record lookup(const Account &);
	const Account a;
	Account b;

	lookup(a);//�ڶ��� 
	lookup(b);//��һ�� ��ȷƥ�䲻��ת���ĺ���

	// 6.7����ָ��



	cin >> g;
	return 0;

}