#include <iostream>
#include <curses.h>
#define StartX  1                    /* �M�w��Ъ�l��m */
#define StartY  1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	WINDOW *win = initscr();
	//attrset(A_NORMAL);            /* ���N�ݩʳ]�w�����`�Ҧ�       */
	attron(A_UNDERLINE);          /* �[���u                       */
	mvaddstr(9,10,"�[���u");      /* �[���u��X�@��r��           */
	attroff(A_UNDERLINE);         /* �����[���u�Ҧ�, ��_���`�Ҧ� */
	attron(A_REVERSE);            /* �}�ҤϥռҦ�                 */
	mvaddstr(10,10,"�ϥ�");       /* ��X�@��ϥզr��             */
	attroff(A_REVERSE);           /* �����ϥռҦ�, ��_���`�Ҧ�   */
	attron(A_BLINK);              /* �}�Ұ{�{�Ҧ�                 */
	mvaddstr(11,10,"�{�{");       /* ��X�@��{�{�r��             */
	attroff(A_BLINK);             /* �����{�{�Ҧ�, ��_���`�Ҧ�   */
	attron(A_BOLD);               /* �}�Ұ��G�׼Ҧ�               */
	mvaddstr(12,10,"���G��");     /* ��X�@�갪�G�צr��           */
	attroff(A_BOLD);              /* �������G�׼Ҧ�, ��_���`�Ҧ� */
	//int c=getch();
	int n=0;
	box(win,'|','-');   //�۰ʵe��� y x
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
