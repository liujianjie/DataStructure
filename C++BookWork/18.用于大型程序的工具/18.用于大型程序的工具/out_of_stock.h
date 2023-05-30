#pragma once
#include <iostream>
class out_of_stock :public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s) :
		std::runtime_error(s) { }
};
