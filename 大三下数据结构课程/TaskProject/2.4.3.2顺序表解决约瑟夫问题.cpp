// 2.顺序表实现约瑟夫环问题
// 时间复杂度O(n * m), 空间复杂度O(n)
#include <iostream>
using namespace std;
#define MaxSize 100 // 定义最大长度 
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
// i是位序，e是元素 
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) { // 是否合法 
		return false;
	}
	for (int j = L.length; j >= i; j--) {// 先向后移动
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;// 再i-1位置放置e
	L.length++; // 长度+1 
	return true;
}
void InitList(SqList& L) {
	L.length = 0;
	// 输入元素
	int e = 0;
	cin >> e;
	for (int i = 1; e != 0; i++) {
		ListInsert(L, i, e);
		cin >> e;
	}
}
// 辅助，遍历
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i];
	}
	cout << endl;
}
// 约瑟夫环
void YSFH(SqList& L, int M) {// M是数到几
	// i是当前数组的下标，j是共几个人出列了,ct是累计M的变量，初始化为0
	int i = -1, j = 0, ct = 0; 
	while (j < L.length) { // 人数没出完
		i++;// i下标前进
		if (i >= L.length) {
			i = 0;// 到达末尾回到首部
		}
		if (L.data[i] < 0) {// 代表出列过了，跳过
			continue;
		}
		ct++;// 这个i位置的人报数
		if (ct >= M) {
			cout << L.data[i] << " ";// 出列
			ct = 0;// 初始化报数值
			L.data[i] = -1;// 置为-1，代表出列过了，逻辑上删除，物理上没删除
			j++;// 出列人数+1
		}
	}
}
int main() {
	SqList L;
	InitList(L);
	cout << "顺序表的元素为:" << endl;
	PrintList(L);
	cout << "约瑟夫输出的元素为:" << endl;
	YSFH(L, 3);// 数到3
}
