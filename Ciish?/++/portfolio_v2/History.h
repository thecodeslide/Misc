#ifndef history_h
#define history_h

#include <sstream>
#include "BST.h"

using namespace std;
class history
{
	string vObjAction, vObjQty, vObjPrice;
public:
	history();
	history(string, string, string);
	~history();
	friend istream &operator>>(istream &in, history &H);
	void setHistory(string, string, string);

	const string& getObjAction() const { return vObjAction; };
	const string& getObjPrice() const { return vObjPrice; };
	const string& getObjQty() const { return vObjQty; };
	string eraseSP(string, char);
};

#endif