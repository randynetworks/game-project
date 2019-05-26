#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, Score;
// deklarasi untuk membuat ujung dari snakenya
int tailX[100], tailY[100];
int nTail;
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
	for (int i = 0; i < width+2 ; i++) {
		cout << "#";
	}
	cout << endl;
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
				// membuat tail
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print) {
					cout << " ";
				}
			}
			if (j == width - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}
	// membuat map battom
	for (int i = 0; i < width +2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score : " << Score << endl;
	cout << "How To: " << endl;
	cout << "W = UP, S = DOWN" << endl;
	cout << "D = RIGHT, A = LEFT" << endl;


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
	//untuk ekornya
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	for (int i = 0; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		tailX[0] = x;
		tailY[0] = y;

	}

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

	/*logika agar ketika mengenai tembok, program berakhir
	if (x > width || x < 0 || y > height || y < 0){
		gameOver = true;
	}
	*/
	//logika agar ketika mengenai tembok, ular menembus dan berpindah ke sisi lainnya
	if (x >= width) { 
		x = 0; 
	} else if (x < 0) { 
		x = width - 1; 
	}
	if (y >= height) { 
		y = 0; 
	} else if (y < 0) {
		y = height - 1; 
	}
	//logika agar ketika ularnya mengenai ekornya, dia mati, program berakhir
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY) {
		// membuat score
		Score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main() {

	setup();
	while (!gameOver) {
		draw();
		input();
		logic();
		Sleep(10); //sleep()
	}

	return 0;
}