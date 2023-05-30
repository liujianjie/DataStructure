#include "Employee.h"



Employee::Employee()
{
}


Employee::~Employee()
{
}
Employee& Employee::operator=(const Employee &e1)
{
	// 自赋值 直接返回
	if(*this == e1){
		return *this;
	}
	idcard = e1.idcard;
	name = e1.name;
	sex = e1.sex;
	salary = e1.salary;
	return *this;
}
Employee& Employee::operator=(initializer_list<string> il)
{
	int i = 0;
	for (auto p = il.begin(); p != il.end(); p++) {
		if (i == 0) {
			idcard = *p;
		}
		else if (i == 1) {
			name = *p;
		}
		else if (i == 2) {
			sex = *p;
		}
		else if (i == 3) {
			salary = atof((*p).c_str());
		}
		i++;
	}
	return *this;
}