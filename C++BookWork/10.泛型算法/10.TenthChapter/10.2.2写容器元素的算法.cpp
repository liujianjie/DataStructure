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
	// 算法不会执行容器操作
	int a;
	vector<int> v1(10);
	fill(v1.begin(), v1.end(), 1);// 不能c开头
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	fill(v1.begin(), v1.begin() + v1.size() / 2, 10);
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// 二 算法不检查写操作
	vector<int> v2;
	fill_n(v2.begin(), v2.size(), 1);// 没有值
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	//fill_n(v2.begin(), 10, 1);// 未定义的

	vector<int> v3(4);
	fill_n(v3.begin(), v3.size(), 1);// 没有值
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	
	// back_inserter	
	vector<int> v4;// 空的
	auto it1 = back_inserter(v4);
	it1 = 1;
	it1 = 2;
	it1 = 3;
	for (auto beg = v4.begin(); beg != v4.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;
	// 可做算法的目的位置来使用
	vector<int> v5;
	fill_n(back_inserter(v5), 10, 0);;//
	for (auto beg = v4.begin(); beg != v4.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// 拷贝算法
	int a1[] = {0,1,2,3,4,5,6,7,8};
	int a2[sizeof(a1) / sizeof(*a1)];//大小必须 a2 >= a1
	auto ret1 = copy(begin(a1), end(a1), a2);// 返回添加元素后的位置 即a2的尾元素之后的位置
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

	// 练习
	vector<int> v8(10);
	fill_n(v8.begin(), v8.size(), 0);
	for (auto beg = v8.begin(); beg != v8.end(); ++beg) {
		cout << *beg << endl;
	}
	cout << endl;

	// v9没有list同等大
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
	v10.reserve(10);// 只是预留10个空间，并没有实际大小
	fill_n(v10.begin(), 10, 0);

	cin >> a;
	return 0;
}