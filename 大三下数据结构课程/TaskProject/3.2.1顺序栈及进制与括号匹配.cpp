// 泛型顺序栈。泛型是为了让题目：括号匹配代码不用另写一个文件代码
#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100

template <class T>
struct SqStack {
	T data[MAXSIZE];
	int top;
};
// -------------------1.顺序栈的基本操作代码--------------------
// 初始化
template <class T>
void InitStack(SqStack<T>& stack) {
	stack.top = 0;
}
// 判空
template <class T>
bool StackEmpty(SqStack<T>& stack) {
	if (stack.top == 0)
		return true;
	return false;
}
// 入栈
template <class T>
bool Push(SqStack<T>& stack, T e) {
	if (stack.top == MAXSIZE) {// 判断是否满了
		return false;
	}
	stack.data[stack.top] = e;// 先放元素
	stack.top++;// 再+1
	return true;
}
// 出栈
template <class T>
bool Pop(SqStack<T>& stack, T &e) {
	if (stack.top == 0) // 判断是否为空
		return false;
	stack.top--;// 先-1
	e = stack.data[stack.top];// 再取值
	return true;
}
// 获取栈顶
template <class T>
T GetTop(SqStack<T>& stack) {
	if (stack.top == 0)// 判断是否为空
		return NULL;
	return stack.data[stack.top - 1];// 注意top要-1，并且不要用--，不然top值会被改变
}
template <class T>
void PrintStack(SqStack<T>& stack) {
	for (int i = 0; i < stack.top; i++) {
		cout << stack.data[i] << "\t";
	}
	cout << endl;
}
// -------------------2.进制转换代码--------------------
void Conversion(int val, int base) {// val是要转换的十进制值,base是要转换成多少进制
	int yval = val, e;// 保存原来的值,e是临时变量
	SqStack<int> stack;
	InitStack(stack);// 不要忘了要先初始化
	while (val != 0) {
		Push(stack, val % base);
		val = val / base;
	}
	cout << "将" << yval << "转换成" << base << "进制后的数值为:" << endl;
	while (!StackEmpty(stack)) {
		Pop(stack, e);
		cout << e << " ";
	}
	cout << endl;
}
// -------------------3.括号匹配代码--------------------
void MatchKuoHao() {// 根据输入的括号序列进行匹配
	SqStack<char> stack;
	string st1;
	char ch, tp;// ch是输入的变量，tp是临时变量
	cout << "请输入括号表达式，以'#' 结束：" << endl;
	cin >> ch;
	while (ch != '0') {// 外层是一直循环，可以让用户多输入几行括号序列
		bool isOk = true;
		InitStack(stack);// 每次开始前，先初始化栈
		while (ch != '#') {// 内层是一行括号序列
			switch (ch)
			{
			case '[':case'(':
				Push(stack, ch);
				break;
			case ')':
				if (!StackEmpty(stack) && GetTop(stack) == '(')
					Pop(stack, tp); // 匹配成功
				else
					isOk = false;//匹配失败
				break;
			case ']':
				if (!StackEmpty(stack) && GetTop(stack) == '[')
					Pop(stack, tp); // 匹配成功
				else
					isOk = false;//匹配失败
				break;
			}
			cin >> ch;//下一个字符
		}
		if (StackEmpty(stack) && isOk) {
			cout << "表达式中所含括号序列，正确。" << endl;
		}
		else {
			cout << "表达式中所含括号序列，不正确！" << endl;
			
		}
		cout << "退出请输入0，继续请输入括号序列：" << endl;
		cin >> ch;//下一个字符
	}
}
int main()
{
	// 1.顺序栈的基本操作
	SqStack<int> stack;
	// 1.1初始化
	InitStack(stack);
	// 1.2入栈
	Push(stack, 2);
	Push(stack, 4);
	Push(stack, 6);
	Push(stack, 8);
	Push(stack, 11);
	cout << "入栈后的栈元素为：" << endl;
	PrintStack(stack);
	// 1.3出栈
	int e;
	Pop(stack, e);
	Pop(stack, e);
	cout << "出两次栈后的栈元素为：" << endl;
	PrintStack(stack);

	// 1.4取栈顶
	e = GetTop(stack);
	if (e != NULL) cout << "栈顶元素为:" <<endl << e << endl;

	// 2.进制转换
	Conversion(15, 8);

	// 3.括号匹配
	MatchKuoHao();

	return 0;
}