#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
/*
1.一次为很多对象分配内存功能
2.两种分配一个对象数组的方法，new和allocator
3.new将分配和初始化绑定在一起，没用到的内存，但是也分配了内存 就浪费了
allocator可将分配和初始化分离，这样更灵活
4.最好使用vector标准库容器，而不是动态分配数组
5.分配动态数组的类必须定义自己版本的操作，在拷贝 复制以及销毁对象时管理所关联的内存
*/
int main()
{
	int a;
	


	cin >> a;
	return 0;
}
