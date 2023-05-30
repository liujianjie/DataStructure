#include <stdio.h> 
#include <string.h>
#include<iostream>
#include <stdlib.h>
#include <ctype.h> 
using namespace std;
typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode, *LiStack;

// 后插法插入,在链栈首处插入一个节点 
bool InsertNextNode(LiStack &L, int e){
	Linknode *s = (Linknode*)malloc(sizeof(Linknode));	
	s->data = e; 
	if(L == NULL){
		L = s;	// 第一个节点 
		s->next = NULL;// 下一个初始化为空 ！！！ 
	}else{
		s->next = L;
		L = s;
	}
	return true;
}

// 入栈
bool Push(LiStack &L, int e){
	return InsertNextNode(L, e);
} 
// 出栈
bool Pop(LiStack &L, int &e){
	if(L == NULL){
		return false;
	}
	Linknode *s = L;
	e = s->data;
	L = s->next;
	free(s);
	return true;
}
// 获取栈顶 
bool GetTop(LiStack &L, int &e){
	if(L == NULL){
		return false;
	}
	e = L->data;
	return true;
}

// 是否为空
bool LiStackEmpty(LiStack &L){
	if(L == NULL){
		return true;
	}
	return false;
}

// 打印
void PrintLiStack(LiStack &L){
	if(L == NULL){
		return;
	}
	Linknode *p = L;
	while(p != NULL){
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
} 
// 对比运算符，反正(最低。返回  0 ：c1 > c2, 1: c1 <= c2 
int CompareCal(char c1, char c2){
	switch(c1){
		case '*':case '/':
			if(c2 == '+' || c2 == '-'){
				return 0;
			}
			break;
	}
	return 1;
}
int cal(int val1, char op, int val2){
	switch(op){
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
// 7.1.后缀表达式计算 
// 有个小缺点，如果数值大于等于10就算错。 
int HouZhuiJisuan(LiStack &L, string &s){
	int leftv, rightv;// 左值右值 
	int sum = 0;
	char curc;
	for(int i = 0; i < s.length(); i++){
		curc = s[i];
		// 1.是操作数直接压入栈 
		if(isdigit(curc)){
			Push(L, curc - '0');
		}else{
			// 2.是运算符，进行弹出栈顶两个元素计算，记住算完后的值再入栈。注意第一次弹出的是右值，第二次才是左值
			Pop(L, rightv);
			Pop(L, leftv);
			sum = cal(leftv, curc, rightv);
			Push(L, sum);
		}
	}
	return sum;
} 
 
int main()
{
	int e;
	LiStack L = NULL;
	string s = "642-/32*+";
	int val = HouZhuiJisuan(L, s);
	printf("%d\n", val);
	return 0;
} 
