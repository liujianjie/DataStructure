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
	// Ҷ�ӽڵ�
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
��������
Alice��һ�����˷ǳ���Ծ����!������ȥѧϰһЩ�����������⣬Ȼ����������ϡ��Źֵ���Ŀ���⼸�죬Alice�ֳ���������ԵĿ��ֵ��У����ѽ�ѧ�������������Զ�������̬ά������Զ����ȵ���Ŀ������Ϊ����Щ����������ֱ��̫û׷���ˣ����ǣ�����һ���˼�������ƣ�Alice�����ó���һ������Ϊ������Ŀ��

��һ��2n-1���ڵ�Ķ�����������ǡ��n��Ҷ�ӽڵ㣬ÿ���ڵ���д��һ������������������������Ҷ�ӽڵ��ϵ���������д��������õ�һ������a[1]��a[n]������������������е�������������٣���Ψһ�Ĳ�������ѡ����һ����Ҷ�ӽڵ㣬������������������������������������������������������ŷ����£������е�������������ж��١�

Alice�Լ��ѽ��������Ŀ�����⣬�������������������Ҫ��������̵�ʱ������ɡ�

�����ʽ
��һ��һ������n��

����ÿ�У�һ����x��

���x=0����ʾ����ڵ��Ҷ�ӽڵ㣬�ݹ�����¶��������Ӻ��Һ��ӵ���Ϣ�����x��0����ʾ����ڵ���Ҷ�ӽڵ㣬ȨֵΪx��

�����ʽ
���һ����������ʾ�����ж�������ԡ�
��������
3
0
0
3
1
2
�������
1
���ݹ�ģ��Լ��
����20%�����ݣ�n <= 5000��

����100%�����ݣ�1 <= n <= 200000��0 <= a[i]<2^31��
*/