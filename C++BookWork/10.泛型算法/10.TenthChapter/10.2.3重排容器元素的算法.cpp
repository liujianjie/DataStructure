#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
using namespace std;

void elimDups(vector<string> &words) 
{
	// ��Ϊ�㷨�ǶԵ��������������������������㷨����ֱ����ӻ�ɾ��Ԫ��
	// ���ֵ�������words
	sort(words.begin(), words.end());
	// �����ظ���
	auto thewei = unique(words.begin(), words.end());
	cout << words.size() << endl;
	// ����ɾ��
	words.erase(thewei, words.end());
	cout << words.size() << endl;
}
int main()
{
	int a;
	vector<string> v1{"the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle"};
	elimDups(v1);
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl; 

	cin >> a;
	return 0;
}