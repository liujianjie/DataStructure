// 泛型链栈。泛型是为了让题目：算术表达式不用另写一个文件代码
#include <iostream>
#include <string>
#include <stack> 
using namespace std;
// 辅助函数
// 1.比较两个运算符优先，(当c1 > c2 返回1， 当 c1 < c2 返回-1 , 当c1 = c2 返回0）
int CompareCal(char c1, char c2) { // 只考虑 +-*/()#; 任何运算符 代表+-*/()#
	// # 是开始与 结束符合
	if (c1 == '#' && c2 == '#') {
		return 0;
	}
	if (c1 == '#') return -1;// c1“#”都小于于除了“#”的任何运算符
	if (c2 == '#') return 1;// c1永远优先 c2为#时
	if (c1 == '(' && c2 == ')') {
		return 0;
	}
	if (c1 == '(' || c2 == '(') {// “(”都小于于除了“)”的任何运算符
		return -1;
	}
	if (c1 == ')' || c2 == ')')// “)”都大于除了“（”的任何运算符
		return 1;

	switch (c1)
	{
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// “+ -”小于“* /”
			return -1;
	}
	return 1; // 默认大于
}
// 2.计算
int Cal(int val1, char op, int val2) {
	switch (op) {
	case '+':
		return val1 + val2;
	case '-':
		return val1 - val2;
	case '*':
		return val1 * val2;
	case '/':
		return val1 / val2;
	}
	return 0;
}
// 计算算术表达式代码-来自严蔚敏书
int CalExpression(stack<int>& valstack, stack<char>& opstack, string& s) { // opstack是运算符栈，valstack是操作数栈
	s.append("#");									// 添加结束标志
	opstack.push('#');								// 运算符栈结束标志
	int a, b;										// a是左操作数，b是右操作数
	char curc, zhanc;								// 当前扫描的字符和栈中的字符 
	int i = 0;										// i下标为0开始
	while (s[i] != '#' || opstack.top() != '#') {// 表达式没有扫描完毕或操作栈运算符还没计算完
		curc = s[i];
		if (isdigit(curc)) {							// ch是数值就放入数值栈
			valstack.push(int(curc - '0'));
			i++;										// 扫描下一个字符
			continue;
		}
		switch (CompareCal(opstack.top(), curc))		// 注意是栈顶的运算符c1与当前的运算符c2对比
		{
		case -1:										// c1<c2（当前运算符优先级高），当前运算符入栈
			opstack.push(curc);
			i++;										// 扫描下一个字符
			break;
		case 1:										// c1>c2（栈顶运算符优先级高），取出数值栈中存储的两个值根据运算符栈的运算符运算。
			zhanc = opstack.top();
			opstack.pop();

			b = valstack.top();						// b是右操作数
			valstack.pop();

			a = valstack.top();
			valstack.pop();							// a是左操作数
			valstack.push(Cal(a, zhanc, b));
			break;
		case 0:										// c1=c2, 相等，#结束符与括号才会相等
			opstack.pop();
			i++;										// 扫描下一个字符
			break;
		}
	}
	return valstack.top();
}
int main() {
	// 程序小缺点：如果数值大于等于10就会算错。

	// 计算算术表达式
	// 需要两个栈，一个运算符栈，一个操作数栈
	stack<char> opstack;
	stack<int> valstack;
	string s3 = "1*(4+3)+1";

	int val2 = CalExpression(valstack, opstack, s3);
	cout << "计算中缀算术表达式" << s3 << "得：" << endl << val2 << endl;

	return 0;
}

