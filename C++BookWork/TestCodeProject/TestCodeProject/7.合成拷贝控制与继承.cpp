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
	//D d2(d);// ����D�ĺϳɿ������캯����ɾ����
	D d3(std::move(d));// ������ʽ��ʹ��D�ı�ɾ���Ŀ������캯��,Ӧ�����ƶ����캯����


	cin >> a;
	return 0;
}