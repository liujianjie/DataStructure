#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	int maxLength = 0, tempLength;
	int size = 1;
	cout << "请输入个数：" << endl;
	cin >> size;
	cout << "请依次输入每个值：" << endl;
	float *cinv = new float[size];
	for (int i = 0; i < size; i++) {
		cin >> cinv[i];
		tempLength = to_string((int)cinv[i]).length(); // 舍去小数部分，计算长度
		maxLength = maxLength < tempLength ? tempLength : maxLength;// 这一批数据中最长的数目
	}
	maxLength = maxLength + 4; // 3位小数加上小数点
	cout << "格式化输出：" << endl;
	cout << setprecision(3) << setiosflags(ios::fixed) ;// 设置3为小数，小数形式输出
	for (int i = 0; i < size; i++) {
		cout.width(maxLength);// 设置长度
		cout.setf(ios::right);// 设置对齐方式
		cout << cinv[i] << endl;
	}
	return 0;
}