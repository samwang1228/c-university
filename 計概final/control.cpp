#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <Windows.h>
#include <cstring>
#include <cmath> //ceil
#include <ctime>
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
		int get_people_wait_time(int people) {
			return person[people][1];
		}

	private:

		int person[150][3]; //����[a][0~2] a�H�@�}�l�����; ���d�h�[; ����n�h���@��
		int sizeUsed; //�����H��
};



People::People() {

	for(int i=0; i<150; i++) {
		for(int j=0; j<3; j++) {
			person[i][j]=0;
		}
	}
	/*person = new int *[150];   //�̦h150�ӤH

	for (int i = 0; i<150; i++) {
		person[i] = new int[3]; // person[n][0] : n�H�@�}�l�n�h���@�� ; [n][1]: ���b���Ӫ��ɶ�; person[n][2]: �A�ӭn�h���@��
	}*/

	sizeUsed = 0;   //�@�}�l�٨S���H

}
void People::setFirst(int n) { //�@�}�l�n�h���@��
	//srand(time(0));
	int f = rand() % 11 + 2; //�H���e�� 2 ~ 12��
	person[n][0] = f;
}
void People::setFloor(int n) {
	int floor = person[n][0]; //�]�w���쥻���Ӽh
	//srand(time(0));
	//int f = rand() % 100 + 1;
	while (floor == person[n][0]) { //�קK�S��P�@�� ��:�p�G���@�ӤH�쥻�b2�ӡA�N���n���L�S��2��
			int f = rand() % 100 + 1;
		if (f < 80) {
			person[n][2] = 1;
		} else if (f == 80 || f == 81) {
			floor = 2;
		} else if (f == 82 || f == 83) {
			floor = 3;
		} else if (f == 84 || f == 85) {
			floor = 4;
		} else if (f == 86 || f == 87) {
			floor = 5;
		} else if (f == 88 || f == 89) {
			floor = 6;
		} else if (f == 90 || f == 91) {
			floor = 7;
		} else if (f == 92 || f == 93) {
			floor = 8;
		} else if (f == 94 || f == 95) {
			floor = 9;
		} else if (f == 96 || f == 97) {
			floor = 10;
		} else if (f == 98 || f == 99) {
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
	//srand(time(0));
	int num = rand() % 3;  //�H���X�{0~2�H
	while (num > 0) {
		if (sizeUsed == 150) { //�p�G�w�g150�N���n�b�[�H
			break;
		}
		++sizeUsed;
		setFirst(sizeUsed - 1);
		num--;
	}

}
class Elevator {
	public:
		Elevator();
		void Add(int elevator,int people); //0 1 2 ���@�x�q�� �W�[�h�֤H

		void minus(int elevator,int people); //0 1 2 ���@�x�q�� ��h�h�֤H

		void setusage(bool a,bool b,bool c);//a b c �ǤJ�q��O�_���b���� �Y���b�}���Nfalse
		//�C���n�I�s�@��

		int assign(int floor,bool first);//���@�ӼӼh�ݭn�A�� �^��0 1 2(���̪�or�ϥζq�̤֪��q��L�h)

		void waitTime(int elevator,int people);//0 1 2���@�x�q��n�X�J�h�֤H
		int getUse(int n) { //�^�Ǩϥζq
			return eleout[n][2];
		}
		int getwait_time(int n) {
			return eleout[n][5];
		}
		int get_elevator_floor_number(int n) {
			return eleout[n][0];
		}
		void settime();//�C���n�I�s�@�� �@�����0����
	private:
		//eleout  �O����x�q�誺��T
		int eleout[3][8]; //[0][] [1][] [2][]����k���T�x�q��
		//[][0]�{�b���X�ӤH
		//[][1]�{�b�b���@��
		//[][2]�ϥζq
		//[][3]�U�@�ӭn�h��
		//[][4]�{�b�b���W(��1)�٩��U(��-1) �ٰ���(��0)
		//[][5]���b���ݪ��ܵ��ݪ��ɶ�
		//[][6]�Ⱥ��P�_(�Ⱥ�1,�D�Ⱥ�-1)
		//[][7]���ݻP�_(���b����1,�_�h-1)

		//elein  �����q��̭������p
		int elein[3][12]; //[0][] [1][] [2][]����k���T�x�q��
		//[][N] �ӹq�褺�n�hN+1�Ӫ����X�ӤH
		//��p[1][5] �O���ۤ������x�q��n�h6�Ӫ����X�ӤH

};
Elevator::Elevator() {
	for(int i=0; i<3; i++) {
		eleout[i][0]=0;
		eleout[i][1]=1;
		eleout[i][2]=0;
		//eleout[i][3]=;
		//eleout[i][4]=;
		eleout[i][5]=0;
		eleout[i][6]=-1;
		eleout[i][7]=-1;
		for(int j=0; j<12; j++) {
			elein[i][j]=0;
		}
	}
}

void Elevator::Add(int elevator,int people) {
	eleout[elevator][0]+=people;
	if(eleout[elevator][0]==10) {
		eleout[elevator][6]=1;
	}
}
void Elevator::minus(int elevator,int people) {
	if(eleout[elevator][0]==10) {
		eleout[elevator][6]=-1;
		eleout[elevator][7]=1;
	}
	eleout[elevator][0]-=people;
}
int Elevator::assign(int floor, bool first) {
	//�n�h�@�� ���ϥζq�̤֪�
	//rand(time(0));
	if(first==true)//�Ĥ@��
	{
		return rand()%3;
	}
	else
	{
	if(floor==1) {
		int elevator;
		int min=5000000;
		for(int i=0; i<3; i++) {
			if( eleout[i][2]<min && eleout[i][6]==-1 && eleout[i][7]==-1) {
				min=eleout[i][2];
				elevator=i;
			}
		}
		return elevator;
	}
	//���O�n�h�@�� ���̪�
	else {
		int min=13;
		int elevator;
		for(int i=0; i<3; i++) {
			if(abs(eleout[i][1]-floor)<=min && eleout[i][6]==-1 && eleout[i][7]==-1) {
				min=abs(eleout[i][1]-floor);
				elevator=i;
			}
		}
		return elevator;
	}
	}
}
void Elevator::setusage(bool a,bool b,bool c) {
	if(a==true) {
		eleout[0][2]+=(eleout[0][0]+3)*1;//(���F�h�֤H+3)*���ʤ@��
	}
	if(b==true) {
		eleout[1][2]+=(eleout[1][0]+3)*1;
	}
	if(c==true) {
		eleout[2][2]+=(eleout[2][0]+3)*1;
	}
}
void Elevator::waitTime(int elevator,int people) {
	eleout[elevator][7]=1;
	double time=people*0.7;
	//�p�󵥩�2����2���ɶ�
	if(time<=2) {
		eleout[elevator][5]=2;
		return;
	} else {
		//�j��2�B���p�ƵL����i��
		if(((int)(time*10)%10)!=0) {
			eleout[elevator][5]=(int)time+1;
			return;
		}
		//�j��2�B�L�p��
		else {
			eleout[elevator][5]=(int)time;
			return;
		}
	}
}
void Elevator::settime() {
	for(int i=0; i<3; i++) {
		if(eleout[i][5]>0) {
			eleout[i][5]-=1;
		}
		if(eleout[i][5]==0) {
			eleout[i][7]=-1;
		}
	}
}
class Control:public People,public Elevator {
	public:
		void move_peo(int i,int y,int x);
		int get_time() {
			return wait_people_floor;
		}
		Control():People(),Elevator() {
			wait_people_floor = 0;
		}
		int setY(int floor); //�]�w�U�Ӽhy���y��
		void Floor(); //�L�X1~12��  x: 0-1
		void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor); //�L�X�U�Ӽh���ݹq�誺�H x: 2-17
		void fstFloor(int n, int fstFloor, int nextFloor); //�L�Xn�H�@�}�l�Q�h���Ӽh  x: 33-47 (15��)
		void outputFloor(int floor, int x, int y);		   //�L�X�Ӽh
		void printE1(int e1Floor, int usage, int num);	   //�Ĥ@�x�q�� x: 50-58  + �ϥζq, num:�q��H��
		void printE2(int e2Floor, int usage, int num);	   // �ĤG�x�q�� x: 61-69 + �ϥζq, num :�q��H��
		void printE3(int e3Floor, int usage, int num);	   //�ĤT�x�q�� x: 72-79 + �ϥζq, �q��H��
		void selectele(int select,int y,int use,int number,int no_move_1,int no_move_2);
		void move_elevator(bool a, bool b, bool c, int first_y1, int after_y1, int first_y2, int after_y2, int first_y3, int after_y3);

	private:
		int wait_people_floor;//�Ӽh���ݮɶ�
};
void Control:: move_elevator(bool a, bool b, bool c, int first_y1, int after_y1, int first_y2, int after_y2, int first_y3, int after_y3)
{
	int use1 = getUse(0);
	int use2 = getUse(1);
	int use3 = getUse(2);
	while(true)
	{
		if((first_y1==after_y1)&&(first_y2==after_y2)&&(first_y3==after_y3))
		{
		break;
		}
	if(a==true&&b==true&&c==true)
	{
	if(first_y1>after_y1)//�V�U
	{
		first_y1--;
		setusage(1,0,0);
		use1 = getUse(0);
	}
	else if(first_y1<after_y1)
	{
		first_y1++;
		setusage(1,0,0);
		use1 = getUse(0);
	}
    else if(first_y1==after_y1)
    {
    }
	if(first_y2>after_y2)//�V�U
	{
		first_y2--;
		setusage(0,1,0);
		use2 = getUse(1);
	}
	else if(first_y2<after_y2)
	{
		first_y2++;
		setusage(0,1,0);
		use2 = getUse(1);
	}
    else if(first_y2==after_y2)
    {
    }
	if(first_y3>after_y3)//�V�U
	{
		first_y3--;
		setusage(0,0,1);
		use3 = getUse(2);
	}
	else if(first_y3<after_y3) 
	{
		first_y3++;
		setusage(0,0,1);
		use3 = getUse(2);
	}
    else if(first_y3==after_y3)
    {
    }
	}
	else if(a==true&&b==true)
	{
	if(first_y1>after_y1)//�V�U
	{
		--first_y1;
		setusage(1,0,0);
		use1 = getUse(0);
	}
	else if(first_y1<after_y1)
	{
		++first_y1;
		setusage(1,0,0);
		use1 = getUse(0);
	}
    else if(first_y1==after_y1)
    {
    }
	if(first_y2>after_y2)//�V�U
	{
		--first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
	else if(first_y2<after_y2) 
	{
		++first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
    else if(first_y2==after_y2)
    {
    }
	if(first_y1==after_y1&&first_y2==after_y2)
		break;
	}
	
	else if(a==true&&c==true)
	{
	if(first_y1>after_y1)//�V�U
	{
		--first_y1;
		setusage(1,0,0);
		use1 = getUse(0);
	}
	else if(first_y1<after_y1)
	{
		++first_y1;
		setusage(1,0,0);
        use1 = getUse(0);
    }
    else if(first_y1==after_y1)
    {
    }
	if(first_y3>after_y3)//�V�U
	{
		--first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
	else if(first_y3<after_y3) 
	{
		++first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
    else if(first_y3==after_y3)
    {
    }
	if(first_y1==after_y1&&first_y3==after_y3)
		break;
	}
	else if(b==true&&c==true)
	{
	if(first_y2>after_y2)//�V�U
	{
		--first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
	else if(first_y2<after_y2)
	{
		++first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
    else if(first_y2==after_y2)
    {
    }
	if(first_y3>after_y3)//�V�U
	{
		--first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
	else if(first_y3<after_y3) 
	{
		++first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
    else if(first_y3==after_y3)
    {
    }
	if(first_y3==after_y3&&first_y2==after_y2)
		break;
	}
	else if(a==true&&b==false&&c==false)
	{
			if(first_y1>after_y1)//�V�U
	{
		--first_y1;
		setusage(1,0,0);
		use1 = getUse(0);
	}
	else if(first_y1<after_y1)
	{
		++first_y1;
		setusage(1,0,0);
		use1 = getUse(0);
	}
	if(first_y1==after_y1)
		break;
	}
	else if(b==true&&a==false&&c==false)
	{
		if(first_y2>after_y2)//�V�U
	{
		--first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
	else if(first_y2<after_y2)
	{
		++first_y2;
		setusage(0,1,0);
		use2 = getUse(1);
	}
	if(first_y2==after_y2)
		break;
	}
	else if(c==true&&a==false&&b==false)
	{
		if(first_y3>after_y3)//�V�U
	{
		--first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
	else if(first_y3<after_y3) 
	{
		++first_y3;
		setusage(0,0,1);
		use3 = getUse(2);
	}
	if(first_y3==after_y3)
		break;
	}
    printE1(first_y1, use1, get_elevator_floor_number(0));
	printE2(first_y2, use2, get_elevator_floor_number(1));
	printE3(first_y3, use3, get_elevator_floor_number(2));
	Sleep(500);
	clear();
	Floor();
	refresh();
	}
}
void Control::move_peo(int i,int y,int x) {
	Sleep((People::get_people_wait_time(i))*500);//�}�l���ݤH��Ӽh���ɶ�
	fstFloor(x, y, People::getSecFloor(i));//���ʤH
}
int Control::setY(int floor) { //�]�w�U�Ӽhy���y��
	int y;
	if (floor == 1) {
		y = 22; //�@�� y:22
	} else if (floor == 2) {
		y = 20; //2�� y:20
	} else if (floor == 3) {
		y = 18; //3�� y:18
	} else if (floor == 4) {
		y = 16; //4�� y:16
	} else if (floor == 5) {
		y = 14; //5�� y:14
	} else if (floor == 6) {
		y = 12; //6�� y:12
	} else if (floor == 7) {
		y = 10; //7�� y:10
	} else if (floor == 8) {
		y = 8; //8�� y:8
	} else if (floor == 9) {
		y = 6; //9�� y:6
	} else if (floor == 10) {
		y = 4; //10�� y:4
	} else if (floor == 11) {
		y = 2; //11�� y:2
	} else if (floor == 12) {
		y = 0; //12�� y:0
	}
	return y;
}

void Control::outputFloor(int floor, int x, int y) { //�L�X�Ӽh
	if (floor == 1) {
		mvaddch(y, x, '1');
	} else if (floor == 2) {
		mvaddch(y, x, '2');
	} else if (floor == 3) {
		mvaddch(y, x, '3');
	} else if (floor == 4) {
		mvaddch(y, x, '4');
	} else if (floor == 5) {
		mvaddch(y, x, '5');
	} else if (floor == 6) {
		mvaddch(y , x, '6');
	} else if (floor == 7) {
		mvaddch(y, x, '7');
	} else if (floor == 8) {
		mvaddch(y, x, '8');
	} else if (floor == 9) {
		mvaddch(y, x, '9');
	} else if (floor == 10) {
		mvaddch(y, x, 'A');
	} else if (floor == 11) {
		mvaddch(y, x, 'B');
	} else if (floor == 12) {
		mvaddch(y , x, 'C');
	}
	refresh();
}

void Control::Floor() { //�L�X1~12��  x: 0-1
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

void Control::waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor) { //�L�X�U�Ӽh���ݹq�誺�H x: 2-17
	int x = n + 2;  //x�y�бq2�}�l�A n: ���h�ӵ��ݹq�誺�ĴX�H (�q0�}�l)
	int y = setY(fstFloor);
	if (elevatorFloor == fstFloor) {
		outputFloor(nextFloor, x, y);
	} else {
		outputFloor (fstFloor, x, y);
	}
}

void Control::fstFloor(int n, int fstFloor, int nextFloor) { //�L�Xn�H�@�}�l�Q�h���Ӽh  x: 33-47 (15��)
	int x = n + 33; //n�O�q 0 �}�l�A�q x = 33�}�l�L
	int y = setY(fstFloor);

	outputFloor (nextFloor, x, y);
}

void Control::printE1(int e1Floor, int usage, int num) { //�Ĥ@�x�q�� x: 50-58  + �ϥζq, num:�q��H��
	int y = setY(e1Floor);
	move(y, 50);
	printw("|__%d__|",usage);

	if (num > 0) { //�q�観�H�~��ܤH��
		move(y - 1, 54);
		attron(A_REVERSE); //���}�ϥ�
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�
	}
	refresh();
}
void Control::printE2(int e2Floor, int usage, int num) { // �ĤG�x�q�� x: 61-69 + �ϥζq, num :�q��H��
	int y = setY(e2Floor);
	move(y, 61);
	printw("|__%d__|",usage);
	if (num > 0) { //�q�観�H�~��ܤH��
		move(y - 1, 64);
		attron(A_REVERSE); //���}�ϥ�
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�
	}

	refresh();
}
void Control::printE3(int e3Floor, int usage, int num) { //�ĤT�x�q�� x: 72-79 + �ϥζq, �q��H��
	int y = setY(e3Floor);
	move(y, 72);
	printw("|__%d__|",usage);
	if (num > 0) { //�q�観�H�~��ܤH��
		move(y - 1, 75);
		attron(A_REVERSE); //���}�ϥ�
		printw("%d", num);
		attroff(A_REVERSE); //�����ϥ�
	}
	refresh();
}

int main() {
	initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);
	refresh();
	refresh();
	
	Control control;
	int total_waiting_time = 0;//�έp�`���ݮɶ�
	int average = 0;//�έp�������ݮɶ�
	int usage=0;
	int after_min[3]= {1,1,1};
	int first_max[3] = {1, 1, 1};
	int after_max[3]={1,1,1};
	srand(time(0));
	control.Floor();//���|�欰��l���p
	control.printE1(1, 0, 0);
	control.printE2(1, 0, 0);
	control.printE3(1, 0, 0);
	int elein_peo_count[3]= {}; //�p��@�}�l���X�H�n�i�h(�ΨӺ�q�誺���d�ɶ�)
	int after_elein_peo_count[3] = {};//��Ӧ��X�ӤH�n�i�h(�ΨӺ�q�誺���d�ɶ�)
	int floor_counter[12] = {};//�O���C�h�Ӧ��X�H
	bool first=true;//�P�_��l��q��
	bool type1[3]= {true,true,true};//�P�_�Ĥ@����assign �ᤩ�̤j�� ]
	bool type[3]= {true,true,true};//�P�_�Ĥ@����assign
	bool select_ele[3]={false,false,false};
	while(true) {
		for(int j=0;j<12;j++)
		{
			floor_counter[j]=0;			
		}
		for(int i=0;i<3;i++)
		{
			elein_peo_count[i]=0;
			after_elein_peo_count[i]=0;
			type1[i]=true;
			type[i]=true;
			select_ele[i] = false;
		}
		int oldsize = control.getSize();//�o��W�@�����`size
		if(control.getSize()<150) { //�p�G�H�ƨS�z���ͤH
			control.add();//���ͤH�èM�w�X�Q�h���Ӽh
		}
		if((control.getSize()-oldsize)==0&&first) {
			continue;
		}
		int n = 1;//���ͪ��H�� �Ψ�move �H��x
		for (int i = oldsize; i<control.getSize(); i++) { //�C�ӤH�Ĥ@����ܹq�誺���p �έp�ϥζq�P�H��
			if(control.assign(control.getFst(i),first)==0) { //�@�}�l��ܹq�誺���p
				select_ele[0] = true;
				control.Add(0, 1); //�O�Ĥ@�ӹq��H�ƴN�[1
				elein_peo_count[0]++;//�N��Ĥ@�q�観�H�ϥ�
				if(type1[0]==true) {
					first_max[0]=control.getFst(i);
					type1[0]=false;
				}
				if (control.getFst(i) > first_max[0]) { //���F�o����ɭ� 
					first_max[0] = control.getFst(i);
				}
			} else if(control.assign(control.getFst(i),first)==1) {
				select_ele[1] = true;
				control.Add(1, 1);
				elein_peo_count[1]++;
				if(type1[1]==true) {
					first_max[1]=control.getFst(i);
					type1[1]=false;
				}
				if (control.getFst(i) > first_max[1]) { //���F�o����ɭ� 
					first_max[1] = control.getFst(i);
				}
			} else if(control.assign(control.getFst(i),first)==2) {
				select_ele[2] = true;
				control.Add(2, 1);
				elein_peo_count[2]++;
				if(type1[2]==true) {
					first_max[2]=control.getFst(i);
					type1[2]=false;
				}
				if (control.getFst(i) > first_max[2]) { //���F�o����ɭ� 
					first_max[2] = control.getFst(i);
				}
			}
			for (int j = 0; j < 12; j++) { //�p��n�h���Ӽh���H���X�H
				if(control.getFst(i)==j) {
					floor_counter[j]++;
				}
			}
			n=n+2; 
			control.fstFloor(n,1,control.getFst(i));
			
		}
		Sleep(2000);//���ɶ���0.5��
		first=false;
		clear();
		control.Floor();
		refresh();
		if(elein_peo_count[0]!=0) { //�N���H�n�ϥβĤ@�ӹq�� move �� cout
			control.waitTime(0, elein_peo_count[0]);//�p�ⵥ�ݮɶ�
			int time = control.getwait_time(0);	 //�o�쵥�ݮɶ�
			total_waiting_time += time; //�ⵥ�ݮɶ��[�J
		} else if(elein_peo_count[1]!=0) { //�N���H�n�ϥβĤG�ӹq��
			control.waitTime(1, elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(elein_peo_count[2]!=0) { //�N���H�n�ϥβĤT�ӹq��
			control.waitTime(2, elein_peo_count[2]);
			int time = control.getwait_time(2);
			total_waiting_time += time;
		}
		control.move_elevator(select_ele[0], select_ele[1], select_ele[2], after_min[0], 1, after_min[1], 1,after_min[2], 1);
		control.move_elevator(select_ele[0], select_ele[1], select_ele[2], 1, first_max[0], 1,first_max[1], 1, first_max[2]);
		for (int i = 0; i < 3;i++)
		{
			select_ele[i] = false;
			after_min[i]=first_max[i];
		}
			for (int i = 0; i < control.getSize(); i++)
			{						 //�ĤG����q�誺���p �έp��
				control.setFloor(i); //���o��ĤG���Q�n�h���Ӽh
				if (control.assign(control.getSecFloor(i), first) == 0)
				{ //��ӿ�ܹq�誺���p
					if (type[0] == true)
					{
						after_min[0] = control.getSecFloor(i);
						type[0] = false;
					}
					control.Add(0, 1); //�O�Ĥ@�ӹq��H�ƴN�[1
					after_elein_peo_count[0]++;
					if (control.getSecFloor(i) < after_min[0])
					{ //���F�o����ɭ� �]�N�Oafter_y �]���Ĥ@�����O1�өҥHfirst_y����
						after_min[0] = control.getSecFloor(i);
					}
					select_ele[0] = true;
					/*if(control.getSecFloor(i)==1)//�p�G���H�^��1�Ӧ��q��H��-1
					control.minus(0,1);*/
				}
				else if (control.assign(control.getSecFloor(i), first) == 1)
				{
					if (type[1] == true)
					{
						after_min[1] = control.getSecFloor(i);
						type[1] = false;
					}
					control.Add(1, 1);
					//control.setusage(0, 1, 0);
					after_elein_peo_count[1]++;
					if (control.getSecFloor(i) < after_min[1])
					{ //���F�o����ɭ� �]�N�Oafter_y �]���Ĥ@�����O1�өҥHfirst_y����
						after_min[1] = control.getSecFloor(i);
					}
					select_ele[1] = true;
					/*if(control.getSecFloor(i)==1)
					control.minus(1,1);*/
				}
				else if (control.assign(control.getSecFloor(i), first) == 2)
				{
					if (type[2] == true)
					{
						after_min[2] = control.getSecFloor(i);
						type[2] = false;
					}
					control.Add(2, 1);
					//control.setusage(0, 0, 1);
					after_elein_peo_count[2]++;
					if (control.getSecFloor(i) < after_min[2])
					{ //���F�o����ɭ� �]�N�Oafter_y �]���Ĥ@�����O1�өҥHfirst_y����
						after_min[2] = control.getSecFloor(i);
					}
					select_ele[2] = true;
					/*if(control.getSecFloor(i)==1)
					control.minus(2,1);*/
				}
				for (int j = 0; j < 12; j++)
				{ //�p��n�h���Ӽh���H���X�H
					if (control.getSecFloor(i) == j)
					{
						floor_counter[j]++;
					}
				}
				if (control.getSecFloor(i) == 1)
				{
					//control.remove(i);//�p�G1�Ӧ��H����
				}
			}
			control.move_elevator(select_ele[0], select_ele[1], select_ele[2], first_max[0], after_min[0], first_max[1], after_min[1], first_max[2], after_min[2]);
		if(after_elein_peo_count[0]!=0) { //�N���H�n�ϥβĤ@�ӹq��
			control.waitTime(0, after_elein_peo_count[0]);
			int time = control.getwait_time(0);
			total_waiting_time += time;
		} else if(after_elein_peo_count[1]!=0) { //�N���H�n�ϥβĤG�ӹq��
			control.waitTime(1, after_elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(after_elein_peo_count[2]!=0) { //�N���H�n�ϥβĤT�ӹq�� 
			control.waitTime(2, after_elein_peo_count[2]);
			int time = control.getwait_time(2);
			total_waiting_time += time;
		}
		int t=control.get_time();
		total_waiting_time += t;
		average = total_waiting_time / control.getSize();
		move(23,70);
		printw("T=%d",total_waiting_time);
		move(23,75);
		printw("A=%d",average);
	}
}


