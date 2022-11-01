#include <iostream> 
#include <Windows.h>
#include <conio.h>
using namespace std;


int const x = 40, y = 20;     /*field size*/
char simv[3]{176,178,219};    /*symbols to indicate*/
int x_plcord = x / 2, y_plcord = y / 2 - 1;  /*the initial position of the player*/
int number_target = 10;  /*number of target*/
void scren(char mod);    /*updating the screen*/
void print_array();      /*Displaying an array on the screen*/
int arr[y][x];           /*array screen*/

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i < y; ++i)             /*filling the empty space*/
		for (int j = 0; j < x - 1; j += 2)
		{
			arr[i][j] = 0;
			arr[i][j+1] = 0;
		}
	for (int i = 0; i < number_target;)     /*filling the space with targets*/
	{
		int rand1 = rand(), rand2 = rand();
		rand1 %= y;
		rand2 = (rand2 % (x - 2))+rand2%2;
		if (arr[rand1][rand2] == 0)
		{
			arr[rand1][rand2] = 1;
			arr[rand1][rand2 + 1] = 1;
			++i;
		}
		

	}

	arr[y_plcord][x_plcord] = 2;    /*creating a player*/
	arr[y_plcord][x_plcord+1] = 2;

	print_array();

	while (number_target>0)         /*screen refresh cycle*/
	{
		char mod;
		mod = _getch();       /*getting a button  8 - up 2 - down 4 - left 6 - right*/
		scren(mod);
		system("cls");
		print_array();
	}
	return  0;
}


void print_array()
{
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
			cout << simv[arr[i][j]];
		cout << '\n';
	}
}

void scren(char mod)
{
	arr[y_plcord][x_plcord] = 0;       /*cleaning up the old place*/
	arr[y_plcord][x_plcord + 1] = 0;
	switch (mod)                       /*reaction to button pressing*/
	{
	case '8':
	{
		y_plcord = (y + y_plcord - 1) % (y);
		break;
	}case '2':
	{
		y_plcord = (y + y_plcord + 1) % (y);
		break;
	}case '4':
	{
		x_plcord = (x + x_plcord - 2) % (x);
		break;
	}case '6':
	{
		x_plcord = (x + x_plcord + 2) % (x);
		break;
	}
	default:
		break;
	}
	if (arr[y_plcord][x_plcord] == 1)    /*checking for a collision with the target*/
		number_target -= 1;
	
	arr[y_plcord%y][x_plcord%x] = 2;         /*additional allocation of the remainder of the division because the compiler was swearing*/
	arr[y_plcord%y][(x_plcord + 1)%x] = 2;
}

