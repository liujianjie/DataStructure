#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;
// �Ա������(��c1 > c2 ����1�� �� c1 < c2 ����-1 ��
int CompareCal(char c1, char c2) {// c1��c2 ����������ٶ�ֻ��+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// ��+ -��С�ڡ�* /��
			return -1;
	}
	return 1;// Ĭ�ϴ���
}
int Cal(int val1, char op, int val2) {
	switch (op) {
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
// 1.��׺ת��׺���ʽ�����㷨 
string GenerateHou(stack<char>& opstack, string& s) {
	string hous;
	char curc, zhanc;// ��ǰɨ����ַ���ջ�е��ַ� 
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.�Ƿ����� ���Ǿͼ����׺���ʽ�� 
		if (isdigit(curc)) {
			hous = hous + curc;
		}
		else {
			// 2.�������֣��ж��Ƿ���޷�
			if (curc == '(') {// ���뵽ջ�� 
				opstack.push(curc);
			}
			else if (curc == ')') {// ����ջ��Ԫ�ؼӵ���׺�� 
				if (!opstack.empty()) {
					zhanc = opstack.top();
					opstack.pop();
					while (zhanc != '(') {// ����ջ�е������
						hous = hous + zhanc;
						// �ٴγ������ 
						zhanc = opstack.top();
						opstack.pop();
					}
				}
			}
			else {
				// �ص㣺3. �������,���ε���ջ��������ȵ�ǰ��������ȼ����ߺ���ȵģ������׺���ʽ ,��ǰ�������ջ ��
				/*
				�������������ջ���������������ǰ���������ջ��
				1.ջ��
				2.ջ���������'('
				3.��ǰ�������ջ����������ȼ���
				*/
				while (!opstack.empty()) {
					zhanc = opstack.top();
					if (zhanc == '(') {
						break;
					}
					if (CompareCal(curc, zhanc) == -1) { // ��ǰ�������ջ����������ȼ���=ջ��������ȵ�ǰ��������ȼ��ߣ��Ͱ�ջ����������׺���ʽ
						// ջ����������ȼ��߳�ջ
						zhanc = opstack.top();
						opstack.pop();
						hous = hous + zhanc;
					}
					else {
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// ��ջ��ʣ�µķ����׺���ʽ��
	while (!opstack.empty()) {
		zhanc = opstack.top();
		opstack.pop();
		hous = hous + zhanc;
	}
	return hous;
}
// 2.��׺���ʽ���� 
int CalHou(stack<int>& distack, string& s) {
	int leftv, rightv;// ��ֵ��ֵ 
	int sum = 0;
	char curc;
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.�ǲ�����ֱ��ѹ��ջ 
		if (isdigit(curc)) {
			distack.push(curc - '0');
		}
		else {
			// 2.������������е���ջ������Ԫ�ؼ��㣬��ס������ֵ����ջ��ע���һ�ε���������ֵ���ڶ��β�����ֵ
			rightv = distack.top();
			distack.pop();

			leftv = distack.top();
			distack.pop();
			sum = Cal(leftv, curc, rightv);
			distack.push(sum);
		}
	}
	return sum;
}
int main()
{
	// ����Сȱ�㣺�����ֵ���ڵ���10�ͻ���� 
	
	// 1.���ɺ�׺���ʽ
	stack<char> opstack0;
	string s1 = "1+4*3+2";
	string s2 = GenerateHou(opstack0, s1);
	cout << "��׺���ʽ" << s1 << "ת����׺���ʽΪ��" << s2 << endl;
	// 2.�����׺���ʽ
	stack<int> distack0;
	int val = CalHou(distack0, s2);
	cout << "�����׺���ʽ" << s2 << "�ã�" << val << endl;

	 s1 = "1+(6+4*3)+2";
	 s2 = GenerateHou(opstack0, s1);
	cout << "��׺���ʽ" << s1 << "ת����׺���ʽΪ��" << s2 << endl;

	return 0;
}
