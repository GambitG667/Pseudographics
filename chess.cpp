#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

int main()
{
	int x1,y1,x2,y2;
	setlocale(LC_ALL, "ru");
	cout << "Введите начальное положение" << endl;
	cin >> x1 >> y1;
	cout << "Введите конечное положение" << endl;
	cin >> x2 >> y2;

	cout << "\nКороль" << endl;
	if (x1-1 <= x2 && x2 <= x1+1 && y1-1 <= y2 && y2 <= y1+1)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nКонь" << endl;
	if (pow((x1-x2),2) + pow((y1 - y2),2) == 5)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nЛадья" << endl;
	if (x1 == x2 || y1 == y2)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nСлон" << endl;
	if (abs(x1 - x2) == abs(y1 - y2))
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nФерзь" << endl;
	if (abs(x1 - x2) == abs(y1 - y2) || x1 == x2 || y1 == y2)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nБелая пешка" << endl;
	if (x2 == x1 + 1 && y1 == y2)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;

	cout << "\nЧерная пешка" << endl;
	if (x2 == x1 - 1 && y1 == y2)
		cout << "ДА" << endl;
	else
		cout << "НЕТ" << endl;
	
	return 0;
}
