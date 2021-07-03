#include <iostream>
#include <curses.h>
#define StartX  1                    /* 決定游標初始位置 */
#define StartY  1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	WINDOW *win = initscr();
	//attrset(A_NORMAL);            /* 先將屬性設定為正常模式       */
	attron(A_UNDERLINE);          /* 加底線                       */
	mvaddstr(9,10,"加底線");      /* 加底線輸出一串字元           */
	attroff(A_UNDERLINE);         /* 關閉加底線模式, 恢復正常模式 */
	attron(A_REVERSE);            /* 開啟反白模式                 */
	mvaddstr(10,10,"反白");       /* 輸出一串反白字元             */
	attroff(A_REVERSE);           /* 關閉反白模式, 恢復正常模式   */
	attron(A_BLINK);              /* 開啟閃爍模式                 */
	mvaddstr(11,10,"閃爍");       /* 輸出一串閃爍字元             */
	attroff(A_BLINK);             /* 關閉閃爍模式, 恢復正常模式   */
	attron(A_BOLD);               /* 開啟高亮度模式               */
	mvaddstr(12,10,"高亮度");     /* 輸出一串高亮度字元           */
	attroff(A_BOLD);              /* 關閉高亮度模式, 恢復正常模式 */
	//int c=getch();
	int n=0;
	box(win,'|','-');   //自動畫方框 y x
	echochar('a');
	char ch1,ch2;
	echochar('a');
	//scanw("%c%c",ch1,ch2);
	move(99,66);
	beep();
	box(win,ch1,ch2);
	scrollok(win,TRUE);
	endwin();
	//printw("%d",c);
	return 0;
}
