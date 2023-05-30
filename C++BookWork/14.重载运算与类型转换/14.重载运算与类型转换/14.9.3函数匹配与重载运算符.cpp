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
���ص������Ҳ�����صĺ���������ͨ�õĺ���ƥ�����ͬ���������ж��ڸ����ı��ʽ��������������������ص������
1.����������������ڱ��ʽ�У���ѡ�������Ĺ�ģҪ��ʹ�õ�����������ú���ʱ����
���ǣ�a + b�� a.operator(b)�� operator(a,b)���õĺ���Ҫ��

���ӵ�˵��
1.a + b��ȷ���ǵ��ó�Ա�������Ƿǳ�Ա����
2.��+���������Ϊ��Ա�����ͷǳ�Ա�������������ǲ������صģ���Ϊ���÷�ʽ��ͬ
3.��Ա������ָ�룬���Ͷ������������ã��ǳ�Ա��ֻ��ʹ�ú�����
���ԣ�
a+b:���ܵ��ã� a.operator(b)
				operator(a,b)
				�����������
��
a.operator(b)
operator(a,b)ֻ���õ�ǰ����

ǰ������Ҫ��ת�����캯��������ת�������ͻ���ֶ��ƥ�䡣
*/
class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0){}
	operator int() const { 
		cout << "operator int() const " << endl;
		return val; 
	}
	//int operator+(const SmallInt& ) const {
	//	return 2;
	//}
private:
	std::size_t val;
};
SmallInt operator+(const SmallInt&, const SmallInt&) {
	cout << "SmallInt operator+(const SmallInt&, const SmallInt&) " << endl;
	SmallInt sl;
	return sl;
}

struct LongDouble {
	//friend LongDouble operator+(LongDouble&, double);
	LongDouble operator+(const SmallInt&)
	{
		cout << "LongDouble operator+(const SmallInt&)" << endl;
		LongDouble l;
		return l;
	}
};
LongDouble operator+(LongDouble&, double)
{
	cout << "LongDouble operator+(LongDouble&, double)" << endl;
	LongDouble l;
	return l;
}
int main()
{
	int a;
	SmallInt s1, s2;
	//SmallInt s3 = s1 + s2;// ���ֶ�������Ϊ��������ͬһ���Ͷ��󣬳�����������+�����
	//int val1 = s1 + 0;// ����3������Ϊ�ڶ������������int�����Խ�s1ת��Ϊint��ʹ�����ã���Ϊ������ת�����죬smallIntתint
	//SmallInt val1 = s1 + 0;// Ҳ��3������Ϊ����������ת����intתsmallInt

	SmallInt si;
	LongDouble ld;
	//ld = si + ld;// si��û���������������
	ld = ld + si;
	ld = ld + double(si);// ������ʾ����

	SmallInt s12;
	//double d1 = s12 + 3.15;����������
	// ��ϰ
	/*
	14.52: ok ������ʾת���Ż����ת�������
	14.53�����Ϸ���s1����ת��int��������תΪdouble���㣬�� doubleת������Ϊsmall��������������ת��Ϊint
	�������������small��ת������ȥ�����У�����ִ���������ͼ���
	*/
	cin >> a;
	return 0;
}