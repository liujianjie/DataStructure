#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// 5.3;
	int getchar;

	int i = 1;

	// 这也行？ 声明？？？
	if (int j = 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	// 5.3 if-else 6个等级
	const vector<string> scores = {"F","D", "C", "B", "A", "A++"};

	int grade;
	cin >> grade;
	string lettergrade;
	if (grade < 60)
		lettergrade = scores[0];
	else {
		lettergrade = scores[(grade - 50) / 10];// 是除以10 不是100
		if (grade != 100) {
			if (grade % 10 > 7)
				lettergrade += '+';
			else if (grade % 10 < 3)
				lettergrade += '-';
		}
	}
	cout << lettergrade << endl;
	lettergrade = scores[(grade - 50) / 10];// 是除以10 不是100
	// 悬垂else
	if (grade % 10 >= 3)
		if (grade % 10 > 7)
			lettergrade += '+';
		else
			lettergrade += '-';
	cout << lettergrade << endl;

	// 用花括号控制执行路径
	if (grade % 10 >= 3) {
		if (grade % 10 > 7)
			lettergrade += '+';
	}
	else
		lettergrade += '-';

	// 5.3.2 switch语句
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch && ch != '0') {
		switch (ch)
		{
		case 'a':
			++aCnt;
			break;
		case 'e' :
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		default:
			break;
		}
	}
	cout << "a: \t" << aCnt << "\n"
		<< "e: \t" << eCnt << "\n"
		<< "i: \t" << iCnt << "\n"
		<< "o: \t" << oCnt << "\n"
		<< "u: \t" << uCnt << "\n";
	// 这也行？
	switch (1)
	{
	
	}
	// 不是说case标签必须是整形常量表达式吗, 哦 1是常量
	int ival = 42;
	/*switch (ch)
	{
	case 3.14:
	case ival: error
	default:
		break;
	}*/

	// switch内部的变量定义
	bool flag = true;
	/* 多个case在同一个作用域，但是当int ival = 0,这样的情况为显示初始化，
		当运行到这时才给予赋值，倘若直接直接跳到falsecase中并且使用ival，会导致错误，隐式初始化也不行。即string，int jval不会隐式初始化*/
	string files_na;
	cout << files_na << endl;
	switch (flag)
	{
	case true:
		//string file_namesss; error 隐式初始化
		//int ival = 0; 编译器发出错误，将跳过case标签ival的初始化操作，显示初始化
		int jval;// 未初始化合法
		break;
	case false:
		jval = 12;
	default:
		break;
	}

	cin >> getchar;
	return 0;
}