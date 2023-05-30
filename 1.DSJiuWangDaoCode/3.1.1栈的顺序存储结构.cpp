#include <stdio.h> 
#define MaxSize 50

typedef struct {
	int data[MaxSize];
	int top;
} SqStack;
// ��ʼ�� 
void InitStack(SqStack& stack) {
	stack.top = 0;
}
// �Ƿ�Ϊ�� 
bool StackEmpty(SqStack& stack) {
	if (stack.top == 0) {
		return true;
	}
	return false;
}
// ��ջ 
bool Push(SqStack& stack, int e) {
	if (stack.top == MaxSize) {// �Ƿ����� 
		return false;
	}
	stack.data[stack.top] = e;
	stack.top++;
	return true;
}
// ��ջ 
bool Pop(SqStack& stack, int& e) {
	if (stack.top == 0) {
		return false;
	}
	stack.top--;
	e = stack.data[stack.top];
	return true;
}
// ��ȡջ�� 
bool GetTop(SqStack& stack, int& e) {
	if (stack.top == 0) {
		return false;
	}
	e = stack.data[stack.top - 1];
	return true;
}
// ����
void PrintStack(SqStack& stack) {
	for (int i = 0; i < stack.top; i++) {
		printf("%d\t", stack.data[i]);
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	SqStack stack;
	InitStack(stack);// ��ʼ��
	printf("ջ�Ƿ�Ϊ�գ�%d\n", StackEmpty(stack));
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	printf("Ԫ��ѹ��ջ��\n");
	PrintStack(stack);
	b = Pop(stack, e);
	if (b) printf("��ջԪ�أ�%d\n", e); 
	b = GetTop(stack, e);
	if (b) printf("ջ��Ԫ���ǣ�%d\n", e);
	Push(stack, 7);
	printf("Ԫ��7ѹ��ջ��\n");
	PrintStack(stack);
	return 0;
}
