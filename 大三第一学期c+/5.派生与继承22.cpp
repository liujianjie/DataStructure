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
class Student1 : private Student          //��˽�м̳з�ʽ����������
{
public:
	// �޸ĵĵط�������һ����ȡ���ݺ���
	void get_value_1()
	{
		get_value();// ֱ�ӷ��ʸ�������뺯��
		cin >> age >> addr;
	}
	void display_1()
	{
		display();// �޸ĵĵط���ֱ�ӷ��ʸ���Ĺ���display�������
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
	st1.get_value_1();// ��ĿҪ��1���̳�����ʱ����num��name��sex��age��addr��ֵ
	st1.display_1();// ��ĿҪ��2������Ӧ�������5�����ݵ�ֵ��
	return 0;
}

