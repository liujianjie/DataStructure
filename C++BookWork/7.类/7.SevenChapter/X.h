#pragma once
struct X {
	friend void f(){}
	//X() { f(); }// f��û������
	//void g();
	void h();
};
//void X::g() { return f(); }	// f��û������
void f();
void X::h() { return f(); }

