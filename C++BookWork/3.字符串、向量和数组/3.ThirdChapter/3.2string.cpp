#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;// 这也要声明？
int main()
{
	int getchar;

	// 3.2.1初始化和定义string对象
	string firsts1;
	string firsts2(firsts1);
	string firsts3 = firsts2;
	string firsts4("values");//firsts4是字面值value的副本 除了字面值最后的那个空字符外
	string firsts5 = "values";
	string firsts6(10,'c');

	// 直接初始化 与 拷贝初始化 =是拷贝初始化 （） 是直接初始化，同时存在还是拷贝初始化

	// 3.2.2string的操作
	string twos1,twos2;
	//cin >> twos1; // 遇到空格不会读了
	//cout << twos1 ;
	//cin >> twos1 >> twos2;
	//cout << twos1 << twos2;

	// 读取未知数量的string对象
	string word;
	//while (cin>>word) {
	//	cout << word << endl;
	//}

	// getline
	string line;
	//while (getline(cin,line))
	//	cout << line << endl;

	// empty size 
	bool bln;
	while (getline(cin, line))
	{
		bln = line.empty();
		if (!line.empty())
			cout << bln << endl;
		else
			cout << bln << endl;
		//if (line.size() > 10) // yujava同 汉字两个byte
		//	cout << line << endl;
	}

	// size_type
	auto se = line.size();// 是无符号的整数变量

	// 比较string对象
	string strs = "Hello";
	string strphrase = "Hello World";
	string strlang = "Hi";// 比较第二个字母 不同 在字母表里谁大谁小，后面的就没有比了

	if (strs < strphrase)
		cout << "strs < strphrase" << endl;
	if (strphrase < strlang)
		cout << "strphrase < strlang" << endl;

	// 为string赋值
	string st1(10, 'c'), st2;
	st1 = st2;

	// 两个string想加
	string plusstr1 = "hello";
	string plusstr2 = "world";
	string plusstr3 = plusstr1 + plusstr2;
	plusstr1 += plusstr2;// 追加内容到plustr1中

	// 字面值和string对象想加
	string zimianstr1 = "hello";
	string zimianstr2 = "world";
	string zimianstr3 = zimianstr1 + "," + zimianstr2 + '\n';//两侧至少有个string

	cout << zimianstr3 << endl;
	string zimianstr4 = zimianstr1 + ",";
	//string zimianstr5 = "hello" + "world";//error;
	string zimianstr6 = zimianstr1 + "," + "world";//(zimainstr + ",") + world
	//string zimianstr7 = "," + "world" + zimainstr1;//error 程序是左结合运算
	// 字符串字面值并不是标准库类型string的对象

	// test 引用 能否绑定多次
	int testrefi = 10,testrefj = 20;
	int &testref = testrefi;
	//&testref = testrefj; 只能引用一次

	// 3.2.3 处理string对象中的字符
	// 输出单个字
	string threestr = "some asdf";
	for (auto a : threestr)
		cout << a << endl;//输出当前字符，并且紧跟换行符endl;
	string threess("Hello World!!!!");
	decltype(threess.size()) punct_cnt = 0;
	for (auto c : threess) 
	{
		if (ispunct(c))
			punct_cnt++;
	}
	cout << punct_cnt << endl;

	// 改变string中字符 需要用引用
	string fourstr("Hello Wolrddd");
	for (auto &c : fourstr) // 每次c都会销毁重新创建吧 因为c不能改变指向的对象
		c = toupper(c);
	cout << fourstr << endl;

	// 改变部分字符 用下标 或迭代
	string fivestr("some string");
	if (!fivestr.empty())
		cout << fivestr[0] << endl;
	fivestr[0] = toupper(fivestr[0]);
	cout << fivestr << endl;

	// && 短路运算符
	for (decltype(fivestr.size()) index = 0; index != fivestr.size() && !isspace(fivestr[index]); index++)
		fivestr[index] = toupper(fivestr[index]);

	cout << fivestr << endl;

	// 小列子 转换为16进制
	const string sixteenstr = "0123456789ABCDEF";
	decltype(sixteenstr.size()) number;
	string cinstr;
	while (cin >> number)
		if (number < sixteenstr.size())
			cinstr += sixteenstr[number];

	cout << cinstr << endl;

	string getchars = "";
	cin >> getchar;
	return 0;
}