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
����ͨ����Ա����Ϊ=default����ʽҪ����������ɺϳɵİ汾

ֻ�ܶԾ��кϳɰ汾�ĳ�Ա����ʹ��=default Ĭ�Ϻ������߿������Ƴ�Ա
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