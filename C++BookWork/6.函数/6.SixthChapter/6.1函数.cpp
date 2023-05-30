#include <iostream>
#include <string.h>

using namespace std;


size_t countstaticv()
{
	static int counts= 0 ;
	return ++counts;
}

void reset(int *ip){
	*ip = 10;
	ip = 0;
}
void reset2(int &j)
{
	j = 8;
}

string::size_type find_char(const string &s1,char c,string::size_type &occurindex)
{
	string::size_type size = 0;
	 occurindex = s1.size();
	for(decltype(s1.size()) i = 0; i < s1.length(); ++i){
		if(s1[i] == c){
			if(occurindex == s1.size())
				occurindex = i;
			size++;
		}
	}
	return size;

}
int main()
{
	int getchar;
	for(size_t i= 0; i != 10; i++){
		cout<< countstaticv()<<"\t";
	}
	// 指针形参
	int val = 42;
	reset(&val);
	cout << val <<endl;

	// 引用形参
	int valj = 54;
	reset2(valj);
	cout<< valj<<endl;

	// 引用形参的用法 多个值返回
	string s = "asdfasdfsdgcxzvxcsdf";
	string::size_type lastindex  = 0;
	string::size_type sizet = find_char(s,'A',lastindex);
	cout<<sizet<<" "<<lastindex<<endl;
	cin>>getchar;
	return 0;
}