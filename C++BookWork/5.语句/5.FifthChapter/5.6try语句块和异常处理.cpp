#include <iostream>
#include "Sales_item.h"
//#include <vcruntime_exception.h>
#include <stdexcept>
using namespace std;

void hasexception();
int main()
{
	int getchar;

	//hasexception();

	// try-catch
	//Sales_item item1, item2;
	//while (cin >> item1 >> item2) {
	//	try
	//	{
	//		if(item1.isbn() != item2.isbn())
	//			throw runtime_error("isbn not same");
	//		cout << item1 + item2;
	//	}
	//	catch (runtime_error err)
	//	{
	//		cout << err.what()
	//			<< "\nTry Again? Enter y or n" << endl;
	//		char c;
	//		cin >> c;
	//		if (!cin || c == 'n')// ����ѭ��
	//			break;
	//	}
	//}

	// stdexcept������쳣�� exception ��Ȼ���Ժ�java��һ�� ���������á���
	try
	{
		//throw range_error("rangeerror�Զ���");
		//throw overflow_error("overflow_error indentify");
		//throw exception("1121");
		//throw logic_error("�����߼�����");
		//throw domain_error("�߼����󣺲�����Ӧ�Ľ��ֵ������");
		//throw std::bad_alloc("bad_allocexction");
	}

	catch (domain_error& de) {
		cout << de.what() << "��domain_error said" << endl;
	}
	catch (logic_error & le)
	{
		cout << le.what() << "login_error exception" << endl;
	}
	catch (overflow_error& oe) {
		cout << oe.what() << ":overflow_er said";
	}
	catch (const std::exception& e)
	{
		cout << e.what() << ":exception said";
	}
	catch (range_error& rgr) {
		cout << rgr.what() << ":rgr said";
	}

	cin >> getchar;
	return 0;
}
void hasexception() 
{
	int val1 = 0, val2 = 0;
	cin >> val1 >> val2;
	if (val1 + val2 == 3)
		throw runtime_error("two values plus is three");
	cout << val1 + val2 << endl;
}