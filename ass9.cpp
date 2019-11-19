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
	//const unsigned short max_p = 400;
	const int       setwidthValues[8] = {4, 5, 5, 5, 4, 6, 5, 2};
	int             arrData[20] = {};
	/*unsigned short	total_p, percent_t, nbr_As,
	nbr_Bs, nbr_Cs, nbr_Ds, nbr_Fs, nbr_of_students,
	highest_p, lowest_p;*/
	//double			avg_of_total_p, avg_of_percent_t, highest_percent, lowest_percent;
	ifstream 		inputFile;
	ofstream		outputFile;
	string			line; //, highestStudentID, lowestStudentID, sID;
	//char			grade;

	/*nbr_As = nbr_Bs = nbr_Cs = nbr_Ds = nbr_Fs = 0;
	nbr_of_students = 0;
	avg_of_total_p = avg_of_percent_t = 0.;
	highest_p = 0;
	lowest_p = 400;*/
	inputFile.open("ass7data.txt");
	outputFile.open("studentReport.txt");
	if (inputFile.fail() || outputFile.fail()){
		cout << "An error has occured when opening file\n";
		exit(1);
	}
	outputFile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
	outputFile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;
	int index = 0;
	if (getline(inputFile, line))
	{
	    parse_inputData(arrData, line);
	    parse_calculatedData(arrData);
	    for (int i = 0; i < 20; i++)
            cout << arrData[i] << " " << endl;
        cin.get();
	    outputFile << arrData[index++]; //Inserting studentID
	    outputFile << setw(setwidthValues[0]) << arrData[index];
		while (index++ < 11)
            outputFile << setw(3) << arrData[index];
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
	    i = line.find_first_of(' ');
        arrData[index] = stoi(line.substr(0, i));
        line = line.substr(i); //update string line
        i = line.find_first_not_of(' ');
        line = line.substr(i);
	}
    arrData[index] = stoi(line);
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
    t_asspoints -= lowest_p;
    arrData[index] = t_asspoints;
    while (++index < 16)
        total_points += arrData[index];
    total_points += t_asspoints;
    arrData[index++] = total_points;
    percent_t = round((static_cast<double>(total_points) / static_cast<double>(max_p)) * 100.);
    arrData[index++] = percent_t;
    grade = get_letter_grade(percent_t);
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

short	write_add_otherpoints(string& line, ofstream& outputFile)
{
	unsigned short total_p = 0, total_ass;

	outputFile << setw(5) << line.substr(0, 3); // writing midterm points
	total_p += stoi(line.substr(0, 3)); //adding midterm points to total points
	line = line.substr(3); //updating string line
	outputFile << setw(5) << line.substr(0, 4); //writing finals points
	total_p += stoi(line.substr(0, 4)); //adding finals points to total points
	line = line.substr(5); //updating string line
	outputFile << setw(4) << line.substr(0, 2); //writing LEx points
	total_p += stoi(line.substr(0, 3)); //adding LEx points to total points
	return (total_p);
}
