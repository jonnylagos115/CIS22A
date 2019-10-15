/*
** Jonathan Lagos
** CIS22A
** Assignment 5
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	unsigned short counter, rand_dice1, rand_dice2, 
	sum, c_tpoints, turn_tpoints;

	c_tpoints = 0;
	counter = 0;
	srand (time(NULL));
	while (c_tpoints < 100)
	{
		turn_tpoints = 0;
		cout << "This is your turn #" << ++counter << endl;
		for (unsigned short i = 0; i < 3; i++)
		{
			rand_dice1 = rand() % 6 + 1;
			rand_dice2 = rand() % 6 + 1;
			sum = rand_dice1 + rand_dice2;
			if (sum == 7) sum = 0;
			cout << "* You rolled " << rand_dice1 << " and "
			<< rand_dice2 << ".  That's " << sum << endl;
			if (!sum) break;
			turn_tpoints += sum;
		}
		c_tpoints += turn_tpoints;
		cout << "** You scored " << turn_tpoints << " points for this turn\n"
		<< "*** Your total is now " << c_tpoints << endl;
		if (c_tpoints < 100) cout << endl; 
	}
	return 0;
}