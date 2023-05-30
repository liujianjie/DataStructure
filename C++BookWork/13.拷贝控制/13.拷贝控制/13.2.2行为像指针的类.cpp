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
���壺
����ָ���Ա�����������ָ���string

��Ҫһ���������Լ���Ƶ�

������Ϊ�����ĳ�Ա����Ϊ�����ʱ���޷�����
����ڶ�̬�ڴ��У�ͨ������ָ���������ָ��
*/

class TreeNode
{
public:
	TreeNode(const string &s = string()): value(s),count(new int(1)),left(nullptr),right(nullptr){}
	TreeNode(const TreeNode& tr) :value(tr.value), count(tr.count), left(tr.left), right(tr.right) { ++*count; }
	TreeNode& operator=(const TreeNode& tr) 
	{
		// ִ�п��������������Ҫ�Ĳ���,�����Ը�ֵ
		++*tr.count;// �����Ҳ�����
		if (--*count == 0) {// �ټ�ȥ���
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
	int* count;// ��Ŀû��*
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree():root(new TreeNode){}
	BinStrTree(const BinStrTree& bst)
	{
		// Ӧ��������ֵ
		root = new TreeNode(*bst.root);
	} 
	BinStrTree& operator=(const BinStrTree& bst)
	{
		// ͬ�� �����������ȿ�����������ͬһ�������ٿ���ͬһ�����޸ģ�
		// �ȿ����ұ�
		auto temp = new TreeNode(*bst.root);
		// ��ɾ���
		delete root;
		// �ٸ������
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
	cout << "fun ��ָ������" << hs.getUse() << endl;
}

int main() {

	int aa;
	size_t *size = new size_t(9);
	cout << (--*size) << endl;

	HasPtr h1("���"), h2;
	fun(h1);
	cout << "main ��ָ������" << h1.getUse() << endl;

	// �Ը�ֵ
	h1 = h1;
	//string* in = new string("3");
	//string* in = nullptr;
	int* in = new int(0);
	if (in) {
		cout << "����" << endl;
	}

	// ��ϰ

	cin >> aa;
	return 0;
}