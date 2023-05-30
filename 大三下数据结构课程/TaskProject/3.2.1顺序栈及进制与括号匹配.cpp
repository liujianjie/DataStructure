// ����˳��ջ��������Ϊ������Ŀ������ƥ����벻����дһ���ļ�����
#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100

template <class T>
struct SqStack {
	T data[MAXSIZE];
	int top;
};
// -------------------1.˳��ջ�Ļ�����������--------------------
// ��ʼ��
template <class T>
void InitStack(SqStack<T>& stack) {
	stack.top = 0;
}
// �п�
template <class T>
bool StackEmpty(SqStack<T>& stack) {
	if (stack.top == 0)
		return true;
	return false;
}
// ��ջ
template <class T>
bool Push(SqStack<T>& stack, T e) {
	if (stack.top == MAXSIZE) {// �ж��Ƿ�����
		return false;
	}
	stack.data[stack.top] = e;// �ȷ�Ԫ��
	stack.top++;// ��+1
	return true;
}
// ��ջ
template <class T>
bool Pop(SqStack<T>& stack, T &e) {
	if (stack.top == 0) // �ж��Ƿ�Ϊ��
		return false;
	stack.top--;// ��-1
	e = stack.data[stack.top];// ��ȡֵ
	return true;
}
// ��ȡջ��
template <class T>
T GetTop(SqStack<T>& stack) {
	if (stack.top == 0)// �ж��Ƿ�Ϊ��
		return NULL;
	return stack.data[stack.top - 1];// ע��topҪ-1�����Ҳ�Ҫ��--����Ȼtopֵ�ᱻ�ı�
}
template <class T>
void PrintStack(SqStack<T>& stack) {
	for (int i = 0; i < stack.top; i++) {
		cout << stack.data[i] << "\t";
	}
	cout << endl;
}
// -------------------2.����ת������--------------------
void Conversion(int val, int base) {// val��Ҫת����ʮ����ֵ,base��Ҫת���ɶ��ٽ���
	int yval = val, e;// ����ԭ����ֵ,e����ʱ����
	SqStack<int> stack;
	InitStack(stack);// ��Ҫ����Ҫ�ȳ�ʼ��
	while (val != 0) {
		Push(stack, val % base);
		val = val / base;
	}
	cout << "��" << yval << "ת����" << base << "���ƺ����ֵΪ:" << endl;
	while (!StackEmpty(stack)) {
		Pop(stack, e);
		cout << e << " ";
	}
	cout << endl;
}
// -------------------3.����ƥ�����--------------------
void MatchKuoHao() {// ����������������н���ƥ��
	SqStack<char> stack;
	string st1;
	char ch, tp;// ch������ı�����tp����ʱ����
	cout << "���������ű��ʽ����'#' ������" << endl;
	cin >> ch;
	while (ch != '0') {// �����һֱѭ�����������û������뼸����������
		bool isOk = true;
		InitStack(stack);// ÿ�ο�ʼǰ���ȳ�ʼ��ջ
		while (ch != '#') {// �ڲ���һ����������
			switch (ch)
			{
			case '[':case'(':
				Push(stack, ch);
				break;
			case ')':
				if (!StackEmpty(stack) && GetTop(stack) == '(')
					Pop(stack, tp); // ƥ��ɹ�
				else
					isOk = false;//ƥ��ʧ��
				break;
			case ']':
				if (!StackEmpty(stack) && GetTop(stack) == '[')
					Pop(stack, tp); // ƥ��ɹ�
				else
					isOk = false;//ƥ��ʧ��
				break;
			}
			cin >> ch;//��һ���ַ�
		}
		if (StackEmpty(stack) && isOk) {
			cout << "���ʽ�������������У���ȷ��" << endl;
		}
		else {
			cout << "���ʽ�������������У�����ȷ��" << endl;
			
		}
		cout << "�˳�������0�������������������У�" << endl;
		cin >> ch;//��һ���ַ�
	}
}
int main()
{
	// 1.˳��ջ�Ļ�������
	SqStack<int> stack;
	// 1.1��ʼ��
	InitStack(stack);
	// 1.2��ջ
	Push(stack, 2);
	Push(stack, 4);
	Push(stack, 6);
	Push(stack, 8);
	Push(stack, 11);
	cout << "��ջ���ջԪ��Ϊ��" << endl;
	PrintStack(stack);
	// 1.3��ջ
	int e;
	Pop(stack, e);
	Pop(stack, e);
	cout << "������ջ���ջԪ��Ϊ��" << endl;
	PrintStack(stack);

	// 1.4ȡջ��
	e = GetTop(stack);
	if (e != NULL) cout << "ջ��Ԫ��Ϊ:" <<endl << e << endl;

	// 2.����ת��
	Conversion(15, 8);

	// 3.����ƥ��
	MatchKuoHao();

	return 0;
}