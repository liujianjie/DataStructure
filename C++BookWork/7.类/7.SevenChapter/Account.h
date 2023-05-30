#pragma once
#include <string>
using namespace std;
// 7.4.1 ���ֲ��������������
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
	typedef double Money; // �������¶���money
	Account();
	~Account();

	Money balance() { return bal; }
private:
	//typedef double Money; // �������¶���money
	Money bal;

	// 7.6 ��ľ�̬��Ա
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();

	// 7.6 �� 
	static constexpr int period = 30; // period �ǳ������ʽ
	double daily_tabl[period];
};

