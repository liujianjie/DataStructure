#include <iostream>
#include <string>
#include <iterator>
#include <cstring>
#include <vector>

using namespace std;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::begin;
using std::end;
using std::strlen;
using std::strcmp;
using std::strcat;
using std::strcpy;

constexpr int getsize()
{
	return 1;
}

int getsize2()
{
	return 1;
}

int main()
{

	// 二 使用数组初始化Vector对象
	int ffivetwo[] = { 0,1,2,3,4,5 };
	vector<int> ffivevec(begin(ffivetwo), end(ffivetwo));
	vector<int> ffivesubvec(&ffivetwo[1], &ffivetwo[4]);
	for (auto a : ffivesubvec) {
		cout << a << endl;
	}
	return 0;
}