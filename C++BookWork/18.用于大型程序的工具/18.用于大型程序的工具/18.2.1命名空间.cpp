#include <iostream>
#include <vector>
#include <fstream>
#include "Sales_data.h"
#include "cplusplus_primer.h"
#include "cplusplus_primer_cpp.h"
//#include "TestIncludeSt.h"
//#include "NoNameSpace1.h"// ��Ϊ���������Ļ����ڸ��ļ������ζ���
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
	typedef size_t result_type;// ��ϣֵ��
	typedef Sales_data argument_type;// ��ҪĬ��==������bool
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
			cout << "�������testIsOk" << val0 << endl;
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
// ������matrix?
mathLib::MatrixLib::matrix
mathLib::MatrixLib::operator*(const matrix&, const matrix&);

using mathLib::MatrixLib::matrix;
matrix mathLib::MatrixLib::operator*(const matrix&, const matrix&)
{
	cout << "�������" << endl;
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
	using cplusplus_primer::Sales_data;// �Ḳ��ͷ�ļ����õ� ȫ��������
	Sales_data s3, s4;
	
	// 4
	s3.testOutIdenti();

	// 5

	// 6 ȫ��
	cout << ::theallspacemember << endl;

	// 7Ƕ��
	cout << outSp::inSp1::val1 << endl;
	cout << outSp::inSp2::val3 << endl;

	outSp::inSp2::testIsOk();
	//outSp::testIsOk();// ������

	// 8����
	cout << cpluscplus_2::v1 << endl;
	cout << cpluscplus_2::FifthEd::v1 << endl;
	cout << cpluscplus_2::FourthEd::v1 << endl;

	// 9
	cout << i << endl;
	//cout << ::i << endl;
	
	cout << local::i << endl;

	cout << val << endl;

	// 
	ifstream ifs("15.9�����ļ�.txt");
	TexTQuery te(ifs);

	using chapter15::Query;
	Query q3 = Query("Daddy");
	print(cout, q3.eval(te));

	//
	matrix m1;
	mathLib::MatrixLib::operator*(m1, m1);
	/*
	��ϰ��
	18.12: ok

	18.13:�붨�徲̬�������ڵĳ�Աʱ�� 

	18.14:��Ŀ˵���˰ɣ���Ҫ���Ƕ���.ok,Ҳ����������
	������matrix�࣬����������
	*/
	cin >> a;
	return 0;
}
