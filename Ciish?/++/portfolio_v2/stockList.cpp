#include <iostream>
#include <string>
#include "stockList.h"

using namespace std;

bool stockList::stockCheckYear(string year) const
{
    bool found = false;
    Node<Port> *location;

    searchYearList(year, found, location);

    return found;
}

void stockList::searchYearList(string year, bool& found, Node<Port>* &current) const
{
    found = false;   
   
    Port temp;

    temp.setStock("", "", year, "", "", "", "");

    if (root == NULL)  //tree is empty
        cout << "Cannot search an empty list. " << endl;
    else
    {
        current = root; //set current point to the root node 
                        //of the binary tree
        found = false;  //set found to false

        while (current != NULL && !found) //search the tree
            if (current->info == temp)    //item is found
                found = true;
            else if (current->info > temp)
                current = current->leftLink;
            else
                current = current->rightLink;
    } //end else
} //end

void stockList::getSharesYear(string &year)
{
	cout << "Get data for year of: ";
	cin >> year;
}

void stockList::getSharesMonth(string &year, string &month)
{
	getSharesYear(year);
	
	cout << "Get total number and cost of shares bought/sold for month of(1-12): ";
	cin >> month;
}

void stockList::showSelection()
{	
	cout << "*** Please choose one of the menu options shown below ***" << endl;
    cout << "To select an item, enter\n " << endl;
    cout << "1: Show capital gain (or loss) for the whole year" << endl;
    cout << "2: For a given month, the number of shares bought that month and the cost" << endl;
	cout << "3: For a given month, the number of shares sold and the capital gain (or loss)" << endl;
    cout << "4: Exit the program" << endl;
}