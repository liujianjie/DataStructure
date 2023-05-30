#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

void prints(map<string,int> maps) 
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
	//for (auto beg = maps.begin(); beg != maps.end(); ++beg)
	//{
	//	cout << (*beg).first << " occurs " << (*beg).second << "times"<<endl;
	//}
}
/*
有序的是按照字典序
*/
int main() 
{
	int a;
	//map<string, int> word_count;
	//string cinstr;
	//while (cin>>cinstr&& cinstr != "-1") {
	//	++word_count[cinstr];
	//}
	//prints(word_count);
	map<string, int> word_count2;
	set<string> word_not{"the","then","but","or","an","a"};
	string cinstr;
	while (cin >> cinstr&& cinstr != "-1") {
		if (word_not.find(cinstr) == word_not.end()) {
			++word_count2[cinstr];
		}
	}
	prints(word_count2);

	cin >> a;
	return 0;
}