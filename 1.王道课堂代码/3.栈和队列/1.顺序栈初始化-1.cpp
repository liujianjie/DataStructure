#include <stdio.h> 
#define MaxSize 50

typedef struct{
	int data[MaxSize];
	int top;
} SqStack;

// ��ʼ�� 
void InitStack(SqStack &stack){
	stack.top = -1;
}
// �Ƿ�Ϊ�� 
bool StackEmpty(SqStack &stack){
	if(stack.top == -1){
		return true;
	}
	return false;
}
// ��ջ 
bool Push(SqStack &stack, int e){
	if(stack.top + 1 == MaxSize){// �Ƿ����� 
		return false;
	}
	stack.top++;
	stack.data[stack.top] = e;
	return true;
}
// ��ջ 
bool Pop(SqStack &stack, int &e){
	if(stack.top == -1){
		return false;
	}
	e = stack.data[stack.top];
	stack.top--;
	return true;
}
// ��ȡջ�� 
bool GetTop(SqStack &stack, int &e){
	if(stack.top == -1){
		return false;
	}
	e = stack.data[stack.top];
	return true;
}

// ����
void PrintStack(SqStack &stack){
	for(int i = 0; i <= stack.top; i++){
		printf("%d\t", stack.data[i]);
	}
	printf("\n");
} 
int main()
{
	SqStack stack;
	// ��ʼ��
	InitStack(stack); 
	printf("%d\n",StackEmpty(stack));
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	PrintStack(stack);
	int e;
	Pop(stack, e);
	printf("��ջһ��%d\n", e);// ��ջ 
	Push(stack, 7);
	PrintStack(stack);
	return 0;
} 
