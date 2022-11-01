#include <iostream> 
#include <Windows.h>

using namespace std;

/*  this is the implementation of the game "Life"
	comments are detailed.
	I hope I'll understand everything if I come back after a while)))*/


int const x = 60, y = 30, n = 3, t = 200; /* initial configuration
x, y - width and height
of n - number of neighbors for life
t - time between frames
*/
void scren(int arr[y][x], int arr2[y][x], int x, int y, int n); /* creating a new frame by rewriting one array into another according to the rule*/
void print_array(int arr[y][x], char simv[], int x, int y); /*displaying an array on the screen*/

int main()
{
	srand(time(NULL));
	char simv[2]{ 176,219 }; /*the symbols with which the cells are displayed on the screen*/
	int arr[y][x];
	int arr2[y][x];

	for (int i = 0; i < y; ++i)                 /*setting random values to cells (0,1) means alive or dead*/
		for (int j = 0; j < x - 1; j += 2)
		{
			int ran = rand() % 2;
			arr[i][j] = ran;
			arr[i][j + 1] = ran;

		}

	print_array(arr, simv, y, x);  /*output of the first frame*/

	while (true)                    /*endless frame refresh cycle*/
	{
		scren(arr, arr2, y, x, n); /*the second array is filled (0,1) based on the first array*/

		Sleep(t);         /*waiting for the next frame*/
		system("cls");    /*clearing the console (screen)*/

		print_array(arr2, simv, y, x); /*output of the second array*/

		scren(arr2, arr, y, x, n); /*the first array is filled (0,1) based on the second array*/

		Sleep(t);
		system("cls");

		print_array(arr, simv, y, x); /*output of the first array again*/
	}


	return 0;
}


void scren(int arr[y][x], int arr2[y][x], int x, int y, int n)
{
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y - 1; j += 2)
		{
			int res = 0;  /*number of cell neighbors*/
			for (int i1 = i - 1; i1 <= i + 1; ++i1)
				for (int j1 = j - 2; j1 <= j + 2; j1 += 2)
				{
					if (i1 < 0 || j1 < 0 || i1 >= x || j1 >= y);
					else
						res += arr[i1][j1];
				}
			res -= arr[i][j];   /*we subtract the cell itself so that it is not a neighbor for itself*/
			/*the logic of the rules*/
			if (arr[i][j] == 0 && res == n)
			{
				arr2[i][j] = 1;
				arr2[i][j + 1] = 1;
			}
			else if (arr[i][j] == 1 && (res > n || res < n - 1))
			{
				arr2[i][j] = 0;
				arr2[i][j + 1] = 0;
			}
			else
			{
				arr2[i][j] = arr[i][j];
				arr2[i][j + 1] = arr[i][j];
			}
		}

}

void print_array(int arr[y][x], char simv[], int x, int y)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
			cout << simv[arr[i][j]]; /*the int value of the array element is replaced by the character*/
		cout << '\n';
	}
}
