#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// 1.void 隐式return 使函数退出
void swap(int a,int b) 
{
	if (a == b) {
		return;
	}
	cout << "swap ing" << endl;
	return;
}
int swap2(int a, int b) 
{
	if (a < b) {
		return 1;
	}
}
int& swap3(int a, int b) {
	return a > b ? a : b;
}
const string &shorterString(const string &s1, const string &s2) 
{
	return s1.size() <= s2.size() ? s1 : s2;
}
const string &mainp() 
{
	string ret;
	// 以某种方式改变一下ret
	if (!ret.empty())
		return ret;// error 返回局部对象的引用
	else
		return "Empty";// error 是一个局部临时量

}
char &get_val(string &str, string::size_type ix) {

	return str[ix];
}

vector<string> process() 
{
	string expected = "runtime", actual = "westtime";
	if (expected.empty())
		return{};
	else if (expected == actual)
		return{ "FunctionX","OKAY" };
	else
		return{ "functionX",expected,actual };

}
int factorial(int val) 
{
	if (val > 1)
		return val * factorial(val - 1);	

		return 1;
}
int main() 
{
	int getchar;

	// 1.无返回值函数
	swap(3,3);
	// 6.3.2有返回值函数
	// return的类型 与定义的类型相同，或者隐式的转换成，这样的函数需要只能通过一条有效的return语句退出，并且需要没有跳过的控制流
	// 出现了，编译器无法发现此错误，在控制流后没有return后的值。
	int get = swap2(5,2);
	cout << get << endl;

	// 二，值是如何被返回的，是拷贝的对象 或者 一个临时对象，所以可以使用引用
	get = swap3(5, 2);
	cout << get << endl;

	// 三，不要返回局部对象的引用或指针
	// 因为mainp返回局部对象，函数结束时候就已经销毁了，所以mainp将返回未定义的值，将引发未定义的行为。指针也是不能是局部对象
	//string s2 = mainp();
	//cout << s2 << endl;

	// 四，返回类类型的函数和调用运算符
	// 调用运算符的优先级（=）与点运算符的和箭头运算符 相同，并且符合左结合律。
	// 所以，函数返回指针，引用或类的对象，我们就能使用函数调用的结果访问结果对象的成员
	string fours1 = "sdfsdgdsf";
	string fours2 = "sdfdsfgdsfsd";
	auto sz = shorterString(fours1, fours2).size();
	cout << sz << endl;

	// 五，引用返回左值
	// 返回引用是一个左值，其它类型为右值。只要不是非常量引用的函数。
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl;

	// 如果返回常量引用则不可以这样
	//shorterString("adf","dfhsd") = "X";

	// 列表初始化返回值
	vector<string> ve = process();
	for (string s : ve)
		cout << s << " ";
	cout << endl;

	// 主函数main的返回值，0表示成功，其它表示其它意思，不添加隐式的添加

	// 递归
	//main(); 奇怪，可以自己调用自己main
	cout << factorial(5) << endl;

	cin >> getchar;
	//return EXIT_FAILURE;
	return EXIT_SUCCESS;
}