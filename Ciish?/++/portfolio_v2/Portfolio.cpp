#include "Portfolio.h"

Port::Port()
{
	vObjSym = "";
}

Port::Port(string day, string month, string year, string symbol, string action="", string qty="", string price="")
		:Date(day, month, year), hist(action, qty, price)
{
	vObjSym = symbol;
}

void Port::setStock(string day, string month, string year, string symbol, string action, string qty, string price)
{
	vObjSym = symbol;
	hist.setHistory(action, qty, price);
	Date::setDate(day, month, year);
}

istream &operator >> (istream& in, Port& P)
{	
	char delim = ',';
	string strPort, strSym;
		if(in.good())
		{
			getline(in, strPort, delim);
			P.setDate(strPort);
			getline(in, strPort, delim);
			strPort = P.eraseSP(strPort, ' ');
			P.vObjSym = strPort;

			in >> P.hist;
		}

	return in;
}

void Port::setDate(string dDateStr)
{
	Date::setDateStr(dDateStr);
}

string Port::eraseSP(string str, char removeChar)
{
	return str = hist.eraseSP(str, removeChar);
}

bool Port::sumCapitalGain(string yearSold, stock *stockList)  // option 1
{
	int len = stockList->size(),  *qtySold = new int[len], countSold = 0;
	string *lastDaySold = new string[len], *lastMonthSold = new string[len], *codeSell = new string[len];
	double *priceSold = new double[len]; 
	
	stock::iterator s= stockList->begin();
	
	for( s; s!=(*stockList).end(); ++s)
	{
		if((*s).first.getYear() == yearSold && (*s).second.getObjAction() == "sell")
		{
			lastDaySold[countSold] = s->second.vObjDay;
			lastMonthSold[countSold] = s->second.vObjMonth;
			qtySold[countSold] = stoi(s->second.getObjQty());
			priceSold[countSold] = stod(s->second.getObjPrice());
			codeSell[countSold] = s->second.vObjSym;
			++countSold;
		 }
	}

	if(countSold > 0)
	{
		calcCapitalGain(len, yearSold, "", lastMonthSold, lastDaySold, countSold, qtySold, priceSold, 0, *stockList, codeSell);
		return true;
	}

	delete [] qtySold, priceSold;
	return false;
}


bool Port::calcCapitalGain(int len, string yearBought, string stockSym, string *lastMonthSold, string *lastDaySold, int countSold, int* qtySold, 
						double* priceSold, int totalQty, const stock &stockList, string *codeSell)
{
	int *qtyBought = new int[len], countBought = 0, j = 0, remainingQty, k = 0;
	double *priceBought = new double[len], totalSum = 0;
	string *codeBuy = new string[len], *lastDayBought = new string[len], *lastMonthBought = new string[len];

	for(stock::const_iterator s = stockList.begin(); s!=stockList.end(); ++s)
	{
		if(totalQty >0)
		{
				for(int m=0; m<countSold; ++m)
				{
					if(s->first.getYear() == yearBought && s->second.vObjMonth == lastMonthSold[m] && s->second.getObjAction() == "buy" 
						&& s->second.vObjDay <= lastDaySold[m] && s->second.getObjSym() == codeSell[m])
					{
						codeBuy[countBought] = s->second.getObjSym();
						qtyBought[countBought] = stoi(s->second.getObjQty());
						priceBought[countBought] = stod(s->second.getObjPrice());
						++countBought;
					}
				}
		}
		else
		{
			for(int m=0; m<countSold; ++m)
			{
				if(s->first.getYear() == yearBought && s->second.vObjMonth <= lastMonthSold[m] && s->second.getObjAction() == "buy" && 
					(s->second.vObjDay <= lastDaySold[m] || s->second.vObjDay > lastDaySold[m]) && s->second.getObjSym() == codeSell[m])
				{
					qtyBought[countBought] =  stoi(s->second.getObjQty());
					priceBought[countBought] = stod(s->second.getObjPrice());
					lastDayBought[countBought] = s->second.vObjDay;
					lastMonthBought[countBought] = s->second.vObjMonth;

					++countBought;
				}
			}
			string tempMonth, tempDay;
			int tempQty;
			double tempPrice;
			bool flag = true;
			for(int m=0; m<countBought; ++m)
			{
				flag = false;
				for(int n=0; n< countBought-m-1; ++n)
					if(lastMonthBought[n] > lastMonthBought[n+1] || (lastMonthBought[n] == lastMonthBought[n+1] && lastDayBought[n] > lastDayBought[n+1]))
					{
						tempMonth = lastMonthBought[n];
						tempDay =  lastDayBought[n];
						tempQty = qtyBought[n];
						tempPrice = priceBought[n];
						lastMonthBought[n] = lastMonthBought[n+1];
						lastDayBought[n] = lastDayBought[n+1];
						qtyBought[n] = qtyBought[n+1];
						priceBought[n] = priceBought[n+1];
						lastMonthBought[n+1] = tempMonth;
						lastDayBought[n+1] = tempDay;
						qtyBought[n+1] = tempQty;
						priceBought[n+1] = tempPrice;

						flag = true;
					}
				if (flag == true)
					continue;
				else break;
			}
		}
	}
	if(countBought > 0)
	{
			for(j; j<countSold; ++j)
			{
				remainingQty = qtySold[j];
				while(remainingQty > 0)
				{
					if(remainingQty < qtyBought[k])
					{
						totalSum += (priceSold[j] - priceBought[k]) * remainingQty;
						qtyBought[k] -= remainingQty;
						remainingQty = 0;
					}
					else
					{
						remainingQty -= qtyBought[k];
						totalSum += (priceSold[j] - priceBought[k]) * qtyBought[k];
						qtyBought[k] = 0;
						++k;
					}
				}
			}
		if(printCapitalGain(totalSum, countSold, yearBought, stockSym, totalQty))
			return true;
	}
	delete [] qtyBought, priceBought, qtySold, priceSold, codeSell, codeBuy, lastMonthSold, lastDaySold, lastDayBought, lastMonthBought;
	return false;
}

bool Port::monthSharesBought(string yearBought, string monthBought, const stock &stockList)  // option 2
{
	int qty =0, len = stockList.size(), j=0;
	double *sum = new double[len], total = 0;
	string *code = new string[len], *listQty = new string[len];

	for( stock::const_iterator s = stockList.begin(); s!=stockList.end(); ++s)
	{
		if((*s).first.getYear() == yearBought && (*s).second.vObjMonth == monthBought && (*s).second.getObjAction() == "buy")
		{
			code[j] = s->second.vObjSym;
			listQty[j] = s->second.getObjQty();
			sum[j] = stod(s->second.getObjPrice());						
			sum[j] *= stoi(s->second.getObjQty());						
			total += sum[j];											//	sum of price for stocks bought for the month
			qty += stoi(s->second.getObjQty());
			++j;
		 }
	}

	cout << yearBought << " " << monthBought << endl;
	delete [] sum;

	if(printMonthShares(qty, total, yearBought, j, code, listQty))
		return true;
	return false;
}

void Port::monthCapitalGain(string year, string month, stock *stockList)  // option 3
{
	int len = stockList->size(), *qtySold = new int[len], totalSold = 0, monthQtySold = 0, *tempQtySold = new int[len];
	string stockSym = "", *lastMonthSold = new string[len], *lastSold = new string[len], *codeSell = new string[len], *tempCodeSell = new string[len],
		*tempLastSold = new string[len], *tempLastMonthSold = new string[len];
	double *priceSold = new double[len], *priceBought = new double[len], *tempPriceSold = new double[len];

	for(stock::iterator s = stockList->begin(); s!=stockList->end(); ++s)
	{
		if(s->first.getYear() == year && s->second.vObjMonth == month && s->second.getObjAction() == "sell")
		{
			codeSell[totalSold] = s->second.vObjSym;
			tempQtySold[totalSold] = stoi(s->second.getObjQty());
			tempPriceSold[totalSold] = stod(s->second.getObjPrice());
			lastSold[totalSold] = s->second.vObjDay;
			lastMonthSold[totalSold] = s->second.vObjMonth;
			++totalSold;

		}
	}

	if(totalSold > 0)
	{
		for(int i =0; i<totalSold-1; ++i)
		{
			for(int j =i+1; j<totalSold; ++j)
			{
				if(codeSell[i] != codeSell[j])
				{
					codeSell[monthQtySold] = codeSell[j];
					qtySold[monthQtySold] = tempQtySold[j];
					lastMonthSold[monthQtySold] = lastMonthSold[j];
					lastSold[monthQtySold] = lastMonthSold[j];
					++monthQtySold;
				}
				else if(codeSell[i] == codeSell[j])
				{
					codeSell[monthQtySold] = codeSell[j];
					qtySold[monthQtySold] = tempQtySold[i] += tempQtySold[j];

					cout << "tempQtySold[i] " << tempQtySold[i] << " qtySold[monthQtySold] " << qtySold[monthQtySold] <<endl;

					if(lastMonthSold[i] < lastMonthSold[j] || (lastMonthSold[i] == lastMonthSold[j] && lastSold[i] < lastSold[j]))
					{
						lastMonthSold[monthQtySold] = lastMonthSold[i];
						lastSold[monthQtySold] = lastSold[i];
					}
				}
				
			}

			
		}
	//		if(calcCapitalGain(len, year, stockSym, month, lastSold, totalSold, qtySold, priceSold, totalSold, *stockList, codeSell))
//				return true;
	}

	delete [] priceSold, priceBought, qtySold, codeSell, tempQtySold, tempCodeSell, tempLastSold, tempLastMonthSold;
}

 // option 1 + 3
bool Port::printCapitalGain(double result, int sellCount, string year, string stock, int monthQty) const
{
	if(sellCount == 0 )
		return false;
	else if(result < 0)
	{
		if(monthQty > 0) // option 3
		{
			cout << "\n" << monthQty << " shares sold for this month and capital loss of (-)$" << 0-result << " for " << stock << endl << endl;
			return true;
		}
		cout << "\nCapital loss of (-)$" << 0-result << " for the year " << year << endl << endl;
		return true;
	}
	else
	{
		if(monthQty > 0) // option3
		{
			cout << "\n" << monthQty << " shares sold for this month and capital gain of $" << result << " for " << stock << endl << endl;
			return true;
		}
		cout << "\nCapital gain of $" << result  << " for the year " << year << endl << endl;
		return true; 
	}
}

 // option 2
bool Port::printMonthShares(int numberShares, double sharesCost, string yearPurchased, int count, string *code, string *listQty) const
{
	if(sharesCost>0 && numberShares >0)
	{		
		cout << endl;
		for(int i=0; i<count; ++i)
			cout << "X-code of shares bought: " << code[i] << "\tQuantity: " << listQty[i] << endl;

			cout << endl << "The total number of shares bought in " << yearPurchased << " for this month is " << numberShares << endl 
			<< "The total cost of shares bought in " << yearPurchased << " for this month is $" << sharesCost << endl << endl;
		delete [] code, listQty;
		return true;
	}

	delete [] code, listQty;
	return false;
}

Port::~Port()
{

}
