#ifndef SCREENS_H
#define SCREENS_H

#include <iostream>
#include <string>
using namespace std;

// 先前置声明Screens模板
//template <unsigned H, unsigned W> class Screens;
//
//template <unsigned H, unsigned W>
//istream& operator >> (istream& is, Screens<H, W> &c);
//
//template <unsigned H, unsigned W>
//ostream& operator << (ostream& os, const Screens<H, W> &c);

template <unsigned H, unsigned W>
class Screens
{
public:
	//friend istream &operator >>
	//	(istream& is, Screens<H, W> &c);
	//friend ostream &operator<< 
	//	(ostream &os, const Screens<H, W> &c);
public:
	typedef std::string::size_type pos;

	Screens() = default;
	Screens(char c) :contents(W * H, c) {}

	char get() const {
		return contents[cursor];
	}		
	Screens &move(pos r, pos c);	


	// 需要指定是哪个模板的输入输出友元
	template <unsigned HH, unsigned WW>
	friend ostream &operator <<(ostream &os, const Screens<HH, WW> &c);
	template <unsigned HH, unsigned WW>
	friend istream &operator >> (istream& is, Screens<HH, WW> &c);
private:
	pos cursor = 0;
	pos height = H;	pos width = W;
	std::string contents;
};

template <unsigned H, unsigned W>
Screens<H,W>& Screens<H,W>::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

template <unsigned H, unsigned W>
istream &operator >> (istream& is, Screens<H, W> &c)
{
	char a;
	is >> a;
	string temp(H * W, a);
	c.contents = temp;
	return is;
}

template <unsigned H, unsigned W>
ostream &operator <<(ostream& os, const Screens<H, W> &c)
{
	for (int i = 0; i < c.height; ++i) {
		os << c.contents.substr(i*W, W) << endl;
	}
	return os;
}

#endif // SCREENS_H