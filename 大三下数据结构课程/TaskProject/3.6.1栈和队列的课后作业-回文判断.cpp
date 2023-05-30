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
// -------------------2.题目：回文问题的实现代码--------------------
template <class T>
bool IsHuiWen(LiStack<T>*& stack, string huistr) {
	int n = huistr.length();
	// 1.让一半字符串入栈
	for (int i = 0; i < n / 2; i++) {
		Push(stack, huistr[i]);
	}
	// 2.让后半段与栈中字符对比。
	char ch; // 栈顶字符
	int j = n % 2 == 0 ? n / 2 : n / 2 + 1; //字符串长度为偶数：后半段n/2开始，奇数：后半段n/2+1开始
	for (; j < n; j++) {
		Pop(stack, ch);// 出栈
		if (huistr[j] != ch) {// 一对不等，返回false
			return false;
		}
	}
	return true;
}
int main() {
	LiStack<char>* stack;
	InitStack(stack);// 初始化栈
	string str = "1";
	cin >> str;
	while (str != "0") {
		if (IsHuiWen(stack, str))
			cout << str << "是回文字符串" << endl;
		else
			cout << str << "不是回文字符串" << endl;
		cout << "继续请输入字符串，退出输入0" << endl;
		cin >> str;
	}
	return 0;
}