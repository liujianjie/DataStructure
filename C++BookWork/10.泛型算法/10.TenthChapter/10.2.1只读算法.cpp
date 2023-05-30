#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main()
{
	int a;
	vector<int> vec{1,2,3,4,5,6};
	cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	
	// ������Ԫ�ص����ͱ��������������ƥ�䣬�ܹ�ת��Ϊ����������������
	vector<string> v1{ "123","456","abc","kjh" };
	string s1 = accumulate(v1.cbegin(), v1.cend(), string(""));
	cout << s1 << endl;
	// string("") ����д�� "" ������ַ�������������� ����const char* ��+�����
	//string s2 = accumulate(v1.cbegin(), v1.cend(), "");

	vector<int> v2{1,2,3,4,5, 6};
	vector<int> v3{ 1,2,3,4,5,6, 9 };
	// v2.size() <= v3.size(); ���� ����������
	cout << equal(v2.cbegin(), v2.cend(), v3.begin()) << endl;

	// ��ϰ
	vector<int> v4{ 1,2,3,4,5,6,7 };
	cout << accumulate(v4.cbegin(), v4.cend(), 0) << endl;

	vector<double> v5{ 1.2,2.4,3.5 };
	cout << accumulate(v5.cbegin(), v5.cend(), 0) << endl;// ������С����ת��Ϊint����ʧ����
	cout << accumulate(v5.cbegin(), v5.cend(), 0.0f) << endl;// ������С����ת��Ϊint����ʧ����

	vector<const char*> v6{"123","456","789"};
	vector<const char*> v7{ "123","456","789" };
	cout << equal(v6.cbegin(), v6.cend(), v7.cbegin()) << endl;
	cin >> a;
	return 0;
}