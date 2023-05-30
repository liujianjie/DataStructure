#include "StrBlob.h"
#include "StrBloPtr.h"

StrBloPtr StrBlob::begin() 
{
	return StrBloPtr(*this);
}
StrBloPtr StrBlob::end()
{
	auto ret = StrBloPtr(*this, data->size());
	return ret;
}
StrBlob::StrBlob():
	data(make_shared<vector<string>>())
{
}
StrBlob::~StrBlob()
{
}
StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)){// ÓÃÖÇÄÜÖ¸Õë


}

void StrBlob::pop_back()
{
	check(0, "pop");
	data->pop_back();
}
string& StrBlob::front()
{
	check(0, "front");
	return data->front();
}
string& StrBlob::back()
{
	check(0, "back");
	return data->back();
}

string& StrBlob::front() const
{
	check(0, "front");
	return data->front();
}
string& StrBlob::back() const
{
	check(0, "back");
	return data->back();
}
void StrBlob::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}