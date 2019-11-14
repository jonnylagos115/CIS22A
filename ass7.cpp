/*
** Jonathan Lagos
** CIS22A
** Assignment 7
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

unsigned short 	write_add_asspoints(string& line, ofstream& outputFile);
unsigned short	write_add_otherpoints(string& line, ofstream& outputFile);
char			get_letter_grade(unsigned short grade_percent);
void			write_plus_minus_sign(ofstream& outputFile, unsigned short grade_percent, char grade);
void			print_student_avg(double avg_of_total_p, double avg_of_percent_t, unsigned short nbr_of_students);
void			print_student_highest(string highestStudentID, unsigned short highest_p, double highest_percent);
void			print_student_lowest(string lowestStudentID, unsigned short lowest_p, double lowest_percent);

int main()
{
	const unsigned short max_p = 400;
	unsigned short	total_p, percent_t, nbr_As,
	nbr_Bs, nbr_Cs, nbr_Ds, nbr_Fs, nbr_of_students,
	highest_p, lowest_p;
	double			avg_of_total_p, avg_of_percent_t, highest_percent, lowest_percent;
	ifstream 		inputFile;
	ofstream		outputFile;
	string			line, highestStudentID, lowestStudentID, sID;
	char			grade;

	nbr_As = nbr_Bs = nbr_Cs = nbr_Ds = nbr_Fs = 0;
	nbr_of_students = 0;
	avg_of_total_p = avg_of_percent_t = 0.;
	highest_p = 0;
	lowest_p = 400;
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
		sID = line.substr(0, 8);
		outputFile << sID; //writing student IDs
		total_p = 0;
		total_p = write_add_asspoints(line, outputFile); //calculating sum of ass points
		outputFile << setw(5) << total_p; //writing sum of ass points
		total_p += write_add_otherpoints(line, outputFile); //calculating thend writing sum of other points (LEx, midterm, final)
		outputFile << setw(6) << total_p; //writing total points
		percent_t = round((static_cast<double>(total_p) / static_cast<double>(max_p)) * 100.);
		outputFile << setw(5) << percent_t;
		grade = get_letter_grade(percent_t);
		switch (grade){
			case 'A':
				nbr_As++;
				break;
			case 'B':
				nbr_Bs++;
				break;
			case 'C':
				nbr_Cs++;
				break;
			case 'D':
				nbr_Ds++;
				break;
			default:
				nbr_Fs++;
		}
		outputFile << setw(2) << grade;
		write_plus_minus_sign(outputFile, percent_t, grade);
		outputFile << endl;
		nbr_of_students++;
		avg_of_total_p += static_cast<unsigned short>(total_p);
		avg_of_percent_t += percent_t;
		if (total_p > highest_p)
		{
			highest_p = total_p;
			highestStudentID = sID;
			highest_percent = (static_cast<double>(total_p) / static_cast<double>(max_p)) * 100.;
		}
		if (total_p < lowest_p)
		{
			lowest_p = total_p;
			lowestStudentID = sID;
			lowest_percent = (static_cast<double>(total_p) / static_cast<double>(max_p)) * 100.;
		}
	}
	print_student_avg(avg_of_total_p, avg_of_percent_t, nbr_of_students);
	print_student_highest(highestStudentID, highest_p, highest_percent);
	print_student_lowest(lowestStudentID, lowest_p, lowest_percent);
	inputFile.close();
	outputFile.close();
	return 0;
}

unsigned short	write_add_asspoints(string& line, ofstream& outputFile)
{
	unsigned short points, ass_p = 0;
	unsigned short lowest_p = 20;

	outputFile << "  " << line.substr(9, 32); //writing all 11 assignment points
	line = line.substr(9); //update string line by assigning substring, truncates previously parsed characters
	for (unsigned short i = 0; i < 11; i++){ //adding up all ass points
		points = stoi(line.substr(0, 2)); //stoi() accepts a string type as argument and converts it to an integral value, then its returned
		ass_p += points;
		if (lowest_p > points) lowest_p = points; //Tracks the lowest point value
		line = line.substr(3); //updating string line
	}
	ass_p -= lowest_p;
	return (ass_p);
}

unsigned short	write_add_otherpoints(string& line, ofstream& outputFile)
{
	unsigned short total_p = 0;

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

char			get_letter_grade(unsigned short grade_percent)
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

void		write_plus_minus_sign(ofstream& outputFile, unsigned short grade_percent, char grade)
{
	unsigned short remainder;

	remainder = grade_percent % 10;
	if ((remainder == 9 || remainder == 8 || grade_percent == 100) && grade != 'F')
		outputFile << "+";
	else if (remainder == 1 || (remainder == 0 && grade_percent != 100 && grade != 'F'))
		outputFile << "-";
	return;
}

void		print_student_avg(double avg_of_total_p, double avg_of_percent_t, unsigned short nbr_of_students)
{
	cout << setprecision(1) << fixed;
	avg_of_total_p = avg_of_total_p / static_cast<unsigned short>(nbr_of_students);
	avg_of_percent_t = avg_of_percent_t / static_cast<unsigned short>(nbr_of_students);
	cout << "Number of students = " << nbr_of_students << endl;
	cout << "The average total points = " << avg_of_total_p << endl;
	cout << "The average percent total = " << avg_of_percent_t << endl;
}

void		print_student_highest(string highestStudentID, unsigned short highest_p, double highest_percent)
{
	cout << "Highest grade: Id=" << highestStudentID 
	<< "  Points=" << highest_p 
	<< "  Percent=" << highest_percent << "%" << endl;
}

void		print_student_lowest(string lowestStudentID, unsigned short lowest_p, double lowest_percent)
{
	cout << "Lowest grade: Id=" << lowestStudentID 
	<< "  Points=" << lowest_p 
	<< "  Percent=" << lowest_percent << "%" << endl;
}