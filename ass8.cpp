/*
** Jonathan Lagos
** CIS22A
** Assignment 8
** GNU C++ Compiler on Linux
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

bool		player_turn(char player, unsigned short&);
bool		isEndofTurn(unsigned short, unsigned short, unsigned short&, unsigned short&);
void		roll_dice(unsigned short&, unsigned short numberOfRolls = 25);
void		print_winner(char, unsigned short, unsigned short, unsigned short);

int main()
{
	unsigned short	larrys_tpoints = 0, curlys_tpoints = 0,
    moes_tpoints = 0;
	char	winner = 0;

    srand(time(NULL));
	while (winner == 0)
	{
		if (player_turn('L', larrys_tpoints) == true)
			winner = 'L';
		else if (player_turn('C', curlys_tpoints) == true) 
			winner = 'C';
		else if (player_turn('M', moes_tpoints) == true)
			winner = 'M';
	}
	print_winner(winner, larrys_tpoints, curlys_tpoints, moes_tpoints);
	return 0;
}

void		roll_dice(unsigned short& tpoints, unsigned short numberOfRolls)
{
    unsigned short rd1, rd2, sumOfTurn = 0;

    for (unsigned short i = 0; i < numberOfRolls; i++)
    {
        rd1 = rand() % 6 + 1;
        rd2 = rand() % 6 + 1;
		cout << "    You rolled " << rd1 << " and "
        << rd2 << ".  That's ";
        if (isEndofTurn(rd1, rd2, tpoints, sumOfTurn)) break;
		cout << rd1 + rd2 << endl;
		sumOfTurn += rd1 + rd2;
		if ((sumOfTurn + tpoints) >= 100) break;
    }
	cout << "  That's " << sumOfTurn << " points for your turn" << endl;
	tpoints += sumOfTurn;
}

bool		isEndofTurn(unsigned short rd1, unsigned short rd2, unsigned short& tpoints, unsigned short& sumOfTurn)
{
	if (rd1 == 1 || rd2 == 1)
    {
        if (rd1 == 1 && rd2 == 1)
        {
            cout << "SKUNK" << endl;
    		tpoints = 0; //Reset total points on SKUNK
        }
		else
			cout << "0" << endl;
		sumOfTurn = 0;
		return (true);
	}
	return(false);
}

bool 		player_turn(char player, unsigned short& tpoints)
{
	switch (player)
	{
		case 'L':
			cout << "Larry, its your turn" << endl;
			roll_dice(tpoints, 1);
			break;
		case 'C':
			cout << "Curly, its your turn" << endl;
			roll_dice(tpoints, 3);
			break;
		case 'M':
			cout << "Moe, its your turn" << endl;
			roll_dice(tpoints);	//Default argument for numberOfRolls is 25 for Moe, not need for Moe to need more than that in any case
	}
	if (tpoints >= 100)
		return (true);
	cout << "Total points = " << tpoints << "\n\n";
	return (false);
}

void		print_winner(char winner, unsigned short larrys_tpoints, unsigned short curlys_tpoints, unsigned short moes_tpoints)
{
	switch (winner)
	{
		case 'L':
			cout << "Larry won the game with " << larrys_tpoints << " points" << endl;
			break;
		case 'C':
			cout << "Curly won the game with " << curlys_tpoints << " points" << endl;
			break;
		case 'M':
			cout << "Moe won the game with " << moes_tpoints << " points" << endl;
	}
}