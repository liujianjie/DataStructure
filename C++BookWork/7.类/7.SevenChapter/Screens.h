#ifndef SCREENS_H
#define SCREENS_H

#include <iostream>
#include <string>
#include "T1.h"
 
//#include "Window_mgr.h" 

using namespace std;
class Window_mgr;
// 成员定义中的普通块作用域的名字查找
//int height = 10;
// 7.3.1 类成员再探
class Screens
{
	friend class Window_mgr;// 友元声明不需要引入头文件
	//friend void Window_mgr::clear(1);// 也可以单独指定一个友元函数 ，但是得有前置声明
	//friend void T1::say() { cout << "可以定义？" << endl; }
	friend void dofriend() { cout << "可以定义？" << endl; }
	
public:
	//Screens();
	~Screens();
	
	typedef std::string::size_type pos;
	// using pos = std::string::size_type;// 等价的声明

	void dummy_fcn(pos height) {
		// 使用 ：：height表示全局的
		cursor = width * height;
	}

	Screens() : contents(100 * 100, ' ') {};

	Screens(pos ht, pos wd, char c):height(ht), width(wd),
		contents(ht * wd, c){}

	Screens(pos ht, pos wd) :height(ht), width(wd){}
	char get() const {
		return contents[cursor];
	}		// 隐式内联
	// inline
	char get(pos ht, pos wd) const; // 显式内联
	Screens &move(pos r, pos c);	// 能在之后被设为内联
	
	void some_member() const;
	void some_member2();

	// 7.3.2 返回*this的成员函数
	Screens &set(char);
	Screens &set(pos, pos, char);

	// const 成员函数若返回this，只能返回const Screen对象
	const Screens &display() const;

	Screens &display(std::ostream &os) { do_display(os); return *this; }
	const Screens &display(std::ostream &os) const { do_display(os); return *this; }
	
	pos getCursor() { return cursor; }

private:
	pos cursor = 0;
	pos height = 2;	pos width = 1;
	std::string contents; // 因为是类成员，会默认初始化会给予空串，即使显示的赋了值也没用

	mutable size_t access_ctr;

	void do_display(std::ostream &os) const { os << contents;}
};
void dofriend();

#endif // SCREENS_H