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

// 自己定义模板比较函数吗？太low了
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
	// 在vector上实现的空栈
	stack<string, vector<string>> str_stk;

	// str_stk2在vector上实现，初始化时保存svec的拷贝
	vector<string> svec{"34","12","56","78","09"};
	stack<string, vector<string>> str_stk2(svec);
	stack<int>::size_type size2 = str_stk2.size();
	for (int i = 0; i < size2; i++) {
		cout << str_stk2.top() << endl;
		str_stk2.pop();
	}
	// 不能用array forward_list
	/*stack<string, array<string, 10>> str_stk3;*/
	stack<string, forward_list<string>> str_stk3;
	//str_stk3.push("123");
	// forward_list不能用来构造适配器所有的
	// 用list和deque构造queue
	queue<string, list<string>> que1;
	que1.push("123");
	//queue<string, vector<string>> que2;
	//que2.pop();// 不能用pop();
	queue<string, array<string,10>> que3;
	//que3.pop();// 不能用pop();

	// 用vector和deque构造
	priority_queue<list<string>> pq1;
	//pq1.push("123");// 不可
	priority_queue<array<string, 10>> pq2;
	//pq2.push("112");// 不可
	//vector<string> v1{"12321"};
	//priority_queue<vector<string>> pq3(v1);// 最麻烦，用vector怎么构造呀？？？好烦。
	//pq3.top();

	// 栈适配器
	stack<int> intStack;// 空栈
	// 填满栈
	for (size_t ix = 0; ix != 10; ++ix) {
		intStack.push(ix);
		//intStack.push_back(ix);// 虽然是基于deque实现的，但是不能用这个。
	}
	// 不为空的时候！
	while (!intStack.empty()) {
		int value = intStack.top();
		cout << value << endl;
		// 使用栈顶值得代码
		intStack.pop();// 弹出栈顶元素，继续循环
	}

	// 队列适配器
	queue<int> q11;
	for (size_t ix = 0; ix != 10; ++ix) {
		q11.push(ix);
	}
	while (!q11.empty()) {
		int value = q11.front();
		cout << value << endl;
		// 使用栈顶值得代码
		q11.pop();// 弹出栈顶元素，继续循环
	}
	priority_queue<int> pq11;
	for (size_t ix = 0; ix != 10; ++ix) {
		pq11.push(ix);
	}
	while (!pq11.empty()) {
		int value = pq11.top();// 返回最高元素
		cout << value << endl;
		// 使用栈顶值得代码
		pq11.pop();// 弹出栈顶元素，继续循环
	}
	cout << "priority_queue<int, vector<int>, greater<int> >" << endl;
	priority_queue<int, vector<int>, greater<int> > pq12;
	for (size_t ix = 0; ix != 10; ++ix) {
		pq12.push(ix);
	}
	while (!pq12.empty()) {
		int value = pq12.top();// 返回最高元素
		cout << value << endl;
		// 使用栈顶值得代码
		pq12.pop();// 弹出栈顶元素，继续循环
	}
	vector<string> ve1;
	list<string> li9;
	//li9.pop_front();
	cin >> a;
	return 0;
}