#include <iostream>

#include <string>

using namespace std;

struct Student {

public:

	int stu_no;

	string stu_name;

	float stu_score;

	Student(int stu_no, string stu_name, float stu_score) {

		this->stu_no = stu_no;

		this->stu_name = stu_name;

		this->stu_score = stu_score;

	}

};

ostream& operator <<(ostream& out, Student& s1)
{

	out << s1.stu_no << " " << s1.stu_name << " " << s1.stu_score;

	return out;

}

// ָ�뷽ʽ����

void SwapByPointer(Student*& s1, Student*& s2) { // ������Ҫ�������͵�ָ��

	Student* s3 = s1;

	s1 = s2;

	s2 = s3;

}

// ���÷�ʽ����

void SwapByRefre(Student& s1, Student& s2) {

	Student s3 = s1;

	s1 = s2;

	s2 = s3;

}

int main() {

	Student* s1 = new Student(1, "����", 70);

	Student* s2 = new Student(2, "С��", 98);

	cout << "ָ�뽻��ǰ" << endl;

	cout << "s1:" << *s1 << endl;

	cout << "s2:" << *s2 << endl;

	SwapByPointer(s1, s2);

	cout << "ָ�뽻����" << endl;

	cout << "s1:" << *s1 << endl;

	cout << "s2:" << *s2 << endl;


	cout << "---------------------" << endl;

	Student s3(3, "С��", 92);

	Student s4(4, "����", 73);

	cout << "���ý���ǰ" << endl;

	cout << "s3:" << s3 << endl;

	cout << "s4:" << s4 << endl;

	SwapByRefre(s3, s4);

	cout << "���ý�����" << endl;

	cout << "s3:" << s3 << endl;

	cout << "s4:" << s4 << endl;

	return 0;

}