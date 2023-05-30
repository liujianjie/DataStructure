#include <iostream>
#include <vector>
#include <fstream>
#include "Sales_data.h"
#include "cplusplus_primer.h"
#include "cplusplus_primer_cpp.h"
//#include "TestIncludeSt.h"
//#include "NoNameSpace1.h"// 因为包含进来的话，在该文件有两次定义
#include "NoNameSpace2.h"

#include "chapter15.h"
#include "chapter15_cpp.h"
using namespace std;

int theallspacemember = 199l;

//1.
namespace std {
	template<>
	struct hash<Sales_data>;
}
template<> struct std::hash<Sales_data>
{
	size_t hash<Sales_data>::operator()(const Sales_data& s) const
	{
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
	typedef size_t result_type;// 哈希值吗
	typedef Sales_data argument_type;// 需要默认==，返回bool
	//size_t operator()(const Sales_data& s) const;
};

namespace outSp {
	void testIsOk0() {
		cout << "outSp::testIsOk0()" << endl;
	}
	int val0 = 0;
	namespace inSp1 {
		int val1 = 10;
	}
	namespace inSp1 {
		int val2 = 10;
	}
	namespace inSp2 {
		void testIsOk() {
			testIsOk0();
			cout << "定义好了testIsOk" << val0 << endl;
		}
		int val3 = 20;
	}
}

namespace cpluscplus_2 {
#include "FifthEd.h"
#include "FourthEd.h"
}

//int i = 1;
namespace {
	int i = 3;
}
namespace local{
	namespace {
		int i = 10;
	}
}

ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

namespace mathLib {
	namespace MatrixLib {
		class matrix{};
		matrix operator*(const matrix&,const matrix&);
	}
}
// 先声明matrix?
mathLib::MatrixLib::matrix
mathLib::MatrixLib::operator*(const matrix&, const matrix&);

using mathLib::MatrixLib::matrix;
matrix mathLib::MatrixLib::operator*(const matrix&, const matrix&)
{
	cout << "定义好了" << endl;
	matrix m;
	return m;
}
int main()
{
	int a;
	//2.
	cplusplus_primer::Query q = cplusplus_primer::Query("hello");
	cplusplus_primer::Sales_data s1, s2;
	//cin >> s1 >> s2;
	//s1 = s1 + s2;
	// 3
	using cplusplus_primer::Sales_data;// 会覆盖头文件引用的 全局作用域？
	Sales_data s3, s4;
	
	// 4
	s3.testOutIdenti();

	// 5

	// 6 全局
	cout << ::theallspacemember << endl;

	// 7嵌套
	cout << outSp::inSp1::val1 << endl;
	cout << outSp::inSp2::val3 << endl;

	outSp::inSp2::testIsOk();
	//outSp::testIsOk();// 不可以

	// 8内联
	cout << cpluscplus_2::v1 << endl;
	cout << cpluscplus_2::FifthEd::v1 << endl;
	cout << cpluscplus_2::FourthEd::v1 << endl;

	// 9
	cout << i << endl;
	//cout << ::i << endl;
	
	cout << local::i << endl;

	cout << val << endl;

	// 
	ifstream ifs("15.9输入文件.txt");
	TexTQuery te(ifs);

	using chapter15::Query;
	Query q3 = Query("Daddy");
	print(cout, q3.eval(te));

	//
	matrix m1;
	mathLib::MatrixLib::operator*(m1, m1);
	/*
	练习：
	18.12: ok

	18.13:想定义静态生命周期的成员时候 

	18.14:题目说错了吧，是要我们定义.ok,也可以声明。
	先声明matrix类，再声明函数
	*/
	cin >> a;
	return 0;
}
