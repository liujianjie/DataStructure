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
				// ��ӡ�������
				std::cout << currval << "occuer" << count << "time" << std::endl;
				count = 1;
				currval = val;
			}
		}
		// ��ӡ���һλ�����ִ���
		std::cout << currval << "occuer" << count << "time" << std::endl;
	}
	

	
	std::cin >> sum;//��ͣ
	getchar();
	return 0;
}