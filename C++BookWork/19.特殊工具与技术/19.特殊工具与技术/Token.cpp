#include "Token.h"



Token::Token()
{
}

// 拷贝赋值
Token& Token::operator=(const Token &t)
{
	// 先处理左侧的，Sales_data也是
	if (tok == STR && t.tok != STR) {
		sval.~string();
	}
	if (tok == SALESDATA && t.tok != SALESDATA) {
		sdval.~Sales_data();
	}
	if (tok == STR && t.tok == STR) {
		sval = t.sval;
	}
	else if (tok == SALESDATA && t.tok == SALESDATA) {
		sdval = t.sdval;
	}
	else {
		copyUnion(t);
	}
	tok = t.tok;
	return *this;
}
// 移动赋值
Token &Token::operator=(const Token&& t)
{
	// 先处理左侧的，Sales_data也是
	if (tok == STR && t.tok != STR) {
		sval.~string();
	}
	if (tok == SALESDATA && t.tok != SALESDATA) {
		sdval.~Sales_data();
	}
	if (tok == STR && t.tok == STR) {
		sval = std::move(t.sval);
	}
	else if (tok == SALESDATA && t.tok == SALESDATA) {
		sdval = std::move(t.sdval);
	}
	else {
		copyUnion(std::move(t));
	}
	tok = t.tok;
	return *this;
}

void Token::copyUnion(const Token& t)
{
	switch (t.tok)
	{
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.ival; break;
		case Token::DBL: dval = t.ival; break;
			// 使用定位new表达式构造它
		case Token::STR: new(&sval) string(t.sval); break;
		case Token::SALESDATA: new(&sdval) Sales_data(t.sdval); break;
		default:
			break;
	}
}
void Token::copyUnion(const Token&& t)
{
	switch (t.tok)
	{
	case Token::INT: ival = t.ival; break;
	case Token::CHAR: cval = t.ival; break;
	case Token::DBL: dval = t.ival; break;
		// 使用定位new表达式构造它
	case Token::STR: new(&sval) string(std::move(t.sval)); break;
	case Token::SALESDATA: new(&sdval) Sales_data(std::move(t.sdval)); break;
	default:
		break;
	}
}

Token &Token::operator=(const Sales_data& sd)
{
	if (tok == STR) { sval.~string(); }
	if (tok == SALESDATA) { 
		sdval.~Sales_data(); 
	}
	else {
		new(&sdval)Sales_data(sd);// 
	}
	tok = SALESDATA;
	return *this;
}
Token& Token::operator=(const std::string&s)
{
	if (tok == SALESDATA) { sdval.~Sales_data(); }
	if (tok == STR)
		sval = s;
	else
		new(&sval)string(s);// 否则需要构造一个string
	tok = STR;
	return *this;
}
Token &Token::operator=(int i)
{
	if (tok == STR) { sval.~string(); }
	if (tok == SALESDATA) { sdval.~Sales_data(); }
	ival = i;
	tok = INT;
	return *this;
}
Token &Token::operator=(char i)
{
	if (tok == STR) { sval.~string(); }
	if (tok == SALESDATA) { sdval.~Sales_data(); }
	cval = i;
	tok = CHAR;
	return *this;
}
Token &Token::operator=(double i)
{
	if (tok == STR) { sval.~string(); }
	if (tok == SALESDATA) { sdval.~Sales_data(); }
	dval = i;
	tok = DBL;
	return *this;
}


void Token::prints() {
	switch (tok)
	{
	case Token::INT: cout << ival << endl; break;
	case Token::CHAR:  cout << cval << endl;; break;
	case Token::DBL:  cout << dval << endl;; break;
		// 使用定位new表达式构造它
	case Token::STR: cout << sval << endl; break;;
	case Token::SALESDATA: cout<<sdval << endl; break;
	default:
		break;
	}
}
