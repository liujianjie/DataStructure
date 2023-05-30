#include <iostream>
#include <fstream>
//#include <string>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)


int main()
{
	int a;

	char *s1 = "";
	if (s1 == NULL) {
		cout << "NULL" << endl;
	}
	if (strlen(s1) == 0) {
		cout << "NULL2" << endl;
	}

	char *s2 = "ax";
	char *s3 = "ag";
	cout << strcmp(s2, s3) << endl;

	cout << boolalpha << true << endl;
	cout << false << endl;
	cout << noboolalpha << true << endl;

	char *c1 = "abcdefghiabcd";
	cout << strstr(c1, "b") << endl;
	//cout << (char)(97) << endl;
	cout << strchr(c1,98) << endl;
	cout << strrchr(c1, 97) << endl;

	cout << strpbrk(c1, "zc") << endl;

	cout << strspn(c1, "xd") << endl;

	cout << strcspn(c1, "zc") << endl;

	//char ch;// ÊÔÓÃint
	int ch;
	fstream infile, outfile;
	infile.open("out1.txt",ios::in);
	if (!infile) {
		
	}

	outfile.open("out2.txt",ios_base::out);
	if (!outfile) {
		
	}
	while ((ch = infile.get()) != EOF) {
		cout << (char)ch;
		outfile.put(ch);
	}

	cout << endl;
	infile.close();
	outfile.close();

	cin >> a;
	return 0;
}