// 泛型链栈。泛型是为了让题目：算术表达式不用另写一个文件代码
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct LiStack {
	T data;
	struct LiStack* next;
};
// -------------------1.链式栈的基本操作代码--------------------
// 初始化
template <class T>
void InitStack(LiStack<T>*& stack) {
	stack = NULL;				// 置为空
}
// 入栈
template <class T>
bool Push(LiStack<T>*& stack, T e) {
	LiStack<T>* nd = new LiStack<T>();	// 新建一个结点
	nd->data = e;					    // 新结点的元素为e
	nd->next = stack;					// 新结点的下一个为首元结点
	stack = nd;						    // 新结点变为首元结点
	return true;
}
// 出栈
template <class T>
bool Pop(LiStack<T>*& stack, T& e) {
	if (stack == NULL) return false;
	LiStack<T>* q = stack;				// 获取首元结点
	e = q->data;							// 保存栈顶的元素
	stack = stack->next;					// 让首元结点指针指向首元结点的下一个结点
	delete q;							// 删除结点
	return true;		
}
// 取栈顶元素
template <class T>
T GetTop(LiStack<T>*& stack) {
	return stack->data;			
}
// 是否为空
template <class T>
bool LiStackEmpty(LiStack<T>*& stack) {
	return stack == NULL;
}
// 打印栈元素
template <class T>
void PrintLiStack(LiStack<T>*& stack) {
	LiStack<T>* p = stack;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
// -------------------2.算术表达式代码--------------------
// 辅助函数
// 1.比较两个运算符优先，(当c1 > c2 返回1， 当 c1 < c2 返回-1 , 当c1 = c2 返回0）
int Precede(char c1, char c2) { // 只考虑 +-*/()#; 任何运算符 代表+-*/()#
	if (c1 == '#' && c2 == '#') {
		return 0;
	}
	if (c1 == '#') return -1;// c1“#”都小于于除了“#”的任何运算符
	if (c2 == '#') return 1;// c1 永远优先 c2为#时
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
	return 1; // 默认小于
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

// 计算算术表达式代码
template <class T, class T2>
void EvaluateExpression(LiStack<T>*& opstack, LiStack<T2>*& valstack) { // opstack是运算符栈，valstack是操作数栈
	int a, b;							
	char tempc;
	char ch;
	cin >> ch;
	while (ch != '0') {
		opstack = NULL;									// 初始化
		valstack = NULL;									// 初始化
		Push(opstack, '#');								// 起始符
		while (ch != '#' || GetTop(opstack) != '#') {	// 表达式没有扫描完毕或操作栈运算符还没计算完
			if (isdigit(ch)) {							// ch是数值就放入数值栈
				Push(valstack, int(ch - '0'));
				cin >> ch;
				continue;
			}
			switch (Precede(GetTop(opstack), ch))		// 注意是栈顶的运算符与当前的运算符对比
			{
			case -1:										// <，当前运算符入栈
				Push(opstack, ch);
				cin >> ch;
				break;
			case 1:										// >，取出数值栈中存储的两个值根据运算符栈的运算符运算。
				Pop(opstack, tempc);
				Pop(valstack, b);						// b是第二个数
				Pop(valstack, a);						// a是第一个数
				Push(valstack, Cal(a, tempc, b));
				break;
			case 0:										// =, 相等
				Pop(opstack, tempc);
				cin >> ch;
				break;
			}
		}
		cout << "当前算术表达式的值为：" << GetTop(valstack) << endl;
		cout << "退出请输入0，继续请输入算术表达式：" << endl;
		cin >> ch;// 下一个字符
	}
}

int main() {
	int e;
	bool b;
	LiStack<int> *stack;
	// 1.初始化栈
	InitStack(stack);
	// 2.栈是否为空
	b = LiStackEmpty(stack);
	if (b) printf("栈为空\n");
	// 3.入栈
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	cout << "入栈后，从栈顶到栈底的元素为：" << endl;
	PrintLiStack(stack);
	// 4.出栈
	Pop(stack, e);
	Pop(stack, e);
	cout << "出栈后，从栈顶到栈底的元素为：" << endl;
	PrintLiStack(stack);
	// 5.获取栈顶元素
	e = GetTop(stack);
	cout << "获取栈顶元素：" << e << endl;

	// 6.计算算术表达式
	LiStack<char>* opstack = NULL;
	LiStack<int>* valstack = NULL;
	EvaluateExpression(opstack, valstack);
	
	return 0;
}

//char c1 = '(', c2 = '*';
//int a = Precede(c1, c2);
//cout << a << endl;