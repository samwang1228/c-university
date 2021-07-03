
#include <curses.h>                  // �޶i curses.h, �æ۰ʤ޶i stdio.h
#include <stdlib.h>
#define StartX  1                    // �M�w��Ъ�l��m
#define StartY  1
#include<vector>

main() {
	int x=StartX;                     // �ŧi x,y �ó]�w����
	int y=StartY;
	int ch;                           // �ŧi ch �����,�t�X getch() �ϥ�
	void initial();
	initial();                        // �I�s initial(), �Ұ� curses �Ҧ�,
	// �ç����䥦�]�w
	box(stdscr,'|','-');              // �e���
	attron(A_REVERSE);                // �}�ҤϥռҦ�
	mvaddstr(0,20,"Curses Program");  // �b (20,0) �B��X�ϥզr��
	attroff(A_REVERSE);               // �����ϥռҦ�

	move(x,y);                        // �N��в��ܪ�l��m

	do {                              // �H�L���j�餣�_���ݿ�J
		ch=getch();                      // ���ݦ���L��J�r��
		switch(ch) {                     // �P�_��J�r������

			case KEY_UP:
				--y;             // �P�_�O�_"��"��Q���U
				break;
			case KEY_DOWN:
				++y;           // �P�_�O�_"��"��Q���U
				break;
			case KEY_RIGHT:
				++x;          // �P�_�O�_"��"��Q���U
				break;
			case KEY_LEFT:
				--x;           // �P�_�O�_"��"��Q���U
				break;
			case '\r':                    // �P�_�O�_ ENTER ��Q���U
				++y;
				x=0;
				break;
			case '\t':                    // �P�_�O�_ TAB ��Q���U
				x+=7;
				break;
			case 127:                     // �P�_�O�_ BACKSPACE ��Q���U
				mvaddch(y,--x,' ');// delete �@�Ӧr��
				break;

			case 27:
				endwin();            // �P�_�O�_[ESC]��Q���U
				exit(1);             // ���� curses �Ҧ�
				// �������{��

			default:
				addch(ch);          // �p�G���O�S��r��, �N���r���L�X
				x++;
				break;
		}
		move(y,x);                      // ���ʴ�Цܲ{�b��m
	} while (1);
}

void initial() {                     // �۩w�}�� curses �禡
	initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
}
