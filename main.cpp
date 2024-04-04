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
	while(true){
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				for (object obj : list){
					if(obj.pos.x == i && obj.pos.y == j){
						print(obj.sprite);
					}else{
						print("#");
					}
				}
			}
			printl("");
		}
		usleep(100000);
		system("clear");
	}
}

int main(){
	std::vector<object> listobj;
	object p;
	p.name = "Player";
	p.sprite = "*";
	listobj.push_back(p);
	/*object p2;
	p2.name = "Player2";
	p2.sprite = "o";
	p2.pos.x = 3;
	p2.pos.y = 7;
	listobj.push_back(p2);*/
	Drow(10 ,20 , listobj);
	return 0;
}
