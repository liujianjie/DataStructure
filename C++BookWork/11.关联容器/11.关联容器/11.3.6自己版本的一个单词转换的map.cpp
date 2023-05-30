#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>
#include <sstream>
#include <iterator>
#include <utility>


using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
/*

*/
void cinneedtrans(vector<string> &ve1)
{
	string line;
	while (getline(cin,line) && line != "-1") {
		ve1.push_back(line);
	}
}
void buildMap(map<string,string> &tranma,ifstream& if1)
{
	string line;
	string one,two;
	while (getline(if1, line)) {
		istringstream is1(line);
		is1 >> one;
		is1 >> two;
		tranma[one] = two;
	}
}
void outwords(vector<string> ve1, map<string, string> &tranma)
{
	string step;
	bool firstwords;
	for (auto beg : ve1) {
		firstwords = true;
		ostringstream os1;
		istringstream is1(beg);
		while (is1 >> step) {
			if (tranma.find(step) != tranma.end()) {
				os1 << tranma[step] << " ";
			}
			else {
				os1 << step <<" ";
			}
		}
		cout << os1.str() << endl;
	}
}
int main()
{
	int a;
	vector<string> ve1;
	cinneedtrans(ve1);

	map<string, string> tranma;
	ifstream if1("11.3.6一个单词转换的map.txt");
	buildMap(tranma, if1);

	outwords(ve1, tranma);
	std::cin >> a;
	return 0;
}