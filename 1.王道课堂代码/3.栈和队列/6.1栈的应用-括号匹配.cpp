#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Linknode{
	char data;
	struct Linknode *next;
}Linknode, *LiStack;

// ∫Û≤Â∑®≤Â»Î,‘⁄¡¥’ª ◊¥¶≤Â»Î“ª∏ˆΩ⁄µ„ 
bool InsertNextNode(LiStack &L, char e){
	Linknode *s = (Linknode*)malloc(sizeof(Linknode));	
	s->data = e; 
	if(L == NULL){
		L = s;	// µ⁄“ª∏ˆΩ⁄µ„ 
		s->next = NULL;// œ¬“ª∏ˆ≥ı ºªØŒ™ø’ £°£°£° 
	}else{
		s->next = L;
		L = s;
	}
	return true;
}

// »Î’ª
bool Push(LiStack &L, char e){
	return InsertNextNode(L, e);
} 
// ≥ˆ’ª
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

//  «∑ÒŒ™ø’
bool LiStackEmpty(LiStack &L){
	if(L == NULL){
		return true;
	}
	return false;
}

// ¥Ú”°
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
// ¿®∫≈∆•≈‰À„∑® 
int MatchKuohao(LiStack &L, char *s, int len){
	char c = 0;
	for(int i = 0; i < len; i++){
		c = s[i];
		// 1.≈–∂œ «∑ÒŒ™◊Û¿®∫≈  «æÕ»Î’ª 
		if(c == '(' || c == '{' || c == '['){
			Push(L, c);
		}else{
			// 2. «”“¿®∫≈£¨»°≥ˆ’ª∂•¿®∫≈”Î÷Æ∆•≈‰
			if(LiStackEmpty(L)){ // ≤ª¥Ê‘⁄◊Û¿®∫≈”Î÷Æ∆•≈‰£¨¥˙±Ì ß∞‹ 
				return 1;
			}
			Pop(L, c); 
			// ≈–∂œ «∑Ò∆•≈‰ 
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
	// 3.‘⁄≈–∂œ’ª «∑Ò”–◊Û¿®∫≈Œ¥∆•≈‰µƒ
	if(!LiStackEmpty(L)){
		return 3;
	}
	return 0; 
} 

int main()
{
	int e;
	LiStack L = NULL;
	// ¿®∫≈∆•≈‰ø™ º
	char *s = "({()})"; 
	int b = MatchKuohao(L, s, strlen(s));
	if(b == 0) {
		printf("¿®∫≈∆•≈‰≥…π¶\n");
	}else if(b == 1){
		printf("¿®∫≈∆•≈‰ ß∞‹, ”“¿®∫≈∂‡¡À\n");
	}else if(b == 2){
		printf("¿®∫≈∆•≈‰ ß∞‹£¨◊Û”“¿®∫≈≤ª∆•≈‰\n");	
	}else if(b == 3){
		printf("¿®∫≈∆•≈‰ ß∞‹£¨ ◊Û¿®∫≈∂‡¡À\n");	
	}
	return 0;
} 
