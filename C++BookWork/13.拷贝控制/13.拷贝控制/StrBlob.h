#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBloPtr;
class StrBlob
{
	friend class StrBloPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	~StrBlob();

	size_type size()const { return data->size(); };
	bool empty() const { return data->empty(); };
	void push_back(const string& t) const { data->push_back(t); };
	void pop_back() ;

	string& front();
	string& back();

	string& front() const;
	string& back() const;

	shared_ptr < vector<string>> data;
	void check(size_type i, const string &msg)const;

	StrBloPtr begin();
	StrBloPtr end();

	// Á·Ï°13.55
	void push_back(const string& t,int i = 2) && { data->push_back(t); };
private:
	
};

#endif // !STRBLOB_H