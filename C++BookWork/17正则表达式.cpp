#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include <vector>
#include <memory>
#include "Disc_quote.h"
#include "Basket.h"
#include <regex>

using namespace std;
/*

*/
using namespace regex_constants;
int main()
{
	int a;
	string s1("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})");
	regex r(s1);
	string str("morgan (201) 555-2368 862-555-1212");
	string form("$2.$5,$7");
	smatch sm1;
	sm1.format(form,format_no_copy);
	if (regex_search(str, sm1, r)) {
		cout << sm1.str() << endl;
		cout << sm1.format(form) << endl;
	}
	// Á·Ï°
	/*
	*/
	cin >> a;
	return 0;
}
