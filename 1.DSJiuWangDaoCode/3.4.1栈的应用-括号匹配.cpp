#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
// 不带头结点
typedef struct Linknode {
	char data;
	struct Linknode* next;
}Linknode, * LiStack;
// 后插法插入,在链栈首处插入一个节点 
bool InsertNextNode(LiStack& L, char e) {
	Linknode* s = (Linknode*)malloc(sizeof(Linknode));
	s->data = e;
	if (L == NULL) {
		L = s;	// 第一个节点 
		s->next = NULL;// 下一个初始化为空 ！！！ 
	}
	else {
		s->next = L;
		L = s;
	}
	return true;
}
// 入栈
bool Push(LiStack& L, char e) {
	return InsertNextNode(L, e);
}
// 出栈
bool Pop(LiStack& L, char& e) {
	if (L == NULL) {
		return false;
	}
	Linknode* s = L;
	e = s->data;
	L = s->next;
	free(s);
	return true;
}
// 是否为空
bool LiStackEmpty(LiStack& L) {
	if (L == NULL) {
		return true;
	}
	return false;
}
// 打印
void PrintLiStack(LiStack& L) {
	if (L == NULL) {
		return;
	}
	Linknode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
// 括号匹配
int MatchKuohao(LiStack& L, const char* s, int len) {
	char c = 0;
	for (int i = 0; i < len; i++) {
		c = s[i];
		// 1.判断是否为左括号 是就入栈 
		if (c == '(' || c == '{' || c == '[') {
			Push(L, c);
		}
		else {
			// 2.是右括号，取出栈顶括号与之匹配
			if (LiStackEmpty(L)) { // 不存在左括号与之匹配，代表失败 
				return 1;
			}
			Pop(L, c);
			// 判断是否匹配 
			if (s[i] == ')' && c != '(') {
				return 2;
			}
			if (s[i] == '}' && c != '{') {
				return 2;
			}
			if (s[i] == ']' && c != '[') {
				return 2;
			}
		}
	}
	// 3.在判断栈是否有左括号未匹配的
	if (!LiStackEmpty(L)) {
		return 3;
	}
	return 0;
}
int main()
{
	int e;
	LiStack L = NULL;
	// 括号匹配开始
	const char* s = "({()})";
	int b = MatchKuohao(L, s, strlen(s));
	printf("%s", s);
	if (b == 0) {
		printf("括号匹配成功\n");
	}
	else if (b == 1) {
		printf("括号匹配失败, 右括号多了\n");
	}
	else if (b == 2) {
		printf("括号匹配失败，左右括号不匹配\n");
	}
	else if (b == 3) {
		printf("括号匹配失败， 左括号多了\n");
	}
	return 0;
}
