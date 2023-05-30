
#include <string>  
#include <iostream>
using namespace std;
struct xyc {
	int x = 0;
	int y = 0;
	char c = ' ';
};
template<unsigned N, unsigned M>
class Screen
{
	unsigned cursor = 0;
	unsigned  width = N, height = M;//C++11新特性，可以类内初始化
	std::string contents;
public:
	Screen() = default;
	Screen(char c) :contents(N*M, c) {}
	char get()const { return contents[cursor]; }
	Screen set(xyc c) {
		cursor = --c.x*width + --c.y;
		contents[cursor] = c.c;
		return *this;
	}
	template<unsigned NN, unsigned MM>
	friend std::ostream &operator<<(std::ostream &os, const Screen<NN, MM> &s);//输出运算符  
	template<unsigned NN, unsigned MM>
	friend std::istream &operator >> (std::istream &is, Screen<NN, MM> &s);//输入运算符
};

template<unsigned NN, unsigned MM>
std::ostream &operator<<(std::ostream &os, const Screen<NN, MM> &s)
{
	for (unsigned i = 0; i < s.width; ++i)
	{
		for (unsigned j = 0; j < s.height; ++j)
			putchar(s.contents[i*s.width + j]);
		putchar('\n');
	}
	return os;
}
istream& operator>>(istream& in, xyc& xy)
{
	in >> xy.x >> xy.y >> xy.c;
	return in;
}

template<unsigned NN, unsigned MM>
std::istream &operator >> (std::istream &is, Screen<NN, MM> &s)
{
	xyc c;
	is >> c;
	s.set(c);
	return is;
}

