#include <iostream>
#include <string>
#include <iterator>
#include <cstring>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::begin;
using std::end;
using std::strlen;
using std::strcmp;
using std::strcat;
using std::strcpy;

constexpr int getsize() 
{
	return 1;
}

 int getsize2()
{
	return 1;
}

int main() 
{
	int right = 2;
	cout << (right >> (-30)) << endl;
	int getchar;
	// 3.5.1����ͳ�ʼ����������
	int cnt = 42;
	constexpr unsigned int sd = 42;
	//int onearr[cnt];// ���� cnt ���ǳ������ʽ
	int onearr2[42];// ����ֵ�ǳ���
	int *onearr3[sd];// �ǳ��� ��������ָ�������
	string onearr4[getsize()];// ֻ�е���������Ϊconstexpr����Ч
	//string onearr5[getsize2()];// ����
	//auto onearr5[1];// ���ɴ���auto�ؼ���
	//string &onearr6 = onearr4; ��������
	cout << onearr2[2] << endl;// δ�����ֵ
	// �� ��ʽ��ʼ������Ԫ��
	const unsigned twosz = 10;
	int twoarr1[twosz] = { 0, 1, 2 };
	int twoarr2[] = { 0, 2, 3 };
	int twoarr3[5] = { 0, 1, 2 };//ʣ������0 0 
	string twoarr4[3] = { "hi","bye" };
	//int twoarr5[2] = { 0, 1, 2 };//error 

	// ���ַ������������
	char threea1[] = { 'c','+','\0' };
	char threea2[] = "C++";// �Զ�����ַ��������Ŀ��ַ�
	//char threea3[6] = "Daniel";// erorrû���㹻�Ŀռ�

	// ���������͸�ֵ
	int foura[] = { 0, 1, 2 };// ����3��������
	//int foura2[] = foura;// Error
	//int foura2[] = {foura};
	//int foura3[] = foura;// �������ʼ�� Ҳ���� ��ֵ

	// five ��⸴�ӵ���������
	int *fivea1[10]; // ����ǿ��Դ��10������ָ�������
	//int &fivearef2[10];error ���������õ�����
	// ���ڵ�������
	// fivea2 ָ��һ������10�����ε�����
	int(*fivea2)[10] = &twoarr1;// ָ���������Բ����б��ʼ�� ���Ǳ����СΪ10
	// fivea3 ����һ������10�����ε�����
	int(&fivea3)[10] = twoarr1;//

	//������η� ��˼�ǣ�����һ�����Դ��10������ָ�������
	int *(&fivea4)[10] = fivea1;

	cout << onearr2[1] << endl;

	// 3.5.2���������Ԫ�� �±�Ϊsize_t����cstddef �ļ���
	unsigned int ftwoscore[11] = {};
	unsigned int grade;
	//while (cin >> grade) 
	//{
	//	++ftwoscore[grade / 10];// auto inde = grade / 10; ftwosocre[inde] = ftwoscore[inde] + 1;
	//}
	for (auto i : ftwoscore)
		cout << i;
	cout << endl;

	// 3.5.3ָ�������
	int fthreearr1[] = { 87,1,2,3,4 };
	cout << *(&fthreearr1[0])<<"3"<< endl;
	int fthreetarr[10] = {};
	cout << *(&fthreetarr[11]) << "3" << endl;// ������δ����ֵ ���Է��ʡ���
	int *fthreep = &fthreearr1[0];
	int *fthreep2 = fthreearr1;// ָ��������Ԫ�ص�ָ��
	//auto
	auto fthreearr2(fthreearr1);// ��һ������ָ�룬ָ���һ��Ԫ��
	cout << *fthreearr2 << endl;

	// ��decltype ��ͬ ����ָ��
	decltype(fthreearr1) fthreearr3 = {87,1};// ��fthreearr1 ά��һ�� ֵ�Լ����壬�����������δ�����ֵ
	cout << fthreearr3[3] << endl;// ��һ��ֵ fthreearr3�õ���ַ��ȡΪһ��ָ����� ��*�����õõ�ֵ

	// �� ָ��Ҳ�ǵ�����
	int fttarr1[] = {0,1,2,3,4,5};
	int *fttp = fttarr1;
	int *ftte = &fttarr1[6];
	while (fttp != ftte) 
	{
		cout << *fttp;
		fttp++;
	}
	cout << endl;

	int *fttp2 = begin(fttarr1);
	int *ftte2 = end(fttarr1);

	while (fttp2 != ftte2) 
	{
		cout << *fttp2;
		*fttp2++;
	}
	cout << endl;

	// ��.ָ������
	int fttharr1[] = { 1,2,3 ,4,5};
	int *ftthip1 = fttharr1;
	int *ftthip2 = ftthip1 + 4;// ָ�����һ�� fttharr1[4] �ȼ�Ϊ��fttharr1 + 4��;
	int *ftthip3 = fttharr1 + 5;// ָ��β��Ԫ�س�����Χ������δ����
	cout << *ftthip1 << endl;
	cout << *ftthip2 << endl;
	cout <<"*ftthip3" << *ftthip3 << endl;
	cout << "*ftthip3" << fttharr1[5] << endl;
	int *ftthip4 = fttharr1 + 5;
	auto ftthe = end(fttharr1) - begin(fttharr1);
	cout << ftthe << endl;

	//���ù�ϵ��������бȽ�
	constexpr size_t sz2 = 5;
	int *ftthb2 = fttharr1, *ftthe2 = fttharr1 + sz2;
	while (ftthb2 < ftthe2) {
		cout << *ftthb2;
		++ftthb2;
	}
	cout << endl;
	int *ftthnullptr = 0;
	cout << ftthnullptr + 0 << endl;

	// �� ������ �� ָ������Ľ���
	int ftfarr1[] = { 0,2,3 };
	int last = *(ftfarr1 + 1);//�ȼ� ftfarr1[2]
	cout << last << endl;
	last = *ftfarr1 + 1;
	cout << last << endl;//��ͬ

	//�壺ָ����±�
	int ffarr1[] = { 10,2,3,4,6,7 };
	int ffi = ffarr1[2]; // ffarr1[2]�õ���ia+2����ָ��Ԫ��
	int *ffp = ffarr1;//
	int ffi2 = *(ffp + 2);//�ȼ���ffarr1[2]
	cout << ffi << endl;
	cout << ffi2 << endl;

	int *ffp2 = &ffarr1[2];
	int ffj = ffp2[1];//�ȼ� *(p+1) ��ָ���� ffarr1[3];
	int ffk = ffp2[-2];//�ȼ� *(p-2) ��ָ���� ffarr1[-1]; �����±�Ϊ��һ��Ԫ��

	cout << ffj <<endl;
	cout << ffk << endl;

	// 3.5.4C����ַ���
	char ffourca[] = { 'c','+','+','\0'};
	cout << strlen(ffourca) << endl;// ��û�п��ַ���Ҳ������ܴ�Ĵ�ֻ�ǳ��ȴ��ˣ�

	// �Ƚ��ַ���
	const char ffourca2[] = "A String Examplez";
	const char ffourca3[] = "A String Examples";
	 char ffourca4[50] = "A String Examplez";//����Ϊconst
	 char ffourca5[] = "A String Examples";
	 string str1 = "A String Examplez";//����Ϊconst
	 string str2 = "A String Examples";
	cout << strcmp(ffourca2, ffourca3) << endl;

	// Ŀ���ַ����Ĵ�С�ɵ�����ָ��
	//strcat(str1, str2); //���С���
	cout << ffourca4 << endl;
	//strcpy(str1, str2);
	cout << ffourca4 << endl;

	// 3.5.5��ɴ���Ľӿ�
	// һ������string�����c����ַ���
	string ffiveones("hello");
	//char *ffiveones2 = ffiveones;//error
	const char *ffiveones3 = ffiveones.c_str();//true
	cout << ffiveones3 << endl;
	ffiveones = "hellos";
	cout << ffiveones3 << endl;//���

	// �� ʹ�������ʼ��Vector����
	int ffivetwo[] = { 0,1,2,3,4,5 };
	vector<int> ffivevec(begin(ffivetwo), end(ffivetwo));
	vector<int> ffivesubvec(&ffivetwo[1], &ffivetwo[4]);
	for (auto a:ffivesubvec) {
		cout << a << endl;
	}

	// 3.6��ά����
	int tsixia[3][4];
	int tsixia2[10][20][30];
	//int tsixival;//δ����
	string tsixstr;//��ʽת��
	cout << tsixstr << endl;

	//�� ��ά����ĳ�ʼ��
	int tsixtia[3][4] = { {0,1,2,3,},{4,5,6,7},{ 4,5,6,7 } };
	int tsixtia2[3][4] = { 0,1,2,3, 4,5,6,7  };

	int (&tsixtia3)[4] = tsixtia2[1];
	for (auto a: tsixtia3) {
		cout << a;
	}
	cout << endl;
	for (size_t i = 0; i != 3; ++i) 
	{
		for (size_t j = 0; j != 4; ++j) {
			cout << tsixtia[i][j];
		}
	}
	cout << endl;

	// important �÷�Χfor
	for (const auto &row : tsixtia) 
	{
		for (auto col : row) 
		{
			cout << col;
		}
	}
	cout << endl;

	for ( auto &row : tsixtia)
	{
		for (auto &col : row)
		{
			cout << col;
		}
	}
	cout << endl;

	int df = 0;
	for (const auto row : tsixtia)
	{
		cout << row << " ";
		cout << &tsixtia[df];
		/*for (auto col : row)
		{
			cout << col;
		}*/
	}
	cout << endl;

	// 3.ָ�����ά����
	int(*dwp)[4] = tsixtia;
	dwp = &tsixtia[2];
	/*cout << dwp <<"test"<< endl;
	cout << dwp+1 << "test" << endl;
	cout << *dwp << "test" << endl;
	cout << *(dwp+1) << "test" << endl;
	cout << *dwp + 2 << "test" << endl;
	cout << **dwp << "test" << endl;
	cout << *(*dwp) << "test" << endl;
	cout << (*dwp) + 2 << "(*p) + 1" << endl;
	cout << "\n\n" << endl;*/
	for (auto p = tsixtia; p != tsixtia + 3; ++p) {
		/*cout << "\n" << endl;
		cout << p << "test2" << endl;
		cout << p+1 << "test2" << endl;
		cout << *p << "test2" << endl;
		cout << *(p + 1) << "test2" << endl;
		cout << *p + 1 << "test2" << endl;
		cout << **p << "test2" << endl;
		*/
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q ;
	}
	cout << endl;

	for (auto p = begin(tsixtia); p != end(tsixtia); ++p)
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q;
	cout << endl;

	//
	using int_array = int[4];
	typedef int int_array[4];
	for (int_array *p = tsixtia; p != tsixtia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q;
	cout << endl;

	/*for (auto a : tsixtia2) {
		cout << a;

	}
	cout << endl;*/
	cin >> getchar;
	return 0;
}