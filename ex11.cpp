/*
** Jonathan Lagos
** CIS22A
** Lab Exercise 11
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <fstream>
using namespace std;

void	swap(int&, int&);
void	sort_dataArr(int[], unsigned short);
void	print_sID(int[], unsigned short, unsigned short start = 0);
bool	search_sID(int[], int, unsigned short);

int main()
{
    ifstream    fin;
    string      line;
    int         dataArr[50] = {}, sID;
    unsigned short index = -1;

    fin.open("ass6data.txt");
    if (fin.fail())
    {
        cerr << "An error has occured when opening file\n";
        exit(1);
    }
    while (getline(fin, line))
        dataArr[++index] = stoi(line.substr(0, 8));
	sort_dataArr(dataArr, 50);
	print_sID(dataArr, 5);
	print_sID(dataArr, 5, 45);
	for (unsigned short i = 0; i < 3; i++)
	{
		cout << "Enter a student ID to search for. (0 to exit) ";
		cin >> sID;
		if (sID == 0)
			break ;
		cout << sID;
		if (search_sID(dataArr, sID, 50))
			cout << " is  a valid student ID." << endl;
		else
			cout << " is not a valid student ID." << endl;
	}
    fin.close();
    return 0;
}

void	sort_dataArr(int dataArr[], unsigned short sizeArr)
{
	unsigned short i = -1;

	while (++i < sizeArr)
	{
		if (i != sizeArr - 1 && dataArr[i] > dataArr[i + 1])
		{
			swap(dataArr[i], dataArr[i + 1]);
			i = -1;
		}
	}
}

void	print_sID(int dataArr[], unsigned short len, unsigned short start)
{
	int digitlen;

	for (unsigned short i = start; i < (len + start); i++)
	{
		digitlen = to_string(dataArr[i]).length();
		if (digitlen != 8)
		{
			digitlen = 8 - digitlen;
			while (digitlen--)
				cout << 0;
		}
		cout << dataArr[i] << endl;
	}
}

bool	search_sID(int dataArr[], int sID, unsigned short sizeArr)
{
	for (unsigned short i = 0; i < sizeArr; i++)
		if (dataArr[i] == sID)
			return true;
	return false;
}

void	swap(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}