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

// ����

void SwapByRefre(Student& s1, Student& s2) {

	Student s3 = s1;

	s1 = s2;

	s2 = s3;

}

// ð������

void BubbleSortStudent(Student stu[], int n) {

	for (int i = n - 1; i > 0; i--) { // ����

		for (int j = 0; j < i; j++) {// ��ǰ����ɸѡ�� j < i ����˼�� j < i < n����Ѿ��źã�����������

			if (stu[j].stu_score > stu[j + 1].stu_score) {

				SwapByRefre(stu[j], stu[j + 1]);

			}

		}

	}

}

// ���

void PrintStudent(Student stu[], int n) {

	for (int i = 0; i < n; i++) {

		cout << stu[i] << endl;

	}

}

int main() {

	Student stu[] = { Student(1, "Сһ", 80), Student(2, "С��", 50),Student(3, "С��", 90),Student(4, "С��", 60),Student(5, "С��", 88) };

	int n = sizeof(stu) / sizeof(Student);

	cout << "����ǰ��" << endl;

	PrintStudent(stu, n);

	BubbleSortStudent(stu, n);



	cout << "�����" << endl;

	PrintStudent(stu, n);

	return 0;

}