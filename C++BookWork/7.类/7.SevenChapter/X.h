#pragma once
struct X {
	friend void f(){}
	//X() { f(); }// f还没有声明
	//void g();
	void h();
};
//void X::g() { return f(); }	// f还没有声明
void f();
void X::h() { return f(); }

