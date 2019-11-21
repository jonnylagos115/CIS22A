/*
** Jonathan Lagos
** CIS22A
** Assignment 10
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void			parse_inputData(string line, string[], double[], double[]);
int				calculateUpDays(double[], double[], int);
int				calculateDownDays(double[], double[], int);
double			findMaxClose(double[], int);
double			findAverageClose(double[], int);
unsigned short	find_n_of(string&, char, unsigned short, unsigned short);

int main()
{
	const int	marketDays[8] = {5, 10, 20, 50, 100, 200, 500, 1000};
	const int	percentage = 100;
    ifstream	fin;
    ofstream	fout;
    string		line;
	string		marketdatesArr[1000] = {};
	double		openpriceData[1000] = {}, closepriceData[1000] = {}, gain;
	int 		index = -1, start_period;

    fin.open("WMT.csv");
    fout.open("djiasReport.txt");
    if (fin.fail() || fout.fail()){
		cerr << "An error has occured when opening file\n";
		exit(1);
	}
	getline(fin, line); //skip over first line with labels
	fout << setprecision(2) << fixed;
	fout << "Stock:  WMT" << endl;
    while (getline(fin, line))
		parse_inputData(line, marketdatesArr, openpriceData, closepriceData);
	fout << "Current Date: " << marketdatesArr[0] << endl;
	fout << "Current Close: $" << closepriceData[0] << endl; 
	fout << "Market Days  Start Date  Close Price  Up Days  Down Days   Gain  Pct Gain  Max Close  Avg Close" << endl;
	fout << "-----------  ----------  -----------  -------  ---------   ----  --------  ---------  ---------" << endl;
	for (unsigned short i = 0; i < 8; i++)
	{
		start_period = index + marketDays[i];
		gain = closepriceData[0] - closepriceData[start_period];
		fout << setw(11) << marketDays[i];
		fout << setw(12) << marketdatesArr[start_period];
		fout << setw(10) << closepriceData[start_period];
		fout << setw(10) << calculateUpDays(openpriceData, closepriceData, marketDays[i]);
		fout << setw(10) << calculateDownDays(openpriceData, closepriceData, marketDays[i]);
		fout << setw(10) << gain;
		fout << setw(9) << (gain / closepriceData[start_period]) * percentage << "%";
		fout << setw(11) << findMaxClose(closepriceData, marketDays[i]);
		fout << setw(11) << findAverageClose(closepriceData, marketDays[i]) << endl;
	}
    fin.close();
    fout.close();
    return 0;
}

int			calculateUpDays(double openpriceData[], double closepriceData[], int nbrOfDays)
{
	int updays = 0;

	for (unsigned short i = 0; i < nbrOfDays; i++)
		if (closepriceData[i] > openpriceData[i])
			updays++;
	return updays;
}

int			calculateDownDays(double openpriceData[], double closepriceData[], int nbrOfDays)
{
	int downdays = 0;

	for (unsigned short i = 0; i < nbrOfDays; i++)
		if (openpriceData[i] > closepriceData[i])
			downdays++;
	return downdays;
}

double		findMaxClose(double closepriceData[], int nbrOfDays)
{
	double	maxclose = closepriceData[0];

	for (unsigned short i = 0; i < nbrOfDays; i++)
		if (closepriceData[i] > maxclose)
			maxclose = closepriceData[i];
	return (maxclose);
}

double		findAverageClose(double closepriceData[], int nbrOfDays)
{
	double	avgclose, sum = 0;

	for (unsigned short i = 0; i < nbrOfDays; i++)
		sum += closepriceData[i];
	avgclose = sum / nbrOfDays;
	return avgclose;
}

void		parse_inputData(string line, string marketdatesArr[], double openpriceData[], double closepriceData[])
{
	static unsigned short index = 1000;
	unsigned short pos;

	pos = line.find_first_of(',');
	marketdatesArr[--index] = line.substr(0, pos++); //storing market date
	line = line.substr(pos);
	pos = line.find_first_of(',');
	openpriceData[index] = stod(line.substr(0, pos++)); //storing open price
	line = line.substr(pos);
	pos = find_n_of(line, ',', pos, 2); //skipping over high and low price
	closepriceData[index] = stod(line.substr(0, pos)); //storing close price
}

unsigned short	find_n_of(string& line, char s, unsigned short pos, unsigned short n)
{
	for (unsigned short i = 0; i < n; i++)
	{
		pos = line.find_first_of(s);
		line = line.substr(++pos);
	}
	return pos;
}