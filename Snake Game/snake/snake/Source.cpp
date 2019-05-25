#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, Score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
//membuat function : Setup, Draw, Input, logic 
void setup() {
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	Score = 0;
}	
void draw() {
	system("cls");
	// membuat map top
	for (int i = 0; i < width ; i++) {
		cout << "#";
	}
	// area tengah 
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "#";
			
			}
			if (i == y && j == x){
				cout << "0";
			}
			else if (i == fruitY && j == fruitX){
				cout << "F";
			}
			else {
				cout << " ";
			}
			if (j == width - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}

	// membuat map battom
	for (int i = 0; i < width +1; i++) {
		cout << "#";
	}


}
void input() {
	//control handdle
	if (_kbhit()) {
		switch (_getch()){
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void logic() {

	//direction
	switch (dir){

	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--; 
		break;
		
	case DOWN:
		y++;
		break;
		
	default:
		break;
	}
}

int main() {

	setup();
	while (!gameOver) {
		draw();
		input();
		logic();
	}

	return 0;
}