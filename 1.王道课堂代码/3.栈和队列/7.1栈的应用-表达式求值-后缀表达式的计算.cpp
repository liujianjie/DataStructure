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

// ��巨����,����ջ�״�����һ���ڵ� 
bool InsertNextNode(LiStack &L, int e){
	Linknode *s = (Linknode*)malloc(sizeof(Linknode));	
	s->data = e; 
	if(L == NULL){
		L = s;	// ��һ���ڵ� 
		s->next = NULL;// ��һ����ʼ��Ϊ�� ������ 
	}else{
		s->next = L;
		L = s;
	}
	return true;
}

// ��ջ
bool Push(LiStack &L, int e){
	return InsertNextNode(L, e);
} 
// ��ջ
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
// ��ȡջ�� 
bool GetTop(LiStack &L, int &e){
	if(L == NULL){
		return false;
	}
	e = L->data;
	return true;
}

// �Ƿ�Ϊ��
bool LiStackEmpty(LiStack &L){
	if(L == NULL){
		return true;
	}
	return false;
}

// ��ӡ
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
// �Ա������������(��͡�����  0 ��c1 > c2, 1: c1 <= c2 
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
// 7.1.��׺���ʽ���� 
// �и�Сȱ�㣬�����ֵ���ڵ���10����� 
int HouZhuiJisuan(LiStack &L, string &s){
	int leftv, rightv;// ��ֵ��ֵ 
	int sum = 0;
	char curc;
	for(int i = 0; i < s.length(); i++){
		curc = s[i];
		// 1.�ǲ�����ֱ��ѹ��ջ 
		if(isdigit(curc)){
			Push(L, curc - '0');
		}else{
			// 2.������������е���ջ������Ԫ�ؼ��㣬��ס������ֵ����ջ��ע���һ�ε���������ֵ���ڶ��β�����ֵ
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
