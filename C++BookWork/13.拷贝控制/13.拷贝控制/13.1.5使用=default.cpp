#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"

using namespace std;
/*
可以通过成员定义为=default来显式要求编译器生成合成的版本

只能对具有合成版本的成员函数使用=default 默认函数或者拷贝控制成员
*/
class Test {
public:
	Test() = default;
	Test(const Test&) = default;
	Test& operator=(const Test&) = default;
	~Test() = default;

};
int main() {

	int aa;

	cin >> aa;
	return 0;
}