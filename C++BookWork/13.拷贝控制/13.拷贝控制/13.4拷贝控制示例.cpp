#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
#include "Folder.h"
#include "Message.h"
using namespace std;
/*
��ƪ������
������Դ�������Ҫ�������ƣ����е���Ҳ��Ҫ�������ƽ��й���


*/

int main() {

	int aa;

	//��ϰ
	/*
	Folder �´����
	const Folder �޸Ĳ��˰�
	*/

	/*
	�������캯��:���Ὣ�Ҳ����ڵ�floder����������
	������ֵ�����ὲ�Ҳ����ڵ�floder���������࣬����ֻ�ǿ��������ͷ�������ڵ�floder����
	����������ɾ��floder�����б�msg����
	*/

	string *s1 = new string("12");
	string &s2 = *s1;
	cout << &s2 << endl;

	Folder f1,f2;
	Message m1("abc"), m2("def"), m3("ghi"), m4("jkl"), m5("mon");
	m1.save(f1);
	m2.save(f1);
	m3.save(f1);
	m4.save(f2);
	m5.save(f2);
	//f1.addMsg(&m1);
	//f1.addMsg(&m2);
	//f1.addMsg(&m3);
	//f1.addMsg(&m4);
	//f1.addMsg(&m5);
	f1.debug_print();
	f2.debug_print();
	// ��ϰ
	/*
	13.38�����������Ļ�
	 ����ѭ��4�Σ���������һ�ε�ѭ��1�Σ���5�Σ���ͨ�ľ����ξͺ� �Լ���ģ���׼ȷ 
	û�ж�̬������ڴ�
	*/


	std::cin >> aa;
	return 0;
}