#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
int main() 
{
	int getchar = 0;
	// 3.3.0
	vector<int> zeroivec;
	vector<string> zeroviec2;
	vector<vector<int>> zeroivec3;

	// 3.3.1 ����ͳ�ʼ��vector����
	// Ĭ�ϳ�ʼ��
	vector<string> oneivec;//�����κ�Ԫ��
	vector<int> oneivec2;
	vector<int> oneivec3(oneivec2);
	vector<int> oneivec4 = oneivec3;
	//vector<string> oneivec5(oneivec2);//error

	// �� �б��ʼ��vector
	vector<string> onetwosvec = {"d","d","dfsd"};
	//vector<string> onetwosvec2 = ("d","d"); /;/error
		
	// ������ָ��������Ԫ�أ�������Ԫ��������ͳһ��ʼ���ĳ�ʼֵ
	vector<int> onethreeivec(10, -1);//10����С ��ʼֵΪ-1
	vector<string> onethreesvec(10, "hi!");

	// ֵ��ʼ������ָ��ͳһ��ʼ��ֵʱ����Ԫ�ص����� ����Ϊ0����Ϊ����
	//vector<int> onefourivec = 10;//erro

	// �б��ʼֵ����Ԫ������
	vector<int> onefivev1(10);//10����С������0
	vector<int> onefivev2{ 10 };//1����С��Ϊ10
	vector<int> onefivev3(10, 1);//10��Ԫ�ض���1
	vector<int> onefivev4{10, 1};//2��Ԫ�� 

	vector<string> onefive5{ "hi" };//һ��Ԫ��
	//vector<string> onefivev6("hi" );//error
	vector<string> onefivev7{10};//ִ��Ĭ��ֵ��ʼ��
	vector<string> onefivev8{ 10, "hi" };//ִ��Ĭ��ֵ��ʼ��

	// 3.3.2 ��vector���������Ԫ��
	vector<int> twov1;
	for (int i = 0; i != 100; ++i) 
	{
		twov1.push_back(i);
	}

	//3.3.3 ����vector����
	vector<int> threev1{1,2,3,4,5,6,7,8,9};
	for (auto &r : threev1)
		r *= r;
	for (auto r : threev1)
		cout << r;
	cout << endl;

	bool bl1 = threev1.empty();
	cout << bl1 << endl;

	vector<string> threev2{"a","b","c","d"};
	vector<string> threev3{"a","b","e","f" };
	if (threev2 <= threev3)
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
	// �� ����vector�ڶ��������
	vector<int> threetwov1(10);
	unsigned score;
	while (cin >> score) 
	{
		if (score <= 100)
			++threetwov1[score/10];
	}
	for (auto r : threetwov1)
		cout << r;
	cout << endl;
	cin >> getchar;
	return 0;
}