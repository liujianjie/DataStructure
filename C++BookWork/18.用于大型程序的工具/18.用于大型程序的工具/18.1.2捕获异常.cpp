#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <cstdlib>
using namespace std;


void mainp() {
	try {
		cout << "test try:" << endl;
		ifstream is("sfadf.txt");
		int zero = 0;
		int a = 12 / zero;
		cout << "end try:" << endl;
	}
	catch (...) {
		cout << "catch :" << endl;
		throw;
	}
}

class exceptionType {
public:
	exceptionType() = default;
	int a;
};

int main()
{
	int a;
	//mainp();
	//try
	//{
	//	exceptionType *e = new exceptionType();
	//	throw *e;
	//}
	//catch (const std::exception& e)
	//{
	//	cout << "exception:" << e.what() << "，msg:";
	//}
	//catch (...)
	//{
	//	cout << " ...:" << "，msg:" << endl;
	//   //abort();
	//}

	// 练习-----
	//try
	//{
	//	throw new exception();
	//}
	//catch (exceptionType *pet)
	//{
	//	cout << "(exceptionType *pet)" << endl;// 能捕获但是没处理
	//}
	//try
	//{
	//	throw exception();
	//}
	//catch (...)
	//{
	//	cout << "b..." << endl;
	//}

	//typedef int EXCPTYPE;
	//try
	//{
	//	throw 1;
	//}
	//catch (EXCPTYPE e)
	//{
	//	cout << "c..." << e<< endl;
	//}
	// 练习结束

	// 自己的想法，但差不多，第一题对了，第二第三不行 但有点思路了
	//try
	//{
	//	exceptionType *e = new exceptionType();
	//	throw *e;
	//}
	//catch ( exceptionType *e)
	//{
	//	cout << "exceptionType:"  << "，msg:";
	//}
	//catch (exception *e)
	//{
	//	cout << "exception:" <<(*e).what()<< "，msg:";
	//}
	//catch (...)
	//{
	//	cout << "a ...:"  << "，msg:" << endl;
	//}

	// b
	//try
	//{
	//	exceptionType *e = new exceptionType();
	//	throw *e;
	//}
	//catch (...)
	//{
	//	cout << "b ...:"  << "，msg:" << endl;
	//}

	// c
	//typedef int EXCPTYPE;
	//try
	//{
	//	EXCPTYPE *e = new EXCPTYPE(12);
	//	throw *e;
	//}
	//catch (EXCPTYPE *e)
	//{
	//	cout << "c EXCPTYPE *e:" << *e << "，msg:" << endl;
	//}
	//catch (...)
	//{
	//	cout << "c ...:" << "，msg:" << endl;
	//}
	/*
	练习：
	18.4:
	应该overflow
		runtime
		exception的顺序
	18.5：
	ok 
	18.6:
	ok
	*/
	cin >> a;
	return 0;
}
