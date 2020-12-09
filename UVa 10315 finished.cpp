#include <iostream>
#include <stdio.h>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

map<char, int> card_vals; //Stores numerical values for

/*
//Char arrays for different outcomes. Self-explanatory.
const char HIGH_CARD[16] = "High card";
const char PAIR[16] = "Pair";
const char TWO_PAIRS[16] = "Two pairs";
const char THREE_KIND[16] = "Three of a kind";
const char STRAIGHT[16] = "Straight";
const char FLUSH[16] = "Flush";
const char FULL_HOUSE[16] = "Full house";
const char FOUR_KIND[16] = "Four of a kind";
const char STRAIGHT_FLUSH[16] = "Straight flush";

map<const char*, int> outcomes; //Ranks possible outcomes
*/

/*
Description:
    Converts cards to their respective values.

Args:
    char hand[5][2]:
        Hand of five cards.

Returns:
    int* vals:
        Pointer to array representing the numerical
        value of each card in hand.
*/
int* get_card_vals(char hand[5][2])
{
	int* vals = new int[5]; //Initially unsorted
	//Store values of cards
	for (int i = 0; i < 5; i++)
	{
		vals[i] = card_vals[hand[i][0]];
	}

	return vals;
}

/*
Description:
	Compare two hands to find which has the highest card. If the highest cards
	of both hands are equal, compare the second highest cards, and so on.
	Used in the case of a Flush.

Arguments:
	int* vals_black:
		Pointer to card values in black's hand.
	int* vals_white
		Pointer to card values in white's hand.

Returns:
	'T' if the cards in Black's and White's hands are equal.
	'B' if Black has the highest card (or 2nd, 3rd highest etc).
	'W' otherwise.
*/
char comp_cards(int* vals_black, int* vals_white, int num_vals)
{
	//Sort value arrays
	sort(vals_black, vals_black + num_vals);
	sort(vals_white, vals_white + num_vals);

    //Compare the highest card values in both hands in descending order
	for (int i = num_vals - 1; i > -1; i--)
	{
	    //If the current highest value in black's hand is equal to that
	    //of white's, compare the next highest values
		if (vals_black[i] == vals_white[i])
		{
			continue;
		}
		//Otherwise, compare the values
		else
		{
			return vals_black[i] > vals_white[i] ? 'B' : 'W';
		}
	}
	//If all of the values are equal, we have a tie
	return 'T';
}

/*
Description:
    Compares the hands of black and white and decides the winner.

Args:
    int* remaining_black:
        Pointer to array of remaining values in black's hand
        (excluding the primary value).
    int* remaining_white:
        Same as int* remaining_black but for white's hand.
    int num_remaining:
        Number of remaining values in black's and white's hand
        (this will always be equal if this function is being called).
    int primary_black:
        Numerical value of the primary card in black's hand, i.e.
        the value of the card(s) that represent(s) the outcome that
        the hands of black and white share.
    int primary_white:
        Numerical value of the primary card in white's hand.

Returns:
    'B' if black has the greater primary card.
    'W' if white has the greater primary card.
    Returns the result of comp_cards() if the primary card values are equal.
*/
char comp_hands(int* remaining_black, int* remaining_white, int num_remaining, int primary_black = 0, int primary_white = 0)
{
    //If the highest primary card of black's hand is equal to that of white's
    //Compare the remaining values
	if (primary_black == primary_white)
	{
		return comp_cards(remaining_black, remaining_white, num_remaining);
	}
	//Otherwise, compare the primary values
	return primary_black > primary_white ? 'B' : 'W';
}

/*
Description:
    Compares the hands of black and white, in the case that both have a two pair,
    and decides the winner.

Args:
    int* remaining_black:
        Pointer to the remaining value (neither of the two pair cards) in black's hand
    int* remaining_white:
        Pointer to the remaining value in white's hand
    int primary_black:
        Value of the primary card in black's hand
    int primary_white:
        Value of the primary card in white's hand
    int secondary_black:
        Value of the secondary card in black's hand
    int secondary_white:
        Value of the secondary card in the white's hand

Returns:
    'B': If black has the higher primary (or secondary) card
    'W': If white has the higher primary (or secondary) card

*/
char comp_two_pair(int* remaining_black, int* remaining_white, int primary_black, int primary_white, int secondary_black, int secondary_white)
{
    //If the value of the highest pair in black's hand is equal to that of white's,
    //compare the second highest pair
   if (primary_black == primary_white)
   {
       //If the value of the second highest pair in black's hand is equal
       //to that of white's, compare the last remaining cards.
       if (secondary_black == secondary_white)
       {
           return comp_cards(remaining_black, remaining_white, 1);
       }
       //Otherwise, compare the second highest pairs
       return secondary_black > secondary_white ? 'B' : 'W';
   }
   //Otherwise, compare the highest pairs
   return primary_black > primary_white ? 'B' : 'W';
}

/*
Description:
    Compares the hands of black and white, in the case that both have a full house,
    and decides the winner.

Args:
    int primary_black:
        Value of the primary card in black's hand
    int primary_white:
        Value of the primary card in white's hand
    int secondary_black:
        Value of the secondary card in black's hand
    int secondary_white:
        Value of the secondary card in the white's hand

Returns:
    'B': If black has the higher primary (or secondary) card
    'W': If white has the higher primary (or secondary) card
    'T': Otherwise.
*/
char comp_full_house(int primary_black, int primary_white, int secondary_black, int secondary_white)
{
    if (primary_black == primary_white)
    {
        if (secondary_black == secondary_white)
        {
            return 'T';
        }
        return secondary_black > secondary_white ? 'B' : 'W';
    }
    return primary_black > primary_white ? 'B' : 'W';
}

/*
Description:
	In the case of a straight or straight flush in both Black's hand and
	White's hand, compare the highest cards in both hands to find the winner.

Arguments:
	int black_highest:
		Value of highest card in Black's hand.
	int white_highest
		Value of highest card in White's hand.

Returns:
	'T' if the cards in Black's and White's hands are equal.
	'B' if Black has the highest card (or 2nd, 3rd highest etc).
	'W' otherwise.
*/
char comp_straight(int black_highest, int white_highest)
{
	if (black_highest > white_highest)
	{
		return 'B';
	}
	else if (white_highest > black_highest)
	{
		return 'W';
	}
	else
	{
		return 'T';
	}
}

/*
Description:
    Takes a hand and returns and determines where or not there
    is a flush.

Args:
    5x2 array representing the hand of black or white,
    where each element is a 1x2 array representing a single card.

Returns:
    The corresponding outcome rank of a flush if the hand contains
    a flush, 0 if there is no flush.
*/
int get_flush(char hand[5][2])
{
	//Check if all cards in black's hand are the same suit
	for (int i = 0; i < 4; i++)
	{
		if (hand[i][1] != hand[i + 1][1])
		{
			return 0;
		}
	}
	return 6;
}

/*
Description:
	Determines whether or not a hand contains a straight.

Args:
	int hand_vals[5]:
		Values of the cards in a hand.

Returns:
	int outcome[2]:
        outcome[0]:
            Value of the highest card found in a straight. This will be zero if no straight is found.
        outcome[1]:
            The corresponding outcome rank of a straight if the hand contains a straight.
            0 otherwise.
*/
int* straight(int hand_vals[5])
{
	int i;
	int min_card = 14, max_card = 0; // To hold values of lowest/highest valued cards in potential flush
	//Stores result. outcome[0] is max_card. outcome[1] is the rank of the outcome found.
	int* outcome = new int[2];
	outcome[1] = 0;  //Default value if none of a straight, flush or straight flush occurs.

	//Get min and max values of the cards
	//then check for a straight

	//Get min and max
	for (i = 0; i < 5; i++)
	{
		if (hand_vals[i] < min_card)
		{
			min_card = hand_vals[i];
		}
		if (hand_vals[i] > max_card)
		{
			max_card = hand_vals[i];
		}
	}

	outcome[0] = max_card;

	//Check if consecutively ordered
	for (i = 0; i < 5; i++)
	{
		//If the cards are not consecutive, there is no straight. Terminate function.
		if (hand_vals[i] != min_card + i)
		{
			outcome[1] = 0;
			return outcome;
		}
	}
	outcome[1] = 5;
	return outcome;
}

/*
Description:
    In the case of two pairs, return the value of the last remaining card after excluding
    the values of the cards forming the two pairs from potential_remaining.

Args:
    int card_to_exclude:
        Value of the card of the second pair
    int* potential_remaining]:
        Pointer to array of remaining card values in hand. Will contain the value of the
        second pair card as well as the value of one other card when this function is called.2

Returns:
    int* remaining_val:
        Pointer to the value of the last remaining card in the hand.
*/
int* get_remaining_val(int card_to_exclude, int* potential_remaining)
{
	int* remaining_val = new int; //Stores values of remaining (non-primary) cards
    *remaining_val = potential_remaining[0] != card_to_exclude ? potential_remaining[0] : potential_remaining[1];

	return remaining_val;
}

/*
Description:
	Takes an array of card values and returns information about occurences of
	high cards, pairs, two pairs, three of a kind, full house and four of a kind instances.

Args:
	int hand[5]:
		Card values of a player's hand

Returns:
	int* return_arr[2] = { int outcome[4], int remaining_vals[4] }:
		outcome[0]:
			The card value of the card with the most occurences in the hand.
		outcome[1]:
			The number of times said card occurs.
			In the case that outcome[1] = 4, 3, 2, 1, we have a four of a kind,
			three of a kind, pair and high card respectively.
		outcome[2]:
			The outcome rank of the outcome found.
		outcome[3]:
			Size of remaining_vals i.e. the number of remaining values.
        outcome[4]:
            Secondary card value if applicable. This will only be in the case of a
            full house or two pairs. In the former, it will be the value of the
            pair card. In the latter, it will be the value of the second highest
            pair card.

		potential_remaining:
			The values of the (at most 4) remaining cards after filtering out the
			most important card(s) needed for determining the outcome. This can be
			used for comparisons between hands if needed for certain outcomes.

*/
int** n_of_kind(int hand[5])
{
	//Integer array representing various possible outcomes of a hand.
	//The first element is the value of the card with
	int* outcome = new int[5];

	map<int, int> num_of_cards; //Stores number of occurences of each card in a hand
	map<int, int>::iterator it; //Iterator of num_of_cards

	int i; //Pointer

	//Stores max of the number of occurences of a card found over all the cards in the hand,
	//and the value of the card whose number of occurences is maximum, respectively
	int max_counts = 0, card_val_max_counts = 0;
	int max_card; //Stores card with number of occurneces max_counts and value card_val_max_counts
	int best_outcome = 0; //Represents the best outcome found

	//Stores values of remaining card(s) after primary card has been found
	int* potential_remaining = new int [4];
	int remaining_count = 0; //Pointer to values in potential_remaining
	int num_remaining; //Stores final number of remaining values

    //Initialize all values in potential_remaining to be 1 higher than the highest card value
    //(i.e. 14) so that, after sorting, values of potential_remaining which are not
    //subsequently assigned to will appear at the end of the array and will not be seen by
    //any of the comparison functions called towards the end of main().
    for (i=0; i < 4; i++)
    {
        potential_remaining[i] = 14;
    }

	//Array to be returned. Will store outcome and potential_remaining.
	int** return_arr = new int* [2];

	for (i = 0; i < 5; i++)
	{
	    //If a card value has not yet been found, set the number of
	    //recorded instances of that card value being found to 1.
		if (num_of_cards.find(hand[i]) == num_of_cards.end())
		{
			num_of_cards[hand[i]] = 1;
		}
		//Otherwise, increase the number of recorded instances of
		//that card value being found by one.
		else
		{
			num_of_cards[hand[i]]++;
		}
	}
	for (it = num_of_cards.begin(); it != num_of_cards.end(); it++)
	{
		//If the number of times that the card value being investigated appears in the
		//hand is greater than that of the current max card...
		if (it->second > max_counts)
		{
			//If this is not the first card being investigated and max_card is assigned to,
			//add the old max_card value to the set potential_remaining
			if (max_counts)
			{
				potential_remaining[remaining_count] = card_val_max_counts;
				remaining_count++;
			}
            //Update
			max_counts = it->second;
			card_val_max_counts = it->first;
		}
		//The following is for high card OR two pair.
		//If the number of times that the card value being investigated appears in the
		//hand is equal to that of the current max card...
		else if (it->second == max_counts)
		{
		    //If the current max card value is less than that of the card value being
		    //investigated, relocate the current max card value to potential_remaining
		    //and update the max card value.
			if (card_val_max_counts < it->first)
			{
				//This will always work as max_card has been assigned to by assumption,
				//since it->second will never be zero
				potential_remaining[remaining_count] = card_val_max_counts;
				card_val_max_counts = it->first;
				remaining_count++;
			}
			//Otherwise, if the card value being investigated is less than the current
			//max card value, record it in potential_remaining.
			else
            {
				potential_remaining[remaining_count] = it->first;
				remaining_count++;
            }
		}
		//Otherwise, if the card value being investigated appears more times than the
		//current max card value, record it in potential_remaining.
		else
		{
		    potential_remaining[remaining_count] = it->first;
            remaining_count++;
		}
	}

	//Fix first two parameters of outcome
	outcome[0] = card_val_max_counts;
	outcome[1] = max_counts; //Note: deprecated an unnecessary

    //High card
	if (max_counts == 1)
	{
		outcome[2] = 1;
		outcome[3] = 4;
	}
	//Pair or Two Pair
	else if (max_counts == 2)
	{
		outcome[2] = 2;
		outcome[3] = 3;
		//Check for two pairs
		for (i = 0; i < remaining_count; i++)
		{
			//If a card is found which occurs twice but is not equal to the card occuring
			//twice with the highest value, then we must have two pairs.
			if (num_of_cards[potential_remaining[i]] == 2)
			{
				outcome[2] = 3;
				outcome[3] = 1;
				outcome[4] = potential_remaining[i];
				break;
			}
		}
	}
	//Three of a kind or full house
	else if (max_counts == 3)
	{
		//Check for full house
		if (num_of_cards[potential_remaining[0]] == 2)
		{
			outcome[2] = 7;
			outcome[3] = 1;
			outcome[4] = potential_remaining[0];
		}
		else
		{
			outcome[2] = 4;
			outcome[3] = 2;
		}
	}
	else //Must be four of a kind
	{
		outcome[2] = 8;
		outcome[3] = 1;
	}

	//Get values of remaining cards
	//If a two pair is found, compare all of the remaining cards types to that of the second pair.
	//Discard the type of the second pair
	if (outcome[2] == 3)
	{
		return_arr[1] = get_remaining_val(outcome[4], potential_remaining);
	}
	//Otherwise, keep all remaining card types. All card types are compared to the first primary card,
	//which is not contained in potential_remaining, so that no card types are discarded.
	else
	{
		return_arr[1] = potential_remaining;
	}

    //First row of return_arr stores outcome data, second row stores remaining values
	return_arr[0] = outcome;
	return return_arr;
}

/*
Description:
	Takes series pairs of hands of five cards for
	player Black and player White and determines
	the winner for each pair of hands.
*/
int main()
{
	//Initialize card values
	card_vals['2'] = 1;
	card_vals['3'] = 2;
	card_vals['4'] = 3;
	card_vals['5'] = 4;
	card_vals['6'] = 5;
	card_vals['7'] = 6;
	card_vals['8'] = 7;
	card_vals['9'] = 8;
	card_vals['T'] = 9;
	card_vals['J'] = 10;
	card_vals['Q'] = 11;
	card_vals['K'] = 12;
	card_vals['A'] = 13;

    /*
	//Initialize outcome rankings
	outcomes[HIGH_CARD] = 1;
	outcomes[PAIR] = 2;
	outcomes[TWO_PAIRS] = 3;
	outcomes[THREE_KIND] = 4;
	outcomes[STRAIGHT] = 5;
	outcomes[FLUSH] = 6;
	outcomes[FULL_HOUSE] = 7;
	outcomes[FOUR_KIND] = 8;
	outcomes[STRAIGHT_FLUSH] = 9;
    */

	char hand_black[5][2]; //Black's hand
	char hand_white[5][2]; //White's hand
	int* vals_black = new int[5];
	int* vals_white = new int[5];
	int best_result_black, best_result_white;
	int flush_black, flush_white;

	int i; //Pointer
	char winner = 'T'; //Tracks winner. Possible values 'W', 'B' and 'T'.

	//Init array
	for (i = 0; i < 5; i++)
	{
		hand_black[i][0] = 0; hand_black[i][1] = 0;
		hand_white[i][0] = 0; hand_white[i][1] = 0;
	}

	while (scanf(" %c%c", &hand_black[0][0], &hand_black[0][1]))
	{
		for (i = 1; i < 5; i++)
		{
			scanf(" %c%c", &hand_black[i][0], &hand_black[i][1]);
		}
		for (i = 0; i < 5; i++)
		{
			scanf(" %c%c", &hand_white[i][0], &hand_white[i][1]);
		}

		vals_black = get_card_vals(hand_black);
		sort(vals_black, vals_black + 5);
		vals_white = get_card_vals(hand_white);
        sort(vals_white, vals_white + 5);

		int* straight_black = new int[2]; //Black's straight flush results
		int* straight_white = new int[2]; //White's straight flush results
		int** n_of_kind_black = new int* [2]; //Black's n_of_kind results
		int** n_of_kind_white = new int* [2]; //White's n_of_kind results

		flush_black = get_flush(hand_black);
		flush_white = get_flush(hand_white);

		straight_black = straight(vals_black);
		straight_white = straight(vals_white);

        //Check for straight flush
		if (straight_black[1] && flush_black)
        {
            best_result_black = 9;
        }
        else
        {
            best_result_black = max(flush_black, straight_black[1]);
        }
        if (straight_white[1] && flush_white)
        {
            best_result_white = 9;
        }
        else
        {
            best_result_white = max(flush_white, straight_white[1]);
        }

		//Otherwise, check for other outcomes.
		n_of_kind_black = n_of_kind(vals_black);
		n_of_kind_white = n_of_kind(vals_white);

		best_result_black = max(n_of_kind_black[0][2], best_result_black);
		best_result_white = max(n_of_kind_white[0][2], best_result_white);

		//If Black's best outcome is better than White's, Black wins.
		if (best_result_black > best_result_white)
		{
			winner = 'B';
		}
		//If White's best outcome is better than Black's, White wins.
		else if (best_result_white > best_result_black)
		{
			winner = 'W';
		}
		//If the best outcomes for Black and White are the same, further comparison is required.
		else
		{
			switch (best_result_black)
			{
            case 3:
                winner = comp_two_pair(n_of_kind_black[1], n_of_kind_white[1], n_of_kind_black[0][0], n_of_kind_white[0][0], n_of_kind_black[0][4], n_of_kind_white[0][4]);
                break;
			case 5:
			case 9:
				winner = comp_straight(straight_black[0], straight_white[0]);
				break;
			case 6:
				winner = comp_hands(vals_black, vals_white, 5);
				break;
            case 7:
                winner = comp_full_house(n_of_kind_black[0][0], n_of_kind_white[0][0], n_of_kind_black[0][4], n_of_kind_white[0][4]);
                break;
			default:
				winner = comp_hands(n_of_kind_black[1], n_of_kind_white[1], n_of_kind_black[0][3], n_of_kind_black[0][0], n_of_kind_white[0][0]);
				break;
			}
		}

		//Delete new arrays
		delete[] straight_black, straight_white, n_of_kind_black[0], n_of_kind_black[1], n_of_kind_white[0], n_of_kind_white[1], vals_black, vals_white;

		//Display winner
		switch (winner)
		{
		case 'B':
			printf("Black wins.\n");
			break;
		case 'W':
			printf("White wins.\n");
			break;
		default:
			printf("Tie.\n");
			break;
		}
	}

	return 0;
}
