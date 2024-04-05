#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void printl(string input){
	cout<<input<<endl;
}
void print(string input){
	cout<<input;
}
class transform{
	public: 
	int x = 0;
	int y = 0;

	public: transform set_vector2(int x , int y)
	{
		transform temp;
		temp.x = x;
		temp.y = y;
		return temp;
	}

	public: transform vector2(){
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

class object{
	public:
	string name = "";
	string sprite = "";
	public: transform pos;
};

void  Drow(int w , int h , std::vector<object>& list){
	bool drow_sprite = false;
	while(true){
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				for (object obj : list){
					if(obj.pos.x == i && obj.pos.y == j){
						print(obj.sprite);
						drow_sprite = true;
					}
				}
				if(drow_sprite == false){
					print("#");
				}
				drow_sprite = false;
			}
			printl("");
		}
		usleep(100000);
		system("clear");
	}
}
vector<object> listobj;
int main(){
	object p1;
	p1.name = "player1";
	p1.sprite = "o";
	p1.pos = transform().set_vector2(1 ,1);
	listobj.push_back(p1);
	//----------------------
	p1.pos = transform().set_vector2(2 ,2);
	p1.sprite = "*";
	listobj.push_back(p1);

	Drow(10 ,20 , listobj);
	return 0;
}
