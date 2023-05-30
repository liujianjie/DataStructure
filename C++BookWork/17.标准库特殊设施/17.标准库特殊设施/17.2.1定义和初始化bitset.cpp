#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <bitset>
using namespace std;

int main()
{
	int a;

	bitset<32> bitvec0(1U);
	cout << bitvec0 << endl;
	//
	bitset<13> bitvec1(0xbeef);
	cout << bitvec1 << endl;
	bitset<20> bitvec2(0xbeef);
	cout << bitvec2 << endl;
	bitset<128> bitvec3(~0ULL);// 多的为0，少了截取
	cout << bitvec3 << endl;

	//
	bitset<32> bitvec4("1100");
	cout << bitvec4 << endl;
	string str1("1111111000011010101010");
	bitset<32> bitvec5(str1, 5,4);
	cout << bitvec5 << endl;
	bitset<32> bitvec6(str1, str1.size()-4);
	cout << bitvec6 << endl;

	bitset<32> bitvec7(32);
	cout << bitvec7 << endl;

	bitset<64> bitvec8(1010101);
	cout << bitvec8 << endl;// 都是从一个int值初始化

	string bstr;
	cin >> bstr;
	bitset<8> bv(bstr);
	cout << bv << endl;

	/*
	练习：
	ok
	*/
	cin >> a;
	return 0;
}
