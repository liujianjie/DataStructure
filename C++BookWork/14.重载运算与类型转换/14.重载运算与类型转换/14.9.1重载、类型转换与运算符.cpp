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
ת�����캯��������ת���������ͬ�����ˣ�������ת����Ҳ�ƣ��û����������ת��
ת�����캯��������������ת��Ϊ������󣬶��幹�캯���Ϳ��ԣ���exclipt
����ת���������������ת������������, operator type() const

����ת����������������������ͣ�����void֮�⣬������Ҫ��������Ϊ�����ķ������ͣ�����������ߺ������Ͳ��ɣ�������ת����ָ�룬��������

����ת�������
1��û����ʽ�ķ������ͣ�Ҳû���β�
2�����붨�����ĳ�Ա����
3��ͨ����Ӧ�øı��ת����������� const

���庬������ת�����������
1.���ܱ�����һ��ֻ��ִ��һ������ת���������ܽ��õ��������ת����ת�����κ�������������
2.����ת�����������ʽִ�еģ������޷�����Щ��������ʵ�Σ���ӦҲ���ܶ����κ��β�
3.��Ȼ������ָ���������ͣ���ʵ���ϻط���һ����Ӧ���͵�ֵ

note:�������ʹ������ת������
�ر���Date���͵Ķ����int���͵�ֵ֮�䲻����һ��һӳ���ϵ����ˣ������������ת�������Ҳ������

��������ת����������ܲ���������
��Ϊ����������Ͷ�����bool����ת�������
����bool��һ���������ͣ����Խ�bool���õ��κ���Ҫ�������͵���������

������ʽ������ת�������
Ϊ�˷�ֹ�������⣬����������ʽ������ת���������
(static_cast<int>(si1) + 3)	

����һ�����⣬�����ʽ�������������������Ὣ��ʽ�������Զ�ת��Ӧ������
�����ʽ����������λ��ʱ����ʽ������ת��������ʽ��ִ��
1.if while do
2.for
3.!|| &&
4. ?:

�ġ�ת��Ϊbool
���ڣ�IO���Ͷ�������void*ת������
���ڣ�Io��׼��ͨ������һ����bool����ʽ����ת��ʵ��ͬ��Ŀ��
����ʲôʱ����������ʹ�������󣬶���ʹ��ΪIO���Ͷ����operatorbool

��bool������ת��ͨ�������������������operator boolһ�㶨��explicit


*/
//
struct Integral {
	Integral(double i = 0) : val(i),intct(2) {
		if (i < 0 || i > 255)
			throw std::out_of_range("bad value");
	}
	// ��������this��תΪconst int
	operator const int() {
		cout << "operator const int() " << endl;
		return intct;
	}
	// �����߿�����this const this����ȷƥ��const this��תΪint
	operator int() const {
		cout << "operator int() const  " << endl;
		return intc;
	}
private:
	double val;
	const int intct;
	int intc;
};
class SamllInt {
public:
	// ת�����캯��
	SamllInt(int i = 0) : val(i) {
		if (i < 0 || i > 255)
			throw std::out_of_range("bad value");
	}
	explicit operator int() const { return val; }
	// ����ת�������
	//operator int() const { return val; }
	//int operator int() const;//���� ��������
	//operator int(int = 0)const;//���� �β� 
	//operator int*() const { return 42; }//����42����һ��ָ��
private:
	std::size_t val;
};
int main()
{
	int a;

	SamllInt si1;
	si1 = 4;// ת�����캯��
	//cout << si1 + 3 << endl;// si1ת��Ϊint

	SamllInt si2 = 3.14;
	//si2 + 3.15;// ��ת��Ϊint��תdouble

	int val1 = 42;
	//std::cin << val1; ���cin����bool������ת��������ʽ�ģ����ǺϷ���
	// ���ҽ�cinתΪbool��boolΪ0��1�����ƶ�42λ

	SamllInt si3;
	// ��ʽ��ǿ������ת��
	cout << (static_cast<int>(si1) + 3) << endl;// si1ת��Ϊint

	int value;
	//while (std::cin >> value);// ������״̬��good����Ϊ�� ��Ϊ��

	Integral i1;
	const Integral i2;

	// i1���÷���const int�����Ը�������ֵ�����ǲ����޸�
	const int a1 = i1;
	int a2 = i1;
	int a3 = i2;

	Integral i3(5.0);
	int a4 = i3;
	cout << a4 << endl;

	Employee e1;
	if (e1) {
		cout << "Employee e1" << endl;
	}

	// ��ϰ
	/*
	14.45,����bookno��double�Ļ�Ӧ�÷���price��
	14.46:��Ӧ�ã��鷳��������bool
	14.47��ok
	14.48��employee����Ҫbool����Ҫ�Ļ�Ҫexplicit �涨
	14.49��ok
	*/
	cin >> a;
	return 0;
}