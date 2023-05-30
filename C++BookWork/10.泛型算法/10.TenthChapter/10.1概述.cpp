#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main() 
{
	int a;
	int val = 1;
	vector<int> vec(10);
	//for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
	//	cout << *beg << endl;
	//}
	auto result = find(vec.cbegin(), vec.cend(), val);
	cout << "is exit?" << (result == vec.end() ? "not" : "yes")<<endl;

	vector<string> ve1{"a vale","two vale", "three vale", "four vale", "five vale" };
	string v1 = "four vale";
	auto res2 = find(ve1.cbegin(), ve1.cend(), v1);
	cout << "is exit?" << (res2 == ve1.end() ? "not" : "yes") << endl;

	int ia1[] = {27, 210, 12, 47, 109, 83};
	int v2 = 109;
	int *res3 = find(begin(ia1), end(ia1), v2);
	cout << *res3 << endl;
	cout << "is exit?" << (res3 == end(ia1) ? "no" : "yes") << endl;

	// 子范围
	auto res4 = find(ia1 + 1, ia1 + 4, v2);
	cout << *res4 << endl;

	// 练习
	vector<int> ve2;
	int res5;
	cout << "请输入int序列(-1结束)" << endl;
	while ((cin >> res5) && res5 != -1 ) {
		ve2.push_back(res5);
	}
	cout << "请输入定值" << endl;
	cin >> res5;
	cout << res5 << "出现的次数：" << count(ve2.begin(), ve2.end(), res5) << endl;

	vector<string> ve3;
	string res6 = "";
	cout << "请输入string序列(-1结束)" << endl;
	while ((cin >> res6) && res6 != "-1") {
		ve3.push_back(res6);
	}
	cout << "请输入string值" << endl;
	cin >> res6;
	cout << res6 << "出现的次数：" << count(ve3.begin(), ve3.end(), res6) << endl;

	cin >> a;
	return 0;
}