#include <stdio.h> 
#define MaxSize 50

typedef struct{
	int data[MaxSize];
	int top;
} SqStack;

// 初始化 
void InitStack(SqStack &stack){
	stack.top = 0;
}
// 是否为空 
bool StackEmpty(SqStack &stack){
	if(stack.top == 0){
		return true;
	}
	return false;
}
// 入栈 
bool Push(SqStack &stack, int e){
	if(stack.top == MaxSize){// 是否满了 
		return false;
	}
	stack.data[stack.top] = e;
	stack.top++;
	return true;
}
// 出栈 
bool Pop(SqStack &stack, int &e){
	if(stack.top == 0){
		return false;
	}
	stack.top--;
	e = stack.data[stack.top];
	return true;
}
// 获取栈顶 
bool GetTop(SqStack &stack, int &e){
	if(stack.top == 0){
		return false;
	}
	e = stack.data[stack.top - 1];
	return true;
}

// 遍历
void PrintStack(SqStack &stack){
	for(int i = 0; i < stack.top; i++){
		printf("%d\t", stack.data[i]);
	}
	printf("\n");
} 
int main()
{
	SqStack stack;
	// 初始化
	InitStack(stack); 
	printf("%d\n",StackEmpty(stack));
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	PrintStack(stack);
	int e;
	Pop(stack, e);
	printf("出栈一个%d\n", e);// 出栈 
	Push(stack, 7);
	PrintStack(stack);
	return 0;
} 
