#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <random>
#include <ctime>
using namespace std;

vector<unsigned> bad_randVec()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}
vector<unsigned> good_randVec()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

unsigned int getRand() {
	static default_random_engine e6;
	static uniform_int_distribution<unsigned> u6;
	return u6(e6);
}
unsigned int getRand2(int sedds) {
	static default_random_engine e6(sedds);
	static uniform_int_distribution<unsigned> u6;
	return u6(e6);
}
unsigned int getRand3(int sedds, int min, int max) {
	static default_random_engine e6(sedds);
	static uniform_int_distribution<unsigned> u6(min,max);
	return u6(e6);
}
int main()
{
	int a;

	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
	{
		cout << e() << " ";
	}
	cout << endl;
	cout << e.min() << " " << e.max() << endl;

	//
	uniform_int_distribution<unsigned> u(0, 9);
	for (size_t i = 0; i < 10; ++i)
	{
		cout << u(e) << " ";
	}
	cout << endl;
	//
	vector<unsigned> v1(bad_randVec());
	vector<unsigned> v2(bad_randVec());
	cout << ((v1 == v2 ? "equal" : "not equal")) << endl;
	for (int i = 0; i <= 10; ++i) {
		cout << "val1:" << v1[i] << endl;
		cout << "val2:" << v2[i] << endl;
	}
	vector<unsigned> v3(good_randVec());
	vector<unsigned> v4(good_randVec());
	cout << ((v3 == v4 ? "equal" : "not equal")) << endl;

	//
	default_random_engine e1;// e1使用默认种子
	default_random_engine e2(212321);// e1 != e2 因为种子不一样
	default_random_engine e3;
	e3.seed(32767);
	default_random_engine e4(32767);// e3 == e4因为种子一样
	for (size_t i = 0; i != 100; ++i) {
		if (e1() == e2())
			cout << "unseeded match at iteration:" << i << endl;
		if (e3() != e4())
			cout << "seed differs at iteration:" << i << endl;
	}
	//
	default_random_engine e5(time(0));
	for (size_t i = 0; i != 10; ++i) {
			cout << "val:" << e5() << endl;
	}

	// 28
	for (int i = 0; i != 10; ++i) {
		cout << "parctice:" << getRand() << endl;
	}

	int seed1;
	cout << "prees your seed:";
	cin >> seed1;
	for (int i = 0; i != 10; ++i) {
		cout << "parctice2:" << getRand2(seed1) << endl;
	}
	int min, max;
	cout << "prees your min,max:";
	cin >> min >> max;
	for (int i = 0; i != 10; ++i) {
		cout << "parctice2:" << getRand3(seed1,min,max) << endl;
	}
	/*
	练习：
	17.28:
	ok
	17.29:
	ok
	17.30:
	ok
	*/
	cin >> a;
	return 0;
}
