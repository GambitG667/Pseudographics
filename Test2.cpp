#include <iostream> 
#include <Windows.h>

using namespace std;

/*  ��� ���������� ���� "�����" 
    ���������� ���������. 
	������� � ��� ����� ���� ������� ����� ��������� �����)))*/


int const x = 60, y = 30, n = 3, t = 200; /* ��������� ������������
x, y - ������ � ������ 
n -  � - �� ������� ��� ������ 
t - ����� ����� �������
*/
void scren(int arr[y][x], int arr2[y][x], int x, int y, int n); /* �������� ������ ����� ����� ������������� ������ ������� � ������ �� �������*/
void print_array(int arr[y][x], char simv[], int x, int y); /*����� ������� �� �����*/

int main()
{
	char simv[2]{ 176,219 }; /*������� �������� ������ ��������� �� �����*/
	int arr[y][x]; 
	int arr2[y][x];
		
	for (int i = 0; i < y; ++i)                 /*������� ��������� �������� ������� (0,1) ������ ��� ��� �����*/
		for (int j = 0; j < x - 1; j += 2)
		{
			int ran = rand() % 2;
			arr[i][j] = ran;
			arr[i][j+1] = ran;

		}
	
	print_array(arr, simv, y, x);  /*����� ������� �����*/

	while (true)                    /*����������� ���� ���������� ������*/
	{
		scren(arr, arr2, y, x, n); /*������ ������ ����������� (0,1) �� ��������� ������� �������*/
		
		Sleep(t);         /*�������� ���������� �����*/
		system("cls");    /*������� ������� (������)*/
		
		print_array(arr2, simv, y, x); /*����� ������� �������*/
		
		scren(arr2, arr, y, x, n); /*������ ������ ����������� (0,1) �� ��������� ������� �������*/
		
		Sleep(t);
		system("cls");
		
		print_array(arr, simv, y, x); /*����� ����� ������� �������*/
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
 