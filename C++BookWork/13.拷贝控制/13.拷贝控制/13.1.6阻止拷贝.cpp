#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"

using namespace std;
/*
��ƪ������
��ĳЩ����˵������ֵ�Ϳ�������û�к�������壬�������ĳ�ֻ�����ֹ

�磺iostream���ܿ���

��.����ɾ���ĺ���
ɾ����������Ȼ���������ǣ����������κη�ʽʹ������
�ں��������б�������=deleteָ��

=delete��������ڵ�һ�������ط�
�ʺ����к���

������������������ɾ���ĳ�Ա
ֻ�ǹ涨����Ҫ����ɾ���Ļ���������������͵ı����򴴽��������ʱ����
���ǿ��Զ�̬���䣬����delete������

�ġ��ϳɵĿ������Ƴ�Ա������ɾ����
������
���������ܻὫ�ϳɵĳ�Ա����Ϊɾ����

1.�����ĳ����Ա������������ɾ���Ļ��߲��ɷ��ʣ���������������������ɾ��
2.�����ĳ����Ա�Ŀ������캯����������������ɾ���Ļ��߲��ɷ��ʣ������Ŀ������캯��������ɾ��
3.�����ĳ����Ա�Ŀ�����ֵ�������ɾ���Ļ��߲��ɷ��ʣ�������һ��const�����ó�Ա���������ϳɵĿ�����ֵ�����������ɾ����
4.�����ĳ����Ա������������ɾ���Ļ��߲��ɷ��ʣ�������һ�����ó�Ա��û�����ڳ�ʼ����������const��Ա ��û�����ڳ�ʼ������������δ��ʾ����Ĭ�Ϲ��캯��
������Ĭ�Ϲ��캯��������Ϊɾ���ġ�

���ʣ�������ĳ����Ա���ܹ��졢���� ���ƻ����٣����Ӧ�ĳ�Ա����������Ϊɾ��

�塢private���ƿ���
�±�׼֮ǰ��ͨ������������ ��ֵ����Ϊprivate����ֹ����

��Ԫ�ͳ�Ա�����Ծɿ��Կ������󣬿���ͨ�����������巽ʽ����������ʱ����
������delete��������private
*/
class A {
public:
	A() { cout << "A()" << endl; }
	void func() {
		A();
	}
};
class NoDtor {
	~NoDtor() = delete;
public:
	int a;
};
class TestCl {

public:
	const int a;
};

class Employee {

public:
	Employee();
	Employee(const string& s);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee& rhs) = delete;
	string name;
	int idcard;
	static int startincr;
};
int Employee::startincr = 1000;
Employee::Employee() 
{
	idcard = ++startincr;
}
Employee::Employee(const string& s):
	name(s), idcard(++startincr) {

}
int main() {

	int aa;
	//NoDtor n1;
	//NoDtor *n2 = new NoDtor();
	//delete n2;
	//TestCl t1;
	A a;
	a.func();

	// ��ϰ
	Employee e1("����");
	cout << e1.idcard << endl;
	Employee e2("����");
	cout << e2.idcard << endl;

	// ��Ҫ��Ψһ��idcard������������������Ҫɾ��������ֵ ��������

	/*
	TextQuery
	�������죺���һ��ָ�����ü���ָ���Ҳ��������
	������ֵ�����������ü�����1���ٸ����Ҳ��data������+1
	���������ü���-1���Ƿ�Ϊ0 �Ǿ��ͷ�
	QueryResult
	��������: ������Ҳָ��ָ��
	������ֵ���ͷ�����ָ��ָ�룬ָ���Ҳ�Ķ���
	�������ͷŰ󶨣���ɾ��
	*/
	// ����Ҫ����Ϊ�ж�һ�����Ƿ���Ҫ���������ȿ��費��Ҫ����������ָ���������Լ��������������Բ���Ҫ

	cin >> aa;
	return 0;
}