#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include "Foo136.h"
//using namespace std;

void swap(int* i, int *j)
{
	std::cout << "inner swap()" << std::endl;
}

void swap()
{
	//using std::swap;
	//using namespace std;// ����Ų�������
	int *ii = new int(2), *jj = new int(3);
	swap(ii, jj);
}
class Y {
public:
	Y(const Y&) { std::cout << "Y(const Y&)" << std::endl; }
};

class hasY {
public:
	hasY() = default;
	hasY(hasY&&) = default;
	//Y mem;// Y��һ��ɾ�����ƶ����캯��,��Ϊֻ�����˿������캯������û�ж����ƶ����캯��
};
hasY hy, hy2 = std::move(hy);// �ƶ����캯����ɾ����
int main()
{
	int a;
	swap();

	Foo136 f1;
	f1.someMem();
	const Foo136 f2;
	std::move(f2).someMem();
	std::cin >> a;
	return 0;
}
