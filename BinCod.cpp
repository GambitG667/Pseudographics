#include <iostream>
#include <string>
#include <vector>
#include <map>

/*идея в том, что для кодовых слов переменной длины должно соблюдаться правило Фано, ни одно слово не должно составлять начало другого, для нахождения таких слов
составляются битовые деревья*/


class BinPoint   //класс точки графа битвого дерева
{
public:

	BinPoint* up_point = 0;
	BinPoint* down_left = 0;
	BinPoint* down_right = 0;

	std::string value;

	int depth;
	bool zero_point;
	bool last_point;
	
	BinPoint(int max_depth)
	{
		this->up_point = 0;
		this->down_left = 0;
		this->down_right = 0;

		this->depth = 0;

		value = "";

		zero_point = true;
		depth == max_depth ? last_point = true : last_point = false;

		if (!last_point)
		{
			down_left = new BinPoint(this, value + "0", depth + 1, max_depth);
			down_right = new BinPoint(this, value + "1", depth + 1, max_depth);
		}
	}
	
	BinPoint(BinPoint* up_point,std::string value , int depth, int max_depth)
	{
		this->up_point = up_point;
		this->depth = depth;

		this->value = value;

		zero_point = false;
		depth == max_depth ? last_point = true : last_point = false;

		if (!last_point)
		{
			if (depth % 2 == 0)
			{
				down_left = new BinPoint(this, value + "0", depth + 1);
				down_right = new BinPoint(this, value + "1", depth + 1, max_depth);
			}
			else
			{
				down_left = new BinPoint(this, value + "0", depth + 1, max_depth);
				down_right = new BinPoint(this, value + "1", depth + 1);
			}

			
		}
	}

	BinPoint(BinPoint* up_point, std::string value, int depth)
	{
		this->up_point = up_point;
		this->depth = depth;

		this->value = value;

		zero_point = false;
		last_point = true;
	}


	~BinPoint()
	{
		delete down_left;
		delete down_right;		
	}

};

class BinTree
{
private:
	BinPoint* tree;
	BinPoint* root;
	BinPoint* reader;

public:
	BinTree(int max_depth)
	{
		tree = new BinPoint(max_depth);
		root = tree;
		reader = tree;
	}

	~BinTree()
	{
		delete tree;
	}

};

void Print(BinPoint* point)
{
	if (point->last_point)
	{
		std::cout << point->value << std::endl;
	}
	else
	{
		Print(point->down_left);
		Print(point->down_right);
	}
}

void Sort(std::vector <std::string>& keys)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;

		for (int i = 0; i + 1 < keys.size(); ++i)
		{
			if ( keys[i].length() > keys[i + 1].length())
			{
				std::swap(keys[i], keys[i + 1]);
				sorted = false;
			}
		}

	}
	
}

void Print(BinPoint* point, std::vector <std::string>& keys)
{
	if (point->last_point)
	{
		keys.push_back(point->value);
	}
	else
	{
		Print(point->down_left,keys);
		Print(point->down_right,keys);
	}

}

class Translator  //сам переводчик. составляет два словаря, а потом ищет значение слова
{
public:
	std::map<std::string, char> decript_key;
	std::map<char, std::string> cript_key;

	Translator()
	{
		BinPoint tree(16);
		std::vector <std::string> keys;
		std::string Alf = " ETAOINSHRDLCUMWFGYPBVKXJQZ"; //буквы в порядке частоты

		Print(&tree, keys);
		Sort(keys);

		for (int i = 0; i < Alf.size(); ++i)
		{
			decript_key.insert(make_pair(keys[i], Alf[i]));
			cript_key.insert(make_pair(Alf[i], keys[i]));
		}
	}
	std::string cript(const std::string& str)
	{
		std::string res = "";

		for (char i : str)
		{
			res.append(cript_key[i]);
		}
		return res;
	}
	std::string decript(const std::string& str)  
	{
		std::string res = "";
		std::string key = "";

		for (char i : str)         //выясняет длину слова увеличивая его на букву и ища его в словаре
		{
			key += i;
			if (decript_key.count(key))
			{
				res += decript_key[key];
				key = "";
			}
		}
		return res;
	}
};



int main()
{
	Translator t;

	std::string str = t.cript("YOU IN THE ARMY NOW OOOUO");  //вооуво, теперь ты в армии, ***)))
	std::string str2 = t.decript("0010101010000111010101101101100100010000010111101100101011001010100001010101000100100001110101010001001100110011101010110011");

	std::cout << str <<std::endl;
	std::cout << str2 << std::endl;

	return 0;
}
