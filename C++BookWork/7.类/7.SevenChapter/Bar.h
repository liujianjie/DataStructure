#pragma once
// 7.6 三
class Bar
{
public:
	Bar();
	~Bar();
	// 可以做默认实参
	void clear(char = bkground);
	//void clear2(char = bkground2);
private:
	// 可以是不完整类型
	static Bar mem1;
	Bar *mem2;
	//Bar mem3;
	static const char bkground;
	char bkground2;
};

