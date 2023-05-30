#include <iostream>
#include <string>
using namespace std;
template <class T>
struct LiStack {
	T data;
	struct LiStack* next;
};
// -------------------1.��ʽջ�Ļ�����������--------------------
// ��ʼ��
template <class T>
void InitStack(LiStack<T>*& stack) {
	stack = NULL;				// ��Ϊ��
}
// ��ջ
template <class T>
bool Push(LiStack<T>*& stack, T e) {
	LiStack<T>* nd = new LiStack<T>();	// �½�һ�����
	nd->data = e;					    // �½���Ԫ��Ϊe
	nd->next = stack;					// �½�����һ��Ϊ��Ԫ���
	stack = nd;						    // �½���Ϊ��Ԫ���
	return true;
}
// ��ջ
template <class T>
bool Pop(LiStack<T>*& stack, T& e) {
	if (stack == NULL) return false;
	LiStack<T>* q = stack;				// ��ȡ��Ԫ���
	e = q->data;							// ����ջ����Ԫ��
	stack = stack->next;					// ����Ԫ���ָ��ָ����Ԫ������һ�����
	delete q;							// ɾ�����
	return true;
}
// -------------------2.��Ŀ�����������ʵ�ִ���--------------------
template <class T>
bool IsHuiWen(LiStack<T>*& stack, string huistr) {
	int n = huistr.length();
	// 1.��һ���ַ�����ջ
	for (int i = 0; i < n / 2; i++) {
		Push(stack, huistr[i]);
	}
	// 2.�ú�����ջ���ַ��Աȡ�
	char ch; // ջ���ַ�
	int j = n % 2 == 0 ? n / 2 : n / 2 + 1; //�ַ�������Ϊż��������n/2��ʼ������������n/2+1��ʼ
	for (; j < n; j++) {
		Pop(stack, ch);// ��ջ
		if (huistr[j] != ch) {// һ�Բ��ȣ�����false
			return false;
		}
	}
	return true;
}
int main() {
	LiStack<char>* stack;
	InitStack(stack);// ��ʼ��ջ
	string str = "1";
	cin >> str;
	while (str != "0") {
		if (IsHuiWen(stack, str))
			cout << str << "�ǻ����ַ���" << endl;
		else
			cout << str << "���ǻ����ַ���" << endl;
		cout << "�����������ַ������˳�����0" << endl;
		cin >> str;
	}
	return 0;
}