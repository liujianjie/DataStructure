#include <iostream>
#include <string>
#include <random>
using namespace std;

class B {
public:
	B() = default;
	//B(const B&) = delete;
	//B(const B&) = default;
	//B(B&&) = default;
	//B& operator=(const B&) = default;
	//B& operator=(B&&) = default;
	B(const B&) {
		cout << "B(const B&);" << endl;
	}
	B(B&&){
		cout << "B(B&&);" << endl;
	}
	B& operator=(B&&){
		cout << "B& operator=(B&&);" << endl;
	}
	virtual ~B() = default;
};
class D :public B {

};
int main()
{
	int a;
	D d;
	//D d2(d);// 错误，D的合成拷贝构造函数是删除的
	D d3(std::move(d));// 错误，隐式的使用D的被删除的拷贝构造函数,应该是移动构造函数吧


	cin >> a;
	return 0;
}