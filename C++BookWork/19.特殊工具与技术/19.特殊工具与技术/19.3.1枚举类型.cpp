#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

enum color { red, yellow, green };
//enum stoplight{red,yellow,green};// �ظ������Ա
enum class peppers{red,yellow,green};

enum class inTypes {
	charTyp, shortType, intType
};
enum class inTypes2 {
	charTyp2 = 8, shortType2 = 16, intType2 = 16,
	longTyp2 = 32, long_longType = 64
};

// ���޶�û��Ĭ��
enum intValues:unsigned long long{
	charTyp = 255, shortTyp = 63552,intType = 2222,
	longTyp = 213213213UL,
	long_longTyp = 221321321ULL
};

enum intValues2 : unsigned long long;
enum class open_modes;

enum class intValues3;
//enum intValues3;
enum intValues4 : int;
//enum intValues4 : long;// ���ܸı�

enum Tokens{INLINE = 128,VIRTUAL = 129};
void ff(Tokens) { cout << "void ff(Tokens)" << endl; }
void ff(int){ cout << "void ff(int)" << endl; }

//void newf(Tokens) { cout << "void newf(Tokens)" << endl; }
void newf(unsigned char){ cout << "void newf(unsigned char)" << endl; }
void newf(int) { cout << "void newf(int)" << endl; }

//enum Xianding : short{
//	xiandingval = 18446744073709551615ULL
//};
enum class Xianding2 {
	xiandingval2 = 18446744073709551615ULL
}; 


// 20190907 
//enum class newview : int;
//enum class newview {
//	long_longTyp2 = 22132132112321321312
//};
enum  newview : unsigned long long;
enum  newview : unsigned long long{
	long_longTyp2 = 2213213211232132421ULL
};
int main()
{
	newview nw1 = newview::long_longTyp2;
	int a;
	/*
	1.�޶�����Ĭ��int�����޶�û��Ĭ�����ͣ�����Ǳ����Ϊ������ö�ٳ�Ա����
	2.Ϊ�޶��Ͳ��޶�ָ��ĳ�����ͣ�ö�ٳ�Ա���ܳ�����Χ�������������Զ��������ᱨ��
	3.�޶������򣬱�����ʾָ����Ա����Ϊö�ٳ�Ա�ķ�Χ��ö����
	*/
	//Xianding x = xiandingval;
	Xianding2 x2 = Xianding2::xiandingval2;

	Tokens curTok = INLINE;
	ff(128);
	ff(INLINE);// �����Ե���ff(int)����ff(tokens)����ȷƥ��
	ff(curTok);

	// ���޶��������Ա����ת��Ϊ���Σ��þ�ȷƥ��
	unsigned char uc = VIRTUAL;
	newf(VIRTUAL);
	newf(uc);
	color eyes = green;// 
	//peppers p = green;// ������

	color hair = color::red;
	peppers p2 = peppers::red;

	constexpr inTypes val1 = inTypes::shortType;

	//
	//inTypes i1 = 2;
	inTypes i2 = inTypes::intType;

	int i = color::red;
	int j = color::yellow;
	cout << i << endl;
	cout << j << endl;

	//
	unsigned long long ui = intValues::long_longTyp;
	cout << ui << endl;


	// test 20190908
	unsigned int test1 = -2;
	cout << test1 << endl;

	cout << "hello world" << endl;

	//int byte - size = 1;
	/*
	��ϰ����
	*/
	cin >> a;
	return 0;
}
