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
#include "Sales_data.h"
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

template<typename T,typename... Args>
ostream &print(ostream &os, const T &t,const Args&... rest)
{
	os << t << ",";
	return print(os,rest...);
}



int main()
{
	int a;

	int i = 0; double d = 3.14; string s = "how now borwn cow";
	short b = 12;
	float ft = 13.43;
	print(cout,i,s,d,b,ft);

	Sales_data sd1;
	//print(cout, sd1, s, d, b, ft);
	/*
	��ϰ��
	16.53:ok
	16.54:ʧ��
	16.55�����������޵ݹ鲢����ģ����ǲ�û�У���֪��Ϊʲô
	*/
	cin >> a;
	return 0;
}
template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;// ��ӡ���һ�����ҽ���
}

