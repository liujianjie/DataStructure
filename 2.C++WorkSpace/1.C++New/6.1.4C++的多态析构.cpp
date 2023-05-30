#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(string, int);
	virtual void DisPlay();
	virtual ~Student() {
		cout << "Student 析构" << endl;
	}
public:
	string name;
	int age;
};

class Graduate : public Student {
public:
	Graduate(string, int, float);
	virtual void DisPlay();
	~Graduate() {
		cout << "Graduate 析构" << endl;
	}
public:
	float salary;
};

Student::Student(string str, int ag) :name(str), age(ag) {
}
void Student::DisPlay() {
	cout << "Student: name:" << name << ",age:" << age << endl;
}
Graduate::Graduate(string str, int ag, float f) : Student(str, ag) {
	this->salary = f;
}
void Graduate::DisPlay() {
	cout << "Graduate: name:" << name << ",age:" << age << ",salary:" << salary << endl;
}
int main() {
	//Student stu(string("ljj"), 12);
	Graduate grad("graljj", 30, 32000.0);

	//Student* pt = &stu;
	//pt->DisPlay();
	//pt = &grad;
	//pt->DisPlay();

	//Student* pt2 = new Graduate("2", 1, 3);
	//cout << typeid(stu).name() << endl;
	//cout << typeid(pt2).name() << endl;

	//delete pt2;
	/*
	普通类变量不用delete，自动析构，并且不用指定virtual，派生类自动调用父类析构
	*/

	// 指针类型不会自动析构，需要调用 delete
	/*
	如果指向派生类，基类的析构不用virtual照样析构
	如果指向基类，基类的析构不virtual不会调用子类析构
							声明virtual会调用子类析构
	*/
	//getchar();
	return 0;
}