#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

int a = 1, val = 2;

void foo(int val)
{
	int si2 = 209;
	static int si = 3;
	enum Loc  { a = 1024, b };
	struct Bar {
		//friend void foo(int val);
		Loc locVal;
		int barVal;

		void fooBar(Loc l = a)
		{
			//barVal = val;// �ֲ��Ĳ���
			barVal = ::val;//ȫ�ֵ�
			//barVal = si2;
			barVal = si;// ��̬�ֲ�����
			locVal = b;// ����
		}
	};
	//cout << Bar::barVal << endl;
}

void foo()
{
	class Bar {
	public:
		int val1 = 0;
		class Nested;
	};
	class Bar::Nested {
	public:
		//prints() { cout << val1 << endl; }
	};
}
int main()
{
	int a;

	/*
	��ϰ��
	*/
	cin >> a;
	return 0;
}
