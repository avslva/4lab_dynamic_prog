#include "functions1.h"

int levenshtein(string s1, string s2)
{
	int len_1 = s1.length();
	int len_2 = s2.length();
	s1 = " "+ s1;
	s2 = " "+ s2;
	int** mass = new int*[len_2+1];
	for(int i = 0; i < len_1+1; i++)
	{
		mass[i] = new int [len_1+1];
		mass[0][i] = i;
	}
	output(mass, len_1, len_2);
	for(int i = 0; i < len_1+1; i++)
	{
		mass[i][0] = i;
	}
	output(mass, len_1, len_2);

	for(int i = 1; i < len_1+1; i++)
	{
		for(int j = 1; j < len_2+1; j++)
		{
			if(s2[j] == s1[i])
			{
				mass[i][j] = mass[i-1][j-1];
				output(mass, len_1, len_2);
			}
			else
			{
				/*если удаление*/
				if(( mass[i-1][j] <= mass[i][j-1]) && ( mass[i-1][j] <= mass[i-1][j-1]))
				{
					mass[i][j]= mass[i -1][j] + 1;
				}
				else
				{
					/*если вставка*/
					if(( mass[i][j-1] <= mass[i-1][j]) && ( mass[i][j-1] <= mass[i-1][j-1]))
					{
						mass[i][j]= mass[i][j-1] + 1;
					}
					else
					{
						/*если замена*/
						if(( mass[i-1][j-1] <= mass[i-1][j]) && ( mass[i-1][j-1] <= mass[i][j-1]))
						{
							mass[i][j]= mass[i-1][j-1] + 1;
						}
					}
				}
				output(mass, len_1, len_2);
			}
		}
	}
	output(mass, len_1, len_2);
	return mass[len_1][len_2];
}

void output(int** mass, int len_1, int len_2)
{
	for(int i = 0; i < len_1+1; i++)
	{
		for(int j = 0; j < len_2+1; j++)
		{
			if(mass[i][j] < 0)
			{
				cout << "n ";
			}
			else
			{
				cout << mass[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "-------------------------------------------" << endl;
}