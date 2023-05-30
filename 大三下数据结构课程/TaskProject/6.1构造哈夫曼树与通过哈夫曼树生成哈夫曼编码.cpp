#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

// 构造哈夫曼树的代码
void SelectTwoSamll(HuffmanTree& HT, int n, int& s1, int& s2) {// 找最小的两个，简单起见，两层for，高级的用优先队列
	int weight = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && weight > HT[i].weight) {
			weight = HT[i].weight;
			s1 = i;
		}
	}
	weight = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && i != s1 && weight > HT[i].weight) {
			weight = HT[i].weight;
			s2 = i;
		}
	}
}
void CreateHuffmanTree(HuffmanTree& HT, int n) {
	if (n <= 1) return;
	int m = 2 * n - 1;	// n个叶子结点的哈夫曼树有2n-1个结点
	HT = new HTNode[m + 1];// 初始化空间
	for (int i = 1; i <= m; i++) {// 初始化哈夫曼树上的结点
		HT[i].parent = 0;
		HT[i].lchild = HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++) {// 输入叶子结点
		cin >> HT[i].weight;
	}
	/*
	思路：从哈夫曼树中选择两个最小的结点结合新结点，直至合并n-1次
	1.选择两个最小的结点s1，s2
	2.把新结点放到递增的i位置上
	3.两个最小结点的父亲为i
	4.新结点的左右孩子为s1,s2,权重为s1与s2权重之和
	*/
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {//n+1 ~ m是要构造出来结点存储的位置序号
		SelectTwoSamll(HT, i - 1, s1, s2);// 注意是i-1，因为每次构造一个新的结点，哈夫曼树就多一个
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
// 遍历结点
void DisPlay(HuffmanTree& HT, int m) {
	for (int i = 1; i <= m; i++) {
		//if (HT[i].lchild == 0 && HT[i].rchild == 0) {
		cout << HT[i].weight << '\t';
		//}
	}
}

// 哈夫曼树生成哈夫曼编码代码
/*
思路：逆序访问，从叶子结点出发一直访问到根节点
*/
void CreateHuffmanCode(HuffmanTree& HT, string(&hfmcodestr)[9], int n) {
	for (int i = 1; i <= n; i++) {			// n个叶子结点
		int curc = i;						// 当前结点的序号
		int curf = HT[i].parent;				// 当前结点的父亲
		string s1;							// 当前叶子结点哈夫曼编码字符串
		while (curf != 0) {					// 没有到达根节点
			if (HT[curf].lchild == curc)		// 当前的父节点的左节点是当前结点
				s1.insert(0, "0");			// 在字符串0的位置增加0字符串
			else								// 当前的父节点的右节点是当前结点
				s1.insert(0, "1");			// 在字符串0的位置增加1字符串
			curc = curf;						// 更新当前结点的序号
			curf = HT[curf].parent;			// 更新当前结点的父亲
		}
		s1.insert(0, to_string(HT[i].weight) + ":");// 哪个叶子结点的哈夫曼编码
		hfmcodestr[i] = s1;
	}
}

void main() {
	HuffmanTree HT;
	const int n = 8;
	// 创建与构造哈夫曼树
	CreateHuffmanTree(HT, n);
	//DisPlay(HT, n*2 - 1);// 测试哈夫曼树结点

	// 得到哈夫曼编码
	string hfmcodestr[n + 1];
	CreateHuffmanCode(HT, hfmcodestr, n);
	// 输出哈夫曼编码
	for (string s : hfmcodestr) {
		cout << s << endl;
	}
}
/*
5 29 7 8 14 23 3 11
*/