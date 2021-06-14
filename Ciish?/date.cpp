#include "date.h"

Date::Date()
{

}

void Date::setDateStr(string strDate)
{
	int date, start =0;
	
//	date = atoi(strDate.substr(start, 2).c_str());
	date = stoi(strDate.substr(start, 2));
	vObjDay.insert(date);

//	date = atoi(strDate.substr(start+3, 2).c_str());
	date = stoi(strDate.substr(start+3, 2));
	vObjMonth.insert(date);

//	date = atoi(strDate.substr(start+6, 4).c_str());
	date = stoi(strDate.substr(start+6, 4));
	vObjYear.insert(date);
}

Date::~Date()
{

}