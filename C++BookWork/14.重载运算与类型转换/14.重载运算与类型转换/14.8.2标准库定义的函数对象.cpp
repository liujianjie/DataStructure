#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
������
��׼�ⶨ����һ���ʾ��������ϵ���߼���������࣬��Щ�ඨ���ģ�����ʽ��ʵ�����������

1.��ͷ�ļ�functional

�������㷨��ʹ�ñ�׼�⺯������
����������㷨�����Զ����lambda

����:
���
���ұȽ�ָ��������õĴ�����,c++14���Դ�����

��������ʹ��less<key_type>��Ԫ�����򣬿��Զ���һ��ָ���set��������map�йؼ���Ϊָ��
*/

int main()
{
	int a;
	plus<int>  intpsa1;
	negate<int> intng1;
	int sum = intpsa1(10, 20);
	cout << sum << endl;
	sum = intng1(intpsa1(10, 20));
	cout << sum << endl;
	sum = intpsa1(10, intng1(10));
	cout << sum << endl;

	equal_to<string> stringsq1;
	cout << stringsq1("123", "123") << endl;

	cout << "----------" << endl;
	less<string*> stringless;
	string *s1 = new string("ad");
	string *s2 = new string("af");
	cout << stringless(s1,s2) << endl;

	vector<string> v4{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	sort(v4.begin(), v4.end(), greater<string>());
	for (auto s : v4) {
		cout << s << " " << endl;
	}
	cout << endl;

	vector<string *> v5;
	sort(v5.begin(), v5.end(), [](string *a, string *b) {return a < b; });
	sort(v5.begin(), v5.end(), less<string*>());

	greater<int> gt1;
	vector<int> v6{ 123,1232,12312,12,12,32,43,123123,23423,4534,3232 };
	int count = 0;
	for (auto i : v6) {
		if (gt1(i, 1024)) {
			count++;
		}
	}
	cout << "v6�д���1024���У�" << count << endl;

	not_equal_to<string> nteqt1;
	//cout << (nteqt1("123", "123")) << endl;
	vector<string> v7{ "pooh","pooh", "pooh", "pooh", "pooh", "over", "pooh", "pooh", "pooh" ,"turtle" };
	int index = 1;
	for (auto i : v7) {
		if (nteqt1(i, "pooh")) {
			cout << "v7�У�" << (index) << endl;
			break;
		}
		++index;
	}
	cout << endl;
	multiplies<int> mt1;
	vector<int> v8{ 2,3,4,6,5,32,43,3,23,43,54 };
	for (auto i : v8) {
		cout << mt1(2, i) << " ";
	}
	cout << endl;
	//for_each(v8.begin(),v8.end(), bind(multiplies<int>(),2,placeholders::_1));

	//vector<int> v9{ 2,3,4,6,5,32,43,3,23,43,54 };
	vector<int> v9{ 54,108,54 };
	auto is = find_if(v9.begin(), v9.end(), bind(modulus<int>(), placeholders::_1, 54));
	if (is == v9.end())
		cout << "yes";
	else
		cout << "no";

	// ��ϰ
	/*
	14.42:ok �е㲻ok
	14.43��ok
		

	*/
	cin >> a;
	return 0;
}