// ������ջ��������Ϊ������Ŀ���������ʽ������дһ���ļ�����
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
// ȡջ��Ԫ��
template <class T>
T GetTop(LiStack<T>*& stack) {
	return stack->data;			
}
// �Ƿ�Ϊ��
template <class T>
bool LiStackEmpty(LiStack<T>*& stack) {
	return stack == NULL;
}
// ��ӡջԪ��
template <class T>
void PrintLiStack(LiStack<T>*& stack) {
	LiStack<T>* p = stack;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
// -------------------2.�������ʽ����--------------------
// ��������
// 1.�Ƚ�������������ȣ�(��c1 > c2 ����1�� �� c1 < c2 ����-1 , ��c1 = c2 ����0��
int Precede(char c1, char c2) { // ֻ���� +-*/()#; �κ������ ����+-*/()#
	if (c1 == '#' && c2 == '#') {
		return 0;
	}
	if (c1 == '#') return -1;// c1��#����С���ڳ��ˡ�#�����κ������
	if (c2 == '#') return 1;// c1 ��Զ���� c2Ϊ#ʱ
	if (c1 == '(' && c2 == ')') {
		return 0;
	}
	if (c1 == '(' || c2 == '(') {// ��(����С���ڳ��ˡ�)�����κ������
		return -1;
	}
	if (c1 == ')' || c2 == ')')// ��)�������ڳ��ˡ��������κ������
		return 1;

	switch (c1)
	{
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// ��+ -��С�ڡ�* /��
			return -1;
	}
	return 1; // Ĭ��С��
}
// 2.����
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

// �����������ʽ����
template <class T, class T2>
void EvaluateExpression(LiStack<T>*& opstack, LiStack<T2>*& valstack) { // opstack�������ջ��valstack�ǲ�����ջ
	int a, b;							
	char tempc;
	char ch;
	cin >> ch;
	while (ch != '0') {
		opstack = NULL;									// ��ʼ��
		valstack = NULL;									// ��ʼ��
		Push(opstack, '#');								// ��ʼ��
		while (ch != '#' || GetTop(opstack) != '#') {	// ���ʽû��ɨ����ϻ����ջ�������û������
			if (isdigit(ch)) {							// ch����ֵ�ͷ�����ֵջ
				Push(valstack, int(ch - '0'));
				cin >> ch;
				continue;
			}
			switch (Precede(GetTop(opstack), ch))		// ע����ջ����������뵱ǰ��������Ա�
			{
			case -1:										// <����ǰ�������ջ
				Push(opstack, ch);
				cin >> ch;
				break;
			case 1:										// >��ȡ����ֵջ�д洢������ֵ���������ջ����������㡣
				Pop(opstack, tempc);
				Pop(valstack, b);						// b�ǵڶ�����
				Pop(valstack, a);						// a�ǵ�һ����
				Push(valstack, Cal(a, tempc, b));
				break;
			case 0:										// =, ���
				Pop(opstack, tempc);
				cin >> ch;
				break;
			}
		}
		cout << "��ǰ�������ʽ��ֵΪ��" << GetTop(valstack) << endl;
		cout << "�˳�������0�������������������ʽ��" << endl;
		cin >> ch;// ��һ���ַ�
	}
}

int main() {
	int e;
	bool b;
	LiStack<int> *stack;
	// 1.��ʼ��ջ
	InitStack(stack);
	// 2.ջ�Ƿ�Ϊ��
	b = LiStackEmpty(stack);
	if (b) printf("ջΪ��\n");
	// 3.��ջ
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	cout << "��ջ�󣬴�ջ����ջ�׵�Ԫ��Ϊ��" << endl;
	PrintLiStack(stack);
	// 4.��ջ
	Pop(stack, e);
	Pop(stack, e);
	cout << "��ջ�󣬴�ջ����ջ�׵�Ԫ��Ϊ��" << endl;
	PrintLiStack(stack);
	// 5.��ȡջ��Ԫ��
	e = GetTop(stack);
	cout << "��ȡջ��Ԫ�أ�" << e << endl;

	// 6.�����������ʽ
	LiStack<char>* opstack = NULL;
	LiStack<int>* valstack = NULL;
	EvaluateExpression(opstack, valstack);
	
	return 0;
}

//char c1 = '(', c2 = '*';
//int a = Precede(c1, c2);
//cout << a << endl;