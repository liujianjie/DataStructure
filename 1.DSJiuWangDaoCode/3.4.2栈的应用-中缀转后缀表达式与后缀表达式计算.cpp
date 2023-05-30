#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;
// 对比运算符(当c1 > c2 返回1， 当 c1 < c2 返回-1 ）
int CompareCal(char c1, char c2) {// c1，c2 是运算符，假定只有+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// “+ -”小于“* /”
			return -1;
	}
	return 1;// 默认大于
}
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
// 1.中缀转后缀表达式生成算法 
string GenerateHou(stack<char>& opstack, string& s) {
	string hous;
	char curc, zhanc;// 当前扫描的字符和栈中的字符 
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.是否数字 ，是就加入后缀表达式中 
		if (isdigit(curc)) {
			hous = hous + curc;
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
					while (zhanc != '(') {// 弹出栈中的运算符
						hous = hous + zhanc;
						// 再次出运算符 
						zhanc = opstack.top();
						opstack.pop();
					}
				}
			}
			else {
				// 重点：3. 是运算符,依次弹出栈中运算符比当前运算符优先级更高和相等的，加入后缀表达式 ,当前运算符入栈 。
				/*
				三种情况，不弹栈中运算符，并将当前运算符加入栈中
				1.栈空
				2.栈顶运算符是'('
				3.当前运算符比栈顶运算符优先级高
				*/
				while (!opstack.empty()) {
					zhanc = opstack.top();
					if (zhanc == '(') {
						break;
					}
					if (CompareCal(curc, zhanc) == -1) { // 当前运算符比栈中运算符优先级低=栈中运算符比当前运算符优先级高，就把栈运算符加入后缀表达式
						// 栈顶运算符优先级高出栈
						zhanc = opstack.top();
						opstack.pop();
						hous = hous + zhanc;
					}
					else {
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// 把栈中剩下的放入后缀表达式中
	while (!opstack.empty()) {
		zhanc = opstack.top();
		opstack.pop();
		hous = hous + zhanc;
	}
	return hous;
}
// 2.后缀表达式计算 
int CalHou(stack<int>& distack, string& s) {
	int leftv, rightv;// 左值右值 
	int sum = 0;
	char curc;
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.是操作数直接压入栈 
		if (isdigit(curc)) {
			distack.push(curc - '0');
		}
		else {
			// 2.是运算符，进行弹出栈顶两个元素计算，记住算完后的值再入栈。注意第一次弹出的是右值，第二次才是左值
			rightv = distack.top();
			distack.pop();

			leftv = distack.top();
			distack.pop();
			sum = Cal(leftv, curc, rightv);
			distack.push(sum);
		}
	}
	return sum;
}
int main()
{
	// 程序小缺点：如果数值大于等于10就会算错。 
	
	// 1.生成后缀表达式
	stack<char> opstack0;
	string s1 = "1+4*3+2";
	string s2 = GenerateHou(opstack0, s1);
	cout << "中缀表达式" << s1 << "转换后缀表达式为：" << s2 << endl;
	// 2.计算后缀表达式
	stack<int> distack0;
	int val = CalHou(distack0, s2);
	cout << "计算后缀表达式" << s2 << "得：" << val << endl;

	 s1 = "1+(6+4*3)+2";
	 s2 = GenerateHou(opstack0, s1);
	cout << "中缀表达式" << s1 << "转换后缀表达式为：" << s2 << endl;

	return 0;
}
