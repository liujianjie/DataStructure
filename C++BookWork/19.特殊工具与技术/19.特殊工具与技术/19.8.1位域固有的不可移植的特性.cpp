#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

typedef unsigned int Bit;

class File {
	Bit mode : 2;
	Bit modified : 1;
	Bit prot_owner : 3;
	Bit prot_group : 3;
	Bit prot_world : 3;
public:
	enum modes { READ = 01, WRITE = 02, EXECUTE = 3 };
	File &open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
};
void File::write()
{
	modified = 1;
}
File &File::open(File::modes m)
{
	mode |= READ;
	if (m & WRITE)
	{
		// 以读写方式打开文件
	}
	return *this;
}
inline bool File::isRead()const {
	return mode & READ;
}
inline void File::setWrite() {
	mode |= WRITE;
}
int main()
{
	int a;

	/*
	练习：
	*/
	cin >> a;
	return 0;
}
