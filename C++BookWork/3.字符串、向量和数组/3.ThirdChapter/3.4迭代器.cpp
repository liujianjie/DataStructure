#include <iostream>
#include <string>
#include <vector>

using  std::cin;
using  std::cout;
using  std::endl;
using std::vector;
using std::string;
int main() 
{
	int getchar;


	// 3.4.1 使用迭代器
	vector<string> onev1 = {"1","2","3","4","5","6","7"};
	auto oneb = onev1.begin(), onee = onev1.end();// b表示v的第一个元素，onee表示onev1的尾元素的后一位，当vector为空，两个相等

	// 二迭代器运算符
	vector<string> onetowv1{"d","d","f","g","g"};
	if (onetowv1.begin() != onetowv1.end())
	{
		
		auto b = onetowv1.begin();
		*b = "D";
		//cout << *b << endl;
	}
	string onetwostr{ "some nedd help" };
	if (onetwostr.begin() != onetwostr.end())
	{
		//auto currp = onetwostr.begin();
		//(*currp) = toupper(*currp);
	}

	
	for (auto onetowbegin = onetowv1.begin(); onetowbegin != onetowv1.end();onetowbegin++)
	{
		//auto currp = ;
		cout << *onetowbegin + "/";
	}
	cout << endl;

	cout << "/" << endl;
	for (auto onetowbegins = onetwostr.begin(); onetowbegins != onetwostr.end(); onetowbegins++)
	{
		cout << *onetowbegins + "/";
	}
	cout << endl;

	// 三将迭代器从一个元素移到另外一个元素
	string onethreestr("i need girl");

	for (auto onethreebegin = onethreestr.begin(); 
		onethreebegin != onethreestr.end() && !isspace(*onethreebegin); onethreebegin++)
	{
		*onethreebegin = toupper(*onethreebegin); // 改成大写？
	}
	for (auto onethreebegin = onethreestr.begin();
		onethreebegin != onethreestr.end(); onethreebegin++)
	{
		cout << *onethreebegin ;
	}
	cout << endl;

	//迭代器类型
	vector<int>::iterator onefourv1;//能读写
	vector<string>::iterator onefourv2;//能读写
	vector<int>::const_iterator oneforv3;//只能读不能写
	vector<string>::const_iterator onefourv4;//只能读不能写

	//begin和end运算符
	vector<int> onefivev1;
	const vector<int> onefivev2;
	auto onefiveb = onefivev1.begin();// 得到vector<int>::iterator
	auto onefivee = onefivev2.begin();//得到vector<int>::const_iterator
	auto onefive3 = onefivev2.cbegin();//得到vector<int>::const_iterator

	// 结合解引用和成员访问操作
	vector<string> osixv1{"ni","ggh","sdfsd sdf","","gghsdf"};//第三个为空元素
	for (auto b = osixv1.cbegin();
		b != osixv1.cend() && !b->empty(); b++)
	{
		cout << *b;
	}
	cout << endl;

	// 3.4.2 迭代器操作
	vector<int> twov1(10);
	auto twob1 = twov1.begin();
	auto twob2 = twov1.end();
	if (twob1 < twob2)
		cout << true << endl;
	else
		cout << false << endl;

	vector<int> twov2{1,2,3,4,5,6,7,8,9};
	auto twob3 = twov2.begin();
	auto twoe2 = twov2.end();
	auto mid = twob3 + (twov2.size() / 2);
	int soughtzhi = 6;
	int count = 0;
	while (mid != twoe2) 
	{
		int zhi = *mid;
		if (zhi < soughtzhi) 
		{
			twob3 = mid;// 不加1 还少一次循环。。。各有优点吧
		}
		else if(zhi > soughtzhi){
			twoe2 = mid;
		}
		else if (zhi == soughtzhi) {
			break;
		}
		mid = twob3 + (twoe2 - twob3)/2;
			count++;
	}
	cout << "循环了" << count << "次"<< endl;
	cout << 1 / 2 << endl;
	cout << 5 / 2 << endl;

	cin >> getchar;
	return 0;
}