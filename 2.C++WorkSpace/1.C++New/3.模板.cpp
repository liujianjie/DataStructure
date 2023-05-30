#include <iostream>
using namespace std;

template<typename type>
class Time{
public:
	Time(int, int, int);
	void display();
private:
	type hour;
	type minute;
	type sec;
};
//void Time<int>::display() {
//	cout << hour << ":" << minute << ":" << sec << endl;
//}

template<typename type>
Time<type>::Time(int m, int s, int y) {
	hour = m;
	minute = s;
	sec = y;
}
template<typename type>
void Time<type>::display() {
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time<int> t1(1,2,3);
	t1.display();
	return 0;
}

