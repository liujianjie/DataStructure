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
	//	cout << "exception:" << e.what() << "��msg:";
	//}
	//catch (...)
	//{
	//	cout << " ...:" << "��msg:" << endl;
	//   //abort();
	//}

	// ��ϰ-----
	//try
	//{
	//	throw new exception();
	//}
	//catch (exceptionType *pet)
	//{
	//	cout << "(exceptionType *pet)" << endl;// �ܲ�����û����
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
	// ��ϰ����

	// �Լ����뷨������࣬��һ����ˣ��ڶ��������� ���е�˼·��
	//try
	//{
	//	exceptionType *e = new exceptionType();
	//	throw *e;
	//}
	//catch ( exceptionType *e)
	//{
	//	cout << "exceptionType:"  << "��msg:";
	//}
	//catch (exception *e)
	//{
	//	cout << "exception:" <<(*e).what()<< "��msg:";
	//}
	//catch (...)
	//{
	//	cout << "a ...:"  << "��msg:" << endl;
	//}

	// b
	//try
	//{
	//	exceptionType *e = new exceptionType();
	//	throw *e;
	//}
	//catch (...)
	//{
	//	cout << "b ...:"  << "��msg:" << endl;
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
	//	cout << "c EXCPTYPE *e:" << *e << "��msg:" << endl;
	//}
	//catch (...)
	//{
	//	cout << "c ...:" << "��msg:" << endl;
	//}
	/*
	��ϰ��
	18.4:
	Ӧ��overflow
		runtime
		exception��˳��
	18.5��
	ok 
	18.6:
	ok
	*/
	cin >> a;
	return 0;
}
