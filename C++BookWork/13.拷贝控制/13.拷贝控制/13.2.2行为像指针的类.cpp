#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"

using namespace std;
/*
定义：
拷贝指针成员本身而不是它指向的string

需要一个计数，自己设计的

不能作为类对象的成员，因为多个的时候无法更新
需放在动态内存中，通过拷贝指向计数器的指针
*/

class TreeNode
{
public:
	TreeNode(const string &s = string()): value(s),count(new int(1)),left(nullptr),right(nullptr){}
	TreeNode(const TreeNode& tr) :value(tr.value), count(tr.count), left(tr.left), right(tr.right) { ++*count; }
	TreeNode& operator=(const TreeNode& tr) 
	{
		// 执行拷贝构造和析构都要的操作,处理自赋值
		++*tr.count;// 先是右侧增加
		if (--*count == 0) {// 再减去左侧
			delete count;
			if (left) {
				delete left;
			}
			if (right) {
				delete right;
			}
		}
		value = tr.value;
		count = tr.count;
		left = tr.left;
		right = tr.right;
		return *this; 
	}
	~TreeNode() 
	{
		if (--*count == 0) {
			delete count;
			if (left) {
				delete left;
			}
			if (right) {
				delete right;
			}
		}
	}
private:
	string value;
	int* count;// 题目没有*
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree():root(new TreeNode){}
	BinStrTree(const BinStrTree& bst)
	{
		// 应该让其像值
		root = new TreeNode(*bst.root);
	} 
	BinStrTree& operator=(const BinStrTree& bst)
	{
		// 同样 两个操作，先考虑两个不是同一个对象，再考虑同一对象修改！
		// 先拷贝右边
		auto temp = new TreeNode(*bst.root);
		// 再删左侧
		delete root;
		// 再赋给左侧
		root = temp;
		return *this;
	}
	~BinStrTree()
	{
		delete root;
	}
private:
	TreeNode *root;

};

void fun(HasPtr hs) 
{
	cout << "fun 中指针数：" << hs.getUse() << endl;
}

int main() {

	int aa;
	size_t *size = new size_t(9);
	cout << (--*size) << endl;

	HasPtr h1("你好"), h2;
	fun(h1);
	cout << "main 中指针数：" << h1.getUse() << endl;

	// 自赋值
	h1 = h1;
	//string* in = new string("3");
	//string* in = nullptr;
	int* in = new int(0);
	if (in) {
		cout << "可以" << endl;
	}

	// 练习

	cin >> aa;
	return 0;
}