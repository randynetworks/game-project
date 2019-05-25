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
	system("cls");
	// membuat map top
	for (int i = 0; i < width ; i++) {
		cout << "#";
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "#";
			
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