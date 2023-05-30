#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include "Sales_data.h"
//#include "BlobAndBloPtr.h"
#include "TestMod.h"
#include "Blob.h"
#include "BloPtr.h"
#include "Foo.h"
#include "QueryResult.h"
#include "TexTQuery.h"
#include "DebugDelete.h"

using namespace std;

/*

*/
//

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
int main()
{
	int a;
	double *p = new double;
	DebugDelete d;
	d(p);
	int *ip = new int;
	DebugDelete() (ip);

	int *ip2 = new int;
	unique_ptr<int, DebugDelete> up(ip2, DebugDelete());
	unique_ptr<string, DebugDelete> usp(new string, DebugDelete());
	up.reset();

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	cout << begin(ia) << endl;//地址
	int* i1 = begin(ia);
	cout << *i1 << endl;//是值
	// 会自动转换为int值吗？明明是 int*的，对 会，vector声明为int，在构造函数，是迭代器为地址会自动执行*取值
	// 所以迭代器会转换为值，int* 也会转换为int值
	vector<int> it(begin(ia), end(ia));
	for (auto beg = it.begin(), end = it.end(); beg != end; ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	Blob<int> bb1(begin(ia), end(ia));

	vector<long> vi = { 0,1,2,3,4,5,6,7,8,9 };
	list<const char*> w = { "now", "is","the","time" };
	Blob<int> a2(vi.begin(), vi.end());
	Blob<string> a3(w.begin(), w.end());


	ifstream ifs("12.3.1文本查询程序设计.txt");
	TexTQuery tq(ifs);
	string words;
	while (cin >> words && words != "q") {
		print(cout, tq.query(words)) << endl;
	}
	/*
	练习:
	16.21：
	16.22：ok
	16.23: 就是当退出的时候呀，shader_ptr自动析构的时候才会执行debugdelete，或者显示release的时候
	16.24:ok，可以是引用的迭代器
	*/

	cin >> a;
	return 0;
}


