#pragma once
// 7.6 ��
class Bar
{
public:
	Bar();
	~Bar();
	// ������Ĭ��ʵ��
	void clear(char = bkground);
	//void clear2(char = bkground2);
private:
	// �����ǲ���������
	static Bar mem1;
	Bar *mem2;
	//Bar mem3;
	static const char bkground;
	char bkground2;
};

