#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <cmath>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

bool gameover, win;
int map[20] = {0};
int new_num, pos;
int score;

void setup() {
	gameover = false;
	win = false;
	new_num = ((rand() % 10) == 0) ? 4 : 2;
	pos = rand() % 16;
	map[pos] = new_num;
	score = 0;
}

bool can_left() {
	bool same[5] = { 0 };
	for (int i = 0; i < 4; i++) {
		int before[5], after[5];
		for (int j = 0; j < 4; j++) {
			before[j] = map[i * 4 + j];
			after[j] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				after[n] *= 2;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int q = 0; q < 4; q++) {
			if (before[q] == after[q]) {
				if (q == 3) same[i] = true;
				else continue;
			}
			else {
				break;
			}
		}
		/*
		for (int r = 0; r < 4; r++) {
			cout<<before[r]<<" ";
		}
		cout << endl;
		for (int r = 0; r < 4; r++) {
			cout << after[r] << " ";
		}
		cout << endl;
		*/
	}
	// cout << same[0] << " " << same[1] << " " << same[2] << " " << same[3] << endl;
	if (same[0] && same[1] && same[2] && same[3]) return false;
	else return true;
}

bool can_right() {
	bool same[5] = { 0 };
	for (int i = 0; i < 4; i++) {
		int before[5], after[5];
		for (int j = 0; j < 4; j++) {
			before[3-j] = map[i * 4 + j];
			after[3-j] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				after[n] *= 2;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int q = 0; q < 4; q++) {
			if (before[q] == after[q]) {
				if (q == 3) same[i] = true;
				else continue;
			}
			else {
				break;
			}
		}
		/*
		for (int r = 0; r < 4; r++) {
			cout<<before[r]<<" ";
		}
		cout << endl;
		for (int r = 0; r < 4; r++) {
			cout << after[r] << " ";
		}
		cout << endl;
		*/
	}
	// cout << same[0] << " " << same[1] << " " << same[2] << " " << same[3] << endl;
	if (same[0] && same[1] && same[2] && same[3]) return false;
	else return true;
}

bool can_up() {
	bool same[5] = { 0 };
	for (int j = 0; j < 4; j++) {
		int before[5], after[5];
		for (int i = 0; i < 4; i++) {
			before[i] = map[i * 4 + j];
			after[i] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				after[n] *= 2;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int q = 0; q < 4; q++) {
			if (before[q] == after[q]) {
				if (q == 3) same[j] = true;
				else continue;
			}
			else {
				break;
			}
		}
		/*
		for (int r = 0; r < 4; r++) {
			cout<<before[r]<<" ";
		}
		cout << endl;
		for (int r = 0; r < 4; r++) {
			cout << after[r] << " ";
		}
		cout << endl;
		*/
	}
	// cout << same[0] << " " << same[1] << " " << same[2] << " " << same[3] << endl;
	if (same[0] && same[1] && same[2] && same[3]) return false;
	else return true;
}

bool can_down() {
	bool same[5] = { 0 };
	for (int j = 0; j < 4; j++) {
		int before[5], after[5];
		for (int i = 0; i < 4; i++) {
			before[3-i] = map[i * 4 + j];
			after[3-i] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				after[n] *= 2;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int q = 0; q < 4; q++) {
			if (before[q] == after[q]) {
				if (q == 3) same[j] = true;
				else continue;
			}
			else {
				break;
			}
		}
		/*
		for (int r = 0; r < 4; r++) {
			cout<<before[r]<<" ";
		}
		cout << endl;
		for (int r = 0; r < 4; r++) {
			cout << after[r] << " ";
		}
		cout << endl;
		*/
	}
	// cout << same[0] << " " << same[1] << " " << same[2] << " " << same[3] << endl;
	if (same[0] && same[1] && same[2] && same[3]) return false;
	else return true;
}

void draw() {
	system("cls");
	cout << "+-----+-----+-----+-----+" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "+";
		for (int j = 0; j < 4; j++) {
			if (map[i * 4 + j] == 0)
				cout << "     ";
			else {
				//printf("%5d", map[i*4+j]);
				
				int bits = (int)log10(map[i * 4 + j]);
				int frontpad = 2 - (bits + 1) / 2;
				int backpad = 2 - bits / 2;
				//cout << bits << " " << frontpad << " " << backpad;
				for (int x = 0; x < frontpad; x++)cout << " ";
				cout << map[i * 4 + j];
				for (int y = 0; y < backpad; y++)cout << " ";
				
			}
			if (!(j == 3))
				cout << "|";
		}
		cout << "+" << endl;
		if (!(i == 3))
			cout << "+-----+-----+-----+-----+" << endl;
	}
	cout << "+-----+-----+-----+-----+" << endl;
	cout << "Score: " << score << endl;
	// cout << can_up() << endl;
}

void moveup() {
	for (int j = 0; j < 4; j++) {
		int after[5];
		for (int i = 0; i < 4; i++) {
			after[i] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				score += after[n];
				after[n] *= 2;
				if (after[n] == 2048) win = true;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			map[i * 4 + j] = after[i];
		}
	}
}

void movedown() {
	for (int j = 0; j < 4; j++) {
		int after[5];
		for (int i = 0; i < 4; i++) {
			after[3-i] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				score += after[n];
				after[n] *= 2;
				if (after[n] == 2048) win = true;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			map[i * 4 + j] = after[3-i];
		}
	}
}

void moveleft() {
	for (int i = 0; i < 4; i++) {
		int after[5];
		for (int j = 0; j < 4; j++) {
			after[j] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				score += after[n];
				after[n] *= 2;
				if (after[n] == 2048) win = true;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			map[i * 4 + j] = after[j];
		}
	}
}

void moveright() {
	for (int i = 0; i < 4; i++) {
		int after[5];
		for (int j = 0; j < 4; j++) {
			after[3-j] = map[i * 4 + j];
		}
		for (int time = 0, key = 0; time < 3; time++) {
			if (after[key] == 0) {
				for (int m = key; m < 3; m++) {
					after[m] = after[m + 1];
				}
				after[3] = 0;
			}
			else key++;
		}
		for (int n = 0; n < 3; n++) {
			if (after[n] == after[n + 1]) {
				score += after[n];
				after[n] *= 2;
				if (after[n] == 2048) win = true;
				for (int p = n + 1; p < 3; p++) {
					after[p] = after[p + 1];
				}
				after[3] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			map[i * 4 + j] = after[3-j];
		}
	}
}

void addnum() {
	new_num = ((rand() % 10) == 0) ? 4 : 2;
	int empty[16] = {};
	int empty_num = 0;
	for (int i = 0; i < 16; i++) {
		if (map[i] == 0) {
			empty[empty_num++] = i;
		}
	}
	map[empty[rand() % empty_num]] = new_num;
	draw();
}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case KEY_UP:
			if (can_up()) {
				moveup();
				addnum();
			}
			break;
		case KEY_DOWN:
			if (can_down()) {
				movedown();
				addnum();
			}break;
		case KEY_LEFT:
			if (can_left()) {
				moveleft();
				addnum();
			}
			break;
		case KEY_RIGHT:
			if (can_right()) {
				moveright();
				addnum();
			}
			break;
		default:
			break;
		}

	}
}

void loop() {
	input();
	if (!(can_up() || can_down() || can_left() || can_right())) gameover = true;
	if (win) {
		cout << "You won!" << endl;
		gameover = true;
	}
}

int main() {
	srand((unsigned)time(NULL));
	setup();
	draw();
	while (!gameover) {
		loop();
		Sleep(10);
	}
	cout << "You achieved " << score << " score!" << endl;
	cout << "Thanks for playing! Have a good time!!!" << endl;
	system("pause");
	return 0;
}