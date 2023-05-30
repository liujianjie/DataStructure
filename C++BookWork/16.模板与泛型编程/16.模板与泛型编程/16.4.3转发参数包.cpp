#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "StrVec.h"
#include "Vec.h"
#include "NoDefault.h"
using namespace std;


template <typename T = int>
void test1()
{
}

template <typename T, typename... Args>
shared_ptr<T> my_make_sharder(Args...args)
{
	 return make_shared<T>(std::forward<Args>(args)...);

}

int main()
{
	int a;
	test1();
	StrVec sv1;
	// ��ֻ�ܴ�һ����emplace_back�ǹ���һ�����󣬲���inli�б�ͨ��ת���������������
	// ��Ҫ����construct�Ĺ��캯��
	sv1.emplace_back("asdf");
	sv1.emplace_back(10,'c');// construct��(dest��int,char)������캯��
	//sv1.emplace_back(1);// �Լ���allocֻ��ȷ��һ�����͡�
	for (auto p1 = sv1.begin(); p1 != sv1.end(); p1++) {
		cout << *p1 << endl;
	}
	shared_ptr<string> sp1 = make_shared<string>(10,'c');
	cout << *sp1 << endl;

	shared_ptr<string> sp2 = my_make_sharder<string>(10,'a');
	cout << *sp2 << endl;

	cout << "-------------" << endl;
	Vec<int> vec1;
	vec1.emplace_back(3);
	vec1.emplace_back(5);
	vec1.emplace_back(12);
	vec1.emplace_back(6);
	vec1.printVec();
	cout << vec1 << endl;

	Vec<string> vec2;
	vec2.emplace_back(4,'c');
	vec2.emplace_back("value");

	cout << vec2 << endl;
	/*
	��ϰ��
	16.58:���ţ���һ�ⶼ��ûд
	16.59:����һ����s��ת��
	16.60:���ܿɱ����ģ�壬ת���������ʼ��һ���ڴ����ڴ�ռ䣬����һ��shared_ptr;
	16.61:���ţ�Ӧ��Ҫ�õ�ת������������

	��ǰ����Ҫ��
	shared_ptr��ʵ����Ҫ��ʾģ��ʵ�Σ��Լ��������Լ��������õĶ��󣬵ȡ�
	*/
	cin >> a;
	return 0;
}


