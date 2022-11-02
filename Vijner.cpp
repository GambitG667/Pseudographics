#include <iostream>
#include <string>
#include <locale.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void vijner(string &txt, string key, int mode);

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	string txt , key;
	int mode;

	char x = '1';
	while (x == '1')
	{
		cout << "Введите текст КАПСОМ: ";
		getline(cin >> ws, txt);
		cout << "Введите ключ КАПСОМ: ";
		getline(cin >> ws, key);
		cout << "Выберите режим (1 - шифровать, -1 - дешифровать): ";
		cin >> mode;
		vijner(txt, key, mode);
		cout << "Получите распишитесь: " << txt << endl;
		x = _getch();

	}



	return 0;
}

void vijner(string &txt, string key, int mode)
{
	string A = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
	string longkey;
	while (longkey.length() < txt.length())
		longkey.append(key);
	for (int i = 0; i < txt.length(); ++i)
	{
		txt[i] = A[(A.length() + A.find(txt[i]) + mode * A.find(longkey[i])) % A.length()];
	}
}