#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
fstream ��д
ifstream ��
ofstream д

һ��ifstream������رպ��������һ������
���ǿ����ж��ifstream�������һ���ļ�
*/

void instead_of(istream& is1,ostream& os1) 
{

}
int main()
{
	int a;
	fstream fs1("file1.txt");
	ofstream of1;
	if (fs1)
		cout << "fs1.opend()" << endl;
	if (of1)
		cout << "of1.opend()" << endl;

	// ����fstream����iostream&
	instead_of(fs1, fs1);

	// ��Ա����open��close
	ifstream fs2("file2.txt");
	ofstream of2;
	of2.open("file3.txt");;

	if (fs2) {
		cout << "fs2.opend()" << endl;
	}
	if (of2) {
		cout << "of2.opend()" << endl;
	}
	// fs2δ�رվ���open���д�
	fs2.close();
	fs2.open("file4.txt");
	cout << fs2.fail() << endl;
	if (fs2) {
		cout << fs2.good() << endl;
		cout << "fs2.opend()" << endl;
	}
	ifstream fs3("file4.txt");
	if (fs3) {
		cout << "fs3.opend()" << endl;
	}

	// �Զ����������
	vector<string> v1{"file5.txt","file6.txt","file7.txt"};
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		ifstream fs4(*beg);
		if (fs4) {
			cout << "fs4.opend()" << endl;
		}
		else {
			cout << "open faile" << endl;
		}
	}
	ifstream if5("filein.txt");
	vector<string> v2;
	string str1;
	while (if5 >> str1) {
		v2.push_back(str1);
	}
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	ofstream of5("out1.txt");
	vector<string> v3{"word","vector","alholic","night"};
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		of5 << *beg<<" ";
	}
	of5 << endl;// �Ỻ��


	cin >> a;
	return 0;
}