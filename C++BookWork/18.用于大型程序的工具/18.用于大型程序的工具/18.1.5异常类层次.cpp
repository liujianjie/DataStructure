#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include "Sales_data.h"
#include <cstdlib>
using namespace std;


// �Զ����쳣��
int main()
{
	int a;
	//Sales_data s1("999",2,2), s2("899", 4, 4);
	//s1 += s2;
	Sales_data item1, item2, sum,sum2;
	while (cin >> item1 >> item2) {
		try {
			//sum�����쳣�Ļ�������ִ��sum2�����������õ����ƥ���catch��
			sum = item1 + item2;

			sum2 = item1.noexceplus(item2);
		}
		catch (const isbn_mismatch &e) {
			cerr << e.what() << ": left isbn(" << e.left << ")right isbn(" << e.right << ")" << endl;
			try {
				throw isbn_mismatch("wrong isbns ", item1.isbn(), item2.isbn());
			}
			catch (const isbn_mismatch &e) {
				cerr << e.what() << "2: left isbn(" << e.left << ")right isbn(" << e.right << ")" << endl;
			}
			
		}
	}

	/*
	��ϰ��
	18.9��
	ok

	18.10��
	ok,һ��δ������쳣 ������ж�
	�����쳣���������Ĵ��벻ִ�У����õ�Ϊƥ���catch�к�

	18.11����catch�������׳��쳣���޷�������û����һ�������ߣ����߿��ܵݹ飬��Ҫ��д��catch����

	*/
	cin >> a;
	return 0;
}
