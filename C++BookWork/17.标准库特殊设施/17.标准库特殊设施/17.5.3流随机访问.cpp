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

/*

abcd
efg
hi
j


*/
int main()
{
	int a;
	// Ϊ��ͳһ��˵������ �ú����İ汾
	// fstreamֻ�е�һ��ǣ�g��p�汾�Ķ�дλ�ö�ӳ���ŵ�һ���
	fstream iout("17.5.3�ı�.txt",
		 fstream::ate|fstream::in|fstream::out);
	auto end_mark = iout.tellg();// βλ�� ������g ����p�汾��������
	//iout.seekp(0, fstream::end);// ����fstream��˵��������g����p�汾����ͬһ��λ��
	iout.seekg(0, fstream::beg);// �ص�һ��ʼλ��
	string line;
	size_t count = 0;
	while (iout && iout.tellg() != end_mark
		&& getline(iout, line)) {
		count += line.size() + 1;// ��ȡ�ж��ٴ�С
		auto mark = iout.tellg();// ��¼��ȡ����һ�е�λ�ã��������Ҫ�������Ҫ������ǰλ��
		iout.seekp(0, fstream::end);// ��ĩβλ��
		iout << count;// ���
		iout << " ";// ��ӡ" "
		 // �ص�����λ��
		iout.seekg(mark);// countҲ��ƫ����
	}
	// ����14�ĺ������һ�����з�
	iout.seekp(0, fstream::end);
	iout << "\n";

	/*
	��ϰ��
	ok
	*/
	cin >> a;
	return 0;
}
