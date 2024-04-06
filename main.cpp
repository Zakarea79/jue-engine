#include <iostream>
#include <vector>
#include <unistd.h>
#include "v.h"

using namespace std;

void printl(string input)
{
	cout << input << endl;
}
void print(string input)
{
	cout << input;
}

class inputSystem
{
public:
	int get_input()
	{
		if (console.kbhit())
		{
			return console.getch();
		}
		else
		{
			return -1;
		}
	}
};
class transform
{
public:
	int x = 0;
	int y = 0;

public:
	transform set_vector2(int x, int y)
	{
		transform temp;
		temp.x = x;
		temp.y = y;
		return temp;
	}

public:
	transform get_vector2()
	{
		transform temp;
		temp.x = x;
		temp.y = y;
		return temp;
	}

public:
	operator string() const
	{
		return "x : " + to_string(x) + " , y : " + to_string(y);
	}
};

class GameObject
{
public:
	string name = "object";
	string sprite = "";

public:
	transform pos;
};
void Drow(string Defult_Sprite, int w, int h, vector<GameObject*>&list)
{
	bool drow_sprite = false;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			for (GameObject* obj : list)
			{
				if (obj->pos.x == i && obj->pos.y == j)
				{
					print(obj->sprite);
					drow_sprite = true;
				}
			}
			if (drow_sprite == false)
			{
				print(Defult_Sprite);
			}
			drow_sprite = false;
		}
		printl("");
	}
	usleep(100000);
	system("clear");
}
vector<GameObject*> listobj;
int main()
{
	GameObject* p1 =  new GameObject;
	p1->name = "player1";
	p1->sprite = "x";
	listobj.push_back(p1);
	//----------------------
	inputSystem ob;
	int x = 0, y = 0;
	while (true)
	{
		char key = ob.get_input();
		if(key == 'w') x -= 1; else if(key == 's') x += 1;
		if(key == 'd') y += 1; else if(key == 'a') y += -1;
		p1->pos = transform().set_vector2(x ,y);
		Drow(" " , 10 , 20 , listobj);
	}
	return 0;
}
