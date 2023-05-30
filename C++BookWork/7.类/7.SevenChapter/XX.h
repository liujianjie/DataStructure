#pragma once
class XX
{
public:
	int i;
	int j;
public:
	XX();
	~XX();
	// 7.5.1 成员初始化的顺序
	XX(int val) : j(val), i(j) {}
};

