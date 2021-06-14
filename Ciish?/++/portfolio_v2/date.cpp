#include "date.h"

Date::Date()
{
	vObjDay = "";
	vObjMonth = "";
	vObjYear = "";
}

Date::Date(string day, string month, string year)
{
	vObjDay = day;
	vObjMonth = month;
	vObjYear = year;
}

Date::Date(string year)
{
	vObjYear = year;
}

void Date::setDate(string day, string month, string year)
{
	vObjDay = day;
	vObjMonth = month;
	vObjYear = year;
}

void Date::setDateStr(string strDate)
{
	int start =0;
	string date, sp("0");
	
	vObjDay = strDate.substr(start, 2);
	size_t found = vObjDay.find(sp);
	string::iterator it = vObjDay.begin();

	if (found != string::npos)
		vObjDay.erase(it+found);// to remove 0.

	vObjMonth = strDate.substr(start+3, 2);
	found = vObjMonth.find(sp);
	it = vObjMonth.begin();
	
	if (found != string::npos)
		vObjMonth.erase(it+found);// to remove 0.

	vObjYear = strDate.substr(start+6, 4);
}

bool Date::operator>(const Date& right) const
{
	return (vObjYear > right.vObjYear);
}

bool Date::operator<(const Date& right) const
{
	return (vObjYear < right.vObjYear);
}

bool Date::operator==(const Date& right) const
{
    return (vObjYear == right.vObjYear);
}

Date::~Date()
{

}