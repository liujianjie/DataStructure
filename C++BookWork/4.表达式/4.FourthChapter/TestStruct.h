
#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include <string>

struct Sals_data
{
	std::string bookNo;
	unsigned sold = 0;
	double reven = 0.0;
};
struct Sals
{

	unsigned sold = 0;
	double reven = 0.0;
	std::string bookNo;
};
// 当在本类中使用定义struct时可以声明对象 
//Sals s1, s2, s3, *s4;

#endif