#include <iostream>
#include "String.h"
#include <map>
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
������
������а���һ����������ת���������ȷ���������ͺ�Ŀ������֮��ֻ����Ψһһ��ת����ʽ��������ڶ�����

�磺
��һ�֣��������ṩ��ͬ������ת��
A�ඨ��һ������B������ת�����캯��
B�ඨ����һ��ת��Ŀ����A�������ת�������
�ڶ��֣��ඨ���˶��ת����������ת�������
�������������Щת���漰�����ͱ������ͨ����������ת����ϵ��һ��

��һ�֣�
ֻ����ʽָ���ĸ������ǲ���ʹ��ǿ������ת�����������Ϊǿ��ת��Ҳ���ٶ�����

�ڶ��֣�
���壺�ඨ��һ������ת�������ǵ�ת��Ŀ�����ͨ������������ϵ��һ���������
��׼������ת�����������ƥ�䵽�����ĸ�

note��������ʾ����bool���͵�ת��֮�⣬�������ⶨ������ת��������
�����ܵ�������Щ ����Ȼ��ȷ"�ķ���ʾ���캯��

�������غ�����ת�����캯��
�����ǵ������صĺ���ʱ���Ӷ������ת���н���ѡ�񽫱�ø��Ӹ���
���������������ת�����ṩ��ͬһ�ֿ���ƥ�䣬����Щ����ת��һ����

�򵥵����ӣ������඼��intת�����캯�����������غ��������������󣬵���ʱ����intֵӦ�õ����ĸ����غ���

��ʾ��ָ�����ĸ��������Խ��

note������Ҫʹ�ù��캯����ǿ������ת�����ı�ʵ�ε����ͣ���ζ������Ʋ���

�ġ����غ������û����������ת��
�������������غ�����������û����������ת�����ṩ�˿���ƥ�䣬����Ϊ��Щ����ת��һ���ã�
��һ���̲��ῼ���κο��ܳ��ֵı�׼��ת�������ȡ�
ֻ�е����غ���ֻ��ͨ��һ������ת�������õ�ƥ��ʱ���ſ��Ǳ�׼���������ȼ����� �����ᵽ�ĵڶ���

��ϰ:
14.51: ������ʾ����ת���Ż���õڶ��֣��������int��
ֻ��һ������ת�������Իῼ�����ȼ��ɣ���������Ϊ��׼�����ȼ����ڶ���.
ֻ��һ������ת�������Իῼ�����ȼ���˵����ת�����캯��������ת��������ȼ�
*/
// ��һ�֣�
struct B;
struct A {
	A() = default;
	A(const B&){}
};
struct B {
	operator A() const{
		return a;
	}
	A a;
};
A f(const A&)
{
	A a;
	return a;
}
struct Test {
public:
	operator int() {
		return 3;
	}
};
// �ڶ���
struct C {
	C() {
	}
	C(int){
		cout << "C(int = 0)" << endl;
	}
	C(double){
		cout << "C(double)" << endl;
	}
	operator int()const{
		return 2;
	}
	operator double() const{
		return 4.0;
	}
};
void f2(long double l) {
	cout << "f2():" << l << endl;
}

struct CC {
	CC(int){}
};
struct DD {
	DD(int){}
};
struct EE {
	EE(double){}
};
void manip(const CC&)
{
}
void manip(const DD&)
{
}

void manip2(const CC&)
{
}
void manip2(const EE&)
{
}

struct LongDouble {
	LongDouble(double = 0.0){}
	operator double() { return 2.0; }
	operator float() { return 1.0; }
	//operator short() { return 1; }
};
struct LongDouble2 {
	LongDouble2(double = 0.0) {}
};
void calc(int)
{
	cout << "void calc(int)" << endl;
}
void calc(LongDouble)
{
	cout << "void calc(LongDouble)" << endl;
}
void calc(LongDouble2)
{
	cout << "void calc(LongDouble2)" << endl;
}
int main()
{
	int a;
	B b;
	//A a = f(b);//���� ��A��ת������ ���� B������ת��ΪA
	// ֻ����ʽָ���ĸ������ǲ���ʹ��ǿ������ת�����������Ϊǿ��ת��Ҳ���ٶ�����
	A a1 = f(b.operator A());
	A a2 = f(A(b));

	Test t1;
	cout << t1 << endl;

	C c1;
	//f2(c1);// ����ת��������

	long long lg = 4;
	//C c2(lg);// ����ת�����춼��
	short stval = 3;
	C c3(stval);// short תΪint ����double����׼������ת�����������ƥ�䵽�����ĸ�

	// ��
	//manip(10);
	manip(CC(10));
	//manip2(10); �����Ǳ�׼������ȼ�

	// ��ϰ
	LongDouble ldObj;
	//int ex1 = ldObj;// ����ѵ�short��ѡ��c+����ת����ƥ�����,����ֻ������û�����ţ���������
	float ex2 = ldObj;

	double dval = 0.0;
	calc(dval);
	//calc(LongDouble(dval));
	/*
	14.50���ðɣ����Ƕ����ԣ��޷���Ӧ���ǵڶ�������)  ����float��
	14.51: ������ʾ����ת���Ż���õڶ��֣��������int��ֻ��һ������ת�������Իῼ�����ȼ��ɣ���������Ϊ��׼�����ȼ����ڶ���ֻ��һ������ת�������Իῼ�����ȼ���˵����ת�����캯��������ת��������ȼ�
	*/
	cin >> a;
	return 0;
}