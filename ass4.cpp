/*
** Jonathan Lagos
** CIS22A
** Assignment 4
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    const unsigned short max_p = 400;
    unsigned short one_p, two_p, three_p, four_p, five_p, six_p, 
    seven_p, eight_p, nine_p, ten_p, eleven_p, lab_ex_p, midterm_p,
    final_p, ass_p, total_p, lowest_p, remainder, percent_t;
    char grade;

    lowest_p = 20;
    cout << "Enter assignment 1 points ";
    cin >> one_p;

    cout << "Enter assignment 2 points ";
    cin >> two_p;

    cout << "Enter assignment 3 points ";
    cin >> three_p;

    cout << "Enter assignment 4 points ";
    cin >> four_p;

    cout << "Enter assignment 5 points ";
    cin >> five_p;

    cout << "Enter assignment 6 points ";
    cin >> six_p;

    cout << "Enter assignment 7 points ";
    cin >> seven_p;

    cout << "Enter assignment 8 points ";
    cin >> eight_p;

    cout << "Enter assignment 9 points ";
    cin >> nine_p;

    cout << "Enter assignment 10 points ";
    cin >> ten_p;

    cout << "Enter assignment 11 points ";
    cin >> eleven_p;

    cout << "Enter lab exercise points ";
    cin >> lab_ex_p;

    cout << "Enter midterm points ";
    cin >> midterm_p;

    cout << "Enter final points ";
    cin >> final_p;

    if (lowest_p > one_p) lowest_p = one_p;
    if (lowest_p > two_p) lowest_p = two_p;
	if (lowest_p > three_p) lowest_p = three_p;
    if (lowest_p > four_p) lowest_p = four_p;
	if (lowest_p > five_p) lowest_p = five_p;
    if (lowest_p > six_p) lowest_p = six_p;
	if (lowest_p > seven_p) lowest_p = seven_p;
    if (lowest_p > eight_p) lowest_p = eight_p;
	if (lowest_p > nine_p) lowest_p = nine_p;
    if (lowest_p > ten_p) lowest_p = ten_p;
	if (lowest_p > eleven_p) lowest_p = eleven_p;
    ass_p = (one_p + two_p + three_p + four_p + five_p + six_p + seven_p + eight_p + nine_p + ten_p + eleven_p) - lowest_p;
    total_p = ass_p + lab_ex_p + midterm_p + final_p;
    percent_t = round((static_cast<float>(total_p) / static_cast<float>(max_p)) * static_cast<float>(100));
    cout << "\nAssignment Grades:" << setw(4) << one_p << setw(4) << two_p << setw(4) << three_p 
    << setw(4) << four_p << setw(4) << five_p << setw(4) << six_p << setw(4) << seven_p 
    << setw(4) << eight_p << setw(4) << nine_p << setw(4) << ten_p << setw(4) << eleven_p;
    cout << "\nAssignment Points:" << setw(4) << ass_p;
    cout << "\nLab Exercises:" << setw(8) << lab_ex_p;
    cout << "\nMidterm:" << setw(14) << midterm_p;
    cout << "\nFinal:" << setw(16) << final_p;
    cout << "\nTotal Points" << setw(10) << total_p;
    cout << "\nPercent of total:" << setw(5) << percent_t << "%\n";
    switch (percent_t / 10){
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
	remainder = percent_t % 10;
	cout << "Grade: " << grade;
	if (remainder == 9 || remainder == 8 || percent_t == 100)
		cout << "+";
	else if (remainder == 1 || (remainder == 0 && percent_t != 100 && grade != 'F'))
		cout << "-";
	cout << endl;
	if (grade == 'A')
		cout << "Excellent work\n";
	else if (grade == 'B' || grade == 'C')
		cout << "Not bad!\n";
	else
		cout << "You better try again\n";
    return 0;
}