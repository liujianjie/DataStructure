#include <iostream>
using namespace std;

class Time {
public:
	Time():minute(0),sec(0){}
	Time(int m, int s):minute(m),sec(s){}
	Time operator++();// 前
	Time operator++(int);// 后置
	void display() {
		cout << minute << ":" << sec << endl;
	}
private:
	int minute;
	int sec;
};

Time Time::operator++() {
	if (++sec >=60) {
		sec -= 60;
		++minute;
	}
	return *this;
}
Time Time::operator++(int) {
	Time temp(*this);
	sec++;
	if (sec >= 60) {
		sec -= 60;
		++minute;
	}
	return temp; // 返回自增前的对象
}
int main()
{
	Time time1(35, 59), time2;
	cout << " time1: ";
	time1.display();
	++time1;
	cout << " ++time1: ";
	time1.display();
	// 赋值
	time2 = time1++;// 赋给自增前的对象

	cout << " time1++: ";
	time1.display();

	cout << " time2++:: ";
	time2.display();

	return 0;
}

