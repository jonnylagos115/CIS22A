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

void 	        insert_studentData(string);
int             access_studentData(unsigned short, unsigned short, int data = 0);

int main()
{
	//const unsigned short max_p = 400;
	const int       setwidthValues[8] = {2, 5, 5, 5, 4, 6, 5, 2};
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
	    insert_studentData(line);
	    outputFile << access_studentData(index, 2) << setw(setwidthValues[index]);
	    index++;
		for (index; index < 11; index++)
            outputFile << setw(3) << access_studentData(index, 2);
	}
	inputFile.close();
	outputFile.close();
	return 0;
}

void 	        insert_studentData(string line)
{
	unsigned short index = 0, i = 0;

	while (index < 14)
	{
	    i = line.find_first_of(' ');
        access_studentData(index++, 1, stoi(line.substr(0, i)));
        line = line.substr(i); //update string line
        i = line.find_first_not_of(' ');
        line = line.substr(i);
	}
    access_studentData(index, 1, stoi(line));
}

int      access_studentData(unsigned short index, unsigned short option, int data)
{
    static int  arrData[20];
    int         ret = 0;

    switch(option)
    {
        case 1:
            arrData[index] = data;
            break;
        case 2:
            ret = arrData[index];
    }
    return (ret);
}

short	write_add_otherpoints(string& line, ofstream& outputFile)
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
