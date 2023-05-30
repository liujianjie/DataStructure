#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include "Sales_data.h"
#include <cstdlib>
using namespace std;


// 自定义异常类
int main()
{
	int a;
	//Sales_data s1("999",2,2), s2("899", 4, 4);
	//s1 += s2;
	Sales_data item1, item2, sum,sum2;
	while (cin >> item1 >> item2) {
		try {
			//sum发生异常的话，不会执行sum2操作，将调用点调到匹配的catch后
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
	练习：
	18.9：
	ok

	18.10：
	ok,一个未捕获的异常 程序会中断
	捕获异常，程序后面的代码不执行，调用点为匹配的catch中后

	18.11：在catch里面再抛出异常，无法处理，若没有上一个调用者，或者可能递归，需要再写个catch。。

	*/
	cin >> a;
	return 0;
}
