#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#include <functional>
class Test1 {
public:
	Test1() = default;
	Test1(const Test1&) {
		cout << "Test1(const Test1)" << endl;
	}
	Test1(const string& s) {
		cout << "Test1(const string& s)" << endl;
	}
};

int main()
{
	int a;
	Test1 t2 = Test1("sdfsd");// �����֣�ֱ�ӹ������,���ᷢ����������
	Test1 t1("sdfsdf");// Ҳ��ֱ�ӹ������Ӧ���Ǻ������⣬���ᷢ����������
	Test1 t3 = string("sdfsd");
	Test1 t4(t1);// ��ʾ���ÿ������캯�� ����һ��t1����
	Test1 t5 = t2;// ��ʽ���ÿ������캯��
	cout << "------" << endl;
	vector<Test1> ve1;
	ve1.push_back(string("sdfd"));
	ve1.push_back(t3);
	//ve1.push_back(t1);
	cin >> a;
	return 0;
}
