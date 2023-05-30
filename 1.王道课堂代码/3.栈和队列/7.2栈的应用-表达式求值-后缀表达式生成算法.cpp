#include <stdio.h> 
#include <string.h>
#include<iostream>
#include <stdlib.h>
#include <ctype.h> 
using namespace std;
typedef struct Linknode{
	char data;
	struct Linknode *next;
}Linknode, *LiStack;

// ��巨����,����ջ�״�����һ���ڵ� 
bool InsertNextNode(LiStack &L, char e){
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
bool Push(LiStack &L, char e){
	return InsertNextNode(L, e);
} 
// ��ջ
bool Pop(LiStack &L, char &e){
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
bool GetTop(LiStack &L, char &e){
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

// 7.2.��׺ת��׺���ʽ�����㷨 
string ZhuanHou(LiStack &L, char *s, int len){
	string hous;
	char curc, zhanc;// ��ǰɨ����ַ���ջ�е��ַ� 
	for(int i = 0; i < len; i++){
		curc = s[i];
		// 1.�Ƿ����� ���Ǿͼ����׺���ʽ�� 
		if(isdigit(curc)){
			hous = hous + curc; 
		}else{
			// 2.�������֣��ж��Ƿ���޷�
			if(curc == '('){// ���뵽ջ�� 
				Push(L, curc);
			}
			else if(curc == ')'){// ����ջ��Ԫ�ؼӵ���׺�� 
				if(!LiStackEmpty(L)){
					Pop(L, zhanc);
					while(zhanc != '('){
						hous = hous + zhanc; 
						Pop(L, zhanc);
					}
				}
			}else{
				// �ص㣺3. �������,���ε���ջ��������ȵ�ǰ��������ȼ����ߺ���ȵģ������׺���ʽ ,��ǰ�������ջ ��
				// ջ�ջ���(ֹͣ, ���ߵ�ǰ�����������ջ���������ֹͣ 
				while(!LiStackEmpty(L)){
					GetTop(L, zhanc);
					if(zhanc == '('){ 
						break;
					}
					if(CompareCal(curc, zhanc)){
						Pop(L, zhanc);
						hous = hous + zhanc; 
					}else{
						break;
					}
				}
				Push(L, curc);
			}
		}
	}
	// ��ջ��ʣ�µķ����׺���ʽ��
	while(!LiStackEmpty(L)){
		Pop(L, zhanc);
		hous = hous + zhanc; 
	}
	return hous;
} 
 
int main()
{
	int e;
	LiStack L = NULL;
//	char *s = "15/(7-(1+17))*3";
	char *s = "1+4*3+2";
	string s2 = ZhuanHou(L, s, strlen(s));
	printf("%s\n", s2.c_str());
	return 0;
} 
