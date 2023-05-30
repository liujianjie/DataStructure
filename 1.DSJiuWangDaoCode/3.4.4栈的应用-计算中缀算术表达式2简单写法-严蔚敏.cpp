// ������ջ��������Ϊ������Ŀ���������ʽ������дһ���ļ�����
#include <iostream>
#include <string>
#include <stack> 
using namespace std;
// ��������
// 1.�Ƚ�������������ȣ�(��c1 > c2 ����1�� �� c1 < c2 ����-1 , ��c1 = c2 ����0��
int CompareCal(char c1, char c2) { // ֻ���� +-*/()#; �κ������ ����+-*/()#
	// # �ǿ�ʼ�� ��������
	if (c1 == '#' && c2 == '#') {
		return 0;
	}
	if (c1 == '#') return -1;// c1��#����С���ڳ��ˡ�#�����κ������
	if (c2 == '#') return 1;// c1��Զ���� c2Ϊ#ʱ
	if (c1 == '(' && c2 == ')') {
		return 0;
	}
	if (c1 == '(' || c2 == '(') {// ��(����С���ڳ��ˡ�)�����κ������
		return -1;
	}
	if (c1 == ')' || c2 == ')')// ��)�������ڳ��ˡ��������κ������
		return 1;

	switch (c1)
	{
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// ��+ -��С�ڡ�* /��
			return -1;
	}
	return 1; // Ĭ�ϴ���
}
// 2.����
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
// �����������ʽ����-������ε����
int CalExpression(stack<int>& valstack, stack<char>& opstack, string& s) { // opstack�������ջ��valstack�ǲ�����ջ
	s.append("#");									// ��ӽ�����־
	opstack.push('#');								// �����ջ������־
	int a, b;										// a�����������b���Ҳ�����
	char curc, zhanc;								// ��ǰɨ����ַ���ջ�е��ַ� 
	int i = 0;										// i�±�Ϊ0��ʼ
	while (s[i] != '#' || opstack.top() != '#') {// ���ʽû��ɨ����ϻ����ջ�������û������
		curc = s[i];
		if (isdigit(curc)) {							// ch����ֵ�ͷ�����ֵջ
			valstack.push(int(curc - '0'));
			i++;										// ɨ����һ���ַ�
			continue;
		}
		switch (CompareCal(opstack.top(), curc))		// ע����ջ���������c1�뵱ǰ�������c2�Ա�
		{
		case -1:										// c1<c2����ǰ��������ȼ��ߣ�����ǰ�������ջ
			opstack.push(curc);
			i++;										// ɨ����һ���ַ�
			break;
		case 1:										// c1>c2��ջ����������ȼ��ߣ���ȡ����ֵջ�д洢������ֵ���������ջ����������㡣
			zhanc = opstack.top();
			opstack.pop();

			b = valstack.top();						// b���Ҳ�����
			valstack.pop();

			a = valstack.top();
			valstack.pop();							// a���������
			valstack.push(Cal(a, zhanc, b));
			break;
		case 0:										// c1=c2, ��ȣ�#�����������ŲŻ����
			opstack.pop();
			i++;										// ɨ����һ���ַ�
			break;
		}
	}
	return valstack.top();
}
int main() {
	// ����Сȱ�㣺�����ֵ���ڵ���10�ͻ����

	// �����������ʽ
	// ��Ҫ����ջ��һ�������ջ��һ��������ջ
	stack<char> opstack;
	stack<int> valstack;
	string s3 = "1*(4+3)+1";

	int val2 = CalExpression(valstack, opstack, s3);
	cout << "������׺�������ʽ" << s3 << "�ã�" << endl << val2 << endl;

	return 0;
}

