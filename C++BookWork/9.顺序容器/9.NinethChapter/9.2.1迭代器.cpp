#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "Sales_data.h"
#include "noDefault.h"

using namespace std;

int main()
{
	int a;
	// һ����������Χ
	// ������պ�
	vector<int>  tve1{1,2,3,4,5,6,7,8,9,10};
	cout << "��������Ҫ�ҵ�����" << endl;
	int findval;
	cin >> findval;
	auto begin = tve1.begin();
	auto end = tve1.end();
	bool bln = false;
	/*while (begin != end) 
	{
		if (*begin == findval) {
			bln = true;
			break;
		}
		++begin;
	}
	if (bln) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}*/

	// ��ϰ9.5
	while (begin != end)
	{
		if (*begin == findval) {
			cout << *begin << endl;
			break;
		}
		++begin;
	}
	// ��ϰ9.6
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	/*while (iter1 < iter2) { Ӧ�ø�Ϊ��=
	
	}*/
	cin >> a;
	return 0;
}