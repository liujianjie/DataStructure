#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
#include <stack>
#include <queue>
using namespace std;

// �Լ�����ģ��ȽϺ�����̫low��
template <class _Tp>
struct greater : public binary_function<_Tp, _Tp, bool>
{
	bool operator()(const _Tp& __x, const _Tp& __y) const { return __x > __y; }
};

int main()
{
	int a;
	deque<int> deq{1,2,3,4,5};
	stack<int> stk(deq);
	//cout << stk.size();
	stack<int>::size_type size = stk.size();
	for (int i = 0; i < size; i++) {
		auto v = stk.top();
		cout << v << endl;
		stk.pop();
	}
	// ��vector��ʵ�ֵĿ�ջ
	stack<string, vector<string>> str_stk;

	// str_stk2��vector��ʵ�֣���ʼ��ʱ����svec�Ŀ���
	vector<string> svec{"34","12","56","78","09"};
	stack<string, vector<string>> str_stk2(svec);
	stack<int>::size_type size2 = str_stk2.size();
	for (int i = 0; i < size2; i++) {
		cout << str_stk2.top() << endl;
		str_stk2.pop();
	}
	// ������array forward_list
	/*stack<string, array<string, 10>> str_stk3;*/
	stack<string, forward_list<string>> str_stk3;
	//str_stk3.push("123");
	// forward_list���������������������е�
	// ��list��deque����queue
	queue<string, list<string>> que1;
	que1.push("123");
	//queue<string, vector<string>> que2;
	//que2.pop();// ������pop();
	queue<string, array<string,10>> que3;
	//que3.pop();// ������pop();

	// ��vector��deque����
	priority_queue<list<string>> pq1;
	//pq1.push("123");// ����
	priority_queue<array<string, 10>> pq2;
	//pq2.push("112");// ����
	//vector<string> v1{"12321"};
	//priority_queue<vector<string>> pq3(v1);// ���鷳����vector��ô����ѽ�������÷���
	//pq3.top();

	// ջ������
	stack<int> intStack;// ��ջ
	// ����ջ
	for (size_t ix = 0; ix != 10; ++ix) {
		intStack.push(ix);
		//intStack.push_back(ix);// ��Ȼ�ǻ���dequeʵ�ֵģ����ǲ����������
	}
	// ��Ϊ�յ�ʱ��
	while (!intStack.empty()) {
		int value = intStack.top();
		cout << value << endl;
		// ʹ��ջ��ֵ�ô���
		intStack.pop();// ����ջ��Ԫ�أ�����ѭ��
	}

	// ����������
	queue<int> q11;
	for (size_t ix = 0; ix != 10; ++ix) {
		q11.push(ix);
	}
	while (!q11.empty()) {
		int value = q11.front();
		cout << value << endl;
		// ʹ��ջ��ֵ�ô���
		q11.pop();// ����ջ��Ԫ�أ�����ѭ��
	}
	priority_queue<int> pq11;
	for (size_t ix = 0; ix != 10; ++ix) {
		pq11.push(ix);
	}
	while (!pq11.empty()) {
		int value = pq11.top();// �������Ԫ��
		cout << value << endl;
		// ʹ��ջ��ֵ�ô���
		pq11.pop();// ����ջ��Ԫ�أ�����ѭ��
	}
	cout << "priority_queue<int, vector<int>, greater<int> >" << endl;
	priority_queue<int, vector<int>, greater<int> > pq12;
	for (size_t ix = 0; ix != 10; ++ix) {
		pq12.push(ix);
	}
	while (!pq12.empty()) {
		int value = pq12.top();// �������Ԫ��
		cout << value << endl;
		// ʹ��ջ��ֵ�ô���
		pq12.pop();// ����ջ��Ԫ�أ�����ѭ��
	}
	vector<string> ve1;
	list<string> li9;
	//li9.pop_front();
	cin >> a;
	return 0;
}