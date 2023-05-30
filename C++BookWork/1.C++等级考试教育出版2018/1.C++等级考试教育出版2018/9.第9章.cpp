#include <iostream>
using namespace std;

template <typename T>
T average(T *data) {
	T s = 0;
	int i = 0;
	while (data[i])
		s += data[i++];
	return (s / (i + 1));
}


template <typename T>
class T2 {


};

template <int T>
class T3 {
public:
	T3() {
		cout << T << endl;
	}

};
int main()
{
	int a;

	double x[] = { 2.5,4.5,6.5,8.5,0.0,12.5 };
	cout << average(x)<<endl;

	T2<int> t21;

	T3<3> t31;
	cin >> a;
	return 0;
}