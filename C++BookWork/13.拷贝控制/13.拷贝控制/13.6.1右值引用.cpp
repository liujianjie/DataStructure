#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <fstream>
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
#include "Folder.h"
#include "Message.h"
#include "String.h"
#include "TexTQuery.h"
#include "QueryResult.h"
/*
��ƪ������
1.�µ���������-��ֵ���ã�����󶨵���ֵ������
2.��&&��ֻ�ܰ󶨵�һ����Ҫ���ٵĶ���
3.��ֵ����ֵ�Ǳ��ʽ�����ԣ�һ����ֵ��ʾ����һ���������ݣ�һ����ֵ��ʾ�����ֵ
4.��ֵ����Ҳ��ĳ���������һ�����ֶ���
5.�󶨵�Ҫ��ת���ı��ʽ�����泣����������ֵ�ñ��ʽ

������ֵ�־ã���ֵ����
��ֵֻ�ܰ󶨵���ʱ����
1.�����õĶ���Ҫ������
2.�ö���û�������û�

��ֵ���õĴ���������ɵĽӹ������õĶ������Դ

������������ֵ
�������ʽ������ֵ��һ����ֵ��������ֵ�����Բ��ܽ�һ����ֵ���ð󶨵�һ����ֵ�������͵ı�����

�ġ���׼��move����
utilityͷ�ļ���
move��ʽ�Ľ�һ����ֵת��Ϊ�������ֵ�������͡�
��move��ŵ�����˶��ƺ�Դ����ֵ���������⣬����ʹ���������ܶ�ֵ���κμ���ʹ�ã�����ȴ����?c+14?

void fun(int &&ci) {
cout << " fun(int &&ci)" << endl;

}
void fun(int ci) {
cout << " fun(int ci)" << endl;

}
int it = 12;
const int &ci1 = std::move(it);
int &&ci2 = std::move(it);
int ci3 = std::move(it);// ������һ����ֵ������ֵ���ã�
// ci2 ��ci3�����ƶ� ��ͬ�ȵ� ���ͻ
fun(it);
//fun(std::move(it));
*/
int f();
int f() 
{
	return 23;
}
int main() {

	int aa;
	
	int i = 42;
	int &r1 = i;
	//int &&rr1 = i;
	//int &r2 = i * 42;
	const int &r3 = i * 42;// �������
	int &&rr2 = i * 42;

	// ������ֵ�־ã���ֵ����

	// ��
	int &&rr3 = 42;
	//int &&rr4 = rr3;

	// ��
	int &&rr4 = std::move(rr3);
	rr3 = 41;
	rr4 = 40;
	cout << rr3 << endl;
	cout << rr4 << endl;

	int f();
	vector<int> vi(100);

	int &&r5 = f();
	int &r6 = vi[0];
	int &r7 = r5;
	int &&r8 = vi[0] * f();

	cout << "������ʼ��ʱ���õĿ������캯��" << endl;
	String s1("you and me,sdfasdf,adf");
	String s2 = s1,s3 = s2;
	//cout << s1.c_str() << endl;
	//cout << s1.c_str2() << endl;

	// ��ϰ
	/*
	��ֵ�����ܰ󶨵�Ҫ��ת���ı��ʽ�����泣����������ֵ�ñ��ʽ
	��ֵ���ò���

	��ֵ���ݣ���ʾ���ʽ�����
	��ֵ�־ã���ʾ���ʽ��ֵ
	*/
	cout << "------------" << endl;
	cout << "��vector�����ڴ�ʱ��ִ��vector�ķ����ڴ沢�ҿ���ÿһ��Ԫ�أ�����String�Ŀ������캯��" << endl;
	vector<String> ve;
	ve.push_back(s1);
	ve.push_back(s2);
	//ve.push_back(s3);
	//ve.push_back((String)"ab");
	//ve.push_back((String)"cd");
	//ve.push_back((String)"ef");
	//ve.push_back((String)"gh");

	/*
		��Ϊ�����·����ڴ棬���ɿռ��Ԫ�ؿ������¿ռ��� ���Իᷢ���ܶ��
	*/
	std::cin >> aa;
	return 0;
}