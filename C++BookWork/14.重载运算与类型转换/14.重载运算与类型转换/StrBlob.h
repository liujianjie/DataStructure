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
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	~StrBlob();

	size_type size()const { return data->size(); };
	bool empty() const { return data->empty(); };
	void push_back(const string& t) const { data->push_back(t); };
	void pop_back();

	string& front();
	string& back();

	string& front() const;
	string& back() const;

	shared_ptr < vector<string>> data;
	void check(size_type i, const string &msg)const;

	StrBloPtr begin();
	StrBloPtr end();

	// ��ϰ13.55
	void push_back(const string& t,int i = 2) && { data->push_back(t); };

	// 14.5
	string& operator[](size_t n) 
	{
		return (*data)[n];
	}
	const string& operator[](size_t n)const
	{
		return (*data)[n];
	}
private:
	
};
inline
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	if (lhs.size() == rhs.size()) {
		for (auto p1 = lhs.data->begin(), p2 = (*rhs.data).begin(); p1 != lhs.data->end(), p2 != (*rhs.data).end(); p1++, p2++)
		{
			if (*p1 != *p2)
				return false;
		}
	}
	else {
		return false;
	}
	return true;
}
inline
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

inline
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	if (lhs.size() < rhs.size()) {
		for (auto p1 = lhs.data->begin(), p2 = (*rhs.data).begin(); p1 != lhs.data->end(); p1++, p2++)
		{
			if ((*p1 > *p2) == 1) {
				return false;
			}
		}
		// ��������ѭ�� ����û���ҳ� ��һ�����ڵڶ����� ����С����
		return true;
	}
	if (lhs.size() >= rhs.size()) {
		for (auto p1 = lhs.data->begin(), p2 = (*rhs.data).begin(); p2 != (*rhs.data).end(); p1++, p2++)
		{
			if ((*p1 < *p2) == 1) {
				return true;
			}
		}
		// ����ÿһ�Ժ󣬶�û�ҵ���һ��С�ڵڶ����ģ����Ǵ����
		return false;
	}
}
#endif // !STRBLOB_H