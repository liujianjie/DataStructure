#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(string, int);
	virtual void DisPlay();
	void DisPlay(int a);
public:
	string name;
	int age;
};

class Graduate : public Student {
public:
	Graduate(string, int, float);
	virtual void DisPlay();
	void DisPlay(int a);
public:
	float salary;
};

Student::Student(string str, int ag) :name(str), age(ag) {

}
void Student::DisPlay() {
	cout << "Student: name:" << name << ",age:" << age << endl;
}
void Student::DisPlay(int a) {
	cout << "Student int a : name:" << name << ",age:" << age << endl;
}
Graduate::Graduate(string str, int ag, float f) : Student(str, ag) {
	this->salary = f;
}
void Graduate::DisPlay() {
	cout << "Graduate: name:" << name << ",age:" << age << ",salary:" << salary << endl;
}
void Graduate::DisPlay(int a) {
	cout << "Graduate int a : name:" << name << ",age:" << age << endl;
}
int main() {
	Student stu(string("ljj"), 12);
	Graduate grad("graljj", 30, 32000.0);

	Student* pt = &stu;
	pt->DisPlay(2);
	pt->DisPlay();
	pt = &grad;
	pt->DisPlay();
	pt->DisPlay(2);
	return 0;
}