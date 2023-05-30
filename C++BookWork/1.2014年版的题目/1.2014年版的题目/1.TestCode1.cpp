#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)


class doc {
public:
	char *str1;
	int size;
}myDoc;

void rever(char *str1)
{
	char *ch1 = new char[strlen(str1) + 1];
	ch1[strlen(str1)] = '\0';
	for (int i = 0; i < strlen(str1); i++) {
		ch1[i] = str1[strlen(str1) - 1 - i];
	}
	//cout << ch1 << endl;

	myDoc.str1 = ch1;
}
int main()
{
	int a;

	//doc myDoc;

	//char *ch2 = "12312";
	//cout << ch2 << endl;
	//cout << *ch2 << endl;

	//char ch3[3] = { '1','2','\0'};
	//cout << ch3 << endl;
	//cout << *ch3 << endl;

	myDoc.str1 = new char[1000];
	ifstream ifs("inTestCode1.txt",ios_base::in);
	if (ifs.good()) {
		ifs.get(myDoc.str1, 1000, '\0');
		cout << myDoc.str1 << endl;

		//myDoc.size = ifs.gcount();
		cout << strlen(myDoc.str1) << endl;
		rever(myDoc.str1);
		cout << myDoc.str1 << endl;
	}
	ifs.close();
	ofstream ofs("ouTestCode1.txt",ios_base::out);
	if (ofs.good())
	{
		ofs << myDoc.str1;
		//ofs.write(myDoc.str1, strlen(myDoc.str1) + 1);
	}
	ofs.close();
	delete[]myDoc.str1;

	cin >> a;
	return 0;
}