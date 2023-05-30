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
	// 因为算法是对迭代器而不是容器操作，所以算法不能直接添加或删除元素
	// 按字典序排序words
	sort(words.begin(), words.end());
	// 消除重复的
	auto thewei = unique(words.begin(), words.end());
	cout << words.size() << endl;
	// 真正删除
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