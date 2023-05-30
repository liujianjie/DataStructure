#include <stdio.h> 
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h> 
#include <stack> 

using namespace std;

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
int Cal(int val1, char op, int val2){
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
// 7.3.��׺ת��׺���ʽ�����ɺͱ߼����㷨 
int Zhongzhui(stack<int> &distack, stack<char> &opstack, string s){
	char curc, zhanc;// ��ǰɨ����ַ���ջ�е��ַ� 
	int leftv, rightv, sum;
	for(int i = 0; i < s.length(); i++){
		curc = s[i];
		// 1.�Ƿ����� ���Ǿͼ����׺���ʽ�� 
		if(isdigit(curc)){
			distack.push(curc - '0');
		}else{
			// 2.�������֣��ж��Ƿ���޷�
			if(curc == '('){// ���뵽ջ�� 
				opstack.push(curc);
			}
			else if(curc == ')'){// ����ջ��Ԫ�ؼӵ���׺�� 
				if(!opstack.empty()){
					zhanc = opstack.top();
					opstack.pop();
					while(zhanc != '('){
						// �޸ĵĵط����ü���
						rightv = distack.top();
						distack.pop();
						
						leftv = distack.top();
						distack.pop();
						
						sum = Cal(leftv, zhanc, rightv);
						// ��ֵ��ջ 
						distack.push(sum);
						// �ٴγ������ 
						zhanc = opstack.top();
						opstack.pop();
					}
				}
			}else{
				// �ص㣺3. �������,���ε���ջ��������ȵ�ǰ��������ȼ����ߺ���ȵģ������׺���ʽ 
				// ջ�ջ���(ֹͣ, ���ߵ�ǰ�����������ջ���������ֹͣ ,��ǰ�������ջ�� 
				while(!opstack.empty()){
					zhanc = opstack.top();// ע������ 
					if(zhanc == '('){ 
						break;
					}
					if(CompareCal(curc, zhanc)){
						// �޸ĵĵط� 
						zhanc = opstack.top();
						opstack.pop();
						
						rightv = distack.top();
						distack.pop();
						
						leftv = distack.top();
						distack.pop();
						
						sum = Cal(leftv, zhanc, rightv);
						// ��ֵ��ջ 
						distack.push(sum);
					}else{
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// ��ջ��ʣ�µļ��� 
	while(!opstack.empty()){
		// �޸ĵĵط� 
		zhanc = opstack.top();
		opstack.pop();
		
		rightv = distack.top();
		distack.pop();
		
		leftv = distack.top();
		distack.pop(); 
		
		sum = Cal(leftv, zhanc, rightv);
		// ��ֵ��ջ 
		distack.push(sum);
	}
	return distack.top();
} 
 
int main()
{
	// ��Ҫ����ջ��һ���������һ��������
	stack<int> distack;
	stack<char> opstack; 
	string s = "1*(4+3)+2";
	
	int val = Zhongzhui(distack, opstack, s);
//	while(!distack.empty()){
//		printf("%d\t", distack.top());
//		distack.pop();
//	}
	printf("%d\n", val);
	return 0;
} 
