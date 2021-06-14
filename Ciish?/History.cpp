#include "History.h"

history::history()
{

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
	H.vObjAction.insert(strHist);

	getline(in, strHist, delim);
	strHist = H.eraseSP(strHist, removeChar);
	stringstream strH(strHist);
	H.vObjQty.insert(strHist);
	
	getline(in, strHist, '\n');
	strHist = H.eraseSP(strHist, removeChar);
	H.vObjPrice.insert(strHist);

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
