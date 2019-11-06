/*
** Jonathan Lagos
** CIS22A
** Assignment 8
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned short user_Playturn(char c);

int main()
{
	unsigned short counter, rand_dice1, rand_dice2,
	sum, c_tpoints, turn_tpoints;

	c_tpoints = 0;
	counter = 0;
	while (c_tpoints < 100)
	{
		turn_tpoints = 0;
		cout << "This is your turn #" << ++counter << endl;
		srand (time(NULL));
		for (unsigned short i = 0; i < 3; i++)
		{
		    user_Playturn('L', turn_tpoints);
		    user_Playturn('C', turn_tpoints);
		    user_Playturn('M', turn_tpoints);
		}
		c_tpoints += turn_tpoints;
		cout << "** You scored " << turn_tpoints << " points for this turn\n"
		<< "*** Your total is now " << c_tpoints << endl;
		if (c_tpoints < 100) cout << endl;
	}
	return 0;
}

unsigned short user_Playturn(char player, unsigned short& turn_tp)
{
    unsigned short rd1, rd2;
    for (unsigned short i = 0; i < 3; i++)
    {
        rd1 = rand() % 6 + 1;
        rd2 = rand() % 6 + 1;
        sum = rand_dice1 + rand_dice2;
        if (rd1 == 1 || rd2 == 1) sum = 0;
        cout << "* You rolled " << rand_dice1 << " and "
        << rand_dice2 << ".  That's " << sum << endl;
        if (!sum) break;
        turn_tpoints += sum;
    }
    return (sum);
}
