#include <iostream>
#include "TemplateBuild.h"
#include "Blob.h"
#include "Compare.h"

template int compare(const int&, const int&);
template class Blob<string>;// 实例化类模板的所有成员

Blob<string> sa3({ "1","2","3","4" });
void TemplateBuild::controll2()
{
	cout << "sa3.size():" << sa3.size() << endl;
	compare(5, 5);// 上面已经定义了，直接适用 
}