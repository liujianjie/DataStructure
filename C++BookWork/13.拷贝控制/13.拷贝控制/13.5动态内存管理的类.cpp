#include <iostream>
#include <vector>
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
#include "TexTQuery.h"
#include "QueryResult.h"
using namespace std;
/*
��ƪ������
ĳЩ����Ҫ������ʱ����ɱ��С���ڴ�ռ䣬����ͨ����׼��������ʵ�֣����ǿ����Լ������ڴ�����Լ����忽�����Ƴ�Ա������

���ӣ�
ֻ����string

ʵ�֣���allocator��������

��Ҫ��
���·����ڴ�Ĺ������ƶ������ǿ���Ԫ��
������Щstring�Ƕ����

�ƶ����캯����std::move��
���ֻ��� 
string���������ƶ����캯�����ƶ����Ա�����Ч�� ��������״̬
move��׼�⺯�� utilityͷ�ļ���
��move����ʾϣ��ʹ��string���ƶ����캯�������û��move�ͻ���string�Ŀ������캯����
ͨ����Ϊmove�ṩһ��using����������ֱ�ӵ���std����move


*/
ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

void func(StrVec sv)
{

}
int main() {

	int aa;
	//string *st1 = new string("1");
	//cout << st1 << endl;
	//cout << *st1 << endl;
	StrVec sv1;
	sv1.push_back("121");
	cout << *sv1.begin() << endl;
	func(sv1);
	//cout << "----------------" << endl;
	//ifstream ifs("12.3.1�ı���ѯ�������.txt");
	//TexTQuery tq(ifs);
	//string words;
	//while (cin >> words && words != "q") {
	//	print(cout, tq.query(words)) << endl;
	//}

	// ��ϰ��
	// 13.39
	// 13.40 
	// 13.41:�� ����ɣ���ָ�����һ������ô��һ���ǲ����ڵ�λ�� ���
	// 13.42
	std::cin >> aa;
	return 0;
}