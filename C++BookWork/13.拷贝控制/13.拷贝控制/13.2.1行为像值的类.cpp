#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"

using namespace std;
/*
���壺
ÿ������Ӧ��ӵ��һ���Լ��Ŀ���

������ֵ������ֵ�����
��������������͹��캯���Ĳ���
��Ϊ��Ҫɾ���������ָ��,�ͷ��ڴ棬���������Ͳ���Ҫ���
��ע������ֵ������Ҫ��ʱ������ɾ�����ָ�룬�Ҳ�ͬ��ɾ���˾ʹ���
*/
void fun(HasPtr h) {
	// �뿪�������deletestring
}
class TestCl {
public:
	TestCl(const string& s = string()) :
		str(new string(s)) {
	}
	~TestCl() {
		delete str;
	}
	string* str;
};
int main() {

	int aa;
	HasPtr *hs = new HasPtr("hss");
	cout << hs->getPss() << endl;
	fun(*hs);// ��ɾ��hs��str��ָ��
	//cout << hs->getPss() << endl;// Ϊ�գ��ڴ�й©
	//TestCl *t1 = new TestCl("12321");
	//auto s2 = t1->str;
	//delete t1;
	//cout << *s2 << endl;
	// ��ϰ
	/*
	���౻����ʱ����Զ������ִ���ͷ�pss��ռ���ڴ�
	δ���忽�����캯��������ɾ��pss��ռ���ڴ棬�����ڴ�й©
	*/
	/*
	strblob
	�������캯���������ݿ�����һ�ݳ�����strblob
	������ֵ���Ƚ�����ɾ�����ٿ����Ҳ��
	strblobptr
	�������죺����һ���Ŀ���
	������ֵ��һ�������ɾ���������Ҳ��

	������Ϊ����ָ���Զ�����
	*/
	cin >> aa;
	return 0;
}