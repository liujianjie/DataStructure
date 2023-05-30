#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Sales_data.h"
using namespace std;

using namespace std::placeholders;

int count_vec(vector<string> &ve) {
	int cts = count_if(ve.begin(),ve.end(),bind(&string::empty, _1));
	return cts;
}
bool gras(Sales_data& s) {
	return s.revenue > 3;
}
Sales_data& count_data(vector<Sales_data> &ve) {
	auto it = find_if(ve.begin(),ve.end(),bind(&gras ,_1));
	return *it;
}
Sales_data& count_data2(vector<Sales_data> &ve) {
	auto f = mem_fn(&Sales_data::avg_price);// 注意avg
	return *(find_if(ve.begin(), ve.end(), [&](const Sales_data &s) {return f(s) > 3; }));
}
int main()
{
	int a;
	
	auto fp = &string::empty;
	vector<string> ve1{ "12","ab","cd","","sdf" };
	//find_if(ve1.begin(),ve1.end(),fp);

	function<bool(const string&)> fcn = &string::empty;
	auto its = find_if(ve1.begin(), ve1.end(), fcn);
	cout << *(its+1) << endl;

	auto it2 = find_if(ve1.begin(), ve1.end(), mem_fn(&string::empty));
	cout << *(it2 + 1) << endl;

	auto f = mem_fn(&string::empty);
	cout << f(*ve1.begin()) << endl;// f使用.*调用empty
	f(&ve1[0]);//f使用->*调用empty
	
	//
	auto it4 = find_if(ve1.begin(), ve1.end(),
		bind(&string::empty, _1));
	cout << *(it4 + 1) << endl;

	auto ff = bind(&string::empty, _1);
	ff(*ve1.begin());
	ff(&ve1[0]);

	cout << "-----练习-------" << endl;
	vector<string> ve2{ "","2","","4","5","6","","" };
	cout << count_vec(ve2) << endl;

	Sales_data sd1("123",1,2);
	Sales_data sd2("sd2", 1, 1.5);
	Sales_data sd3("sd3", 1, 1.8);
	Sales_data sd4("sd4", 1, 1.7);
	Sales_data sd5("sd5", 1, 4);
	vector<Sales_data> ve3;
	ve3.push_back(sd1);
	ve3.push_back(sd2);
	ve3.push_back(sd3);
	ve3.push_back(sd4);
	ve3.push_back(sd5);
	Sales_data sd6 = count_data(ve3);
	cout << sd6.isbn() << endl;

	Sales_data sd7 = count_data2(ve3);
	cout << sd7.isbn() << endl;
	/*
	练习：
	19.18:ok
	19.19:ok
	*/
	cin >> a;
	return 0;
}
