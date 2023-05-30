#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
using namespace std;

int main()
{
	// �㷨����ִ����������
	int a;
	vector<int> v1(10);
	fill(v1.begin(), v1.end(), 1);// ����c��ͷ
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	fill(v1.begin(), v1.begin() + v1.size() / 2, 10);
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// �� �㷨�����д����
	vector<int> v2;
	fill_n(v2.begin(), v2.size(), 1);// û��ֵ
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	//fill_n(v2.begin(), 10, 1);// δ�����

	vector<int> v3(4);
	fill_n(v3.begin(), v3.size(), 1);// û��ֵ
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	
	// back_inserter	
	vector<int> v4;// �յ�
	auto it1 = back_inserter(v4);
	it1 = 1;
	it1 = 2;
	it1 = 3;
	for (auto beg = v4.begin(); beg != v4.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	// �����㷨��Ŀ��λ����ʹ��
	vector<int> v5;
	fill_n(back_inserter(v5), 10, 0);;//
	for (auto beg = v4.begin(); beg != v4.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// �����㷨
	int a1[] = {0,1,2,3,4,5,6,7,8};
	int a2[sizeof(a1) / sizeof(*a1)];//��С���� a2 >= a1
	auto ret1 = copy(begin(a1), end(a1), a2);// �������Ԫ�غ��λ�� ��a2��βԪ��֮���λ��
	for (auto beg = begin(a2); beg != end(a2); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	vector<int> v6{1,2,3,4,5,6,7};
	vector<int> v7(v6.size());
	replace_copy(v6.begin(), v6.end(),v7.begin(), 1, 54);
	for (auto beg = v7.begin(); beg != v7.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// ��ϰ
	vector<int> v8(10);
	fill_n(v8.begin(), v8.size(), 0);
	for (auto beg = v8.begin(); beg != v8.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// v9û��listͬ�ȴ�
	/*vector<int> v9;
	list<int> lst;
	int i;
	while (cin >> i && i != -1) {
		lst.push_back(i);
	}
	v9.resize(lst.size());
	copy(lst.cbegin(), lst.cend(), v9.begin());
	for (auto beg = v9.begin(); beg != v9.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;*/
	vector<int> v10;
	v10.reserve(10);// ֻ��Ԥ��10���ռ䣬��û��ʵ�ʴ�С
	fill_n(v10.begin(), 10, 0);

	cin >> a;
	return 0;
}