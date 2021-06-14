#ifndef date_h
#define date_h

#include "Vector.h"
//#include "History.h"

using namespace std;

class Date
{
protected:
	Vector<int> vObjDay, vObjMonth, vObjYear;
public:
	Date();
	void setDateStr(string);
	/*const Vector<int>& getDay() const { return vObjDay; };
	const Vector<int>& getMonth() const { return vObjMonth; };
	const Vector<int>& getYear() const { return vObjYear; };*/
	~Date();
};

#endif
