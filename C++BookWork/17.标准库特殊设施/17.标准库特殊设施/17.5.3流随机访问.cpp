#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

/*

abcd
efg
hi
j


*/
int main()
{
	int a;
	// 为了统一来说，还是 用好理解的版本
	// fstream只有单一标记，g和p版本的读写位置都映射着单一标记
	fstream iout("17.5.3文本.txt",
		 fstream::ate|fstream::in|fstream::out);
	auto end_mark = iout.tellg();// 尾位置 可以用g 或者p版本，都可以
	//iout.seekp(0, fstream::end);// 对于fstream来说，不管是g还是p版本都是同一个位置
	iout.seekg(0, fstream::beg);// 回到一开始位置
	string line;
	size_t count = 0;
	while (iout && iout.tellg() != end_mark
		&& getline(iout, line)) {
		count += line.size() + 1;// 读取有多少大小
		auto mark = iout.tellg();// 记录读取完上一行的位置，这个很重要，输出完要回来当前位置
		iout.seekp(0, fstream::end);// 到末尾位置
		iout << count;// 输出
		iout << " ";// 打印" "
		 // 回到读的位置
		iout.seekg(mark);// count也做偏移量
	}
	// 是在14的后面输出一个换行符
	iout.seekp(0, fstream::end);
	iout << "\n";

	/*
	练习：
	ok
	*/
	cin >> a;
	return 0;
}
