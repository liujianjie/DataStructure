#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;
// 辅助函数
// 对比运算符(当c1 > c2 返回1， 当 c1 < c2 返回-1 ）
int CompareCal(char c1, char c2) {// c1，c2 是运算符，假定只有+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// “+ -”小于“* /”
			return -1;
	}
	return 1;
}
// 计算
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
// 中缀转后缀表达式边生成和边计算算法 
int CalExpression(stack<int>& distack, stack<char>& opstack, string& s) {
	char curc, zhanc;// 当前扫描的字符和栈中的字符 
	int leftv, rightv, sum;
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.是否数字 ，是就加入后缀表达式中 
		if (isdigit(curc)) {
			distack.push(curc - '0');
		}
		else {
			// 2.不是数字，判断是否界限符
			if (curc == '(') {// 加入到栈中 
				opstack.push(curc);
			}
			else if (curc == ')') {// 弹出栈的元素加到后缀中 
				if (!opstack.empty()) {
					zhanc = opstack.top();
					opstack.pop();
					while (zhanc != '(') {
						// 相对于后缀表达式生成代码，修改的地方，得计算
						rightv = distack.top();
						distack.pop();

						leftv = distack.top();
						distack.pop();

						sum = Cal(leftv, zhanc, rightv);
						// 数值入栈 
						distack.push(sum);
						// 再次出运算符 
						zhanc = opstack.top();
						opstack.pop();
					}
				}
			}
			else {
				// 重点：3. 是运算符,依次弹出栈中运算符比当前运算符优先级更高和相等的，加入后缀表达式 
				/*
				三种情况，不弹栈中运算符，并将当前运算符加入栈中
				1.栈空
				2.栈顶运算符是'('
				3.当前运算符比栈顶运算符优先级高
				*/
				while (!opstack.empty()) {
					zhanc = opstack.top();// 注意这里 
					if (zhanc == '(') {
						break;
					}
					if (CompareCal(curc, zhanc) == -1) { // 当前运算符比栈中运算符优先级低=栈中运算符比当前运算符优先级高，就把栈运算符加入后缀表达式
						// 栈顶运算符优先级高就计算
						// 相对于后缀表达式生成代码 修改的地方 
						zhanc = opstack.top();
						opstack.pop();

						rightv = distack.top();
						distack.pop();

						leftv = distack.top();
						distack.pop();

						sum = Cal(leftv, zhanc, rightv);
						// 数值入栈 
						distack.push(sum);
					}
					else {
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// 把栈中剩下的计算 
	while (!opstack.empty()) {
		// 相对于后缀表达式生成代码 修改的地方 
		zhanc = opstack.top();
		opstack.pop();

		rightv = distack.top();
		distack.pop();

		leftv = distack.top();
		distack.pop();

		sum = Cal(leftv, zhanc, rightv);
		// 数值入栈 
		distack.push(sum);
	}
	return distack.top();
}
int main()
{
	// 程序小缺点：如果数值大于等于10就会算错。
	 
	// 计算算术表达式
	// 需要两个栈，一个运算符栈，一个操作数栈
	stack<int> distack;
	stack<char> opstack;
	string s3 = "1*(4+3)+2";

	int val2 = CalExpression(distack, opstack, s3);
	cout << "计算中缀算术表达式" << s3 << "得：" << val2 << endl;
	return 0;
}
