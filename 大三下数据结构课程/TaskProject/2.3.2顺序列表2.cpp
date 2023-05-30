#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
enum Status {
	ERROR,
	ok
};
typedef struct {
	ElemType* elem;
	int length;
}SqList;
//InitList
Status InitList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) return ERROR;
	L.length = 0;
	return ok;
}
//getElem
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i = -1];
	return ok;
}
//search
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}
//insert
Status ListInsert(SqList& L, int i, ElemType e) {
	if ((i < 1) || (i > L.length + 1)) return ERROR;
	if (L.length == MAXSIZE)return ERROR;
	for (int j = L.length - 1; j >= i - 1; j++)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return ok;
}
//delete
Status ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length)) return ERROR;
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return ok;
}
void DisplayList(SqList& L) {
	if (L.elem) {
		for (int i = 0; i < L.length; i++)
			cout << L.elem[i] << " ";
	}
	else cout << "List is empty！" << endl;
}
int main() {
	SqList L;
	int a = InitList(L);
	if (a) cout << "链表创建成功！" << endl;
	DisplayList(L);

	cout << "插入数据：";
	ListInsert(L, 1, 3);
	ListInsert(L, 2, 5);
	ListInsert(L, 3, 7);
	ListInsert(L, 4, 9);
	DisplayList(L);
	cout << endl;

	cout << "删除数据";
	ListDelete(L, 3);
	ListDelete(L, 4);
	DisplayList(L);
	cout << endl;

	int i = LocateElem(L, 4);
	cout << 4 << "在列表的第" << i << "个位置" << endl;

	cout << "遍历列表：";
	DisplayList(L);
	return 0;

}
