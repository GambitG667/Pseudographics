#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

long long fib(int n);
long long fib2(int n);

int main()
{
	setlocale(LC_ALL, "ru");
	for (int i = 1; i < 95; ++i)
	{
		float t = ((float)clock()) / CLOCKS_PER_SEC;
		cout << i << " " << fib(i) << "  К-во сек. со старта "  << ((float)clock()) / CLOCKS_PER_SEC << endl;
	}
	cout << "\n\n\n";
	for (int i = 1; i < 95; ++i)
	{
		float t = ((float)clock()) / CLOCKS_PER_SEC;
		cout << i << " " << fib2(i) << "  К-во сек. со старта " << ((float)clock()) / CLOCKS_PER_SEC << endl;
	}
	
}





long long fib(int n)
{
	long long a1 = 0, a2 = 1,a3 =1, res = 0;
	int i = 3;

	switch (n)
	{
	case 0:
		return 0;
		break;
	case 1:
		return 0;
		break;
	case 2:
		return 1;
		break;
	case 3:
		return 1;
		break;
	default:
		while (true)
		{
			a1 = a2 + a3;
			++i;
			if (i == n)
			{
				res = a1;
				break;
			}

			a2 = a3 + a1;
			++i;
			if (i == n)
			{
				res = a2;
				break;
			}

			a3 = a1 + a2; 
			++i;
			if (i == n)
			{
				res = a3;
				break;
			}
		}

		return res;
		break;
	}
}

long long fib2(int n)
{
	if (n == 0 || n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fib2(n - 2) + fib2(n - 1);
}