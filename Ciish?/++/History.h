#ifndef history_h
#define history_h

#include "Vector.h"
#include <sstream>

using namespace std;
class history
{
//	typedef Vector<string> vObj;
//	vObj vObjAction, vObjQty, vObjPrice;
	Vector<string> vObjAction, vObjQty, vObjPrice;
public:
	history();
	~history();
	friend istream &operator>>(istream &in, history &H);
	const Vector<string>& getObjAction() const { return vObjAction; };
	const Vector<string>& getObjPrice() const { return vObjPrice; };
	const Vector<string>& getObjQty() const { return vObjQty; };
	string eraseSP(string, char);
};

#endif
