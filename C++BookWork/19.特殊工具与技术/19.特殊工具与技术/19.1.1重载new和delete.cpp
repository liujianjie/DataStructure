#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//void *operator new(size_t size)
//{
//	cout << "our indentity new" << endl;
//	if (void *mem = malloc(size))
//		return mem;
//	else
//		throw bad_alloc();// �ڴ治�� ��������
//}
//void operator delete(void *mem) noexcept
//{
//	cout << "our indentity delete"  << endl;
//	free(mem);
//}

int main()
{
	int a;
	int *i1 = new int(10);
	cout << i1 << endl;
	cout << *i1 << endl;

	// ʹ��ȫ�ֵģ��Ҳ������Ǳ�׼���
	int *i2 = ::new int(1);
	cout << *i2 << endl;

	delete i2;

	void *mem = malloc(1);// �����ڴ棬���ص�ַ
	int *i3 = new (mem) int(2);// ָ���ַ �����ʼֵ
	cout << *i3 << endl;// Ϊ2

	void *mem2 = malloc(2);
	int *i4 = new(mem2) int;
	cout << (*i4) << endl;

	string *sp = new string("a vale");
	sp->~string();

	/*
	��ϰ��
	19.1
	ok
	19.2:
	�����ʵ�ɣ�alloc.allocate(e - b);�����¿ռ� ��ʼ��λ�úͿ�����β���λ����ô�죿������
	*/
	cin >> a;
	return 0;
}
