#include <iostream>
#include <fstream>
#include "Portfolio.h"
#include "BST.h"
#include "date.h"
#include <map>
#include <string>
#include <utility>
#include "stockList.h"

using namespace std;

int main()
{
	ifstream iFile( "shared-data.txt" );
	
	if( !iFile )
	{
		cout << "File does not exist." << endl;
		return -1;
	}

	Port P;
	Date D;
	stockList list;

	typedef multimap<Date, Port> stock;
	stock stockMap, *ptrStockMap;

	for(unsigned c = 0; c < SIZE; c++)
	{
		iFile >> P;
		stockMap.insert(make_pair(Date(P.getYear()), Port(P.getDay(), P.getMonth(), P.getYear(), P.getObjSym(), P.getObjAction(), P.getObjQty(), P.getObjPrice())));
		list.insert(P);
	}

	iFile.close();

	list.showSelection();

	int choice;
	string symbol, month, year;
	ptrStockMap = &stockMap;

	while(cin >> choice)
	{
			switch(choice)
			{
			case 1:
				list.getSharesYear(year);
				if(!list.stockCheckYear(year))
					cout << endl << "There are no data for this year. Please try again." << endl << endl;
				else if(!P.sumCapitalGain(year, ptrStockMap))
					cout << endl << "There are no data for this year. Please try again." << endl << endl;
				break;
			case 2:
				list.getSharesMonth(year, month);
				if(!list.stockCheckYear(year))
					cout << endl << "There are no data for the chosen month or year. Please try again." << endl << endl;
				else if(!P.monthSharesBought(year, month, stockMap))
					cout << endl << "There are no data for the chosen month or year. Please try again." << endl << endl;
				break;
			case 3:
				list.getSharesMonth(year, month);
				if(!list.stockCheckYear(year))
					cout << endl << "There are no data for the chosen month or year. Please try again." << endl << endl;
				else 
					P.monthCapitalGain(year, month, ptrStockMap);
//					cout << endl << "3 There are no data for the chosen month or year. Please try again." << endl << endl;
				break;
			case 4:
				if(iFile.fail())
				{
					cerr << "\nThe file could not be closed!";
					return 1;
				}
				cout << "\nThe file was closed successfully!";
				cout << " Exiting Program" << endl;
				return 0;
			default:
				cout << "\nInvalid selection.\n" << endl;
			}
			list.showSelection();
	}
	
	return 0;
}
