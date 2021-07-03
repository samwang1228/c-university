#include <iostream>
#include <curses.h> 
#include <cstdlib> 
#include <Windows.h>

using namespace std;

void initial()   
{
	initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	refresh();
}

int setY(int floor); //�]�w�U�Ӽhy���y�� 
void Floor(); //�L�X1~12��  x: 0-1
void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor); //�L�X�U�Ӽh���ݹq�誺�H x: 2-17
void fstFloor(int n, int fstFloor, int nextFloor); //�L�Xn�H�@�}�l�Q�h���Ӽh  x: 33-47 (15��) 


int setY(int floor) //�]�w�U�Ӽhy���y�� 
{
	int y;
	if (floor == 1)
	{
		y = 22; //�@�� y:22 
	}
	else if (floor == 2)
	{
		y = 20; //2�� y:20 
	}
	else if (floor == 3)
	{
		y = 18; //3�� y:18 
	}
	else if (floor == 4)
	{
		y = 16; //4�� y:16 
	}
	else if (floor == 5)
	{
		y = 14; //5�� y:14 
	}
	else if (floor == 6)
	{
		y = 12; //6�� y:12 
	}
	else if (floor == 7)
	{
		y = 10; //7�� y:10 
	}
	else if (floor == 8)
	{
		y = 8; //8�� y:8 
	}
	else if (floor == 9)
	{
		y = 6; //9�� y:6 
	}
	else if (floor == 10)
	{
		y = 4; //10�� y:4
	}
	else if (floor == 11)
	{
		y = 2; //11�� y:2 
	}
	else if (floor == 12)
	{
		y = 0; //12�� y:0
	}
	return y;
}

void outputFloor(int floor, int x, int y) //�L�X�Ӽh
{
	if (floor == 1)
	{
		mvaddch(y, x, '1');
	}
	else if (floor == 2)
	{
		mvaddch(y, x, '2');
	}
	else if (floor == 3)
	{
		mvaddch(y, x, '3');
	}
	else if (floor == 4)
	{
		mvaddch(y, x, '4');
	}
	else if (floor == 5)
	{
		mvaddch(y, x, '5');		
	}
	else if (floor == 6)
	{
		mvaddch(y , x, '6');
	}
	else if (floor == 7)
	{
		mvaddch(y, x, '7');
	}
	else if (floor == 8)
	{
		mvaddch(y, x, '8');
	}
	else if (floor == 9)
	{
		mvaddch(y, x, '9');
	}
	else if (floor == 10)
	{
		mvaddch(y, x, 'A');
	}
	else if (floor == 11)
	{
		mvaddch(y, x, 'B');		
	}
	else if (floor == 12)
	{
		mvaddch(y , x, 'C');
	}
	refresh();
}

void Floor()  //�L�X1~12��  x: 0-1
{
	attron(A_REVERSE); //���}�ϥ� 
	mvaddstr(22, 0, "1F");
    mvaddstr(20, 0, "2F");
    mvaddstr(18, 0, "3F");
    mvaddstr(16, 0, "4F");
    mvaddstr(14, 0, "5F");
    mvaddstr(12, 0, "6F");
    mvaddstr(10, 0, "7F");
    mvaddstr(8, 0, "8F");
    mvaddstr(6, 0, "9F");
    mvaddstr(4, 0, "AF");
    mvaddstr(2, 0, "BF");
    mvaddstr(0, 0, "CF");
    attroff(A_REVERSE); //�����ϥ� 
    refresh();
}

void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor) //�L�X�U�Ӽh���ݹq�誺�H x: 2-17
{
	int x = n + 2;  //x�y�бq2�}�l�A n: ���h�ӵ��ݹq�誺�ĴX�H (�q0�}�l) 
	int y = setY(fstFloor);  
	if (elevatorFloor == fstFloor)
	{
		outputFloor(nextFloor, x, y);
	}
	else 
	{
		outputFloor (fstFloor, x, y);
	}
}

void fstFloor(int n, int fstFloor, int nextFloor) //�L�Xn�H�@�}�l�Q�h���Ӽh  x: 33-47 (15��) 
{
	int x = n + 33; //n�O�q 0 �}�l�A�q x = 33�}�l�L
	int y = setY(fstFloor);

	outputFloor (nextFloor, x, y);
} 

void printE1(int e1Floor, int usage, int num) //�Ĥ@�x�q�� x: 50-58  + �ϥζq, num:�q��H�� 
{
	int y = setY(e1Floor);
	move(y, 50);
	printw("|__%d__|",usage);
	
	if (num > 0) //�q�観�H�~��ܤH�� 
	{
		move(y - 1, 54);
		attron(A_REVERSE); //���}�ϥ�  
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�	
	}
	refresh();
}
void printE2(int e2Floor, int usage, int num) // �ĤG�x�q�� x: 61-69 + �ϥζq, num :�q��H�� 
{
	int y = setY(e2Floor);
	move(y, 61);
	printw("|__%d__|",usage);
	if (num > 0) //�q�観�H�~��ܤH�� 
	{
		move(y - 1, 64);
		attron(A_REVERSE); //���}�ϥ�  
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�	
	}
	
	refresh();
}
void printE3(int e3Floor, int usage, int num) //�ĤT�x�q�� x: 72-79 + �ϥζq, �q��H�� 
{
	int y = setY(e3Floor);
	move(y, 72);
	printw("|__%d__|",usage);
	if (num > 0) //�q�観�H�~��ܤH�� 
	{
		move(y - 1, 75);
		attron(A_REVERSE); //���}�ϥ�  
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�	
	}
	refresh();
}


int main()
{
	
	initial();
	Floor();
	waitEle(1, 2, 3, 2);
	fstFloor(1, 1, 12);
	printE1(1, 22, 2);
	printE2(1, 22, 1);
	
	printE3(1, 22, 5);

	return 0;
}



