#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>

//#include <>
using namespace std;
/*
1.��������ָ����������ڵ�����ָ�룬ָ��shared_ptr����Ķ���
2.����ָ�룬��ȫ�Ը��߰ɡ�
*/
int main()
{
	int a;
	auto p1 = make_shared<int>(42);
	weak_ptr<int> wp1(p1);// wp������p��p���ü���δ�ı�
	if (shared_ptr<int> p2 = wp1.lock())
	{
		// ��if���У�p2��p1�������
		cout << "if ��" << p2.use_count() << endl;
	}
	StrBlob sb1;
	ifstream ifs("��ϰ12.20.txt");
	string line;
	while (getline(ifs, line)) {
		sb1.push_back(line);
	}
	// sb1.begin() end ���ǻ�ȡstrbloptr;
	for (auto beg = sb1.begin(); nteq(beg, sb1.end()) ; beg.incr()) {
		cout << beg.deref() << endl;
	}

	// �Լ�д�ģ���׼ȷ���ǽ�˽�г�Ա�ų���
	//StrBloPtr sbp1(sb1);
	//while (sbp1.curr < sb1.data->size()) {
	//	cout << sbp1.deref() << endl;
	//	sbp1.incr();
	//}

	// return (*check(curr, "dereference"))[curr]; �ɶ��Ե�

	// 12.22 StrBloPtr(StrBlob &a, size_t sz = 0):������Ҫ������

	cin >> a;
	return 0;
}
