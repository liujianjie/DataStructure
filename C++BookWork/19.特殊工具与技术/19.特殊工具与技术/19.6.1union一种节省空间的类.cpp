#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Token.h"
#include "TextQuerys.h"
using namespace std;

union Token0 {
	char cval;
	int ival;
	double dval;
};

union Token1 {
	string st1;
	int ival2;
};

/*
˼�����Ҫ��
������Ҫ�������Ƶ����ϳ�Ա��
1.����������union����һ��enum�б�ʽ
2.�ÿ������Ƹ�union��ֵ��ͨ��enum�Ƿ��컹������
3.���磬��token = 32���жϵ�ǰ�Ƿ�Ϊstring���Ǿ��������ٸ�ival��ֵ32
4.���磬��token��ֵstring���жϵ�ǰ�Ƿ�Ϊstring�������Ǿ͹��죬���Ǿ�ֱ�Ӹ�ֵ
*/
int main()
{
	int a;
	//Token0 first_token = { 'a' };// cval
	//Token0 last_token;// δ��ʼ����
	//Token0 *pt = new Token0;//δ��ʼ��

	////last_token.ival = 12;
	//last_token.cval = 'z';
	////cout << last_token.ival << endl;
	//pt->ival = 42;

	////
	//union 
	//{
	//	char cval1;
	//	int ival1;
	////protected:
	//	double dval;
	//};
	//cval1 = 'c';
	//cout << cval1 << endl;

	//
	//Token1 tk1;
	//Token1 *tk2 = new Token1;
	//Token to;
	//to = 'z';
	//to = 32;
	////to = "nihao";
	//to.prints();

	//Token to2;
	//to2 = "asdfasd";
	//to = to2;
	//to.prints();

	cout << "-----��ϰ----------" << endl;
	Token tk1,tk2;
	//tk1 = "12321321";
	//tk1 = tk1;
	//tk1.prints();
	tk1 = 23;
	tk1 = Sales_data("a-df-s12",1,1);
	tk1.prints();

	tk2 = Sales_data("12312-s12", 1, 1);
	tk1 = tk2;
	tk1.prints();

	a = 10;
	if (a > 6) {
		cout << "a > 6" << endl;
	}
	else if (a > 7) {
		cout << "a > 7" << endl;
	}
	else {
		cout << "a > 9" << endl;
	}

	/*
	��ϰ��
	19.21:ok
	19.22:ok
	19.23:ok
	19.24:����ú� ���ᷢ������ ���ǵ��ÿ������캯������������ͬ�ȵ�tok����Ȼ�Լ������Լ� ��û�����
	19.25��ok ���п���
	*/
	cin >> a;
	return 0;
}
