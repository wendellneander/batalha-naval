#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 9;
string letters[SIZE] = {"   ","A |","B |","C |","D |","E |","F |","G |","H |"};
string numbers[SIZE] = {"   "," 1|"," 2|"," 3|"," 4|"," 5|"," 6|"," 7|"," 8|"};

struct point{
	string user;
	string ship;
};

point map[SIZE][SIZE];


void implements_map();
void draw_map();
void verify_position();

main(){
	implements_map();
	draw_map();
}

void implements_map(){
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			
			if(x == 0 && y == 0){
				map[x][y].user = "  |";
			}else if(x == 0){
				map[x][y].user = letters[y];
			}else if(y == 0){
				map[x][y].user = numbers[x];
			}else{
				map[x][y].user = "  |";
			}
			
		}
	}
}

void draw_map(){
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			cout << map[x][y].user;
		}
		cout << endl << "---------------------------" << endl;
	}
}


