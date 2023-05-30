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
#include "StrBlob.h"

using namespace std;

/*
���»���˼·�ɣ������ǣ��� 20190607��Ϊû�м����� �˷������ʱ��
file����ÿһ��������vector��
map�����ݳ�Աһ���ǹؼ��֣�һ��������ؼ��ֳ��ֵ��к�

���캯��
���ļ���ȡ���ݵ�file�У����𲽷ֽ�ÿһ�����ʱ�����map�У�������ظ����־���ӵ�set���棬�����file��map��ʼ��

query�����Ƕ�ָ����string���ң���map��find�õ�set�кż���

print��ʱ�򽫻�ȡfile�Ŀ�ʼλ��Ȼ������кŵõ�����string
*/

class QueryResult;
class TexTQuery {
public:
	using line_no = vector<string>::size_type;
	TexTQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	// ÿһ�е��ı���
	shared_ptr<vector<string>> file;
	//StrBlob strblo;
	map<string, shared_ptr<set<line_no>>> wm;
};


#endif // !TEXTQUERY_H_