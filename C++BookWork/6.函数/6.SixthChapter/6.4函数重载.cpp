#include <iostream>
#include <string>
#include "Phone.h"
#include "Record.h"
#include "Account.h"
using namespace std;

 #pragma warning(disable:4996);
void print(const char *cp) {
	cout << "print(const char *cp)" << endl;
}

void print(const int *beg, const int *end) 
{
	cout << "print(const int *beg,const int *end)" << endl;
}
void print(const int ia[], size_t size) {
	cout << "print(const int ia[],size_t size)" << endl;
}

int lookup(char &r) 
{
	return 0;
}
int lookup(string &p)
{
	return 0;
}
int lookup(int &name)
{
	return 0;
}
// note: �β�һ�������Ƿ���ֵ��һ���Ĳ�������
//char lookup(int &c) 
//{
//
//}

Record lookup(Phone) { Record r; return r; }
//Record lookup(const Phone) { Record r; return r; }

Record lookup(Phone*) { Record r; return r; }
//Record lookup(Phone* const) { Record r; return r; } Ҳ���С�


Record lookup(Phone&) { Record r; return r; }
Record lookup(const Phone&) { Record r; return r; }// �º���
Record lookup(Account*) { Record r; return r; }// �º���
Record lookup(const Phone*) { Record r; return r; }// �º���

const string &shorterString(const string &s1, const string &s2) 
{
	return s1.size() <= s2.size() ? s1 : s2;
}

// 
string &shorterString(string &s1, string &s2) 
{
	auto& r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

// 6.4.1
string read();
//void prints(const string &);
//void prints(double);
void footBars(int ival)
{
	bool read = false;
	// error ��Ϊbool read�����Բ��е�
	//string s = read();
	//void prints(int);
	// error ��Ϊ������ĸ����������prints������string
	//prints("Value: ");
	//prints(ival);
	//prints(3.14);
}
// ������3������ͬһ���������ʾ���ɼ�
//void printt(const string&);
//void printt(double);
//void printt(int);
void fooBar2(int ival)
{
	//printt("Value:");
	//printt(ival);
	//printt(3.14);
}
typedef string::size_type sz;// 
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ')// (, int i);һ��ĳ����������Ĭ�ϲ��� �������Ҳ������Ĭ�ϲ��������򲻿���
{
	string s;
	return s;

}
string screen2(sz, sz, char = ' ');

// Ĭ��ʵ������ �����޸�һ���Ѿ����ڵ�Ĭ��ֵ
//string screen2(sz,sz,char = '*');//�ظ�����

// �е㲻������������Ĭ��ʵ�Σ�ȴ���ܰ�char���ں��棿�ð� char����Ĭ��ʵ�Σ�

/*
	1.�ðɣ��ҷ������������ˣ���������������Ϊ����������char ����Ĭ��ʵ��
	2.���ǣ����涨����screen2��Ĭ��ʵ�Σ��ǿ��е�
	3.���Բ����������Ǹ�һ���޸�һ���Ѿ����ڵ�Ĭ��ֵ��ֻ���޸Ĳ���Ĭ��ʵ�εĲ���
*/
string screen2(sz, sz = 3, char);
/*
string screen2(sz = 2, sz = 1, char);��һ���ǲ��е�sz = 3������������ֻ�������Ĭ��ֵ
*/
string screen2(sz = 2, sz, char);

sz wd = 80;
char def = ' ';
sz ht() {
	return 2;
}

string screen3(sz  s1 = ht(), sz s2 = wd, char ch = def) {
	cout<< s1 <<" "<< s2 << " "<<ch;
	return " need return window value or error";
}
void f2();
int main() 
{
	int getchar;
	int j[2] = {0,1};
	print("hello world"); // ����print(const char*)
	print(j, end(j) - begin(j));
	print(begin(j), end(j));	// ��������һ���̶��ϼ������Ա�����֡������ֵĸ���
	
								
	// �������غ���
	int a1;
	lookup(a1);

	// �ж������βε������Ƿ�����
	// ��ʱ�������β��б�������һ������ʵ��������ͬ��
	//Record lookup(const Account &acct);
	//Record lookup(const Account &); ֻ��ʡ�����βε�����

	/*typedef Phone Telno; Telno��Phone�ı���
	Recorde lookup(const Phone&);
	Recorde lookup(const Telno&);*/

	// ����const��Ӱ�촫�뺯���Ķ���
	
	// ����β���ĳ�����͵�ָ��������ã�����������ָ���ǳ��������Ƿǳ����������ʵ�ֺ�������
	// 1.�����볣���β�ʱ�����ܱ仯���������ͣ�����ֻ��ƥ�䳣���β�
	// 2.������ǳ����β�ʱ�����Ա仯�ɳ����βΣ������4���ᶼ����ƥ���޳����Ķ�������ָ�룬����220ҳ �ὲ����ƥ��
	
	// const_cast ������
	
	// �������صĺ���

	// 6.4.1������������
	
	// 6.5.1Ĭ��ʵ��
	
	// ���þ���Ĭ��ʵ�εĺ�������������ʡ��Ҳ���������û��Զ���ֵ
	// 1.ʡ�Լ��ǵ������Ĭ�ϲ���
	/*string window;
	window = screen();
	window = screen(66);
	window = screen(66, 256);
	window = screen(66, 256, '#');*/
	// 2.Ĭ��ʵ��ֻ�β��������ֻ��ʡ��β���Ĳ���
	//screen(,,'?');//error
	// ? ��תΪint��Ȼ����תΪstring,����˵����ֻ�Ӵ�����ƥ��
	//screen('?');//true ,����screen('?',80,' ')

	// ����Ĭ��ʵ��������screen2

	// ����Ĭ��ʵ�γ�ʼֵ
	// 1.�ֲ�����������ΪĬ��ʵ�Ρ�ֻҪ���ʽ�������ܹ�ת�����β���������ͣ��ñ��ʽ������ΪĬ��ʵ��

	/*sz wd = 80;
	char def = ' ';
	sz ht();*/

	//string screen3(sz = ht(), sz = wd, char = def);
	// ��סscreen3��Ҫreturnֵ ��Ϊwindow��Ҫ���գ���Ȼ�ᱨ��
	string window = screen3();//����screen3(ht(),80,' ')

	f2();



	cin >> getchar;
}
void f2() 
{
	def = '*';// �ı���Ĭ��ʵ�ε�ֵ��
	sz wd = 100;// ��������㶨���wd������û�иı�Ĭ��ֵ����Ӱ�����wd
	string window = screen3();// screen(ht(),80,'*');
}
