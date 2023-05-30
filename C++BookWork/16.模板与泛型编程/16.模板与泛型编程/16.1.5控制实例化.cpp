#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include "Sales_data.h"
//#include "BlobAndBloPtr.h"
//#include "TestMod.h"
#include "Blob.h"
#include "BloPtr.h"
#include "Foo.h"
//#include "QueryResult.h"
//#include "TexTQuery.h"
//#include "DebugDelete.h"
#include "Application.h"
#include "TemplateBuild.h"
#include "Compare.h"
#include "NoDefault.h"

using namespace std;

/*

*/
template class vector<NoDefault>;
int main()
{
	int a;

	Application a1;
	TemplateBuild t1;
	a1.controll();
	t1.controll2();
	
	//vector<NoDefault> ve1;
	/*
	练习:
	16.25:
	在别处有这个类型的定义
	在本文件进行定义

	16.26：
	不可以，因为实例化定义,Nodefault也会实例化，调用构造函数

	16.27：
	a.不会,没有调用
	b.不会，引用不会，没有数值存在？
	c.会
	d.不会，指针不会
	e.会，函数实例因为接受到了值 *s是值
	f.会
	*/

	cin >> a;
	return 0;
}


