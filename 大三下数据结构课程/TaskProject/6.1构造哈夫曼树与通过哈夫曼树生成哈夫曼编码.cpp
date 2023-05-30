#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, * HuffmanTree;

// ������������Ĵ���
void SelectTwoSamll(HuffmanTree& HT, int n, int& s1, int& s2) {// ����С�������������������for���߼��������ȶ���
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
	int m = 2 * n - 1;	// n��Ҷ�ӽ��Ĺ���������2n-1�����
	HT = new HTNode[m + 1];// ��ʼ���ռ�
	for (int i = 1; i <= m; i++) {// ��ʼ�����������ϵĽ��
		HT[i].parent = 0;
		HT[i].lchild = HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++) {// ����Ҷ�ӽ��
		cin >> HT[i].weight;
	}
	/*
	˼·���ӹ���������ѡ��������С�Ľ�����½�㣬ֱ���ϲ�n-1��
	1.ѡ��������С�Ľ��s1��s2
	2.���½��ŵ�������iλ����
	3.������С���ĸ���Ϊi
	4.�½������Һ���Ϊs1,s2,Ȩ��Ϊs1��s2Ȩ��֮��
	*/
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {//n+1 ~ m��Ҫ����������洢��λ�����
		SelectTwoSamll(HT, i - 1, s1, s2);// ע����i-1����Ϊÿ�ι���һ���µĽ�㣬���������Ͷ�һ��
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
// �������
void DisPlay(HuffmanTree& HT, int m) {
	for (int i = 1; i <= m; i++) {
		//if (HT[i].lchild == 0 && HT[i].rchild == 0) {
		cout << HT[i].weight << '\t';
		//}
	}
}

// �����������ɹ������������
/*
˼·��������ʣ���Ҷ�ӽ�����һֱ���ʵ����ڵ�
*/
void CreateHuffmanCode(HuffmanTree& HT, string(&hfmcodestr)[9], int n) {
	for (int i = 1; i <= n; i++) {			// n��Ҷ�ӽ��
		int curc = i;						// ��ǰ�������
		int curf = HT[i].parent;				// ��ǰ���ĸ���
		string s1;							// ��ǰҶ�ӽ������������ַ���
		while (curf != 0) {					// û�е�����ڵ�
			if (HT[curf].lchild == curc)		// ��ǰ�ĸ��ڵ����ڵ��ǵ�ǰ���
				s1.insert(0, "0");			// ���ַ���0��λ������0�ַ���
			else								// ��ǰ�ĸ��ڵ���ҽڵ��ǵ�ǰ���
				s1.insert(0, "1");			// ���ַ���0��λ������1�ַ���
			curc = curf;						// ���µ�ǰ�������
			curf = HT[curf].parent;			// ���µ�ǰ���ĸ���
		}
		s1.insert(0, to_string(HT[i].weight) + ":");// �ĸ�Ҷ�ӽ��Ĺ���������
		hfmcodestr[i] = s1;
	}
}

void main() {
	HuffmanTree HT;
	const int n = 8;
	// �����빹���������
	CreateHuffmanTree(HT, n);
	//DisPlay(HT, n*2 - 1);// ���Թ����������

	// �õ�����������
	string hfmcodestr[n + 1];
	CreateHuffmanCode(HT, hfmcodestr, n);
	// �������������
	for (string s : hfmcodestr) {
		cout << s << endl;
	}
}
/*
5 29 7 8 14 23 3 11
*/