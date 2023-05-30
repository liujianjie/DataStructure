#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Screen.h"

// 单
extern "C" size_t strlen(const char*);
// 符合
extern "C" {
	int strcmp(const char*, const char*);
	char *strcat(char*, const char*);
}

extern "C" {
#include <string.h>
}

extern "C" void(*pf)(int);
void(*pf1)(int);
extern "C" void(*pf2)(int);
void(*pf3)(int);

extern "C" void f1(void(*)(int)){}

extern "C" typedef void FC(int);
void f2(FC *){}

//extern "C" double calc(double dparm) { return 1.2; }

//
extern "C" void prints(const char*){}
//extern "C" void prints(int){}
class SmallInt{};
class BigNum{};
extern "C" double calc(double) { return 1; }
extern SmallInt calc(const SmallInt&) { SmallInt s; return s; }
extern BigNum calc(const BigNum&) { BigNum b; return b; }

// 这也算重载吗
extern "C" int calc2(int*, int) { return 1; }
extern "C" double calc2(double*, double) { return 1; }

void clac3(int *,int) {

}
void clac3(double*, double) {

}

int main()
{
	int a;

	//pf1 = pf2;
	pf1 = pf3;

	f1(pf3);
	//f1(pf2);
	//f2(pf3);
	f2(pf3);

	//
	
	/*
	练习：
	19.26：使用c语言编译器 解释的函数 有一个int指针和int类型 返回int
			使用c语言编译器 解释的函数 有一个double指针和double类型 返回double

	这也算重载？报错。
	*/
	cin >> a;
	return 0;
}
