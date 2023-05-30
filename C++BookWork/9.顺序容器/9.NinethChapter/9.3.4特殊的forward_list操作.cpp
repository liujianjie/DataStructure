#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;
/*
1.// end(),end++ 会有异常 会直接抛出越界异常
2.forward_list没有办法直接获取尾元素
3.forward_list不能--
4.push_back都没有
*/
void parninetwoeight(forward_list<string> &fwl, string &str1, string &str2)
{
	for (auto beg = fwl.begin(), end = fwl.end(),
		pre = fwl.before_begin();
		beg != end; ++beg) {
		if (*beg == str1) {
			fwl.insert_after(beg, str2);
			break;
		}
		// 没有找到
		pre = beg;// 先保存当前的，因为一旦++就减不了
		if (++beg == end) {
			fwl.insert_after(pre, str2);
			break;
		}
	}
}
int main()
{
	// end(),end++ 会有异常 会直接抛出越界异常
	
	int a;
	// 没有简单的方法获取前驱
	forward_list<int> flst = {0,1,2,3,3,3,4,5,6,7,8,9,10};
	//auto end = flst.end()++;
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;// 不要加加更保险 不过也一样的
			curr++;
		}
	}
	for (auto beg = flst.begin(), end = flst.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 练习 
	// 9.28
	forward_list<string> pfwl{"123","456","789"};
	string str1 = "124";
	string str2 = "000";
	parninetwoeight(pfwl, str1, str2);
	for (auto beg = pfwl.begin(), end = pfwl.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	cin >> a;
	return 0;
}