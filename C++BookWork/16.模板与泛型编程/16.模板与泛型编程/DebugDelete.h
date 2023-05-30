#pragma once
#include <iostream>

using namespace std;
class DebugDelete {
public:
	DebugDelete(ostream &s = cerr):os(s){ }
	
	template <typename T>
	void operator()(T *p) const {
		os << "deleteing unique_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};
