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

class Student1 : public Student
{
public:
	// �޸ĵĵط�������һ����ȡ���ݺ���
	void get_value_1()
	{
		cin >> age >> addr;
	}
	void display_1()
	{
		// �޸ĵط��������˽�б�������ֱ�ӷ���
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
	// ��ĿҪ��1����������ʱ����num��name��sex��age��addr��ֵ
	st1.get_value();
	st1.get_value_1();
	// ��ĿҪ��2������Ӧ�������5�����ݵ�ֵ
	st1.display();
	st1.display_1();
	return 0;
}

