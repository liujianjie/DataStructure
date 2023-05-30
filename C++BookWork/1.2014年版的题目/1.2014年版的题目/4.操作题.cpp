#include <iostream>
#include <fstream>
//#include <string>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)


bool endsWith(const char *s1, const char* s2) {
	if (strlen(s2) == 0 || strcmp(s1,s2) == 0) {
		return false;
	}
	//char *news1 = new char[strlen(s1) + 1];
	//strcpy(news1, s1);
	const char *s3 = strrchr(s1, s2[0]);
	if (s3 != nullptr) {
		if (strcmp(s3, s2) == 0) {
			return true;
		}
	}
	return false;
}
int main()
{
	int a;

	char *s1 = "acb";
	char * s2 = strrchr(s1, 97);
	cout << strlen(s2) << endl;


	bool b1 = endsWith("abcd","z");
	cout << b1 << endl;

	cin >> a;
	return 0;
}