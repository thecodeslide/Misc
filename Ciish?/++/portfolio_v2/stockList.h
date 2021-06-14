#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <iostream>
#include <fstream>
#include "Portfolio.h"
#include "BST.h"
#include <map>
#include <string>
#include <utility>

using namespace std;

class stockList:public binaryTree<Port>
{
public:
void getSharesYear(string &);
void getSharesMonth(string &, string &);
void showSelection();

bool stockCheckYear (string) const;
bool YearSearch(string);

void searchYearList  (string , bool& , Node<Port>* &) const;
};

#endif
