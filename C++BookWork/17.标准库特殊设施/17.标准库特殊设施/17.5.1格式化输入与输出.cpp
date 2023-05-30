#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	cout << "def" << true << " " << false
		<< "\nal: " << boolalpha
		<< true << " " << false << endl;

	cout << true << endl;
	cout << noboolalpha;
	cout << false << endl;

	//
	cout << "de: " << 20 << " " << 1024 << endl;
	cout << "oc:" << oct << 20 << " " << 1024 << endl;
	cout << "hex:" << hex << 20 << " " << 1024 << endl;
	cout << "decimal:" << dec << 20 << " " << 1024 << endl;

	cout << showbase;
	cout << "de: " << 20 << " " << 1024 << endl;
	cout << "oc:" << oct << 20 << " " << 1024 << endl;
	cout << "hex:" << hex << 20 << " " << 1024 << endl;
	cout << "decimal:" << dec << 20 << " " << 1024 << endl;

	cout << uppercase << showbase << endl;
	cout << "de: " << 20 << " " << 1024 << endl;
	cout << "oc:" << oct << 20 << " " << 1024 << endl;
	cout << "hex:" << hex << 20 << " " << 1024 << endl;
	cout << "decimal:" << dec << 20 << " " << 1024 << endl;

	cout << nouppercase << noshowbase << dec << endl;
	cout << "decimal:" << dec << 20 << " " << 1024 << endl;

	cout << "Pre: " << cout.precision()
		<< ",val: " << sqrt(2.0) << endl;
	cout.precision(12);
	
	cout << "Pre: " << cout.precision()
		<< ",val: " << sqrt(2.0) << endl;
	//cout << setprecision(19);// 需要头文件
	cout << setprecision(3);
	cout << "Pre: " << cout.precision(19)
		<< ",val: " << sqrt(2.0) << endl;

	//
	cout << uppercase;
	cout << "def : " << 100 * sqrt(2.0) << '\n'
		<< "sc:" << scientific << 100 * sqrt(2.0) << '\n'
		<< "sc:" << scientific << 100 * sqrt(2.0) << '\n'
		<< "sc:" << fixed << 100 * sqrt(2.0) << '\n'
		<< "sc:" << hexfloat << 100 * sqrt(2.0) << '\n'
		<< "sc:" << defaultfloat << 100 * sqrt(2.0) << '\n';

	//
	cout << 10.0 << endl;
	cout << showpoint << 10.0
		<< noshowpoint << endl;

	cout << cout.precision(6);
	int i = -16;
	double d = 3.14159;
	cout << "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "nex col" << '\n';
	cout << left
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< right;
	cout<<right
		<<"i:"<<setw(12)<<i<<"nex col"<<'\n'
		<< "d: " << setw(12) << d << "nex col" << '\n';
	cout << internal
		<< "i:" << setw(12) << i << "nex col" << '\n'
		<< "d: " << setw(12) << d << "nex col" << '\n';
	cout << setfill('#')
		<< "i:" << setw(12) << i << "nex col" << '\n'
		<< "d: " << setw(12) << d << "nex col" << '\n'
		<< setfill(' ');

	//
	char ch;
	//while (cin >> ch)
		//cout << ch;
	//cin >> noskipws;
	//while (cin >> ch)
	//	cout << ch;

	cout << setbase(16)
		<< 10 << endl;
	cout << flush << endl;

	cout << uppercase
		<< "hex :" << hexfloat<< 100 * sqrt(2.0) << endl;
	cout << uppercase
		<< "hex :" << scientific << 100 * sqrt(2.0) << endl;

	cout << right
		<< "1: " << setw(30) << scientific << 100 * sqrt(2.0) << '\n'
		<< "2: " << setw(30) << scientific << 100 * sqrt(7.0) << '\n'
		<< "3: " << setw(30) << scientific << 100 * sqrt(5.0) << '\n'
		<< "4: " << setw(30) << scientific << 100 * sqrt(13.0) << '\n';
	/*
	练习：
	17.34:ok
	17.35:ok
	17.36:ok
	
	*/
	cin >> a;
	return 0;
}
