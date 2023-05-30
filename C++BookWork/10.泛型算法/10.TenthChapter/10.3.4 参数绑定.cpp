#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <functional>
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;// ռλ���ռ�

// ������Ԫ�ص�ֵ������ת��Ϊ����Ĳ���
bool isShorter(const string &s1, const string &s2 )
{
	return s1.size() < s2.size();
}
bool check_size(const string &s1, string::size_type sz)
{
	return s1.size() >= sz;
}
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
// this chapter method
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto firstit = find_if(words.begin(), words.end(), bind(check_size,_1, 5));// ֻ��һ������
	cout << words.end() - firstit << endl;
	for (auto beg = firstit; beg != words.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
}
void f(int a, int b, int c,int d, int e) 
{
	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}
ostream &prints(ostream &os, const string& s, char c)
{
	return os << s << c;
}

bool check_size2(const string &s1, string::size_type sz)
{
	return s1.size() <= sz;
}
void biggies2(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto firstit = find_if(words.begin(), words.end(), 
		bind(check_size2, _1, sz));// ֻ��һ������
	cout << words.end() - firstit << endl;
	
}

void biggiesstable_partition(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string &s2) {return s1.size() < s2.size(); });
	auto parit = stable_partition(words.begin(), words.end(),
		bind(check_size, _1, sz) );//�������һ��true֮���λ�ã����Ҳ���Ū���źõ����˳��
	for_each(words.begin(), words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
	// for - each
	for_each(words.begin(), parit,
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
// _1 ���������ռ���ģ�bind���Է�ת����λ��
int main()
{
	int a;
	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggies(v1, 5);

	a = 1;
	int b = 2;
	int c = 3;
	auto g = bind(f, a, b, _2, c, _1);
	g(4, 5);
	// g(X,Y) f(a,b,Y,c,X);

	// ��bind���Ų���˳��
	vector<string> v2{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	sort(v2.begin(), v2.end(), bind(isShorter, _2, _1));// �ߵ�
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;

	ostream& os = cout;
	char cs = ' ';
	vector<string> v3{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	for_each(v3.begin(), v3.end(),
		[&os, cs](const string& s) {os << s << cs; });
	cout << "----" << endl;
	for_each(v3.begin(), v3.end(),
		bind(prints, ref(os), _1, cs));// ʹ��ͬ����bind��ʽ������Ҫref cref�Բ��ܿ����Ķ���

	cout << endl;
	// ��ϰ
	vector<string> v4{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggies2(v4, 6);

	string str1 = "avasdas";
	vector<int> v5{ 1,2,3,4,5,6,7,8 };
	auto v5it = find_if(v5.begin(), v5.end(),
		bind(check_size2, str1, _1) );// ��Ҫ��ת��������Ϊ���_1��str1
	cout << *v5it << endl;

	vector<string> v6{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggiesstable_partition(v6, 5);

	cin >> a;
	return 0;
}

