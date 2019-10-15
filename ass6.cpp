/*
** Jonathan Lagos
** CIS22A
** Assignment 6
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	const unsigned short max_p = 400;
	ifstream 		inputFile;
	ofstream		outputFile;
	stringstream	ss;
	string			line, buffer;
	char			grade;
	unsigned short	points, ass_p, lowest_p, total_p, 
	percent_t, remainder, nbr_As, nbr_Bs, nbr_Cs, nbr_Ds,
	nbr_Fs;

	nbr_As = nbr_Bs = nbr_Cs = nbr_Ds = nbr_Fs = 0;
	inputFile.open("ass6data.txt");
	outputFile.open("studentReport.txt");
	if (inputFile.fail() || outputFile.fail()){
		cout << "An error has occured when opening file\n";
		exit(1);
	}
	outputFile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
	outputFile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;
	while (getline(inputFile, line)) //I read through the input file one line at a time in each iteration
	{
		ss.str(line);
		getline(ss, buffer, ' ');
		outputFile << buffer << setw(4);
		ass_p = 0;
		lowest_p = 20;
		total_p = 0;
		for (unsigned short i = 0; i < 11; i++){
			getline(ss, buffer, ' ');
			if (buffer.compare("") == 0) getline(ss, buffer, ' ');
			points = stoi(buffer);
			ass_p += points;
			if (lowest_p > points) lowest_p = points;
			outputFile << buffer << setw(3);
		}
		ass_p -= lowest_p;
		total_p += ass_p;
		outputFile << setw(5) << ass_p << setw(5);
		for (unsigned short i = 0; i < 2; i++){
			ss.ignore();
			getline(ss, buffer, ' ');
			if (buffer.compare("") == 0) getline(ss, buffer, ' ');
			total_p += stoi(buffer);
			outputFile << buffer << setw(5);
		}
		getline(ss, buffer, '\r'); //carriage return is set to be delimiter at the end of stream
		total_p += stoi(buffer);
		outputFile << setw(4) << buffer << setw(6) << total_p;
		percent_t = round((static_cast<float>(total_p) / static_cast<float>(max_p)) * static_cast<float>(100));
		outputFile << setw(5) << percent_t;
		switch (percent_t / 10){
			case 10:
			case 9: 
				grade = 'A';
				nbr_As++;
				break;
			case 8: 
				grade = 'B';
				nbr_Bs++;
				break;
			case 7: 
				grade = 'C';
				nbr_Cs++;
				break;
			case 6: 
				grade = 'D';
				nbr_Ds++;
				break;
			default: 
				grade = 'F';
				nbr_Fs++;
		}
		outputFile << setw(2) << grade;
		remainder = percent_t % 10;
		if ((remainder == 9 || remainder == 8 || percent_t == 100) && grade != 'F')
			outputFile << "+";
		else if (remainder == 1 || (remainder == 0 && percent_t != 100 && grade != 'F'))
			outputFile << "-";
		outputFile << endl;
		ss.str(string());
	}
	for (unsigned short i = 0; i < 5; i++)
	{
		cout << "The number of ";
		switch (i)
		{
			case 4:
				cout << "F's = " << nbr_Fs << endl;
				break;
			case 3:
				cout << "D's = " << nbr_Ds << endl;
				break;
			case 2:
				cout << "C's = " << nbr_Cs << endl;
				break;
			case 1:
				cout << "B's = " << nbr_Bs << endl;
				break;
			case 0:
				cout << "A's = " << nbr_As << endl;
		}

	}
	inputFile.close();
	outputFile.close();
	return 0;
}