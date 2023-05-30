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

// T当做返回类型
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
//非模板类型参数
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

// 编写类型无关的代码
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
	auto it3 = it1;// const不能修改只能有一个临时变量
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

// 非类型模板参数,自动推断
/*
T：int,N:10，const int(&arr)[10],返回值是 int*  就是指向原数组第一个元素，指针给一个指针可以
问题是arr是const的，无法给T为普通的，是一个问题。
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

// 自己写的，意思是很难理解，T转换为 int [10],参数为int (&a)[10],返回T* 为 int (*a)[10],arr是int [10],所以要加上&，才能转换给返回值
// 但是需要**，因为数组转换为首元素指针
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
	//compare4(sd1, sd2);// 实例化时检错

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

	// 题目16.7的前提掌握，数组引用与指针之间的转换
	// 1.数组的引用，可以指定大小，也可以不指定，rear自动转换指针
	// 2.数组的指针 可以指向一个数组的引用，也可以指向数组本身，但是大小必须对得上，
	 int (&rear)[10] = arr1;

	const int(*re2)[10] = &rear;

	const int(*re3)[10] = &arr1;

    // 指针可以给一个指针。。
	int *testp1 = rear;
	int *testp2 = arr1;
	cout << testp1 << " " << testp2 << endl;
	cout << *testp1 << " " << *testp2 << endl;

	cout << rear + 2 << endl;

	cout << "----" << endl;
	// 自己的
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//cout << **begins(arr2) << endl;
	// 正确的
	cout << *(begins(arr2)) << endl;
	cout << *(ends(arr2)) << endl;

	// 
	auto si = getshusize(arr2);
	cout << si << endl;

	// 练习
	/*
	16.1 ok
	16.2:ok
	16.3:没有<运算符，就是找sd1类型的运算符，左操作，没有
	16.4:不是很完美的 网上的OK
	16.5:ok
	16.6：网上的const问题，我的比较难理解，但是可以
	16.7：ok，同上，就是需要一个非模板类型参数来推断值
	16.8:因为<是模板？运算符？还是end数组大小会变，所以获取一次
	网上说：因为很多类型都有!= 运算符，但是可能没有<运算符
	*/

	cin >> a;
	return 0;
}