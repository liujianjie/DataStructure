#include <iostream>
#include "Application.h"
#include "Blob.h"
#include "Compare.h"

using namespace std;

extern template class Blob<string>;
extern template int compare(const int&, const int&);

Blob<string> sa1({"1","2","3","4"}), sa2;// 声明了在其它文件实例化，但是可以使用吧

void Application::controll()
{
	cout << "sa1.size():" << sa1.size() << endl;
	compare(5, 5);// 别的文件定义了，直接适用 
}

// 本文件里实例化
Blob<int> a1 = { 0,1,2,3,4,5,6,7,8 };
Blob<int> a2(a1);
int i = compare(a1[0], a2[0]);