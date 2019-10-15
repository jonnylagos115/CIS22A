/*
** Jonathan Lagos
** CIS22A
** Assignment 2
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string	first_name, last_name;
    float	percent_value;
	int		t_ass_points, t_ex_points, midterm_points, f_points, cl_points, total;

	cout << "Enter your first name => ";
	cin >> first_name;

	cout << "Enter your last name => ";
	cin >> last_name;

	cout << "Enter the total assignment points => ";
	cin >> t_ass_points;

	cout << "Enter the total exercise points => ";
	cin >> t_ex_points;

	cout << "Enter the midterm points => ";
	cin >> midterm_points;

	cout << "Enter the final points => ";
	cin >> f_points;

	cout << "Enter the CodeLab points => ";
	cin >> cl_points;

	cout << endl;
	total = t_ass_points + t_ex_points + midterm_points + f_points + cl_points;
	percent_value = float(total) / 400;
	cout << first_name << " " << last_name << "'s grade points\n";
	cout << "Assignments: " << t_ass_points << endl;
	cout << "Exercises:   " << t_ex_points << endl;
	cout << "Midterm:     " << midterm_points << endl;
	cout << "Final:       " << f_points << endl;
	cout << "Codelab:     " << cl_points << endl;
	cout << "             ---\n";
	cout << "Total:       " << total << endl;
	cout << "Percent:     " << percent_value * 100 << "%\n";
    return 0;
}