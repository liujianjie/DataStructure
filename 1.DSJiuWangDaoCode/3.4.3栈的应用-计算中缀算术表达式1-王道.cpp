#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;
// ��������
// �Ա������(��c1 > c2 ����1�� �� c1 < c2 ����-1 ��
int CompareCal(char c1, char c2) {// c1��c2 ����������ٶ�ֻ��+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// ��+ -��С�ڡ�* /��
			return -1;
	}
	return 1;
}
// ����
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
// ��׺ת��׺���ʽ�����ɺͱ߼����㷨 
int CalExpression(stack<int>& distack, stack<char>& opstack, string& s) {
	char curc, zhanc;// ��ǰɨ����ַ���ջ�е��ַ� 
	int leftv, rightv, sum;
	for (int i = 0; i < s.length(); i++) {
		curc = s[i];
		// 1.�Ƿ����� ���Ǿͼ����׺���ʽ�� 
		if (isdigit(curc)) {
			distack.push(curc - '0');
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
					while (zhanc != '(') {
						// ����ں�׺���ʽ���ɴ��룬�޸ĵĵط����ü���
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
			}
			else {
				// �ص㣺3. �������,���ε���ջ��������ȵ�ǰ��������ȼ����ߺ���ȵģ������׺���ʽ 
				/*
				�������������ջ���������������ǰ���������ջ��
				1.ջ��
				2.ջ���������'('
				3.��ǰ�������ջ����������ȼ���
				*/
				while (!opstack.empty()) {
					zhanc = opstack.top();// ע������ 
					if (zhanc == '(') {
						break;
					}
					if (CompareCal(curc, zhanc) == -1) { // ��ǰ�������ջ����������ȼ���=ջ��������ȵ�ǰ��������ȼ��ߣ��Ͱ�ջ����������׺���ʽ
						// ջ����������ȼ��߾ͼ���
						// ����ں�׺���ʽ���ɴ��� �޸ĵĵط� 
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
					else {
						break;
					}
				}
				opstack.push(curc);
			}
		}
	}
	// ��ջ��ʣ�µļ��� 
	while (!opstack.empty()) {
		// ����ں�׺���ʽ���ɴ��� �޸ĵĵط� 
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
	// ����Сȱ�㣺�����ֵ���ڵ���10�ͻ����
	 
	// �����������ʽ
	// ��Ҫ����ջ��һ�������ջ��һ��������ջ
	stack<int> distack;
	stack<char> opstack;
	string s3 = "1*(4+3)+2";

	int val2 = CalExpression(distack, opstack, s3);
	cout << "������׺�������ʽ" << s3 << "�ã�" << val2 << endl;
	return 0;
}
