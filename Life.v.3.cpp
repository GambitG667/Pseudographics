#include <iostream> 
#include <Windows.h>
#include <conio.h>

/* Не удержался и написал через структуру)) тут все тоже самое, но вместо геттеров и сеттеров прямое обращение к полям */

using namespace std;

struct Cels
{
	bool life = rand()%2;
	int neighbors;

};

int main()
{
	int const x = 30, y = 30, n = 3, t = 200;
	char simv[2]{ 176,219 };
	srand(time(NULL));

	Cels arr[y][x];
	
	while (true)
	{
		Sleep(t);
		system("cls");

		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				if (arr[i][j].life)
					cout << simv[1] << simv[1];
				else
					cout << simv[0] << simv[0];
			}
			cout << '\n';
		}

		for (int i = 0; i < y; ++i)
			for (int j = 0; j < x; ++j)
			{
				arr[i][j].neighbors = 0;
				for (int i1 = i - 1; i1 <= i + 1; ++i1)
					for (int j1 = j - 1; j1 <= j + 1; ++j1)
					{
						if (arr[(y + i1) % y][(x + j1) % x].life)
							arr[i][j].neighbors += 1;
					}
				if (arr[i][j].life)
					arr[i][j].neighbors -=1;
			}
		for (int i = 0; i < y; ++i)
			for (int j = 0; j < x; ++j)
			{
				if (arr[i][j].life && (arr[i][j].neighbors < (n - 1) || arr[i][j].neighbors > n))
					arr[i][j].life = 0;
				else if (!arr[i][j].life && arr[i][j].neighbors == n)
					arr[i][j].life = 1;
			}
	}

	return 0;
}
