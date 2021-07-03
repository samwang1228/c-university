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

int setY(int floor); //砞﹚加糷y畒夹 
void Floor(); //1~12加  x: 0-1
void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor); //加糷单筿辫 x: 2-17
void fstFloor(int n, int fstFloor, int nextFloor); //n秨﹍稱加糷  x: 33-47 (15) 


int setY(int floor) //砞﹚加糷y畒夹 
{
	int y;
	if (floor == 1)
	{
		y = 22; //加 y:22 
	}
	else if (floor == 2)
	{
		y = 20; //2加 y:20 
	}
	else if (floor == 3)
	{
		y = 18; //3加 y:18 
	}
	else if (floor == 4)
	{
		y = 16; //4加 y:16 
	}
	else if (floor == 5)
	{
		y = 14; //5加 y:14 
	}
	else if (floor == 6)
	{
		y = 12; //6加 y:12 
	}
	else if (floor == 7)
	{
		y = 10; //7加 y:10 
	}
	else if (floor == 8)
	{
		y = 8; //8加 y:8 
	}
	else if (floor == 9)
	{
		y = 6; //9加 y:6 
	}
	else if (floor == 10)
	{
		y = 4; //10加 y:4
	}
	else if (floor == 11)
	{
		y = 2; //11加 y:2 
	}
	else if (floor == 12)
	{
		y = 0; //12加 y:0
	}
	return y;
}

void outputFloor(int floor, int x, int y) //加糷
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

void Floor()  //1~12加  x: 0-1
{
	attron(A_REVERSE); //ゴ秨はフ 
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
    attroff(A_REVERSE); //闽超はフ 
    refresh();
}

void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor) //加糷单筿辫 x: 2-17
{
	int x = n + 2;  //x畒夹眖2秨﹍ n: ê糷加单筿辫材碭 (眖0秨﹍) 
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

void fstFloor(int n, int fstFloor, int nextFloor) //n秨﹍稱加糷  x: 33-47 (15) 
{
	int x = n + 33; //n琌眖 0 秨﹍眖 x = 33秨﹍
	int y = setY(fstFloor);

	outputFloor (nextFloor, x, y);
} 

void printE1(int e1Floor, int usage, int num) //材筿辫 x: 50-58  + ㄏノ秖, num:筿辫计 
{
	int y = setY(e1Floor);
	move(y, 50);
	printw("|__%d__|",usage);
	
	if (num > 0) //筿辫Τ陪ボ计 
	{
		move(y - 1, 54);
		attron(A_REVERSE); //ゴ秨はフ  
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ	
	}
	refresh();
}
void printE2(int e2Floor, int usage, int num) // 材筿辫 x: 61-69 + ㄏノ秖, num :筿辫计 
{
	int y = setY(e2Floor);
	move(y, 61);
	printw("|__%d__|",usage);
	if (num > 0) //筿辫Τ陪ボ计 
	{
		move(y - 1, 64);
		attron(A_REVERSE); //ゴ秨はフ  
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ	
	}
	
	refresh();
}
void printE3(int e3Floor, int usage, int num) //材筿辫 x: 72-79 + ㄏノ秖, 筿辫计 
{
	int y = setY(e3Floor);
	move(y, 72);
	printw("|__%d__|",usage);
	if (num > 0) //筿辫Τ陪ボ计 
	{
		move(y - 1, 75);
		attron(A_REVERSE); //ゴ秨はフ  
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ	
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



