#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

int main()
{
	int a;
	// ���Ԫ��
	// ֮ǰ֮��ĵ�����ʧЧ�ᱨ�������ú�ָ������δ�����ֵ
	vector<int> v1{0,1,2,3,4,5,6};
	auto itprev1 = v1.begin() + 0;
	auto itafter1 = v1.begin() + 3;

	int* pprev1 = &v1.at(0);// 1֮ǰλ�õ�ָ��
	int* pafter1 = &v1.at(3);// 1֮���λ��ָ��
	auto &rprev1 = v1.at(0);// ����
	auto &rafter1 = v1.at(3);// ����
	
	cout << *itprev1 << endl;
	cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	v1.insert(v1.begin()+2, 2);

	cout << "----------------" << endl;
	//cout << *itprev1 << endl;
	//cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;
	cout << "----------------" << endl;
	// deque,��β֮���������ʧЧ��ָ��Ԫ�ص����ú�ָ�벻��ʧЧֻ��ָ��ֵ��һ���ˣ���������β��ָ��ֵ�����
	deque<int> de1{ 0,1,2,3,4,5,6,7,8,9 };
	auto itprev2 = de1.begin() + 0;
	auto itafter2 = de1.begin() + 3;
	int* pprev2 = &de1.at(0);// 1֮ǰλ�õ�ָ��
	int* pafter2 = &de1.at(3);// 1֮���λ��ָ��
	auto &rprev2 = de1.at(0);// ����
	auto &rafter2 = de1.at(3);// ����

	cout << *itprev2 << endl;
	cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	de1.insert(de1.begin() + 2, 9);

	cout << "----------------" << endl;
	//cout << *itprev2 << endl;
	//cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	cout << "-------list��forward_list-------" << endl;
	// ������������ʧЧ
	list<int> li1{ 0,1,2,3,4,5,6,7,8,9 };
	auto itprev3 = li1.begin();
	auto itafter3 = ++++++li1.begin();

	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	li1.insert(++++li1.begin(), 9);

	cout << "----------------" << endl;
	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	// ɾ��Ԫ��
	cout << "--- ɾ��Ԫ��---------" << endl;
	cout << "-----vector--------" << endl;
	// ֻ��ɾ��֮ǰ�ĵ�������ʧЧ��֮���֮ǰ�����ú�ָ�붼��Ч��֮���ָ���ָ����һ��ֵ����
	vector<int> v2{ 0,1,2,3,4,5,6,7,8,9 };
	itprev1 = v2.begin() + 0;
	itafter1 = v2.begin() + 3;

	pprev1 = &v2.at(0);// 1֮ǰλ�õ�ָ��
	pafter1 = &v2.at(3);// 1֮���λ��ָ��
	rprev1 = v2.at(0);// ����
	rafter1 = v2.at(3);// ����

	cout << *itprev1 << endl;
	cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	v2.erase(v2.begin() + 2);

	cout << "----------------" << endl;
	cout << *itprev1 << endl;
	//cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	cout << "------de2--------" << endl;
	// ����λ�ã�������ʧЧ��ָ��Ԫ�ص����ú�ָ�벻��ʧЧֻ��ָ��ֵ��һ����
	// β��λ�ò�Ӱ��
	// ��λ�ã�������ʧЧ��ָ��Ԫ�ص����ú�ָ�벻Ӱ��
	deque<int> de2{ 0,1,2,3,4,5,6,7,8,9 };
	itprev2 = de2.begin() + 0;
	itafter2 = de2.begin() + 3;
	pprev2 = &de2.at(0);// 1֮ǰλ�õ�ָ��
	pafter2 = &de2.at(3);// 1֮���λ��ָ��
	rprev2 = de2.at(0);// ����
	rafter2 = de2.at(3);// ����

	cout << *itprev2 << endl;
	cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	de2.erase(de2.begin());

	cout << "----------------" << endl;
	//cout << *itprev2 << endl;
	//cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	cout << "------list--------" << endl;
	// ����ʧЧ
	list<int> li2{ 0,1,2,3,4,5,6,7,8,9 };
	 itprev3 = li2.begin();
	 itafter3 = ++++++li2.begin();

	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	li2.erase(++li2.begin());

	cout << "----------------" << endl;
	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	cout << "----------------" << endl;
	// ��д�ı�������ѭ������
	vector<int> vi3 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter3 = vi3.begin();
	while (iter3 != vi3.end()) {
		if (*iter3 % 2) {
			iter3 = vi3.insert(iter3, *iter3);// insertָ�����֮ǰ��Ԫ��
			iter3 += 2;// ��ǰ����2��
		}
		else {
			iter3 = vi3.erase(iter3);// eraseָ��ɾ��֮���Ԫ��
		}
	}
	for (auto beg = vi3.begin(), end = vi3.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// ��Ҫ����end���صĵ�����
	// end���صĵ�������vector��string��ɾ��/���Ԫ�أ�deque��֮�����/ɾ����end�ܻ�ʧЧ
	vector<int> vi4 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin = vi4.begin();
	auto end = vi4.end();
	// end��������ʧЧ
	//while (begin != end) {
	//	++begin;// ���ڵ�ǰԪ��֮�����
	//	begin = vi4.insert(begin, 42);
	//	++begin;
	//}
	while (begin != vi4.end()) {
		++begin;// ���ڵ�ǰԪ��֮�����
		begin = vi4.insert(begin, 42);
		++begin;
	}
	for (auto beg = vi4.begin(), end = vi4.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// ��ϰ
	cout << "��ϰ" << endl;
	// 9.31
	list<int> li4 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter4 = li4.begin();
	while (iter4 != li4.end()) {
		if (*iter4 % 2) {
			iter4 = li4.insert(iter4, *iter4);// insertָ�����֮ǰ��Ԫ��
			++++iter4;// ��ǰ����2��
		}
		else {
			iter4 = li4.erase(iter4);// eraseָ��ɾ��֮���Ԫ��
		}
	}
	cout << "out while" << endl;
	for (auto beg = li4.begin(), end = li4.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.32
	vector<int> vi5 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter5 = vi5.begin();
	while (iter5 != vi5.end()) {
		if (*iter5 % 2) {
			iter5 = vi5.insert(iter5, *iter5++);// insertָ�����֮ǰ��Ԫ��
			iter5++;// ��ǰ����2��
		}
		else {
			iter5 = vi5.erase(iter5);// eraseָ��ɾ��֮���Ԫ��
		}
	}
	for (auto beg = vi5.begin(), end = vi5.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.33 ��ʧЧ��vi6��Ӻ���Ϊ�����������֮�������Ի�ʧЧ��
	vector<int> vi6 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin2 = vi6.begin();
	//while (begin2 != (vi6.end() - 2)) {
	//	++begin2;// ���ڵ�ǰԪ��֮����ӻ��õ�����ʧЧ ��û���¶���
	//	vi6.insert(begin2, 42);
	//}
	for (auto beg = vi6.begin(), end = vi6.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.34 ����ѭ��
	cout << "9.34"<<endl;
	vector<int> vi7 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin3 = vi7.begin();
	while (begin3 != (vi7.end())) {
		if (*begin3 % 2)
			begin3 = vi7.insert(begin3, *begin3);
		++begin3;
	}
	for (auto beg = vi7.begin(), end = vi7.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	//int val1 = 4;
	//int	*p2 = &val1;
	//int &r2 = val1;
	//cout << val1 << endl;
	//*p2 = 5;
	//cout << val1 << endl;
	//r2 = 6;
	//cout << val1 << endl;
	cin >> a;
	return 0;
}