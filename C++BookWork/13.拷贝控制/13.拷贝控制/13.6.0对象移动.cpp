#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <fstream>
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
#include "Folder.h"
#include "Message.h"
#include "TexTQuery.h"
#include "QueryResult.h"
using namespace std;
/*
开篇引出：
1.移动而非拷贝对象可以大幅提升性能
2.容器保存的类可以是拷贝或者移动的其一
3.标准库容器、string或shared_ptr类既可以移动也可以拷贝，Io类unique_ptr类不能被共享的资源，不能拷贝但是能移动
*/

int main() {

	int aa;
	
	std::cin >> aa;
	return 0;
}