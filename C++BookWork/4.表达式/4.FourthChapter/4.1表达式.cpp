#include <iostream>
#include <string>
#include "TestStruct.h"
#include <vector>

using namespace std;
int main()
{
	int getchar = 0;

	cout << getchar << endl;

	int ival;

	ival + 5;
	;
	// 4.13 ��ֵ˳��
	int i = 0;
	cout << i << " " << ++i << endl;
	int i2 = 1024;
	int k = -i;
	bool b = true;
	bool bb2 = -b;
	cout << (bool)bb2 << endl;

	//���
	short st = 32767;
	cout << st + 2 << endl;
	int it = 2147483647;
	cout << it + 1 << endl;

	//
	int m = 21, n = -5;
	cout << m%n << endl;
	m = -21, n = -8;
	cout << m%n << endl;
	m = -21, n = 8;
	cout << m%n << endl;

	// 4.3�߼��������ϵ�����
	int ival2, *pval2;
	//ival2 = pval2 = 0;
	string s1, s2;
	s1 = s2 = "333";
	cout << s1 << endl;

	// 4.5������ݼ�
	int fivei = 0;
	cout << fivei++ << endl;
	cout << ++fivei << endl;

	// ����ý�������������������Ϊ��ֵ�����fpival������ͬ�����Բ����л��ҹ�ϵ��
	int *fpival = &fivei;
	int fivei2 = *fpival++;
	cout << fivei2 << endl; // 2

	// ��������ڻ��ҹ�ϵ�������� *(recl+1) = toupper(*recl);(�����Ҳ��ֵ) ���� *��recl) = toupper(*beg)(��������ֵ);
	char c1 = 'a';
	char *rec1 = &c1;
	/**rec1 = toupper(*rec1++);*/
	*rec1 = toupper(*rec1);
	cout << *rec1 << endl;
	*(rec1) = toupper(*rec1 + 1);
	cout << *rec1 << endl;

	// 4.6 ��Ա���������
	string str = "asdfasdf", *p = &str;
	size_t nn = str.size();
	// ���������ȼ�
	nn = (*p).size();
	nn = p->size();
	cout << nn << endl;


	//4.7��������� ?:
	int fourgrade = 70;
	string foursoutpr = fourgrade > 60 ? "pass" : "fail";
	cout << foursoutpr << " ";
	//Ƕ�׵�
	fourgrade = 50;
	string foursoutpr2 = fourgrade > 90 ? "high" : fourgrade > 60 ? "pass" : "fail";
	cout << foursoutpr2;
	cout << endl;

	//��cout ���� ��Ϊ��������������ȼ��ܵ�
	cout << (fourgrade > 60 ? "pass" : "fail") << endl;
	cout << (fourgrade > 60) ? "pass" : "fail";//  << endl ��ʡ�� ���� endl ������һ�� ����ֵ����
	//cout << fourgrade > 60 ? "pass" : "fail";// error ��ͼ�Ƚ� cout��60

	// �ڶ��� �ȼ� cout<<(fourgrade > 60) ���1 �� 0  Ȼ�� ? ������ַ���������Ӧ������ֵ
	// ������ ���ɣ���Ϊ cout<<fourgrade �����four.. Ȼ������cout������ 60 �� cout > 60 ?����cout����>�����������

	// 4.8λ�����
	int fei = 9;
	cout << (fei << 3) << endl;//9 * 2��3�η�
	cout << (fei >> 2) << endl;//9 / 2��2�η�

	unsigned char bitchar = 0233;// 0 ��ͷΪ�˽����� 155
	cout << (bitchar << 2) << endl;// 155 * 2��2�η� 
	cout << bitchar << 2 << endl;//�������������� �������С�

	//λ��
	unsigned char bits = 0227; // 10010111
	cout << (~bits) << endl;// 111111111111111111111111 01101000

	// λ�� λ��  λ��� �������������
	unsigned char b1 = 0145; // 01100101
	unsigned char b2 = 0257; // 10101111
	cout << (b1 & b2) << endl;// 00100101
	cout << (b1 | b2) << endl;// 11101111
	cout << (b1 ^ b2) << endl;// 11001010

	//  ʹ��λ���������
	unsigned long quiz1 = 0;
	1UL << 27;// ����һ��ֵ ֻ�е�27λΪ1��ԭ�� ��ֵΪ1��λ��������27λ��0�����ǵ�27λΪ1
	// Ϊ�˸���quiz1��ֵ
	quiz1 |= 1UL << 27;// |= Ϊ quiz1 = quiz | 1UL<<27
	// Wδͨ�� ��Ϊ0
	quiz1 &= ~(1UL<<27);//~ ʹ27Ϊ0����Ϊ1�����ּ��˸�& ʹ���˵� �ָֻ���ԭ��
	// �鿴27λ�Ƿ�Ϊ1
	bool status = quiz1 &(1UL << 27);
	cout << status << endl;
	quiz1 |= 1UL << 27;
	status = quiz1 &(1UL << 27);
	cout << status << endl;

	// ��λ������������������ �ȹ�ϵ ��ֵ ���������

	// sizeof �����
	cout << "sizeof" << endl;
	Sals_data datas, *salsDatap;
	cout << sizeof(Sals_data) << endl;// Sals_data ���͵Ķ�����ռ�Ŀռ��С
	cout << sizeof datas << endl;// data�����͵Ĵ�С���� sizeof(Sals_data)
	cout << sizeof salsDatap << endl;// ָ����ռ�Ŀռ��С
	cout << sizeof *salsDatap << endl;// p��ָ���͵Ŀռ��С����sizeof��Sals_data) 
	cout << sizeof datas.reven << endl;// Sals_data ��reven��Ա��Ӧ�����͵Ĵ�С
	cout << sizeof Sals_data::reven << endl;// ��һ�ֻ�ȡreven��С�ķ�ʽ
	cout << sizeof Sals_data::bookNo << endl;
	cout << sizeof Sals_data::sold << endl;
	// sizeof �����ҽ���� ���Եȼ� sizeof��*p),���Ҳ�ʵ������ֵ��ָ������Ч δ�����Ҳû��Ӱ��

	// 4.10���������
	vector<int> ivec = {2,5,6,7,3,4,5,9};
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;

	for (auto i = 0; i != ivec.size(); ++i)
		cout << ivec[i];
	cout << endl;

	cin >> getchar;
	return -1;
}