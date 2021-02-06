/*
Credit to Tanjim Bin Faruk (https://tanjim131.github.io/2020-05-26-uva-11507/)
*/

#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	int L, end_dir[3], rot_axis[3], temp[3], neg_y[3] = { 0, -1, 0 }, pos_y[3] = { 0, 1, 0 }, neg_z[3] = { 0, 0, -1 }, pos_z[3] = { 0, 0, 1 }, i, j; //point 0 endpoint, point 1 one point in from endpoint
	int bend_to[3];
	bend_to[0] = 0;
	char bend[2];

	map<string, int*> axis_map;
	axis_map["-y"] = neg_y;
	axis_map["+y"] = pos_y;
	axis_map["-z"] = neg_z;
	axis_map["+z"] = pos_y;

	while (scanf("%d", &L))
	{
		if (L == 0)
		{
			break;
		}
		end_dir[0] = 1; end_dir[1] = 0; end_dir[2] = 0;
		for (i = 1; i < L; i++)
		{
			scanf("%s", bend);

			if (bend[0] != 'N')
			{
				if (bend[1] == 'y')
				{
					if (bend[0] == '+')
					{
						bend_to[1] = 1;
					}
					else
					{
						bend_to[1] = -1;
					}
					bend_to[2] = 0;
				}
				else
				{
					if (bend[0] == '+')
					{
						bend_to[2] = 1;
					}
					else
					{
						bend_to[2] = -1;
					}
					bend_to[1] = 0;
				}

				// Effectively taking cross product rot_axis = bend_to x xaxis
				rot_axis[0] = 0;
				rot_axis[1] = -bend_to[2];
				rot_axis[2] = bend_to[1];

				// New end direction is cross product end_dir = end_dir x rot_axis
				temp[0] = -((end_dir[1] * rot_axis[2]) - (end_dir[2] * rot_axis[1]));
				temp[1] = ((end_dir[0] * rot_axis[2]) - (end_dir[2] * rot_axis[0]));
				temp[2] = -((end_dir[0] * rot_axis[1]) - (end_dir[1] * rot_axis[0]));

				if (!(temp[0] == 0 && temp[1] == 0 && temp[2] == 0))
				{
					end_dir[0] = temp[0]; end_dir[1] = temp[1]; end_dir[2] = temp[2];
				}
			}
		}
		
		if (end_dir[0] == 1)
		{
			printf("%s\n", "+x");
		}
		else if (end_dir[0] == -1)
		{
			printf("%s\n", "-x");
		}
		else if (end_dir[1] == 1)
		{
			printf("%s\n", "+y");
		}
		else if (end_dir[1] == -1)
		{
			printf("%s\n", "-y");
		}
		else if (end_dir[2] == 1)
		{
			printf("%s\n", "+z");
		}
		else if (end_dir[2] == -1)
		{
			printf("%s\n", "-z");
		}
	}

	return 0;
}
