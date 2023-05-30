// 2.˳���ʵ��Լɪ������
// ʱ�临�Ӷ�O(n * m), �ռ临�Ӷ�O(n)
#include <iostream>
using namespace std;
#define MaxSize 100 // ������󳤶� 
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
// i��λ��e��Ԫ�� 
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) { // �Ƿ�Ϸ� 
		return false;
	}
	for (int j = L.length; j >= i; j--) {// ������ƶ�
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;// ��i-1λ�÷���e
	L.length++; // ����+1 
	return true;
}
void InitList(SqList& L) {
	L.length = 0;
	// ����Ԫ��
	int e = 0;
	cin >> e;
	for (int i = 1; e != 0; i++) {
		ListInsert(L, i, e);
		cin >> e;
	}
}
// ����������
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i];
	}
	cout << endl;
}
// Լɪ��
void YSFH(SqList& L, int M) {// M��������
	// i�ǵ�ǰ������±꣬j�ǹ������˳�����,ct���ۼ�M�ı�������ʼ��Ϊ0
	int i = -1, j = 0, ct = 0; 
	while (j < L.length) { // ����û����
		i++;// i�±�ǰ��
		if (i >= L.length) {
			i = 0;// ����ĩβ�ص��ײ�
		}
		if (L.data[i] < 0) {// ������й��ˣ�����
			continue;
		}
		ct++;// ���iλ�õ��˱���
		if (ct >= M) {
			cout << L.data[i] << " ";// ����
			ct = 0;// ��ʼ������ֵ
			L.data[i] = -1;// ��Ϊ-1��������й��ˣ��߼���ɾ����������ûɾ��
			j++;// ��������+1
		}
	}
}
int main() {
	SqList L;
	InitList(L);
	cout << "˳����Ԫ��Ϊ:" << endl;
	PrintList(L);
	cout << "Լɪ�������Ԫ��Ϊ:" << endl;
	YSFH(L, 3);// ����3
}
