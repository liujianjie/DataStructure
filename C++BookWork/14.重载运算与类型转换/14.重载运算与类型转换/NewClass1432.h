#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "StrBloPtr.h"
using namespace std;

class NewClass1432
{
public:
	NewClass1432();
	NewClass1432(StrBloPtr &sp):sp(new StrBloPtr(sp)){}
	~NewClass1432();
	StrBloPtr& operator*()const
	{
		return *sp;
	}
	StrBloPtr* operator->()const
	{
		return &this->operator*();
	}
private:
	StrBloPtr *sp;
};

