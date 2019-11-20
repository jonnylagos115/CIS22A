/*
** Jonathan Lagos
** CIS22A
** Assignment 9
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void 	        parse_inputData(int[], string);
void            parse_calculatedData(int[]);
char			get_letter_grade(int);
char		    get_suffix(int grade_percent, int grade);

int main()
{
	const int       setwidthValues[7] = {5, 5, 5, 4, 6, 5, 2};
	int             arrData[20] = {};
	int 			index = 0, i;
	ifstream 		inputFile;
	ofstream		outputFile;
	string			line;

	inputFile.open("ass7data.txt");
	outputFile.open("studentReport.txt");
	if (inputFile.fail() || outputFile.fail()){
		cout << "An error has occured when opening file\n";
		exit(1);
	}
	outputFile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
	outputFile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;
	while (getline(inputFile, line))
	{
	    parse_inputData(arrData, line);
	    parse_calculatedData(arrData);
		if (!(arrData[0] / 10000000)) outputFile << 0; //Accounted for leading 0 of sID
		outputFile << arrData[0] << " "; //writing student ID
	    for (i = 1; i < 18; i++)
		{
			if (i >= 1 && i <= 11)
				outputFile << setw(3) << arrData[i]; //writng all 11 assignments points
			else if (i >= 12 && i <= 17) //writing assignment total, midterm, final, lex, total points, and percent
			{
				if (i == 12) //I swap between assignment total & midterm when writing to outputfile
					outputFile << setw(setwidthValues[index++]) << arrData[15];
				if (i == 15) 
					i++;
				outputFile << setw(setwidthValues[index++]) << arrData[i];
			}
		}
		outputFile << setw(setwidthValues[index++]) << static_cast<char>(arrData[i++]); //writing letter grade
		outputFile << static_cast<char>(arrData[i]) << endl; //writing letter grade suffix
		index = 0;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}

void 	       parse_inputData(int arrData[], string line)
{
	unsigned short index = -1, i = 0;

	while (++index < 14)
	{
	    i = line.find_first_of(' '); //locate first occurence of ' ', I use that index as the number of digits of the current integer
        arrData[index] = stoi(line.substr(0, i)); //get substring then convert to integral value
        line = line.substr(i); //update string line
        i = line.find_first_not_of(' '); //skip over spaces to the first available digit
        line = line.substr(i); //update string line
	}
    arrData[index] = stoi(line); //the last value to insert from input file
}

void            parse_calculatedData(int arrData[])
{
    const unsigned short max_p = 400;
    int t_asspoints = 0, lowest_p = 20, index = 0,
    total_points = 0, percent_t, grade;

    while (++index < 12)
    {
        t_asspoints += arrData[index];
        if (lowest_p > arrData[index]) lowest_p = arrData[index];
    }
    while (index < 15)
	{
        total_points += arrData[index++];
	}
	t_asspoints -= lowest_p;
    total_points += t_asspoints;
    arrData[index++] = t_asspoints;
	arrData[index++] = total_points;
    percent_t = round((static_cast<double>(total_points) / static_cast<double>(max_p)) * 100.);
    arrData[index++] = percent_t;
    grade = get_letter_grade(percent_t);
	arrData[index++] = grade;
    arrData[index] = get_suffix(percent_t, grade);
}

char			get_letter_grade(int grade_percent)
{
	char grade;

	switch (grade_percent / 10){
		case 10:
		case 9:
			grade = 'A';
			break;
		case 8:
			grade = 'B';
			break;
		case 7:
			grade = 'C';
			break;
		case 6:
			grade = 'D';
			break;
		default:
			grade = 'F';
	}
	return (grade);
}

char		    get_suffix(int grade_percent, int grade)
{
	int remainder;

	remainder = grade_percent % 10;
	if ((remainder == 9 || remainder == 8 || grade_percent == 100) && grade != 'F')
		return '+';
	else if (remainder == 1 || (remainder == 0 && grade_percent != 100 && grade != 'F'))
		return '-';
    return ' ';
}