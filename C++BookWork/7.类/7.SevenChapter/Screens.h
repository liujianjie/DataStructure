#ifndef SCREENS_H
#define SCREENS_H

#include <iostream>
#include <string>
#include "T1.h"
 
//#include "Window_mgr.h" 

using namespace std;
class Window_mgr;
// ��Ա�����е���ͨ������������ֲ���
//int height = 10;
// 7.3.1 ���Ա��̽
class Screens
{
	friend class Window_mgr;// ��Ԫ��������Ҫ����ͷ�ļ�
	//friend void Window_mgr::clear(1);// Ҳ���Ե���ָ��һ����Ԫ���� �����ǵ���ǰ������
	//friend void T1::say() { cout << "���Զ��壿" << endl; }
	friend void dofriend() { cout << "���Զ��壿" << endl; }
	
public:
	//Screens();
	~Screens();
	
	typedef std::string::size_type pos;
	// using pos = std::string::size_type;// �ȼ۵�����

	void dummy_fcn(pos height) {
		// ʹ�� ����height��ʾȫ�ֵ�
		cursor = width * height;
	}

	Screens() : contents(100 * 100, ' ') {};

	Screens(pos ht, pos wd, char c):height(ht), width(wd),
		contents(ht * wd, c){}

	Screens(pos ht, pos wd) :height(ht), width(wd){}
	char get() const {
		return contents[cursor];
	}		// ��ʽ����
	// inline
	char get(pos ht, pos wd) const; // ��ʽ����
	Screens &move(pos r, pos c);	// ����֮����Ϊ����
	
	void some_member() const;
	void some_member2();

	// 7.3.2 ����*this�ĳ�Ա����
	Screens &set(char);
	Screens &set(pos, pos, char);

	// const ��Ա����������this��ֻ�ܷ���const Screen����
	const Screens &display() const;

	Screens &display(std::ostream &os) { do_display(os); return *this; }
	const Screens &display(std::ostream &os) const { do_display(os); return *this; }
	
	pos getCursor() { return cursor; }

private:
	pos cursor = 0;
	pos height = 2;	pos width = 1;
	std::string contents; // ��Ϊ�����Ա����Ĭ�ϳ�ʼ�������մ�����ʹ��ʾ�ĸ���ֵҲû��

	mutable size_t access_ctr;

	void do_display(std::ostream &os) const { os << contents;}
};
void dofriend();

#endif // SCREENS_H