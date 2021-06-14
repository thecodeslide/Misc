#include <iostream>
#include <fstream>
#include "Portfolio.h"
//#include <vector>
//#include <cstdlib>

using namespace std;

void showSelection();
void getSharesMonth(int &, int &, string &);

int main()
{
	ifstream iFile( "shared-data.txt" );
	
	if( !iFile )
	{
		cout << "File does not exist." << endl;
		return -1;
	}

	Port P;
	iFile >> P;
	iFile.close();

	showSelection();

	int choice;
	while(cin >> choice)
	{
		int month, year;
		string symbol;
		
		if(choice == 4)
		{
			if(iFile.fail())
			{
				cerr << "\nThe file could not be closed!";
				return 1;
			}
			else
				cout << "\nThe file was closed successfully!";

			cout << " Exiting Program" << endl;
			return 0;
		}
		else
		{
			switch(choice)
			{
			case 1:
				if(!P.sumCapitalGain())
					cout << endl << "There are no data for this year. Please try again." << endl <<endl;
				break;
			case 2:
				getSharesMonth(month, year, symbol);
				if(!P.monthSharesBought(month, year, symbol))
					cout << endl << "There are no data for the chosen month of this year. Please try again." << endl <<endl;
				break;
			case 3:
				getSharesMonth(month, year, symbol);
				if(!P.monthCapitalGain(month, year))
					cout << endl << "There are no data for the chosen month of this year. Please try again." << endl <<endl;
				break;
			default:
				cout << "\nInvalid selection.\n" << endl;
			}
			showSelection();
		}
	}
	
	return 0;
}

void showSelection()
{	
	cout << "*** Please choose one of the menu options shown below ***" << endl;
    cout << "To select an item, enter\n " << endl;
    cout << "1: Show capital gain (or loss) for the whole year" << endl;
    cout << "2: For a given month, the number of shares bought that month and the cost" << endl;
	cout << "3: For a given month, the number of shares sold and the capital gain (or loss)" << endl;
    cout << "4: Exit the program" << endl;
}

void getSharesMonth(int &month, int &year, string &sym)
{
//	int month;

	cout << "Get total number and cost of shares bought/sold for month of(1-12): ";
	cin >> month;
	year = 2011;
	sym = "ABC";
//	return month;
}
