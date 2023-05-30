#include <iostream>
using namespace std;

class Student
{
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << " num : " << num << endl;
		cout << " name : " << name << endl;
		cout << " sex : " << sex << endl;
	}
private:
	int num;
	string name;
	char sex;
};
class Student1 : private Student          //用私有继承方式声明派生类
{
public:
	// 修改的地方：增加一个获取数据函数
	void get_value_1()
	{
		get_value();// 直接访问父类的输入函数
		cin >> age >> addr;
	}
	void display_1()
	{
		display();// 修改的地方：直接访问父类的公用display输出函数
		cout << " age : " << age << endl;
		cout << " address :" << addr << endl;
	}
private:
	int age;
	string addr;
};
int main()
{
	Student1 st1;
	st1.get_value_1();// 题目要求1：程充运行时输入num，name，sex，age，addr的值
	st1.display_1();// 题目要求2：程序应输出以上5个数据的值。
	return 0;
}

