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

// 交换

void SwapByRefre(Student& s1, Student& s2) {

	Student s3 = s1;

	s1 = s2;

	s2 = s3;

}

// 冒泡排序

void BubbleSortStudent(Student stu[], int n) {

	for (int i = n - 1; i > 0; i--) { // 趟数

		for (int j = 0; j < i; j++) {// 从前往后筛选， j < i 的意思是 j < i < n这段已经排好，不用再排了

			if (stu[j].stu_score > stu[j + 1].stu_score) {

				SwapByRefre(stu[j], stu[j + 1]);

			}

		}

	}

}

// 输出

void PrintStudent(Student stu[], int n) {

	for (int i = 0; i < n; i++) {

		cout << stu[i] << endl;

	}

}

int main() {

	Student stu[] = { Student(1, "小一", 80), Student(2, "小二", 50),Student(3, "小三", 90),Student(4, "小四", 60),Student(5, "小五", 88) };

	int n = sizeof(stu) / sizeof(Student);

	cout << "排序前：" << endl;

	PrintStudent(stu, n);

	BubbleSortStudent(stu, n);



	cout << "排序后：" << endl;

	PrintStudent(stu, n);

	return 0;

}