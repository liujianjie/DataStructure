#include <stdio.h> 
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h> 
#include <stack> 

using namespace std;

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
// 7.3.中缀转后缀表达式边生成和边计算算法 
int Zhongzhui(stack<int> &distack, stack<char> &opstack, string s){
	char curc, zhanc;// 当前扫描的字符和栈中的字符 
	int leftv, rightv, sum;
	for(int i = 0; i < s.length(); i++){
		curc = s[i];
		// 1.是否数字 ，是就加入后缀表达式中 
		if(isdigit(curc)){
			distack.push(curc - '0');
		}else{
			// 2.不是数字，判断是否界限符
			if(curc == '('){// 加入到栈中 
				opstack.push(curc);
			}
			else if(curc == ')'){// 弹出栈的元素加到后缀中 
				if(!opstack.empty()){
					zhanc = opstack.top();
					opstack.pop();
					while(zhanc != '('){
						// 修改的地方，得计算
						rightv = distack.top();
						distack.pop();
						
						leftv = distack.top();
						distack.pop();
						
						sum = Cal(leftv, zhanc, rightv);
						// 数值入栈 
						distack.push(sum);
						// 再次出运算符 
						zhanc = opstack.top();
						opstack.pop();
					}
				}
			}else{
				// 重点：3. 是运算符,依次弹出栈中运算符比当前运算符优先级更高和相等的，加入后缀表达式 
				// 栈空或者(停止, 或者当前运算符优先于栈中运算符就停止 ,当前运算符入栈。 
				while(!opstack.empty()){
					zhanc = opstack.top();// 注意这里 
					if(zhanc == '('){ 
						break;
					}
					if(CompareCal(curc, zhanc)){
						// 修改的地方 
						zhanc = opstack.top();
						opstack.pop();
						
						rightv = distack.top();
						distack.pop();
						
						leftv = distack.top();
						distack.pop();
						
						sum = Cal(leftv, zhanc, rightv);
						// 数值入栈 
						distack.push(sum);
					}else{
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// 把栈中剩下的计算 
	while(!opstack.empty()){
		// 修改的地方 
		zhanc = opstack.top();
		opstack.pop();
		
		rightv = distack.top();
		distack.pop();
		
		leftv = distack.top();
		distack.pop(); 
		
		sum = Cal(leftv, zhanc, rightv);
		// 数值入栈 
		distack.push(sum);
	}
	return distack.top();
} 
 
int main()
{
	// 需要两个栈，一个运算符，一个操作数
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
