#include <iostream>
#include <fstream>
using namespace std;


class Person {
public:
	char name[10];
	char date[12];
	bool isFemale;
};

Person staff[] = { "����","1977.05.30",true,
				"��С��","1985.11.01",true,
				"��½��","1978.05,19",false,
				"��ǿ","1997.01.10",false,
				"��˹ޱ","1967.06.01",true, };


Person staff2[] = { "����","1977.05.30",true,
				"��С��","1985.11.01",true,
				"��½��","1978.05,19",false,
				"��ǿ","1997.01.10",false,
				"��˹ޱ","1967.06.01",true, };

int main()
{
	int a;

	//char *c1 = (char *)&staff[0];

	//cout << c1 <<" "<<sizeof(staff[0])<< endl;

	//ofstream ofs("data.txt",ios::out|ios::binary);
	//if (!ofs) {
	//	cout << "create fail()" << endl;
	//}
	//for (int i = 0; i < 5; i++) {
	//	//ofs << (char*)(&staff[i]) << endl; ֻ��һ���ֶ�
	//	ofs.write((char*)(&staff[i]), sizeof(staff[i]));
	//}

	//ofs.close();

	ifstream ifs("data.txt");
	if(!ifs)
		cout << "ifs fail()" << endl;

	for (int i = 0; i < 5; i++) {
		ifs.read((char*)&staff2[i], sizeof(staff[i]));
		cout << "������" << staff2[i].name << "\t"
			<< "�Ա�:" << (staff2[i].isFemale ? "��" : "Ů") << "\t"
			<< "������" << staff2[i].date << endl;
	}
	ifs.close();
	cin >> a;
	return 0;
}