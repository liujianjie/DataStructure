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
	// 拷贝构造
	Token(const Token&t) :tok(t.tok) { copyUnion(t);}
	Token &operator=(const Token&);// 赋值运算符需要销毁左侧的string若是的话

	// 移动构造 和 移动赋值
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
	// 先检查判别式 再考虑Union成员
	void copyUnion(const Token&);
	void copyUnion(const Token&&);
};

