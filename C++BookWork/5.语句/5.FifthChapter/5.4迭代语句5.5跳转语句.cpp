#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int getchar;
	// while
	//int j = 3;
	/*while (int jj = 4) {
		cout << "has this caozuo？d" << jj<< endl;
		jj = 0;
	}*/
	//int i;
	//vector<int> v;
	//while (cin >> i  && i != 0)
	//{
	//	v.push_back(i);
	//}
	//auto begin = v.begin();
	//while (begin != v.end() && *begin >= 0) {
	//	cout << *begin++ <<" ";
	//}
	//if (begin == v.end())
	//	cout << "no zero" << endl;


	//// 传统的for语句
	//string consforstr = "adflkjlkcxzvzlkj sadf sdf ";
	//for (decltype(consforstr.size()) index = 0;index != consforstr.size() && !isspace(consforstr[index]); ++index) 
	//{
	//	consforstr[index] = toupper(consforstr[index]);
	//}
	//// 开头部分多重定义
	//for (decltype(consforstr.size()) index = 0,size = consforstr.size(); index != size && !isspace(consforstr[index]); ++index)
	//{
	//	consforstr[index] = toupper(consforstr[index]);
	//}
	//// for循环省略部分 begin定义在上面
	//begin = v.begin();
	//for (; begin != v.end() && *begin >= 0;) {
	//	cout << *begin++ << "s ";
	//}
	//cout << consforstr << endl;

	vector<int> vecs;
	//for (int i; cin >> i;)
		//v.push_back(i);

	// 5.4.3 范围for语句
	vector<int> fivefortv = { 0,1,2,3,4,5,6,7,8,9 };
	// 范围变量必须是引用类型，这样才能对元素执行写操作
	for (auto &r : fivefortv) {
		r *= 2;
		cout << r << '\t';
		//fivefortv.pop_back();
	}
	// 如果用传统for
	for (auto beg = fivefortv.begin(), end = fivefortv.end(); beg != end; ++beg) {
		// 必须是引用类型才可操作里面的元素
		auto &r = *beg;
		r *= 2;
		//fivefortv.push_back(10);
		//fivefortv.pop_back
	}
	/*
		前面p90说不能通过范围for增加vector对象元素，因为在for语句总，预存了end()的值，
		一旦添加或删除，end函数可能	会变无效？
		试了下会报错
	*/

	// 5.4.4 do while
	//do{

	//} while(int is = get_foo());
	/*string fivefourf;
	int val1, val2;
	do {
		cout << "enter two values\n";
		cin >> val1 >> val2;
		cout << val1 + val2 << '\n';
		cout << "do you want again?yes/no\n";
		cin >> fivefourf;
	} while (fivefourf[0] != 'n' && !fivefourf.empty());*/

	// continue switch？只能当嵌套才有用
	int fivcs = 4;
	/*switch (fivcs)
	{
	default:
		continue;
		break;
	}*/

	// goto语句
	goto label;
	label:cout << "goto label out str" << endl;

	goto labels;
	int fffix = 10;
labels: fffix = 42;

	// 向后跳过一个已经执行的定义是合法的，意味着系统将销毁该变量，然后重新创建它
	/*begin:
	int sz = -20;
		
	if (sz < 0) {
		sz = -4;
		cout << sz << endl;
		goto begin;
	}*/

	cin >> getchar;
	return 0;
}
int get_foo() 
{
	return 9;
}