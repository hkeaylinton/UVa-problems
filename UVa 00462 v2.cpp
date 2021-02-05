/*
Passes debug tests but gets TLE.
Credit to: https://tritanngo99.blogspot.com/2019/01/uva-00462-bridge-hand-evaluator.html
*/

#include <cstdio>
#include <map>

int main()
{
    char card[2]; //Holds card

    //Converts each suit to an index
    std::map<char, int> suit_indices;
    suit_indices['H'] = 0;
    suit_indices['D'] = 1;
    suit_indices['S'] = 2;
    suit_indices['C'] = 3;

    char index_to_suit[4] = {'H', 'D', 'S', 'C'};

    int suit_index; //Holds suit index of each card

    //Columns of 4-arrays correspond to the suits H, D, S and C respectively.
    //ith column is true if an ace/king/queen/jack/trump is found in the ith suit,
    //false otherwise.
    bool king[4], queen[4], jack[4], stopped[4];
    int cards[4]; //Holds number of cards of each suit
    int points, extra_points; //Score of hand, from rules 1-4 and 5-7, respectively.
    int max_suit; //Holds index of suit in hand with the most cards
    int i; //Pointer

    //Get first card
    while (scanf(" %s", card))
    {
        //Initialize arrays
        for(i = 0; i < 4; i++)
        {
            king[i] = queen[i] = jack[i] = stopped[i] = false;
            cards[i] = 0;
        }

        points = extra_points = 0; //Reset score of hand

        //Get remaining cards
        for (i = 0; i < 13; i++)
        {
            //Get new card if not first
            if (i != 0)
            {
                scanf(" %s", card);
            }

            suit_index = suit_indices[card[1]]; //Get index of suit

            //Check for ace, king, queen or jack in hand
            switch(card[0])
            {
            case 'A': //If ace, hand is stopped
                stopped[suit_index] = true;
                points += 4;
                break;
            case 'K':
                king[suit_index] = true;
                points += 3;
                break;
            case 'Q':
                queen[suit_index] = true;
                points += 2;
                break;
            case 'J':
                jack[suit_index] = true;
                points += 1;
                break;
            }
            //Increase the number of cards of the suit of the current card by one
            cards[suit_index]++;
        }

        //Loop over each suit and perform score subtractions
        for (i = 0; i < 4; i++)
        {
            if (king[i] && cards[i] > 1)
            {
                stopped[i] = true;
            }
            else if (king[i])
            {
                points--;
            }
            if (queen[i] && cards[i] > 2)
            {
                stopped[i] = true;
            }
            else if (queen[i])
            {
                points--;
            }
            if (jack[i] && cards[i] < 4)
            {
                points--;
            }
            if (cards[i] == 2) //If the suit contains two cards
            {
                extra_points++;
            }
            else if (cards[i] < 2) //If the suit contains one or no cards
            {
                extra_points += 2;
            }
        }
        //If all four suits in the hand are stopped and the hand has at least 16 points
        //Disregarding rules 5-7, the player can bid no-trump.
        if (stopped[0] && stopped[1] && stopped[2] && stopped[3] && points > 15)
        {
            printf("BID NO-TRUMP\n");
        }
        //Otherwise, find final score account for rules 5-7.
        //If score is at least 14, player can bid with the suit with the most cards.
        else if (points + extra_points > 13)
        {
            max_suit = 0;
            for (int i = 1; i < 4; i++)
            {
                if (cards[i] > cards[max_suit])
                {
                    max_suit = i;
                }
            }
            printf("BID %c\n", index_to_suit[max_suit]);
        }
        //Otherwise, the player must pass.
        else
        {
            printf("PASS\n");
        }
    }

    return 0;
}
