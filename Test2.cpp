#include <iostream> 
#include <Windows.h>

using namespace std;

/*  это реализация игры "Жизнь" 
    коментарии подробные. 
	надеюсь я все пойму если вернусь через некоторое время)))*/


int const x = 60, y = 30, n = 3, t = 200; /* начальная конфигурация
x, y - ширина и высота 
n -  к - во соседей для жизнии 
t - время между кадрами
*/
void scren(int arr[y][x], int arr2[y][x], int x, int y, int n); /* создание нового кадра путем переписывания одного массива в другой по правилу*/
void print_array(int arr[y][x], char simv[], int x, int y); /*вывод массива на экран*/

int main()
{
	char simv[2]{ 176,219 }; /*символы которыми клетки выводятся на экран*/
	int arr[y][x]; 
	int arr2[y][x];
		
	for (int i = 0; i < y; ++i)                 /*задание рандомных значений клеткам (0,1) значит жив или мертв*/
		for (int j = 0; j < x - 1; j += 2)
		{
			int ran = rand() % 2;
			arr[i][j] = ran;
			arr[i][j+1] = ran;

		}
	
	print_array(arr, simv, y, x);  /*вывод первого кадра*/

	while (true)                    /*бесконечный цикл обновления кадров*/
	{
		scren(arr, arr2, y, x, n); /*второй массив заполняется (0,1) на основании первого массива*/
		
		Sleep(t);         /*ожидание следующего кадра*/
		system("cls");    /*очистка консоли (экрана)*/
		
		print_array(arr2, simv, y, x); /*вывод второго массива*/
		
		scren(arr2, arr, y, x, n); /*первый массив заполняется (0,1) на основании второго массива*/
		
		Sleep(t);
		system("cls");
		
		print_array(arr, simv, y, x); /*вывод снова первого массива*/
	}
		
	
	return 0;
}


void scren(int arr[y][x], int arr2[y][x], int x, int y, int n)
{
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y - 1; j += 2)
		{
			int res = 0;
			for (int i1 = i - 1; i1 <= i + 1; ++i1)
				for (int j1 = j - 2; j1 <= j + 2; j1 += 2)
				{
					if (i1 < 0 || j1 < 0 || i1 >= x || j1 >= y);
					else
						res += arr[i1][j1];
				}
			res -= arr[i][j];
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
			cout << simv[arr[i][j]];
		cout << '\n';
	}
}
 