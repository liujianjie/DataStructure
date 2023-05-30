#include <iostream>
#include <string>
#include <fstream>
#include "QueryResult.h"
#include "AllClass.h"

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

/*
д���ܽᣬ�����ǣ�
���Ǽ̳���ϵ��һԪ���������Ԫ�������ʵ�ʲ�ѯ�������
ÿ�����������һ��Query��
һԪ�������һ��Query�������
��Ԫ�����������Query�������
��~(Query("adf")),~��һԪ���������������������Query

Query������һ��Query_base�������ָ�룬�����������㡣����
Query q = Query("fiery") & Query("bird") | Query("wind");
���������������ʹ���ĸ��������������ϼ���Query����
1.
  (Query�������)OrQuery(Query�������)
2.����������ͨ��Query��ָ��Query_base �õ��������
  (Query������� AndQuery Query�������)OrQuery(WordQuery)
  (WordQuery AndQuery WordQuery)OrQuery(WordQuery)
  (WordQuery AndQuery WordQuery)OrQuery (QueryResult)
  (QueryResult)OrQuery (QueryResult)
  QueryResult
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
	//BinaryQuery b1 = Query("a") | Query("b");
	//AndQuery b1 = Query("a") & Query("b");
	//OrQuery b1 = Query("a") | Query("b");

	ifstream ifs("15.9�����ļ�.txt");
	TexTQuery te(ifs);
	
	Query q = Query("fiery") & Query("bird") | Query("wind");
	//cout << q << endl;
	//print(cout, q.eval(te));
	cout << "------" << endl;
	Query q2 = ~Query("Alice");
	
	//print(cout, q2.eval(te));

	Query q3 = Query("Daddy");
	//print(cout, q3.eval(te));

	Query q4 = Query("hair")|Query("Alice");
	print(cout, q4.eval(te));
	// ��ϰ
	/*
	Query q = Query("fiery") & Query("bird") | Query("wind");
	15.34��
	(a).��OrQuery | left��ΪAndQuery &
							left�� Query(string)���캯�� WordQuery(s)   3
							right�� Query(string)���캯�� WordQuery(s)   2
							BinaryQuery���캯��   4
							AndQuery���캯��   5
					right:ΪQuery(string)���캯�� WordQuery(s)   1
					BinaryQuery���캯��  6
					OrQuery���캯��  7
	(b).ͬa�ĺ���
		|��BinaryQuery��rep��|left&��BinaryQuery��rep��&leftWordQuer�ģ�&rightWordQuery�ģ�|rightWordQuery��
	(c).Ҳ�ǲ��� q.eval()
	������|��Queryչ��,��ΪbinaryQueryû��eval����ʡ����
			     rhs.eval����word�����Ĳ�ѯ����QueryResult
	|Query eval:
							rhs.eval
				&Query eval:
							lfs.eval
				

	15.35:ok
	15.36:ok
	15.37:ʵ�����ķ�ʽ��һ������ֵ��ʽҲ��һ�������ǻ�Ķ��ܶ�ɡ��о���������Ҫ~(new WordQuery(".."))��֪��������д
	15.38��ok

	15.39:ok
	15.40:ok
	15.41:��Ҫ�ֶ�delete����
	15.42��

	(a)����һС�ʸо��е����⣬�����������������⣺���ļ�����֮��ÿ�б�����һ��vector<string>�У��������뵥�ʣ�ÿ�в�ѯ�������Ӧ����

	(b)�����¶���һ���࣬��ÿ�εĲ�ѯ�����һ��map<int,map>���������ͺ��ˣ�intΪ��ţ�mapΪ��ѯ���

	(c)��ָ���ı���Χ��������������һ��vector<string> �����ݼ���
	---------------------
	���ߣ�MISAYAONE
	��Դ��CSDN
	ԭ�ģ�https://blog.csdn.net/misayaaaaa/article/details/61925162
	��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

	*/
	cin >> a;
	return 0;
}
