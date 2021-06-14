#include "Portfolio.h"

Port::Port()
{

}

istream &operator >> (istream& in, Port& P)
{	
	char delim = ',';
	string strPort;

	for(unsigned c = 0; c < SIZE; c++)
	{
		if(in.good())
		{
			getline(in, strPort, delim);
			P.setDate(strPort);
			getline(in, strPort, delim);
			strPort = P.eraseSP(strPort, ' ');
			P.vObjSym.insert(strPort);

			in >> P.hist;
		}
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

bool Port::sumCapitalGain()  // option 1
{
	int len = vObjSym.getLen(), yearBought = 2011, lastDaySold, lastMonthSold, *qtySold = new int[len], countSold = 0;
	string stockSym ("ABC");
	double *priceSold = new double[len]; 

	for(int m=0; m<len; ++m)
	{
		if(vObjYear.atPos(m) == yearBought && getObjSym().atPos(m) == stockSym && getObjAction().atPos(m) == "sell")
		{
			/*qtySold[countSold] =  atoi(getObjQty().atPos(m).c_str());
			priceSold[countSold] = strtod(getObjPrice().atPos(m).c_str(), NULL);*/
			qtySold[countSold] =  stoi(getObjQty().atPos(m));
			priceSold[countSold] = stod(getObjPrice().atPos(m));
			lastDaySold = vObjDay.atPos(m);
			lastMonthSold = vObjMonth.atPos(m);

			++countSold;
		}
	}

	if(countSold > 0)
	{
		if(calcCapitalGain(len, yearBought, stockSym, lastMonthSold, lastDaySold, countSold, qtySold, priceSold, 0))
			return true;
	}

	delete [] qtySold, delete [] priceSold;
	return false;
}

bool Port::calcCapitalGain(int len, int yearBought, string stockSym, int lastMonthSold, int lastDaySold, int countSold, int* qtySold, double* priceSold, int totalQty)
{
	int *qtyBought = new int[len], countBought = 0, j = 0, remainingQty, k = 0;
	double *priceBought = new double[len], totalSum = 0;

		for(int k=0; k<len; ++k)
		{
			if(vObjYear.atPos(k) == yearBought && getObjSym().atPos(k) == stockSym && getObjAction().atPos(k) == "buy" && vObjMonth.atPos(k) <= lastMonthSold && (vObjDay.atPos(k) <= lastDaySold || vObjDay.atPos(k) > lastDaySold))
			{
				/*qtyBought[countBought] = atoi(getObjQty().atPos(k).c_str());
				priceBought[countBought] = strtod(getObjPrice().atPos(k).c_str(), NULL);*/
				qtyBought[countBought] = stoi(getObjQty().atPos(k));
				priceBought[countBought] = stod(getObjPrice().atPos(k));

				++countBought;
			}
		}

		for(; j<countSold; ++j)
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

		delete [] qtyBought, delete [] priceBought, delete [] qtySold, delete [] priceSold;

		if(printCapitalGain(totalSum, countSold, yearBought, stockSym, totalQty))
			return true;
		return false;
}

bool Port::monthSharesBought(int monthBought, int yearBought, string symbol)  // option 2
{
	int qty =0;
	int len = vObjSym.getLen();
	double *sum = new double[len], total = 0;

	for(int j=0; j<len; ++j)
	{
		if(vObjYear.atPos(j) == yearBought && vObjMonth.atPos(j) == monthBought && getObjAction().atPos(j) == "buy" && vObjSym.atPos(j) == symbol)
		{
//			sum[j] = strtod(getObjPrice().atPos(j).c_str(), NULL);
			sum[j] = stod(getObjPrice().atPos(j));
//			sum[j] *= intQty(getObjQty().atPos(j));
			sum[j] *= stoi(getObjQty().atPos(j));
			total += sum[j];
//			qty += intQty(getObjQty().atPos(j));
			qty += stoi(getObjQty().atPos(j));
		}
	}

	delete [] sum;

	if(printMonthShares(qty, total, yearBought))
		return true;
	return false;
}

bool Port::monthCapitalGain(int month, int year)  // option 3
{
	int len = vObjSym.getLen(), *qtySold = new int[len], lastSold = 0, totalSold = 0, monthQtySold = 0;
	string stockSym ("ABC");
	double *priceSold = new double[len];

	for(int j=0; j<len; ++j)
	{
		if(getObjSym().atPos(j) == stockSym && vObjYear.atPos(j) == year && vObjMonth.atPos(j) <= month && getObjAction().atPos(j) == "sell")
		{
			/*qtySold[totalSold] =  atoi(getObjQty().atPos(j).c_str());
			priceSold[totalSold] = strtod(getObjPrice().atPos(j).c_str(), NULL);*/
			qtySold[totalSold] =  stoi(getObjQty().atPos(j));
			priceSold[totalSold] = stod(getObjPrice().atPos(j));
			lastSold = vObjDay.atPos(j);
			++totalSold;
		}
		if(getObjSym().atPos(j) == stockSym && vObjYear.atPos(j) == year && vObjMonth.atPos(j) == month && getObjAction().atPos(j) == "sell")
			//monthQtySold += atoi(getObjQty().atPos(j).c_str());
			monthQtySold += stoi(getObjQty().atPos(j));
	}

	if(monthQtySold > 0)
	{
		if(calcCapitalGain(len, year, stockSym, month, lastSold, totalSold, qtySold, priceSold, monthQtySold))
			return true;
	}
	delete [] priceSold, delete [] qtySold;

	return false;
}

//int Port::intQty(string j)
//{
////	int q = atoi(j.c_str());
//	int q = stoi(j);
//
//	return q;
//}

 // option 1 + 3
bool Port::printCapitalGain(double result, int sellCount, int year, string stock, int monthQty) const
{
	if(sellCount == 0 )
		return false;
	else if(result < 0)
	{
		if(monthQty > 0)
		{
			cout << "\n" << monthQty << " shares sold for this month and capital loss of (-)$" << 0-result << " for " << stock << endl << endl;
			return true;
		}
		cout << "\nCapital loss of (-)$" << 0-result << " for " << stock <<  " for the year " << year << endl << endl;
		return true;
	}
	else
	{
		if(monthQty > 0)
		{
			cout << "\n" << monthQty << " shares sold for this month and capital gain of $" << result << " for " << stock << endl << endl;
			return true;
		}
		cout << "\nCapital gain of $" << result  << " for " << stock << " for the year " << year << endl << endl;
		return true; 
	}
}

 // option 2
bool Port::printMonthShares(int numberShares, double sharesCost, int yearPurchased) const
{
	if(sharesCost>0 && numberShares >0)
	{
		cout << endl << "The total number of shares bought in " << yearPurchased << " for this month is " << numberShares << endl << "The total cost of shares bought in " << yearPurchased << " for this month is $" << sharesCost << endl << endl;
		return true;
	}
	return false;
}

Port::~Port()
{

}
