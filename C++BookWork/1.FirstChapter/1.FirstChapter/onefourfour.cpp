#include <iostream>

int main()
{
	int val = 0, sum = 0;
	int currval = 0;
	if (std::cin>>currval) {
		int count = 1;
		while (std::cin >> val) {
			if (currval == val) {
				count++;
			}
			else {
				// 打印输出次数
				std::cout << currval << "occuer" << count << "time" << std::endl;
				count = 1;
				currval = val;
			}
		}
		// 打印最后一位数出现次数
		std::cout << currval << "occuer" << count << "time" << std::endl;
	}
	

	
	std::cin >> sum;//暂停
	getchar();
	return 0;
}