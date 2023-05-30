#include "Screens.h"

//Screens::Screens()
//{
//}
Screens::~Screens()
{
}

//inline
Screens &Screens::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
// inline // �Ϸ� ���������ⲿ û���� �ڲ����ⲿ�����ܶ���inline
char Screens::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}
void Screens::some_member() const
{
	++access_ctr;
}
void Screens::some_member2()
{
	cout << "some_member2" << endl;
}

Screens& Screens::set(char c)
{
	contents[cursor] = c;
	return *this;
}
// inline û����
 Screens& Screens::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

const Screens &Screens::display() const
{
	return *this;
}