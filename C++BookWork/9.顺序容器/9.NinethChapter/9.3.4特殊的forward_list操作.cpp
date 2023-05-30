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
1.// end(),end++ �����쳣 ��ֱ���׳�Խ���쳣
2.forward_listû�а취ֱ�ӻ�ȡβԪ��
3.forward_list����--
4.push_back��û��
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
		// û���ҵ�
		pre = beg;// �ȱ��浱ǰ�ģ���Ϊһ��++�ͼ�����
		if (++beg == end) {
			fwl.insert_after(pre, str2);
			break;
		}
	}
}
int main()
{
	// end(),end++ �����쳣 ��ֱ���׳�Խ���쳣
	
	int a;
	// û�м򵥵ķ�����ȡǰ��
	forward_list<int> flst = {0,1,2,3,3,3,4,5,6,7,8,9,10};
	//auto end = flst.end()++;
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;// ��Ҫ�ӼӸ����� ����Ҳһ����
			curr++;
		}
	}
	for (auto beg = flst.begin(), end = flst.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// ��ϰ 
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