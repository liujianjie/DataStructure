#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(string, int);
	virtual void DisPlay();
	~Student() {
		cout << "Student Îö¹¹" << endl;
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
		cout << "Graduate Îö¹¹" << endl;
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

	Student* pt2 = new Student("2", 1);
	//cout << typeid(stu).name() << endl;
	cout << typeid(pt2).name() << endl;


	//delete pt2;
	//getchar();
	return 0;
}