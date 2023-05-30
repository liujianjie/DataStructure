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

struct Strp11 {
	bitset<100> bt;
	void set(int pos, int val) {
		bt[pos] = val;
	}
	void setval(int val) {
		bitset<100> bt1(val);
		bt = bt1;
	}
};


int main()
{
	int a;
	bitset<32> test1(1U);
	bitset<32> test2;
	test2 = test1;
	cout << test2 << endl;

	bitset<32> bitvec(1U);
	/*bool is_set = bitvec.any();
	bool is_not_set = bitvec.none();
	bool all_set = bitvec.all();
	size_t onBits = bitvec.count();
	size_t sz = bitvec.size();
	bitvec.flip();
	bitvec.reset();
	bitvec.set();*/
	cout << bitvec << endl;

	bitvec.flip(0);
	cout << bitvec << endl;
	bitvec.set(bitvec.size() - 1);
	cout << bitvec << endl;
	bitvec.set(0, 0);// 
	cout << bitvec << endl;
	bitvec.reset(0);// ���� ��λ�Ǹ�ԭ����λ����ָֻ�Ƿ�תһ�£���λ��ָ��Ϊ0��
	cout << bitvec << endl;
	bitvec.reset(0);
	cout << bitvec << endl;
	cout << bitvec.test(0) << endl;

	bitvec[0] = 0;
	bitvec[31] = bitvec[0];
	bitvec[0].flip();
	~bitvec[0];// �ȼ۲�����Ҳ�Ƿ�ת��һλ
	bool b = bitvec[0];// ��bitvec[0]��ֵת��Ϊbool����
	cout << b << endl;

	// ��ȡbitsetֵ
	string s2("11001");
	bitset<32> bitvec2(s2);// �ǽ�������ת��Ϊʮ���Ƶ�ֵ
	cout << bitvec2 << endl;
	unsigned long ulong = bitvec2.to_ulong();
	cout << "ulong = " << ulong << endl;

	//
	//bitset<16> bits;
	//cin >> bits;
	//cout << "bits:" << bits << endl;//��ӡ

	//
	bitset<30> quizB;
	quizB.set(27);
	bool status = quizB[27];
	quizB.reset(27);

	cout << 0x0020212e << endl;
	bitset<32> bt1(0x0020212e);
	bitset<32> bt2;
	bt1.set(1,1);
	bt1.set(2, 1);
	bt1.set(3, 1);
	bt1.set(4, 1);
	bt1.set(5, 1);
	bt1.set(13, 1);
	bt1.set(21, 1);
	bt2.set(1.1, 1);
	cout << bt1.to_ulong() << endl;
	cout << bt2.to_ulong() << endl;

	bitset<100> bt3;
	cout << bt3 << endl;

	Strp11 sp1;
	sp1.set(1,1);
	cout << sp1.bt << endl;
	sp1.set(2, 90);// ���ܶ�� ������λ
	cout << sp1.bt << endl;

	// ���� ֻ���ڳ�ʼ����ʱ��ɻ��߳�ʼ��һ���ٸ�ֵ�������
	sp1.setval(20);
	cout << sp1.bt << endl;

	/*
	��ϰ��
	17.10��ok
	17.11:bitset<100>
	17.12:ok
	17.13:ok
	*/
	cin >> a;
	return 0;
}
