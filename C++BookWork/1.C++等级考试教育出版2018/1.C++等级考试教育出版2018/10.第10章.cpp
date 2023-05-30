#include <iostream>
#include <fstream>
using namespace std;


class Person {
public:
	char name[10];
	char date[12];
	bool isFemale;
};

Person staff[] = { "五月","1977.05.30",true,
				"赵小光","1985.11.01",true,
				"王陆生","1978.05,19",false,
				"张强","1997.01.10",false,
				"李斯薇","1967.06.01",true, };


Person staff2[] = { "二月","1977.05.30",true,
				"赵小光","1985.11.01",true,
				"王陆生","1978.05,19",false,
				"张强","1997.01.10",false,
				"李斯薇","1967.06.01",true, };

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
	//	//ofs << (char*)(&staff[i]) << endl; 只能一个字段
	//	ofs.write((char*)(&staff[i]), sizeof(staff[i]));
	//}

	//ofs.close();

	ifstream ifs("data.txt");
	if(!ifs)
		cout << "ifs fail()" << endl;

	for (int i = 0; i < 5; i++) {
		ifs.read((char*)&staff2[i], sizeof(staff[i]));
		cout << "姓名：" << staff2[i].name << "\t"
			<< "性别:" << (staff2[i].isFemale ? "男" : "女") << "\t"
			<< "出生：" << staff2[i].date << endl;
	}
	ifs.close();
	cin >> a;
	return 0;
}