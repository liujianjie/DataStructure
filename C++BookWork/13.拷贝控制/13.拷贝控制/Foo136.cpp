#include "Foo136.h"

Foo136& Foo136::operator=(const Foo136& rhs)&
{
	cout << "Foo136& Foo136::operator=(const Foo136& rhs)&" << endl;
	return *this;
}
//Foo136& Foo136::operator=(const Foo136& rhs)&&
//{
//	cout << "Foo136& Foo136::operator=(const Foo136& rhs)&&" << endl;
//	return *this;
//}

Foo136 Foo136::someMem() &
{
	cout << "&" << endl;
	sort(data.begin(), data.end());
	return *this;
}
// ������ֻ��һ�� const& ��ô&����const& Ϊconst��this���ɸı���
Foo136 Foo136::someMem() const &// �������κ����͵�Foo������const�ľ�ȷƥ�� ������ֵ
{
	cout << "const &" << endl;
	Foo136 ret(*this);
	sort(ret.data.begin(), ret.data.end());
	//sort(data.begin(), data.end());// ����
	return ret;
}
Foo136 Foo136::someMem() && // �����ڿɸı����ֵ
{
	cout << "&&" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo136 Foo136::someMem() const &&
{
	cout << "const &&" << endl;
	//sort(data.begin(), data.end());
	//return *this;
	Foo136 ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}

Foo136 Foo136::sorted() &&
{
	cout << "Foo136 Foo136::sorted() &&" << endl;
	return *this;
}
Foo136 Foo136::sorted() const &
{
	cout << "Foo136 Foo136::sorted() const &" << endl;
	Foo136 ret(*this);// �������ͨ����
	//return ret.sorted();// ���ǻ����const &�汾 ѭ��
	return *this;
	//return Foo136(*this).sorted();
	//return std::move(ret).sorted();// ���ǻ����const &�汾,�õ�const &&����ת��const&
}