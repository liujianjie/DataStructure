#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void fcn(const int i) {}
void fcn(int i);// �������������ǲ���void fcn(int i){} ��Ϊ�����Ѿ������ˣ������������塣

// const string s1�����Խ���const�����string���Լ�����const�����string���������Ϊ string&s1 ��ֻ�ܽ��ղ���const��string
void find_char(const string &s1, char c, string::size_type &ctr) {

}
void reset( int &i) 
{
	i = 9;
}
void reset(int *i)
{
	*i = 9;
}

void print(const int* a) {
	//cout << *a << "print(const int *a)" << endl;
}
/*
���һ��ͬ������˼�������ٶ��壬�������� ����
void print(const int[]) {}
void print(const int[10]) {}*/

// ���
// 1.c����ַ�������
void print(const char *cp) {
	if (cp)
		while (*cp)
			cout << *cp++;
}
// 2����׼��淶�����鱾������׼���淶 ֻ������ ���˺�������
void print(const int *beg, const int *end) {
	// ���beg��end֮�� ����end������Ԫ��
	while (beg != end) {
		cout << *beg << "no zero??" << endl;// �����ǰԪ�ز���ָ����ǰ�ƶ�һ��λ��
		beg++;
	}

}
// 3.��ʾ�����С���β�
void print(const int ia[], size_t size) 
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << "size_t size" << endl;
	}
}

void prints(int (&arr)[10]) {

}

// �ȼ۶��壬��������һ����ά���飬ʵ�����β���ָ����10�������������ָ��
void printtwo(int martix[][3], int rowsize) 
{
	for (auto p = martix; p != martix + 3; ++p)
	{
		for (auto q = *p; q != *p+3; ++q) 
		{
			cout << *q << " printwo";
		}
	}
}
// matrixָ���ά�������Ԫ�أ��������Ԫ����3���������ɵ�����
void printtwos(int (*martix)[3], int rowsize)
{
	// ���ֻ����� 1 2 3
	/*for (auto q = *martix; q != *martix + 3; ++q)
	{
		cout << *q << " printwo";
	}*/
	// �����ȫ���������Ϊ���martix��ָ���ά�������Ԫ��ָ�룬Ȼ���p��p����ָ���ά����ָ�������Ԫ����
	// �ٽ�pָ��һ��Ԫ�ص���ָ�����q��q��ָ��p����ָ�룬*p��ָ��ͷָ��λ�ã�*q��ָ��ֵ����*q��ʵ�� **q
	for (auto p = martix; p != martix + 3; ++p)
	{
		cout << "*p = " << *p << endl;
		for (auto q = *p; q != *p + 3; ++q)
		{
			cout << *q << " printwo";
		}
	}
}
int main(int argc, char *argv[])
{
	int gethcar;
	int i = 0;
	const int ci = i;
	string::size_type ctr = 0;
	reset(&i);
	//reset(&ci);// ����ָ��const int ��ָ���ʼ��int*
	reset(i);
	//reset(ci);	// ���ܰ���ͨ���ð󶨵�const����ci��
	//reset(42);	// ���ܰ���ͨ���ð󶨵�����ֵ��
	//reset(ctr);// ���Ͳ�ƥ��ctr���޷�������

	find_char("Hello_world", '0', ctr);

	// 6.2.4�����β�
	int sixtwoi = 0, j[] = { 0,1 ,2,3,4,5,6 };
	print(&sixtwoi);
	print(j);// jת����int*��ָ�� j[0],����Ĵ�С�Ժ����ĵ���û��Ӱ��

	// warning ��ʹ����������Ĵ���һ������������Ϊ�βεĺ���Ҳ����ȷ��ʹ������ʱ����Խ��

	// 3�ּ��� ��֤ʹ�����鲻��Խ��
	// 1.ʹ�ñ��ָ�����鳤��,����Ҫ���鱾���н������ ����c����ַ������ַ����������һ���ַ��������һ�����ַ�
	const char cs1[] = "sdfs";
	const char *cs2[] = {"sdfs","dfdsf"
};
	print(cs1);

	cout << endl;

	// 2.ʹ�ñ�׼��淶 ������Ԫ�� ��β��Ԫ�ص�ָ��sixtwoi
	print(begin(j), end(j));
	
	// 3.��ʽ����һ����ʾ  �����С  ���βΣ���c����͹�ȥ��c++�����г���ʹ�����ַ���
	// ��ס �������С���β�
	print(j, end(j) - begin(j));

	// ���������βκ�const

	// �������������β�
	//void print(int(&arr)[10])// ������Ҫָ����С��int &arr[10]�ǲ���ȷ�ģ�Ϊ��arr����Ϊ�����õ�����
	// int (&arr)[10]��ȷ��arr�Ǿ���10���������������������
	int threek[10] = {0,1,2,3,4,5,6,7,8,9};
	//prints(&sixtwoi);// ����ʵ�β��Ǻ���10������������
	//prints(j);//����ʵ�β��Ǻ���10������������
	prints(threek);
	// �������ñ���淶��С�ſɣ��ں���p578�ὲ����δ��������С

	// �ġ����ݶ�ά����
	int fourarray[3][3] = { {1,2,3 },{ 4,5,6 },{7,8,9 }};
	printtwos(fourarray,3);

	// 
	cin >> gethcar;
	return 0;
}