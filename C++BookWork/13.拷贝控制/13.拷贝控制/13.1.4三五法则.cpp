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
1.�������캯����������ֵ���������������ͨ������һ�����廹������

��Ҫ������������Ҳ��Ҫ�����͸�ֵ����
���ۣ��Ƿ����Ҫ�������Ƴ�Ա�����Ƿ���Ҫһ���������������������Ҫһ����������Ҳ����Ҫ��������͸�ֵ�����
2.��Ϊ��������һ����̬��Դ����Ҫ��ʾdelete�������Ĭ�ϵĿ��Ʋ������Ὣ��ַ�����µĶ�����ôִ�����������������ɾ�������Ǹ���ַ�ڴ棬��ô���ǲ���ȡ��

��Ҫ������������Ҳ��Ҫ��ֵ��������֮��Ȼ
1.ĳЩ�����Ҫ��ɵĹ�����ֻ��Ҫ������ֵ����������Ҫ��������
���ۣ���ô������ֵ�Ͱ���һ����һ������Ҫһ���������캯������ôҲҪ������ֵ�����
�෴����Ҫ��ֵ�϶�Ҫ����������һ��Ҫ����

1.�����Ҫһ����������Ҳ����Ҫ��������͸�ֵ�����
2.��һ������Ҫһ���������캯������ôҲҪ������ֵ�����
�෴����Ҫ��ֵ�϶�Ҫ����������һ��Ҫ����
*/
class number {
public:
	number() :mysn(rand()) {}
	// ��������
	number(const number& rhs) :mysn(rand()) {

	}
public:
	int mysn;
};
void f(number s)
{
	cout << s.mysn << endl;
}
// �����
//void f(const number& s)
//{
//	cout << s.mysn << endl;
//}
int main() {

	int aa;
	srand((unsigned)time(NULL));

	number a, b = a, c = b;
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
	f(a);
	f(b);
	f(c);
	// 6����ͬ����
	// ����ֻ��3���� const &
	cin >> aa;
	return 0;
}