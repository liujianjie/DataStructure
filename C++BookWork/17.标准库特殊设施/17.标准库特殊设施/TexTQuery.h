#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <tuple>
using namespace std;

/*
记下基本思路吧，怕忘记：唉 20190607因为没有记下来 浪费了许多时间
file保存每一行数据再vector中
map的数据成员一个是关键字，一个是这个关键字出现的行号

构造函数
对文件读取内容到file中，会逐步分解每一个单词保存在map中，如果有重复出现就添加到set后面，即完成file与map初始化

query：就是对指定的string查找，在map中find得到set行号集合

print的时候将获取file的开始位置然后加上行号得到整行string
*/

class TexTQuery {
public:
	using line_no = vector<string>::size_type;
	using TUP = tuple<const string, shared_ptr<set<line_no>>, shared_ptr <vector<string>>>;
	TexTQuery(ifstream&);
	TUP query(const string&) const;
private:
	// 每一行的文本？
	shared_ptr<vector<string>> file;
	//StrBlob strblo;
	map<string, shared_ptr<set<line_no>>> wm;
	//TUP tup;
};


#endif // !TEXTQUERY_H_