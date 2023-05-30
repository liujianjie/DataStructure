#pragma once
#include <string>
using namespace std;
// 7.4.1 名字查找与类的作用域
//typedef double Money;
//string bal;
//class Account
//{
//public:
//	Account();
//	~Account();
//
//	Money balance() { return bal; }
//private:
//	Money bal;
//};
//typedef double Money;
class Account
{
public:
	typedef double Money; // 可以重新定义money
	Account();
	~Account();

	Money balance() { return bal; }
private:
	//typedef double Money; // 可以重新定义money
	Money bal;

	// 7.6 类的静态成员
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();

	// 7.6 二 
	static constexpr int period = 30; // period 是常量表达式
	double daily_tabl[period];
};

