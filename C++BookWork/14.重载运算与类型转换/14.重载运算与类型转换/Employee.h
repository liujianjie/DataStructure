#pragma once
#include <string>
using namespace std;

class Employee
{
	friend bool operator==(const Employee &lhs, const Employee &rhs);
public:
	Employee();
	~Employee();
	Employee(string idcard,string name,string sex,double salary):idcard(idcard),name(name),sex(sex),salary(salary)
	{
	}
	Employee &operator=(const Employee &e1);
	Employee &operator=(initializer_list<string>);

	// 14.49
	operator bool()
	{
		return 1;
	}
private:
	string idcard;
	string name;
	string sex;
	double salary;
};

inline
bool operator==(const Employee &lhs, const Employee &rhs)
{
	return lhs.idcard == rhs.idcard && lhs.name == rhs.name && lhs.salary == rhs.salary &&
		lhs.sex == rhs.sex;
}
inline
bool operator!=(const Employee &lhs, const Employee &rhs)
{
	return !(lhs == rhs);
}