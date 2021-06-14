#ifndef port_h
#define port_h

#include "History.h"
#include "date.h"
#include <map>
#include <list>

using namespace std;

/**
 * \brief 	  Class to get input for symbol.
 * \details   This class is used to extract symbol and date from file and insert into vector array, send date to Date class.
 * \author    xxxx
 * \version   0.1.3
 * \date      20xx
 * \pre       First read in the input file and extract symbol data.
 * \post 	  Calculates capital gain/loss or number of shares sold/bought
 * \bug       Nothing to show
 * \warning   Nothing to show
 * \copyright GNU Public License.
 */
class Port:public Date
{
	/**
	 * A private variable.
	 * This is a data type class variable of class history for composition.
	 */
	history hist;

	/**
	 * A private variable.
	 * This is to store x-code.
	 */
	string vObjSym;

	/**
	 * A private variable.
	 * This is used to pass and declare multimap variables.
	 */
	typedef multimap<Date, Port> stock;
public:
	/**
	 * The default constructor.
	 * This is the constructor for class Port.
	 */
	Port();


	Port(string, string, string, string, string, string, string);

	/**
	 * A destructor.
	 * This is the destructor for class Port
	 */
	~Port();

	/**
	 * A friend member taking two arguments and overloading the extraction operator.
	 * @see monthCapitalGain()
	 * @param in an input stream.
	 * @param P a class data type of class Port.
	 * @retval in the input stream object
	 */
	friend istream &operator >> (istream& in, Port& P);

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see operator>>()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @param string year the data type for third argument
	 * @param string symbol the data type for fourth argument
	 * @param string action the data type for fifth argument
	 * @param string qty the data type for sixth argument
	 * @param string price the data type for seventh argument
	 * @retval void returns nothing the data type for first argument
	 */
	void setStock(string, string, string, string, string, string, string);

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see operator>>()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @param string year the data type for third argument
	 * @param string symbol the data type for fourth argument
	 * @param string action the data type for fifth argument
	 * @param string qty the data type for sixth argument
	 * @param string price the data type for seventh argument
	 * @retval void returns nothing the data type for first argument
	 */
	void setDate(string);

	//@{
	/**
	 * 3 inline constant members taking nothing and returning a string
	 * @see getMonth()
	 * @see getYear()
	 * @retval vObjSym the x-code
	 */
	const string& getObjSym() const { return vObjSym; };
	/**
	 * @retval vObjAction the action
	 */
	const string& getObjAction() const { return hist.getObjAction(); };
	/**
	 * @retval vObjPrice the price
	 */
	const string& getObjPrice() const { return hist.getObjPrice(); };
	/**
	 * @retval vObjQty the object
	 */
	const string& getObjQty() const { return hist.getObjQty(); };
	//@}

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see operator>>()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @retval void returns nothing the data type for first argument
	 */
	string eraseSP(string, char);

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see operator>>()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @retval void returns nothing the data type for first argument
	 */
	bool sumCapitalGain(string, stock *);

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see operator>>()
	 * @param day an integer
	 * @param month a string
	 * @param year a string
	 * @param symbol a string
	 * @param action a string
	 * @param qty an integer
	 * @param price an integer
	 * @param priceSold a double
	 * @param totalQty an integer
	 * @param stockList data type of stock
	 * @param codeSell a string
	 * @see Port()
	 * @see ~Port()
	 * @see operator>>()
	 * @see setStock()
	 * @see setDate()
	 * @see getObjSym()
	 * @see getObjAction()
	 * @see getObjPrice()
	 * @see getObjQty()
	 * @see eraseSP()
	 * @see sumCapitalGain()
	 * @see printMonthShares()
	 * @see printCapitalGain()
	 * @see monthSharesBought()
	 * @see monthCapitalGain()
	 * @see hist()
	 * @see vObjSym()
	 * @retval boolean true or false
	 */
	bool calcCapitalGain(int, string, string, string *, string *, int, int*, double*, int, const stock &, string *);

	/**
	 * A costant member taking 6 arguments and returning a boolean value
	 * @see calcCapitalGain()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @retval boolean true or false
	 */
	bool printMonthShares(int, double, string, int, string*, string*) const;

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see printMonthShares()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @retval boolean true or false
	 */
	bool printCapitalGain(double, int, string, string, int) const;

	/**
	 * A normal member taking 7 strings to set share details and not returning anything
	 * @see printCapitalGain()
	 * @param string day the data type for first argument
	 * @param string month the data type for second argument
	 * @retval boolean true or false
	 */
	bool monthSharesBought(string, string, const stock&);

	/**
	 * A normal member taking 3 arguments and not returning anything
	 * @see monthSharesBought()
	 * @param string year the data type for first argument
	 * @param string month the data type for second argument
	 * @param stock *stockList the data type for third argument
	 * @retval void returns nothing
	 */
	void monthCapitalGain(string, string, stock *);
};

#endif