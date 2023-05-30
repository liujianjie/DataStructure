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

// 后插法插入,在链栈首处插入一个节点 
bool InsertNextNode(LiStack &L, char e){
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
bool Push(LiStack &L, char e){
	return InsertNextNode(L, e);
} 
// 出栈
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
// 获取栈顶 
bool GetTop(LiStack &L, char &e){
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

// 7.2.中缀转后缀表达式生成算法 
string ZhuanHou(LiStack &L, char *s, int len){
	string hous;
	char curc, zhanc;// 当前扫描的字符和栈中的字符 
	for(int i = 0; i < len; i++){
		curc = s[i];
		// 1.是否数字 ，是就加入后缀表达式中 
		if(isdigit(curc)){
			hous = hous + curc; 
		}else{
			// 2.不是数字，判断是否界限符
			if(curc == '('){// 加入到栈中 
				Push(L, curc);
			}
			else if(curc == ')'){// 弹出栈的元素加到后缀中 
				if(!LiStackEmpty(L)){
					Pop(L, zhanc);
					while(zhanc != '('){
						hous = hous + zhanc; 
						Pop(L, zhanc);
					}
				}
			}else{
				// 重点：3. 是运算符,依次弹出栈中运算符比当前运算符优先级更高和相等的，加入后缀表达式 ,当前运算符入栈 。
				// 栈空或者(停止, 或者当前运算符优先于栈中运算符就停止 
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
	// 把栈中剩下的放入后缀表达式中
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
