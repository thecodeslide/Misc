#ifndef date_h
#define date_h

#include "BST.h"
#include <string>

using namespace std;

class Date
{
protected:
	string vObjDay, vObjMonth, vObjYear;
public:
	Date();
	Date(string date, string month, string year);
	friend ostream& operator<< (ostream&, const Date&);
	Date(string year);
	void setDate(string, string, string);
	void setDateStr(string);

	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	bool equalDate(const Date&) const;
	const string& getDay() const { return vObjDay; };
	const string& getMonth() const { return vObjMonth; };
	const string& getYear() const { return vObjYear; };
	~Date();
};

#endif
