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
	// һ���½�
	list<Sales_data> oli;
	deque<double> ode;

	vector<vector<string>> lines;

	// ��������
	vector<noDefault> tv1(10, 3);// �����˶���Ĺ��캯������ʽ��
	//vector<noDefault> tv2(10);// false,��Ϊ�������û�ж���Ĭ�Ϲ��캯��
	cout << tv1[0].noas << endl;

	vector<int> tv11(10, 3);
	vector<int> tv3;
	vector<int> tv4(tv3);
	vector<int> tv5(tv11.begin(), tv11.end());
	vector<int> tv6{ 2,3,4,5 };

	tv3 = tv5;
	tv5 = { 4,5,6,8 };
	tv6.swap(tv5);
	swap(tv6, tv5);

	cout << tv6.size() << " ," << tv6.max_size() << " ," << tv6.empty() << endl;
	

	cin >> a;
	return 0;
}