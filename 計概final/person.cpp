#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;



class People {
	public:
		People();
		void setFirst(int n);  //�@�}�l�n�h���@��
		void setFloor(int n); //�Ĥ@������n�h���Ǽ�
		void setTime(int n); // ���b�ӼӮɶ�
		void remove(int n);  //  �^��@�Ӥ������
		void add(); // �C�j�@�q�ɶ��X�{���H(0~2)
		int getFst(int n) {
			return person[n][0];
		}  //return �@�}�l�h���@��
		int getSecFloor(int n) {
			return person[n][2];    //return ��ӥh���@��
		}
		int getSize() {
			return sizeUsed;   // return ���h�֤H
		}

	private:

		int **person; //����[a][0~2] a�H�@�}�l�����; ���d�h�[; ����n�h���@��
		int sizeUsed; //�����H��
};



People::People() {

	*person = new int [150];   //�̦h150�ӤH

	for (int i = 0; 150 > i; i++) {
		person[i] = new int[3]; // person[n][0] : n�H�@�}�l�n�h���@�� ; [n][1]: ���b���Ӫ��ɶ�; person[n][2]: �A�ӭn�h���@��
	}

	sizeUsed = 0;   //�@�}�l�٨S���H

}
void People::setFirst(int n) { //�@�}�l�n�h���@��
	int f = rand() % 12 + 2; //�H���e�� 2 ~ 13��
	person[n][0] = f;
}
void People::setFloor(int n) {
	int floor = person[n][0]; //�]�w���쥻���Ӽh
	int f = rand() % 100 + 1;
	while (floor == person[n][0]) { //�קK�S��P�@�� ��:�p�G���@�ӤH�쥻�b2�ӡA�N���n���L�S��2��
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
void People::setTime(int n) { //�]�w���d�ɶ�
	int time = rand() % 81 + 20;
	person[n][1] = time;
}
void People::remove(int n) { //�^��@�ӫ����
	for (int i = 0; 3 > i; i++) {
		person[n][i] = person[sizeUsed - 1][i];  //��̫�@�ӤH����������ӤH����m
	}
	sizeUsed--;
}
void People::add() {
	int num = rand() % 3;  //�H���X�{0~2�H
	while (num > 0) {
		if (sizeUsed == 150) { //�p�G�w�g150�N���n�b�[�H
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


