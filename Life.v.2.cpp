#include <iostream> 
#include <Windows.h>
#include <conio.h>


/* Более элегантная версия Жизни. Конечно короче было бы через структуру, но хотелось написать класс)) */

using namespace std;

class Cels        /*класс клетки*/
{
private:
	bool cels_life;  /* состояние жива или нет */
	int neighbors;   /* количество соседей */
public:
	Cels()          /* конструктор, позволяет задать рандомное состояние в момент объявления */
	{
		setLife();
	}
	void setLife()
	{
		cels_life = rand() % 2;  /* если состояние не указано точно, то оно определяется рандомно */
	}
	void setLife(bool life)    /* сеттеры */
	{
		cels_life = life;
	}
	void setNeighbors(int nam)
	{
		neighbors = nam;
	}
	void neighborsAdd(int nam)   /* типо сеттер, нужен для счетчика соседей */
	{
		neighbors += nam;
	}
	bool getLife()       /* геттеры */
	{
		return cels_life;
	}
	int getNeighbors()
	{
		return neighbors;
	}
};

int main()
{
	int const x = 30, y = 30, n = 3, t = 200;
	char simv[2]{ 176,219};
	srand(time(NULL));

	Cels arr[y][x];   /* объявление двумерного массива клеток */

	while (true)      /* счетчик соседей позволяет обходится одним массивом и вычислять один кадр за цикл */
	{
		Sleep(t);        /* ожилание и очистка консоли */
		system("cls");

		for (int i = 0; i < y; ++i)         /* вывод массива на экран */
		{
			for (int j = 0; j < x; ++j)
			{
				if (arr[i][j].getLife())
					cout << simv[1] << simv[1];
				else
					cout << simv[0] << simv[0];
			}
			cout << '\n';
		}

		for (int i = 0; i < y; ++i)              /* итерация массива и определение количества соседей каждой клетки клетки */
			for (int j = 0; j < x; ++j)
			{
				arr[i][j].setNeighbors(0);
				for (int i1 = i - 1; i1 <= i + 1; ++i1)
					for (int j1 = j - 1; j1 <= j + 1; ++j1)
					{
						if (arr[(y + i1) % y][(x + j1) % x].getLife())   /* (y + i1) % y - конструкция нужна для бесконечного поля */
							arr[i][j].neighborsAdd(1);
					}
				if (arr[i][j].getLife())
					arr[i][j].neighborsAdd(-1);    /* вычитаем 1 если клетка жива, чтобы она не была соседом для себя же самой */
			}
		
    for (int i = 0; i < y; ++i)          /* итерируем массив еще раз и по правилу убиваем клетку если соседей >3 или <2 и оживляем мертвую если ровно 3*/
			for (int j = 0; j < x; ++j)
			{
				if (arr[i][j].getLife() && (arr[i][j].getNeighbors() < (n - 1) || arr[i][j].getNeighbors() > n))
					arr[i][j].setLife(0);
				else if (!arr[i][j].getLife() && arr[i][j].getNeighbors() == n)
					arr[i][j].setLife(1);
			}
	}
	return 0;
}
