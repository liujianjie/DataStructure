#pragma once
#include <string>
#include <iostream>
#include "Sales_data.h"
using namespace std;
class Token
{
public:
	Token();
	~Token() { if (tok == STR) { sval.~string(); } }
	// ��������
	Token(const Token&t) :tok(t.tok) { copyUnion(t);}
	Token &operator=(const Token&);// ��ֵ�������Ҫ��������string���ǵĻ�

	// �ƶ����� �� �ƶ���ֵ
	Token(const Token&&t) :tok(std::move(t.tok)) { copyUnion(std::move(t)); }
	Token &operator=(const Token&&);

	
	
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data& sd);
	

	void prints();
private:
	enum{INT,CHAR,DBL,STR,SALESDATA}tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
	// �ȼ���б�ʽ �ٿ���Union��Ա
	void copyUnion(const Token&);
	void copyUnion(const Token&&);
};

