#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
	int a;
	try
	{
		range_error r("dsf");
		exception *p = &r;
		//throw r;
		//throw *p;
		throw p;
	}
	catch (range_error e)
	{
		cout << "range_error:" << e.what() << "��msg:";
	}
	catch (exception e)
	{
		cout << "exception e:" << e.what() << "��msg:";
	}
	catch (exception *e)
	{
		cout << "exception *e:" << (*e).what() << "��msg:";
	}
	/*
	��ϰ��
	18.1:
	a. range_error
	b. exception ����̬���;������е�������range_error�Ĳ���
	��Ҫ�׳� exception *p����

	18.2��
	������vector�����Ķ�������������������������٣�����p��̬������󲻻��Զ����١�

	18.3��
	1.��p��дΪ����ָ��
	2.����һ������int*��Ա���࣬����������������ָ��

	*/
	cin >> a;
	return 0;
}
