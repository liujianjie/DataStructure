#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

int main()
{
	int a;
	list<string> li = { "Milton", "Shakespeare","Austen" };
	auto it1 = li.begin();
	auto it2 = li.rbegin();
	auto it3 = li.cbegin();
	auto it4 = li.crbegin();
	const list<string> cli = { "Milton", "Shakespeare","Austen" };
	// 显式
	list<string>::iterator it5 = li.begin();
	//list<string>::iterator it55 = cli.begin();
	list<string>::const_iterator it6 = li.begin();// 转换了 先获取为iterator再转为const
	list<string>::const_iterator it7 = li.cbegin();// *就是获取了const_iterator类型
	list<string>::const_iterator it66 = cli.begin();// constlist默认获取const_iterator，类型


	cin >> a;
	return 0;
}