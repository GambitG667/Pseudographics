#include <iostream>
#include <string>
#include <locale.h>
#include <conio.h>
#include <windows.h>

/*Я наконец понял как сюда добавить кириллицу))*/

using namespace std;

void vijner(string &txt, string key, int mode);

int main()
{
	SetConsoleCP(1251);       /* исключительно винды прикол установление кодировки ввода с консоли на linux должно и без этого работать*/
	setlocale(LC_ALL, "ru");
	string txt , key;
	int mode;

	char x = '1';
	while (x == '1')
	{
		cout << "Введите текст КАПСОМ: ";                            /*"cin >> ws" - чтобы знаки переноса в потоке не сохранялись и ввод работал нормально*/
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
	string A = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";   /* Алфавит. Можно добавить еще какие угодно символы, но у шифратора и дешифратора должен быть одинаковым*/
	string longkey;
	while (longkey.length() < txt.length())  /*удлинение ключа по алгоритму шифрования до длины теста*/
		longkey.append(key);
	for (int i = 0; i < txt.length(); ++i)
	{
		txt[i] = A[(A.length() + A.find(txt[i]) + mode * A.find(longkey[i])) % A.length()]; 
	}
}                                                                                                  /*Капец сложная формула которую я 
												вывожу четвертый раз и каждый раз забываю как я это сделал
												по идее тут тоже самое что и с мотоциклистом
												индекс буквы - его место в алфавите
												индекс зашифрованной буквы - это индекс первоначальной буквы
												смещенный вправо на величину индекса соответствующей буквы ключа,
												если индекс выходит за пределы алфавита,
												то происходит закольцовывание (переход к противоположному концу алфавита)
												дешифровка - смещение наоборот влево*/
