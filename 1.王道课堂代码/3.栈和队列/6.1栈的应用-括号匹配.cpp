#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

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
// ����ƥ���㷨 
int MatchKuohao(LiStack &L, char *s, int len){
	char c = 0;
	for(int i = 0; i < len; i++){
		c = s[i];
		// 1.�ж��Ƿ�Ϊ������ �Ǿ���ջ 
		if(c == '(' || c == '{' || c == '['){
			Push(L, c);
		}else{
			// 2.�������ţ�ȡ��ջ��������֮ƥ��
			if(LiStackEmpty(L)){ // ��������������֮ƥ�䣬����ʧ�� 
				return 1;
			}
			Pop(L, c); 
			// �ж��Ƿ�ƥ�� 
			if(s[i] == ')' && c != '('){
				return 2;
			}	
			if(s[i] == '}' && c != '{'){
				return 2;
			}	
			if(s[i] == ']' && c != '['){
				return 2;
			}			
		}
	}
	// 3.���ж�ջ�Ƿ���������δƥ���
	if(!LiStackEmpty(L)){
		return 3;
	}
	return 0; 
} 

int main()
{
	int e;
	LiStack L = NULL;
	// ����ƥ�俪ʼ
	char *s = "({()})"; 
	int b = MatchKuohao(L, s, strlen(s));
	if(b == 0) {
		printf("����ƥ��ɹ�\n");
	}else if(b == 1){
		printf("����ƥ��ʧ��, �����Ŷ���\n");
	}else if(b == 2){
		printf("����ƥ��ʧ�ܣ��������Ų�ƥ��\n");	
	}else if(b == 3){
		printf("����ƥ��ʧ�ܣ� �����Ŷ���\n");	
	}
	return 0;
} 
