#include <iostream>
#include "Query.h"

using namespace std;
/*
������
1.����Ȥ�Ĳ�����ʵ����ʵ�Ĳ�ѯ����
2.����WordQuery�������඼��һ������������������������������
3.������������query_baseָ�����ʽ�洢������ʵ��������Query����ӿ�����

2.WordQuery��
1.û��public��Ա��Query��Ϊ��Ԫ
2.eval����TextQueryִ��ʵ�ʵĲ���

3.NoteQuery�༰~�����
1.Ҫ��~������趨Ϊ��Ԫ��
2.������Ľ���������ţ�֪����ѯ�����ȼ�
3.rep�ǵ���Query��rep��ִ�����յ��������rep
4.return std::shared_ptr<Query_base>(new NotQuery(operand));��ʽ��ʹ�ý���shader...�Ĺ��캯��

4.BinaryQuery��
1.�����������һ�������������
2.û��evalҲ�ǳ�������

5.AndQuery�ࡢOrquery�༰��Ӧ�������
1.���������࣬�̳��˸����rep���������Լ���eval
2.�����Ҳ�ǵ���sharder_�Ĺ��캯��
*/

ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
int main()
{
	int a;
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q;

	// ��ϰ
	/*
	Query q = Query("fiery") & Query("bird") | Query("wind");
	15.34��
	(a).��OrQuery | left��ΪAndQuery &
							left�� Query(string)���캯�� WordQuery(s)
							right�� Query(string)���캯�� WordQuery(s)
							BinaryQuery���캯��
							AndQuery���캯��
					right:ΪQuery(string)���캯�� WordQuery(s)
					BinaryQuery���캯��
					OrQuery���캯��
	(b).|��BinaryQuery��rep��&��BinaryQuery��rep��WordQuer�ģ�WordQuery�ģ�WordQuery��
	(c).emmm

	15.35:
	15.36:
	15.37:ʵ�����ķ�ʽ��һ������ֵ��ʽҲ��һ��
	15.38��

	*/
	cin >> a;
	return 0;
}
