#include <iostream>
#include <iomanip>
using namespace std;

class T1 {
private:
	static int static_data;
	const int const_data;
public:
	T1(int d):const_data(d){}
	//static void fool() {
	//	cout << const_data;
	//}
	void foo2()const {
		cout << static_data;
	}
	void foo3() {
		cout << static_data;
	}
};

class T2 {
private:
	int val1;
public:
	friend class T3;
};
class T3 : public T2 {
public:
	void foo(){
		val1 = 3;
	}
};
int main()
{
	int a;
	//T3 t3;
	//t3.val1 = 3;

	//cout  << setfill('#') << "357";
	cout  << setw(5) << 357;
	cin >> a;
	return 0;
}