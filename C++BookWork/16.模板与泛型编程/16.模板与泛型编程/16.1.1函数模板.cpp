#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include "Sales_data.h"

using namespace std;

template <typename T>
int compare(const T& v1, const T &v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

// T������������
template <class T>
T foo(T* p)
{
	T temp = *p;
	return tmp;
}

//template <typename T,  U> T calc(const T& a, const U&);
template <typename T, class U> T calc(const T& v1, const U &v2)// true
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}
//��ģ�����Ͳ���
template <unsigned N,unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
	return strcmp(p1, p2);
}

template <typename T>inline constexpr T min(const T&, const T& a)
{
	return a;
}
// template <typename T> T min(const T&, const T& a)
//{
//	return a;
//}

// ��д�����޹صĴ���
template <typename T> int compare4(const T& v1, const T &v2)
{
	if (less<T>()(v1, v2))return -1;
	if (less<T>()(v2, v1))return -1;
	return 0;
}

template <typename T> int compare5(const T& v1, const T &v2)
{
	cout << "compare5:" << v1 + v2 << endl;
	return 0;
}
// T<U>::iterator
template <typename T,typename U> 
U finds(const T& con, const U &items)
{
	cout << "finds:" << endl;
	auto end = con.end();
	for (auto beg = con.begin(); beg != end; ++beg) {
		if (*beg == items) {
			return *beg;
		}
	}
	return *(--end);
}
template <typename T, typename U>
bool finds(const T& it1,const T& it2, const U &items)
{
	cout << "finds2:" << endl;
	auto it3 = it1;// const�����޸�ֻ����һ����ʱ����
	for (it3; it3 != it2; ++it3) {
		if (*it3 == items) {
			return true;
		}
	}
	return false;
}

//void print(int(&arr)[10]) {}

template <typename T>
void print(const T &arr)
{
	for (auto it : arr) {
		cout << it << endl;
	}
}

// ������ģ�����,�Զ��ƶ�
/*
T��int,N:10��const int(&arr)[10],����ֵ�� int*  ����ָ��ԭ�����һ��Ԫ�أ�ָ���һ��ָ�����
������arr��const�ģ��޷���TΪ��ͨ�ģ���һ�����⡣
*/
template <typename T, unsigned N>
T* begins(const T (&arr)[N])
{
	auto arr1 = const_cast<int*>(arr);
	return arr1;
}
template <typename T, unsigned N>
T* ends(const T (&arr)[N])
{
	auto arr1 = const_cast<int*>(arr + N);
	return arr1;
}

// �Լ�д�ģ���˼�Ǻ�����⣬Tת��Ϊ int [10],����Ϊint (&a)[10],����T* Ϊ int (*a)[10],arr��int [10],����Ҫ����&������ת��������ֵ
// ������Ҫ**����Ϊ����ת��Ϊ��Ԫ��ָ��
template <typename T>
T* beginsself(T &arr)
{
	return &arr;
}

// 
template <typename T,unsigned N>
constexpr
unsigned getshusize(const T(&arr)[N])
{
	return N;
}

int main()
{
	int a;
	int ia = 4, ib = 6;
	double da = 12.0, db = 1.0;
	cout << compare(ia,ib) << endl;
	cout << compare(da, db) << endl;

	vector<int> vec1{ 1,2,3 }, vec2{ 4,5,6 };
	cout << compare(vec1, vec2) << endl;

	cout << compare("hi", "mom") << endl;

	compare5(4,12);
	Sales_data sd1, sd2;
	//compare4(sd1, sd2);// ʵ����ʱ���

	vector<int> ve1{ 1,2,4,3 };
	auto val1 = find(ve1.begin(), ve1.end(), 3);
	vector<int>::iterator val2 = find(ve1.begin(), ve1.end(), 3);
	cout << *val1 << endl;
	cout << *val2 << endl;
	//cout << find(ve1.begin(), ve1.end(), 3) << endl;

	vector<int> ve2{ 1,2,4,3 };
	int fivl = 3;
    auto uvl1 = finds(ve2, fivl);
	cout << uvl1 << endl;


	list<string> li{ "aaa","bbb","ccc","ddd"};
	string fiv2 = "ccc";
	auto uvl2 = finds(li, fiv2);
	cout << uvl2 << endl;

	cout << (finds(li.begin(),li.end(),fiv2)) << endl;

	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	print(arr1);

	cout << *begin(arr1) << endl;
	cout << *end(arr1)<<"*end(arr1)" << endl;

	// ��Ŀ16.7��ǰ�����գ�����������ָ��֮���ת��
	// 1.��������ã�����ָ����С��Ҳ���Բ�ָ����rear�Զ�ת��ָ��
	// 2.�����ָ�� ����ָ��һ����������ã�Ҳ����ָ�����鱾�����Ǵ�С����Ե��ϣ�
	 int (&rear)[10] = arr1;

	const int(*re2)[10] = &rear;

	const int(*re3)[10] = &arr1;

    // ָ����Ը�һ��ָ�롣��
	int *testp1 = rear;
	int *testp2 = arr1;
	cout << testp1 << " " << testp2 << endl;
	cout << *testp1 << " " << *testp2 << endl;

	cout << rear + 2 << endl;

	cout << "----" << endl;
	// �Լ���
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//cout << **begins(arr2) << endl;
	// ��ȷ��
	cout << *(begins(arr2)) << endl;
	cout << *(ends(arr2)) << endl;

	// 
	auto si = getshusize(arr2);
	cout << si << endl;

	// ��ϰ
	/*
	16.1 ok
	16.2:ok
	16.3:û��<�������������sd1���͵���������������û��
	16.4:���Ǻ������� ���ϵ�OK
	16.5:ok
	16.6�����ϵ�const���⣬�ҵıȽ�����⣬���ǿ���
	16.7��ok��ͬ�ϣ�������Ҫһ����ģ�����Ͳ������ƶ�ֵ
	16.8:��Ϊ<��ģ�壿�����������end�����С��䣬���Ի�ȡһ��
	����˵����Ϊ�ܶ����Ͷ���!= ����������ǿ���û��<�����
	*/

	cin >> a;
	return 0;
}