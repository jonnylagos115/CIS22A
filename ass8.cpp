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

void    roll_dice(unsigned short numberOfRolls, unsigned short& sum);
unsigned short  Larrys_turn(unsigned short ret_sum = 0);
unsigned short  Curlys_turn(unsigned short ret_sum = 0);
unsigned short  Moes_turn(unsigned short ret_sum = 0);

int main()
{
	unsigned short counter = 0, sum = 0,
	check_winner = 0;

	do
	{
        check_winner = Larrys_turn();
        check_winner = Curlys_turn();
        //check_winner = Moes_turn();
		if (check_winner == 0) cout << endl;
		abort();
	}while (check_winner == 0);
	switch (check_winner)
	{
	    case 1:
	        cout << "Larry ";
	        sum = Larrys_turn(1);
	        break;
        case 2:
            cout << "Curly ";
            sum = Curlys_turn(1);
            break;
        case 3:
            cout << "Moe ";
            sum = Moes_turn(1);
	}
	cout << "won the game with " << sum << endl;
	return 0;
}

void    roll_dice(unsigned short numberOfRolls, unsigned short& sum)
{
    unsigned short rd1, rd2;

    srand(time(NULL));
    for (unsigned short i = 0; i < numberOfRolls; i++)
    {
        rd1 = rand() % 6 + 1;
        rd2 = rand() % 6 + 1;
        if (rd1 == 1 || rd2 == 1)
        {
            if (rd1 == 1 && rd2 == 1)
            {
                 cout << "SKUNK" << endl;
                 sum = 0; //reset total point of player
            }
            break ;
        }
        else
            sum = rd1 + rd2;
        cout << "* You rolled " << rd1 << " and "
        << rd2 << ".  That's " << sum << endl;
    }
}

unsigned short Larrys_turn(unsigned short ret_sum)
{
    static unsigned short c_tpoints;

    if (ret_sum != 0)
        return c_tpoints;
    cout << "Larry, its your turn " << endl;
    roll_dice(1, c_tpoints);
    cout << "Total points = " << c_tpoints;
    if (c_tpoints >= 100)
        return 1;
    else
        return 0;
}

unsigned short Curlys_turn(unsigned short ret_sum)
{
    static unsigned short c_tpoints;

    if (ret_sum != 0)
        return c_tpoints;
    cout << "Curly, its your turn " << endl;
    roll_dice(3, c_tpoints);
    cout << "Total points = " << c_tpoints;
    if (c_tpoints >= 100)
        return 2;
    else
        return 0;
}

unsigned short Moes_turn(unsigned short ret_sum)
{
    static unsigned short c_tpoints;

    if (ret_sum != 0)
        return c_tpoints;
    cout << "Moe, its your turn " << endl;
    while (c_tpoints >= 100 || c_tpoints)
        roll_dice(1, c_tpoints);
    cout << "Total points = " << c_tpoints;
    if (c_tpoints >= 100)
        return 3;
    else
        return 0;
}
