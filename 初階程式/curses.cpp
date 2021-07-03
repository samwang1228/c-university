#include <iostream>
#include <curses.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<cstdlib>
#include<time.h>
using namespace std;
int main() {
	srand(time(0));
	int x=79/2;                     // 宣告 x,y 並設定其初值
	int y=23/2;
	int a=0;
	initscr();
	cbreak();
	move(y,x);
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
	refresh();
	while(1) {
		int t=rand()%10+1;
		int select=rand()%100+1;
		if(y<23&&y>0&&x<79&&x>0&&(a==0||a==1)) {
			attron(A_UNDERLINE);     
			if(select<=85)
				x++;
			else if(select>85&&select<=90)
				x--;
			else if(select>90&&select<=95)
				y++;
			else if(select>95&&select<=100)
				y--;     	
		}
		if(y<23&&y>0&&x<79&&x>0&&a==2) {
			attron(A_BLINK);
			if(select<=85)
				x--;
			else if(select>85&&select<=90)
				x++;
			else if(select>90&&select<=95)
				y++;
			else if(select>95&&select<=100)
				y--; 
		}
		if(y<23&&y>0&&x<79&&x>0&&a==3) {
				 attron(A_REVERSE);
			if(select<=85)  
				y++;
			else if(select>85&&select<=90)
				x--;
			else if(select>90&&select<=95)
				x++;
			else if(select>95&&select<=100)
				y--;
		}
		if(y<23&&y>0&&x<79&&x>0&&a==4) {
			attron(A_BOLD);   
			if(select<=85)
				y--;
			else if(select>85&&select<=90)
				x--;
			else if(select>90&&select<=95)
				y++;
			else if(select>95&&select<=100)
				x++;
		}
		else if(y==23&&x==79&&select>=50)
			{
			x--;
			a=2;
		}
		else if (y==23&&x==79&&select<=50)
			{y--;a=4;}
		else if(x==0&&y==0&&select>=50)
			{x++;a=1;}
		else if (y==0&&x==0&&select<=50)
			{y++;a=3;}
		else if(x==79&&y==0&&select>=50)
			{y++;a=3;}
		else if (y==0&&x==79&&select<=50)
			{x--;a=2;}
		else if(x==0&&y==23&&select>=50)
			{y--;a=4;}
		else if (y==23&&x==0&&select<=50)
			{x++;a=1;}
		else if(y==0&&(x>0&&x<79)) {
			if(select<33)
				{y++;a=3;}
			else if(select>=33&&select<66)
				{x--;a=2;}
			else
				{x++;a=1;}
		}
		else if(y==23&&(x>0&&x<79)) {
			if(select<33)
				{y--;a=4;}
			else if(select>=33&&select<66)
				{x--;a=2;}
			else
				{x++;a=1;}
		}
		else if(x==0&&(y>0&&y<23)) {
			if(select<33)
				{y++;a=3;}
			else if(select>=33&&select<66)
				{y--;a=4;}
			else
				{x++;a=1;}
		}
		else if(x==79&&(y>0&&y<23)) {
			if(select<33)
				{y++;a=3;}
			else if(select>=33&&select<66)
				{y--;a=4;}
			else
				{x--;a=2;}
		}
		//refresh();
		move(y,x);
		addstr("助教好帥");
		refresh();
		Sleep(100);
		clear();
		refresh();
		//clrscr();
	}
}
