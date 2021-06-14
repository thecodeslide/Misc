#include "History.h"

history::history()
{
	vObjAction = "";
	vObjQty = "";
	vObjPrice = "";
}

history::history(string action, string qty, string price)
{
	vObjAction = action;
	vObjQty = qty;
	vObjPrice = price;
}

void history::setHistory(string action, string qty, string price)
{
	vObjAction = action;
	vObjQty = qty;
	vObjPrice = price;
}

history::~history()
{

}

istream &operator >> (istream &in, history &H)
{	
	char removeChar = ' ', delim = ',';
	string strHist;

	getline(in, strHist, delim);
	strHist = H.eraseSP(strHist, removeChar);
	H.vObjAction = strHist;

	getline(in, strHist, delim);
	strHist = H.eraseSP(strHist, removeChar);
	H.vObjQty = strHist;
	
	getline(in, strHist, '\n');
	strHist = H.eraseSP(strHist, removeChar);
	H.vObjPrice = strHist;

	return in;
}

string history::eraseSP(string str, char removeChar)
{
	size_t found= str.find(removeChar);
	string::iterator start = str.begin();

	if (found != string::npos)
		str.erase(start+found);

	return str;
}
