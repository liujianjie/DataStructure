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
	// ��ʽ
	list<string>::iterator it5 = li.begin();
	//list<string>::iterator it55 = cli.begin();
	list<string>::const_iterator it6 = li.begin();// ת���� �Ȼ�ȡΪiterator��תΪconst
	list<string>::const_iterator it7 = li.cbegin();// *���ǻ�ȡ��const_iterator����
	list<string>::const_iterator it66 = cli.begin();// constlistĬ�ϻ�ȡconst_iterator������


	cin >> a;
	return 0;
}