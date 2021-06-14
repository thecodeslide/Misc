#ifndef port_h
#define port_h

#include "History.h"
#include "date.h"

using namespace std;

const int SIZE = 7;

class Port:public Date
{
	history hist;
	Vector<string> vObjSym;
public:
	Port();
	~Port();
	friend istream &operator >> (istream& in, Port& P);
	void setDate(string);
	
	const Vector<string>& getObjSym() const { return vObjSym; };
	/*const Vector<int>& getYear() const { return Date::getYear(); };
	const Vector<int>& getMonth() const { return Date::getMonth(); };
	const Vector<int>& getDay() const { return Date::getDay(); };*/
	const Vector<string>& getObjAction() const { return hist.getObjAction(); };
	const Vector<string>& getObjPrice() const { return hist.getObjPrice(); };
	const Vector<string>& getObjQty() const { return hist.getObjQty(); };
	string eraseSP(string, char);
//	int intQty(string);
	bool sumCapitalGain();
	bool calcCapitalGain(int, int, string, int, int, int, int*, double*, int);
	bool printMonthShares(int, double, int) const;
	bool printCapitalGain(double, int, int, string, int) const;
//	bool printMonthCapitalGain(int, double, double, int) const;
	bool monthSharesBought(int, int, string);
	bool monthCapitalGain(int, int);
};

#endif
