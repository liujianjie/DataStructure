#include <iostream>

using namespace std;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
// ��ʾ�Ķ�����β��б�
void fact2(void) {}

// �ֲ���̬����
size_t count_calls() 
{
	static size_t ctr = 0;// ���ý��������ֵ��Ȼ��Ч��
	return ++ctr;
}
int main() 
{
	int getchar;
	//int zhi = fact(4);
	//cout << zhi << endl;
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << "\t" << endl;

	cin >> getchar;
	return 0;
}