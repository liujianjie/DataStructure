#pragma once
#include "HasPtr.h"

class Foo {
	friend void swap(Foo &lhs, Foo &rhs);

public:
	Foo() = default;
	Foo(const HasPtr& hs) :h(hs) {}
	HasPtr& getHas() {
		return h;
	}
private:
	HasPtr h;
};
