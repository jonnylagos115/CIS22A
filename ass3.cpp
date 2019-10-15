/*
** Jonathan Lagos
** CIS22A
** Assignment 3
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int	main()
{
	string purchase_date, sell_date, stock_ticker;
	int initial_i, nbr_of_shares;
	float purchase_p, sell_p, val_share_sold, cash, gain, percent_gain;

	initial_i = 10000;
	stock_ticker = "WMT";
	purchase_date = "01/02/19";
	cout << "Enter the purchase price => ";
	cin >> purchase_p;

	cout << "Enter the sell date (mm/dd/yy) => ";
	cin >> sell_date;

	cout << "Enter the sell price => ";
	cin >> sell_p;

	nbr_of_shares = initial_i / purchase_p;
	val_share_sold = sell_p * nbr_of_shares;
	cash = initial_i - (nbr_of_shares * purchase_p);
	gain = val_share_sold + cash - static_cast<float>(initial_i);
	percent_gain = gain / static_cast<float>(100);
	cout << "\nStock Ticker: " << stock_ticker << "\n\n";

	cout << "Purchase Date: " << purchase_date << endl;
	cout << "Purchase Price: $" << purchase_p << endl;
	cout << "Number of Shares Purchased: " << nbr_of_shares << "\n\n";

	cout << setprecision(2);
	cout << fixed;
	cout << "Sell Date: " << sell_date << endl;
	cout << "Sell Price: $" << sell_p << endl;
	cout << "Value of Shares Sold: $" << val_share_sold << "\n\n";

	cout << "Gain: $" << gain << endl;
	cout << "Percent Gain: " << setprecision(1) << percent_gain << "%\n";
	return 0;
}