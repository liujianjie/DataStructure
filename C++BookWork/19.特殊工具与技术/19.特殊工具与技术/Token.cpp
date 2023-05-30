#include "Token.h"



Token::Token()
{
}

// ������ֵ
Token& Token::operator=(const Token &t)
{
	// �ȴ������ģ�Sales_dataҲ��
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
// �ƶ���ֵ
Token &Token::operator=(const Token&& t)
{
	// �ȴ������ģ�Sales_dataҲ��
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
			// ʹ�ö�λnew���ʽ������
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
		// ʹ�ö�λnew���ʽ������
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
		new(&sval)string(s);// ������Ҫ����һ��string
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
		// ʹ�ö�λnew���ʽ������
	case Token::STR: cout << sval << endl; break;;
	case Token::SALESDATA: cout<<sdval << endl; break;
	default:
		break;
	}
}
