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

	// 3.3.1 定义和初始化vector对象
	// 默认初始化
	vector<string> oneivec;//不含任何元素
	vector<int> oneivec2;
	vector<int> oneivec3(oneivec2);
	vector<int> oneivec4 = oneivec3;
	//vector<string> oneivec5(oneivec2);//error

	// 二 列表初始化vector
	vector<string> onetwosvec = {"d","d","dfsd"};
	//vector<string> onetwosvec2 = ("d","d"); /;/error
		
	// 三创建指定数量的元素，所容纳元素数量和统一初始化的初始值
	vector<int> onethreeivec(10, -1);//10个大小 初始值为-1
	vector<string> onethreesvec(10, "hi!");

	// 值初始化，不指定统一初始化值时，看元素的类型 可能为0或者为“”
	//vector<int> onefourivec = 10;//erro

	// 列表初始值还是元素数量
	vector<int> onefivev1(10);//10个大小，都是0
	vector<int> onefivev2{ 10 };//1个大小，为10
	vector<int> onefivev3(10, 1);//10个元素都是1
	vector<int> onefivev4{10, 1};//2个元素 

	vector<string> onefive5{ "hi" };//一个元素
	//vector<string> onefivev6("hi" );//error
	vector<string> onefivev7{10};//执行默认值初始化
	vector<string> onefivev8{ 10, "hi" };//执行默认值初始化

	// 3.3.2 向vector对象中添加元素
	vector<int> twov1;
	for (int i = 0; i != 100; ++i) 
	{
		twov1.push_back(i);
	}

	//3.3.3 其它vector操作
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
	
	// 二 计算vector内对象的索引
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