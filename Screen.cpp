#include <iostream>

struct ScreenArray
{
	int* screenArray;
	int width;
	int height;
};
struct TitlArray
{
	int* titlArray;
	int lengthTitl;
	int heightTitl;
	int widthTitl;

};


class Screen
{
private:

	int* titlArray;
	int lengthTitl;
	int heightTitl;
	int widthTitl;


	int *screenArray;

	char *simbolsArray;

	int width;
	int height;


public:
	Screen()
	{
		titlArray = new int[18]{0, 0, 0,
								0, 0, 0,
								0, 0, 0,
								0, 1, 0,
								1, 1, 1,
								0, 1, 0};
		lengthTitl = 9;
		heightTitl = 3;
		widthTitl = 3;
		

		screenArray = new int[25]{0,0,0,0,0,
								  0,0,1,0,0,
								  0,0,0,1,0,
								  0,1,1,1,0,
								  0,0,0,0,0,};
		height = 5;
		width = 5;

		simbolsArray = new char[2] {char(32),char(254)};

	}

	Screen(ScreenArray screenArr, TitlArray titlArr, char(&simbolsArr)[])
	{
		screenArray = screenArr.screenArray;

		height = screenArr.height;
		width = screenArr.width;

		titlArray = titlArr.titlArray;

		lengthTitl = titlArr.lengthTitl;
		
		heightTitl = titlArr.heightTitl;
		widthTitl = titlArr.widthTitl;


		simbolsArray = simbolsArr;
	}

	void print()
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				std::cout << simbolsArray[screenArray[i * width + j]];
			}
			std::cout << std::endl;
		}
	}

	void titlPrint()
	{
		for (int i = 0; i < height * heightTitl; ++i)
		{
			for (int j = 0; j < width * widthTitl; ++j)
			{
				int coordinatInScreen = i / heightTitl * width + j / widthTitl;
				int coordinatInTitl = i % heightTitl * widthTitl + j % widthTitl + lengthTitl * screenArray[coordinatInScreen];
				std::cout << simbolsArray[titlArray[coordinatInTitl]];
			}
			std::cout << '\n';
		}
		
	}
};
