#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

char players[4] = { 'N', 'E', 'S', 'W' };
//Numerical values of each card value and suit, respectively.
map<char, int> card_vals = { {'2', 0}, {'3', 1}, {'4', 2}, {'5', 3}, {'6', 4}, {'7', 5}, {'8', 6}, {'9', 7}, {'T', 8}, {'J', 9}, {'Q', 10}, {'K', 11}, {'A', 12} };
map<char, int> suit_vals = { {'C', 0}, {'D', 1}, {'S', 2}, {'H', 3} };

/*
Comparison function for sorting algorithm. Sorts first by suit, then by value.

Args:
	string card1, card2:
		Two-character strings representing cards to compare

Returns:
	True if card1 ranks lower than card2. False otherwise.
*/
bool comp_func(string card1, string card2)
{
	if (card1[0] != card2[0])
	{
		return suit_vals[card1[0]] < suit_vals[card2[0]];
	}
	else
	{
		return card_vals[card1[1]] < card_vals[card2[1]];
	}
}

int main()
{
	map<int, vector<string> > hands; //Holds hands of four players. Key is an int from 0-3. Values are vectors of cards.
	vector<string> init_vec(13, "00");
	int i, j, player_idx;
	char player;

	hands[0] = init_vec;
	hands[1] = init_vec;
	hands[2] = init_vec;
	hands[3] = init_vec;
	
	scanf("%c", &player);
	while (player != '#')
	{
		//Find index of given player and get next player in cycle
		player_idx = (std::find(players, players + 4, player) - players + 1) % 4;
		for (i = 0; i < 13; i++)
		{
			//Get hands and adjust player index mod 4
			for (j = 0; j < 4; j++)
			{
				scanf(" %c%c", &hands[player_idx][i][0], &hands[player_idx][i][1]);
				player_idx = (player_idx + 1) % 4;
			}
		}
		
		//Sort
		for (i = 0; i < 4; i++)
		{
			sort(hands[i].begin(), hands[i].end(), comp_func);
		}
		
		player_idx = 2; //Reset player to 'S' for printing output
		//Print sorted cards
		for (i = 0; i < 4; i++)
		{
			printf("%c:", players[player_idx]);
			for (j = 0; j < 13; j++)
			{
				printf(" %c%c", hands[player_idx][j][0], hands[player_idx][j][1]);
			}
			printf("\n");
			player_idx = (player_idx + 1) % 4;
		}
		scanf(" %c", &player); //Get new player for next case
	}

	return 0;
}
