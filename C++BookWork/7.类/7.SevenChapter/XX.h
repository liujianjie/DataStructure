#pragma once
class XX
{
public:
	int i;
	int j;
public:
	XX();
	~XX();
	// 7.5.1 ��Ա��ʼ����˳��
	XX(int val) : j(val), i(j) {}
};

