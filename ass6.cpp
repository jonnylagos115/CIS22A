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
	unsigned short	points, ass_p, lowest_p, total_p, 
	percent_t, remainder, nbr_As, nbr_Bs, nbr_Cs, nbr_Ds,
	nbr_Fs;
	ifstream 		inputFile;
	ofstream		outputFile;
	string			line;
	char			grade;

	nbr_As = nbr_Bs = nbr_Cs = nbr_Ds = nbr_Fs = 0;
	inputFile.open("ass6data.txt");
	outputFile.open("studentReport.txt");
	if (inputFile.fail() || outputFile.fail()){
		cout << "An error has occured when opening file\n";
		exit(1);
	}
	outputFile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
	outputFile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;
	while (getline(inputFile, line)) //Reading through the input file one line at a time for each iteration
	{
		outputFile << line.substr(0, 8); //writing student IDs
		ass_p = 0;
		lowest_p = 20;
		total_p = 0;
		outputFile << "  " << line.substr(9, 32); //writing all 11 assignment points
		line = line.substr(9); //update string line by assigning substring, truncates previously parsed characters
		for (unsigned short i = 0; i < 11; i++){ //adding up all ass points
			points = stoi(line.substr(0, 2)); //stoi() accepts a string type as argument and converts it to an integral value, then its returned
			ass_p += points;
			if (lowest_p > points) lowest_p = points; //Tracks the lowest point value
			line = line.substr(3); //updating string line
		}
		ass_p -= lowest_p;
		total_p += ass_p;
		outputFile << setw(5) << ass_p; //writing sum of ass points
		outputFile << setw(5) << line.substr(0, 3); // writing midterm points
		total_p += stoi(line.substr(0, 3)); //adding midterm points to total points
		line = line.substr(3); //updating string line
		outputFile << setw(5) << line.substr(0, 4); //writing finals points
		total_p += stoi(line.substr(0, 4)); //adding finals points to total points
		line = line.substr(5); //updating string line
		outputFile << setw(4) << line.substr(0, 2); //writing LEx points
		total_p += stoi(line.substr(0, 3)); //adding LEx points to total points
		outputFile << setw(6) << total_p; //writing total points
		percent_t = round((static_cast<double>(total_p) / static_cast<double>(max_p)) * 100.);
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