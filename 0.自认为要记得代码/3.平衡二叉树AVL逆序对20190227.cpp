#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ForD(i,n) for(int i = n; i; i--)
#define F (100000007)
#define MAXN (2 * 200000 + 10)

long long mul(long long a, long long b) {
	return (a * b) % F;
}

long long add(long long a, long long b) {
	return (a + b) % F;
}
long long sub(long long a, long long b) {
	return (a - b + (a - b) / F * F + F) % F;
}

int n, root = 0;
struct node {
	int fa, ch[2], size, c;
	node() :size(0), c(0) {
		ch[0] = ch[1] = fa = 0;
	}
}tree[MAXN];

void update(int x) {
	tree[x].size = tree[tree[x].ch[0]].size + tree[tree[x].ch[1]].size + (tree[x].c > 0);
}

int tail = 0;
void pushdown(int x) {
	tree[tree[x].ch[0]].fa = tree[tree[x].ch[1]].fa = x;
}
void build(int &x)
{
	if (!x)
		x = ++tail;
	cin >> tree[x].c;
	if (tree[x].c == 0) {
		build(tree[x].ch[0]);
		build(tree[x].ch[1]);
		update(x);
		pushdown(x);
	}
	else {
		tree[x].size = 1;
	}
}
void rotate(int x) 
{
	int y = tree[x].fa;
	int z = tree[y].fa;
	bool p = tree[y].ch[0] == x;
	if (z) {
		if (tree[z].ch[0] == y) {
			tree[z].ch[0] = x;
		}
		else {
			tree[z].ch[1] = x;
		}
	}
	tree[x].fa = z;
	tree[y].fa = x;
	if (tree[x].ch[p])
		tree[tree[x].ch[p]].fa = y;
	tree[y].ch[p ^ 1] = tree[x].ch[p];
	tree[x].ch[p] = y;
	update(y);
}

void splay(int x)
{
	while (tree[x].fa) {
		int y = tree[x].fa;
		int z = tree[y].fa;
		if (z) {
			if ((tree[y].ch[0] == x) ^ tree[z].ch[0] == y)
				rotate(x);
			else
				rotate(y);
		}
		rotate(x);
	}
	update(x);
}

void ins(long long &tot,int x,int y)
{
	tree[x].size++;
	if (tree[y].c <= tree[x].c) {
		if (tree[x].ch[0])
			ins(tot, tree[x].ch[0], y);
		else {
			tree[y].fa = x;
			splay(tree[x].ch[0] = y);
		}
	}
	else {
		tot += tree[tree[x].ch[0]].size + (tree[x].c > 0);
		if (tree[x].ch[1])
			ins(tot, tree[x].ch[1], y);
		else {
			tree[y].fa = x;
			splay(tree[x].ch[1] = y);
		}
	}
}
int q[MAXN], siz;
void clac(int x,int y)
{
	if (tree[y].ch[0])
		clac(x, tree[y].ch[0]);
	if (tree[y].c)
		q[++siz] = y;
	if (tree[y].ch[1])
		clac(x, tree[y].ch[1]);
}

long long merge(bool &lor, int z) {
	int x = tree[z].ch[0], y = tree[z].ch[1];
	if (tree[x].size < tree[y].size)
		swap(x, y);

	tree[x].fa = 0;
	tree[y].fa = 0;
	q[1] = y;
	siz = 0;
	clac(x, y);
	long long tot = 0;
	ForD(i, siz) {
		int now = q[i];
		tree[now].ch[0] = tree[now].ch[1] = tree[now].fa = 0;
		tree[now].size = 1;
		ins(tot, x, now);
		x = now;
	}
	tree[x].fa = z;
	tree[z].ch[0] = 0;
	tree[z].ch[1] = x;
	return tot;
}
long long qur(int &x) {
	// 叶子节点
	if (tree[x].c)
		return 0;
	else
	{
		long long lson = tree[tree[x].ch[0]].size, rson = tree[tree[x].ch[1]].size;
		long long ls = qur(tree[x].ch[0]);
		long long rs=qur(tree[x].ch[1]);
		bool lor = 0;
		long long ms = merge(lor, x);
		return ls + rs + min(lson * rson - ms, ms);
	}
}

int main() 
{
	cin >> n;
	build(root);
	cout << qur(root) << endl;
	cin >> n;
	return 0;
}
/**
*
问题描述
Alice是一个让人非常愉跃的人!他总是去学习一些他不懂的问题，然后再想出许多稀奇古怪的题目。这几天，Alice又沉浸在逆序对的快乐当中，他已近学会了如何求逆序对对数，动态维护逆序对对数等等题目，他认为把这些题让你做简直是太没追求了，于是，经过一天的思考和完善，Alice终于拿出了一道他认为差不多的题目：

有一颗2n-1个节点的二叉树，它有恰好n个叶子节点，每个节点上写了一个整数。如果将这棵树的所有叶子节点上的数从左到右写下来，便得到一个序列a[1]…a[n]。现在想让这个序列中的逆序对数量最少，但唯一的操作就是选树上一个非叶子节点，将它的左右两颗子树交换。他可以做任意多次这个操作。求在最优方案下，该序列的逆序对数最少有多少。

Alice自己已近想出了题目的正解，他打算拿来和你分享，他要求你在最短的时间内完成。

输入格式
第一行一个整数n。

下面每行，一个数x。

如果x=0，表示这个节点非叶子节点，递归地向下读入其左孩子和右孩子的信息，如果x≠0，表示这个节点是叶子节点，权值为x。

输出格式
输出一个整数，表示最少有多少逆序对。
样例输入
3
0
0
3
1
2
样例输出
1
数据规模与约定
对于20%的数据，n <= 5000。

对于100%的数据，1 <= n <= 200000，0 <= a[i]<2^31。
*/