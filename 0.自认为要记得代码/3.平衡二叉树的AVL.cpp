#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a[102000];
struct node 
{
	int val;
	struct node *left, *right;
};
int getHeight(node *root) 
{
	if (root == NULL)
		return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *rotateLeft(node *root) 
{
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node *rotateRight(node *root)
{
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node *rotateLeftRight(node *root)
{
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}
node *rotateRightLeft(node *root)
{
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}
node *insert(node *root, int val)
{
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2) {
			root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
		}
	}
	else {
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2) {
			root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
		}
	}
	return root;
}
// 中根排序吧
void display(node *root) 
{
	if (root->left != NULL) {
		display(root->left);
	}
	cout << root->val << " ";
	if (root->right != NULL) {
		display(root->right);
	}
}
int main() 
{
	int n;
	node  *root = NULL;
	while (cin >> n) {
		// insert返回根节点于是可以做display的node来显示数据
		root = insert(root, n);
		display(root);
		cout << endl;
	}

	cin >> n;
	return 0;
}