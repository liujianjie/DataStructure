#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)


class doc {
public:
	char *str1;
	int length;// ×ÖµÄ³¤¶È

	doc(char *filename);

	void writeToFile(char *filename);
	void reverse();
	~doc();

};

doc::doc(char *filename):length(0)
{
	//int tmp;
	char tmp;
	str1 = new char[1000];
	ifstream ifs(filename);
	if (ifs.good()) {
		while ((tmp = ifs.get()) != EOF) {
			str1[length++] = tmp;
		}
		str1[length] = '\0';
	}
	cout << str1 << endl;
	ifs.close();
}
doc:: ~doc() {
	delete[] str1;
}

void doc::reverse()
{
	char *ch1 = new char[length + 1];
	ch1[length] = '\0';
	for (int i = 0; i < length ; i++) {
		ch1[i] = str1[length - 1 - i];
	}
	str1 = ch1;
}

void doc::writeToFile(char *filename)
{
	ofstream ofs(filename, ios_base::out);
	if (ofs.good())
	{
		ofs << str1;
		//ofs.write(myDoc.str1, strlen(myDoc.str1) + 1);
	}
	ofs.close();
}
int main()
{
	int a;
	string s1("12312312");
	cout<<s1.find('1')<<endl;


	int val1 = 20, val2 = 30;
	int *p1 = &val1;
	int **pp1 = &p1;
	**pp1 = val2;
	cout << pp1 << endl;
	cout << *pp1 << endl;
	cout << **pp1 << endl;

	cout << p1 << endl;
	cout << *p1 << endl;
	//char *ch1 = "agcsdf";
	//cout << ch1 << endl;
	//cout << strcspn(ch1, "g") << endl;


	/*doc myDoc("inTestCode1.txt");
	myDoc.reverse();
	cout << myDoc.str1 << endl;
	myDoc.writeToFile("ouTestCode1.txt");*/


	cin >> a;
	return 0;
}