#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include "NewClass1432.h"
using namespace std;


class st_sort {
public:
	bool operator()(const string& s1, const string& s2)
	{
		return s1.size() < s2.size();
	}
};
class fd_if {
public:
	fd_if(vector<string>::size_type t):sz(t){}
	bool operator()(const string& s1)
	{
		return s1.size() >= sz;
	}
private:
	vector<string>::size_type sz;
};
void elimDups(vector<string> &words)
{
	// ��Ϊ�㷨�ǶԵ��������������������������㷨����ֱ����ӻ�ɾ��Ԫ��
	// ���ֵ�������words
	sort(words.begin(), words.end());
	// �����ظ���
	auto thewei = unique(words.begin(), words.end());
	// ����ɾ��
	words.erase(thewei, words.end());
}
void biggieslambda(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
		st_sort());
	auto firstit = find_if(words.begin(), words.end(),
		fd_if(sz));
	for (auto beg = firstit; beg != words.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
	// for - each
	for_each(firstit, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
/*
������
lambda�Ǻ������󣬱�������lambda���ʽ�����һ��δ�������δ�������󡣾���һ�����صĺ������������
1.��Ϊ���ܸı䲶��ı��������Ժ��������������һ��const��Ա����

�������ʽlambda�Լ���Ӧ������Ϊ����
���Բ������õĳ�Ա����ʹ��

ֵ����ı�����������lambda�У����Բ����������Ϊÿ��ֵ����ı���������Ӧ�����ݳ�Ա��ͬʱ�������캯����ʼ��

lambda���ʽ�������಻��Ĭ�Ϲ��캯������ֵ�������Ĭ���������������Ƿ���Ĭ�ϵĿ������ƶ����캯��ͨ��Ҫ��
��������ݳ�Ա���Ͷ���

*/
class Par1 {
public:
	Par1():countve(11){}
	void operator()(const string &s1)
	{
		if (s1.length() > 10) {
			return;
		}
		++countve[s1.length()];
	}
	vector<int> countve;
};
class Par2 {
public:
	Par2() :countve(2) {}
	void operator()(const string &s1)
	{
		if (s1.length() >= 10) {
			++countve[1];
		}
		else if (s1.length() < 10) {
			++countve[0];
		}
	}
	vector<int> countve;
};
int main()
{
	string st1("asdfasdf");
	cout << st1.size() << endl;
	cout << st1.length() << endl;
	int a;
	//vector<int> ve1(10);
	//cout << ve1.size() << endl;
	Par1 p1;
	vector<string> ve2{ "123","123" ,"12asdf3" ,"12df3" ,"d123" ,"1sd23" ,"12asdfasdf3" ,"1sdfa23" ,"1sdfsd23" };
	for(auto s : ve2) {
		p1(s);
	}
	int i = 0;
	for (auto s : p1.countve) {
		cout << "������ = " << i << "����Ŀ��:" << s << endl;
		i++;
	}
	Par2 p2;
	vector<string> ve3{ "123","123adsfadsfadfa" ,"12asdfsfsd3" ,"12df3" ,"d123" ,"1sd23" ,"12asdfasdf3" ,"1sdfa23" ,"1sdfsd23" };
	for (auto s : ve3) {
		p2(s);
	}
	i = 0;
	for (auto s : p2.countve) {
		cout << "������ = " << i << "����Ŀ��:" << s << endl;
		i++;
	}

	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggieslambda(v1, 5);

	// ��ϰ
	/*
	14.38 ok
	14.39 ok
	14.40 ok
	14.41:��ΪΪ����ʽ����С����ɣ�lambda����ʱ ֻʹ��һ�Σ�ʹ����ʹ�ö�ζ�����������ҿ��Զ�����һ�鲻ͬ�����ĵ��ö���
	*/

	cin >> a;
	return 0;
}