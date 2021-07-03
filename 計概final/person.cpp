#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;



class People {
	public:
		People();
		void setFirst(int n);  //秨﹍璶加
		void setFloor(int n); //材Ωぇ璶êㄇ加
		void setTime(int n); // 氨赣加丁
		void remove(int n);  //  加ぇア
		void add(); // –筳琿丁瞷(0~2)
		int getFst(int n) {
			return person[n][0];
		}  //return 秨﹍加
		int getSecFloor(int n) {
			return person[n][2];    //return ㄓ加
		}
		int getSize() {
			return sizeUsed;   // return Τぶ
		}

	private:

		int **person; //魁[a][0~2] a秨﹍柑; 氨痙; ぇ璶加
		int sizeUsed; //魁计
};



People::People() {

	*person = new int [150];   //程150

	for (int i = 0; 150 > i; i++) {
		person[i] = new int[3]; // person[n][0] : n秨﹍璶加 ; [n][1]: 氨ê加丁; person[n][2]: ㄓ璶加
	}

	sizeUsed = 0;   //秨﹍临⊿Τ

}
void People::setFirst(int n) { //秨﹍璶加
	int f = rand() % 12 + 2; //繦诀玡┕ 2 ~ 13加
	person[n][0] = f;
}
void People::setFloor(int n) {
	int floor = person[n][0]; //砞﹚セ加糷
	int f = rand() % 100 + 1;
	while (floor == person[n][0]) { //磷加 ㄒ:狦Τセ2加碞ぃ璶琵2加
		if (f < 80) {
			person[n][2] = 1;
		} else if (f == 80 && f == 81) {
			floor = 2;
		} else if (f == 82 && f == 83) {
			floor = 3;
		} else if (f == 84 && f == 85) {
			floor = 4;
		} else if (f == 86 && f == 87) {
			floor = 5;
		} else if (f == 88 && f == 89) {
			floor = 6;
		} else if (f == 90 && f == 91) {
			floor = 7;
		} else if (f == 92 && f == 93) {
			floor = 8;
		} else if (f == 94 && f == 95) {
			floor = 9;
		} else if (f == 96 && f == 97) {
			floor = 10;
		} else if (f == 98 && f == 99) {
			floor = 11;
		} else {
			floor = 12;
		}
	}
	person[n][2] = floor;
}
void People::setTime(int n) { //砞﹚氨痙丁
	int time = rand() % 81 + 20;
	person[n][1] = time;
}
void People::remove(int n) { //加ア
	for (int i = 0; 3 > i; i++) {
		person[n][i] = person[sizeUsed - 1][i];  //р程簿アê竚
	}
	sizeUsed--;
}
void People::add() {
	int num = rand() % 3;  //繦诀瞷0~2
	while (num > 0) {
		if (sizeUsed == 150) { //狦竒150碞ぃ璶
			break;
		}
		setFirst(sizeUsed - 1);
		num--;
		sizeUsed++;
	}

}
int main() {
	initscr();
	cbreak();
	move(y,x);
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
	refresh();
}


