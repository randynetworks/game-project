#include <iostream>
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

}
void input() {

}
void logic() {

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