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
		int get_people_wait_time(int people) {
			return person[people][1];
		}

	private:

		int person[150][3]; //魁[a][0~2] a秨﹍柑; 氨痙; ぇ璶加
		int sizeUsed; //魁计
};



People::People() {

	for(int i=0; i<150; i++) {
		for(int j=0; j<3; j++) {
			person[i][j]=0;
		}
	}
	/*person = new int *[150];   //程150

	for (int i = 0; i<150; i++) {
		person[i] = new int[3]; // person[n][0] : n秨﹍璶加 ; [n][1]: 氨ê加丁; person[n][2]: ㄓ璶加
	}*/

	sizeUsed = 0;   //秨﹍临⊿Τ

}
void People::setFirst(int n) { //秨﹍璶加
	//srand(time(0));
	int f = rand() % 11 + 2; //繦诀玡┕ 2 ~ 12加
	person[n][0] = f;
}
void People::setFloor(int n) {
	int floor = person[n][0]; //砞﹚セ加糷
	//srand(time(0));
	//int f = rand() % 100 + 1;
	while (floor == person[n][0]) { //磷加 ㄒ:狦Τセ2加碞ぃ璶琵2加
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
	//srand(time(0));
	int num = rand() % 3;  //繦诀瞷0~2
	while (num > 0) {
		if (sizeUsed == 150) { //狦竒150碞ぃ璶
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
		void Add(int elevator,int people); //0 1 2 筿辫 糤ぶ

		void minus(int elevator,int people); //0 1 2 筿辫 搭ぶ

		void setusage(bool a,bool b,bool c);//a b c 肚筿辫琌タ簿笆 璝タ秨碞false
		//–常璶㊣Ω

		int assign(int floor,bool first);//加糷惠璶狝叭 肚0 1 2(程orㄏノ秖程ぶ筿辫筁)

		void waitTime(int elevator,int people);//0 1 2筿辫璶ぶ
		int getUse(int n) { //肚ㄏノ秖
			return eleout[n][2];
		}
		int getwait_time(int n) {
			return eleout[n][5];
		}
		int get_elevator_floor_number(int n) {
			return eleout[n][0];
		}
		void settime();//–常璶㊣Ω 搭0ゎ
	private:
		//eleout  癘魁俱筿辫戈癟
		int eleout[3][8]; //[0][] [1][] [2][]オ筿辫
		//[][0]瞷Τ碭
		//[][1]瞷加
		//[][2]ㄏノ秖
		//[][3]加璶
		//[][4]瞷┕(1)临┕(-1) 临氨ゎ(0)
		//[][5]タ单杠单丁
		//[][6]骸籔(骸1,獶骸-1)
		//[][7]单籔(タ单1,玥-1)

		//elein  魁筿辫柑薄猵
		int elein[3][12]; //[0][] [1][] [2][]オ筿辫
		//[][N] 赣筿辫ず璶N+1加Τ碭
		//ゑ[1][5] 癘魁帝い丁ê筿辫璶6加Τ碭

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
	//璶加 ㄏノ秖程ぶ
	//rand(time(0));
	if(first==true)//材Ω
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
	//ぃ琌璶加 程
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
		eleout[0][2]+=(eleout[0][0]+3)*1;//(更ぶ+3)*簿笆加
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
	//单2钡2虫丁
	if(time<=2) {
		eleout[elevator][5]=2;
		return;
	} else {
		//2Τ计礚兵ン秈
		if(((int)(time*10)%10)!=0) {
			eleout[elevator][5]=(int)time+1;
			return;
		}
		//2礚计
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
		int setY(int floor); //砞﹚加糷y畒夹
		void Floor(); //1~12加  x: 0-1
		void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor); //加糷单筿辫 x: 2-17
		void fstFloor(int n, int fstFloor, int nextFloor); //n秨﹍稱加糷  x: 33-47 (15)
		void outputFloor(int floor, int x, int y);		   //加糷
		void printE1(int e1Floor, int usage, int num);	   //材筿辫 x: 50-58  + ㄏノ秖, num:筿辫计
		void printE2(int e2Floor, int usage, int num);	   // 材筿辫 x: 61-69 + ㄏノ秖, num :筿辫计
		void printE3(int e3Floor, int usage, int num);	   //材筿辫 x: 72-79 + ㄏノ秖, 筿辫计
		void selectele(int select,int y,int use,int number,int no_move_1,int no_move_2);
		void move_elevator(bool a, bool b, bool c, int first_y1, int after_y1, int first_y2, int after_y2, int first_y3, int after_y3);

	private:
		int wait_people_floor;//加糷单丁
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
	if(first_y1>after_y1)//
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
	if(first_y2>after_y2)//
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
	if(first_y3>after_y3)//
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
	if(first_y1>after_y1)//
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
	if(first_y2>after_y2)//
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
	if(first_y1>after_y1)//
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
	if(first_y3>after_y3)//
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
	if(first_y2>after_y2)//
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
	if(first_y3>after_y3)//
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
			if(first_y1>after_y1)//
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
		if(first_y2>after_y2)//
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
		if(first_y3>after_y3)//
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
	Sleep((People::get_people_wait_time(i))*500);//秨﹍单加糷丁
	fstFloor(x, y, People::getSecFloor(i));//簿笆
}
int Control::setY(int floor) { //砞﹚加糷y畒夹
	int y;
	if (floor == 1) {
		y = 22; //加 y:22
	} else if (floor == 2) {
		y = 20; //2加 y:20
	} else if (floor == 3) {
		y = 18; //3加 y:18
	} else if (floor == 4) {
		y = 16; //4加 y:16
	} else if (floor == 5) {
		y = 14; //5加 y:14
	} else if (floor == 6) {
		y = 12; //6加 y:12
	} else if (floor == 7) {
		y = 10; //7加 y:10
	} else if (floor == 8) {
		y = 8; //8加 y:8
	} else if (floor == 9) {
		y = 6; //9加 y:6
	} else if (floor == 10) {
		y = 4; //10加 y:4
	} else if (floor == 11) {
		y = 2; //11加 y:2
	} else if (floor == 12) {
		y = 0; //12加 y:0
	}
	return y;
}

void Control::outputFloor(int floor, int x, int y) { //加糷
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

void Control::Floor() { //1~12加  x: 0-1
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

void Control::waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor) { //加糷单筿辫 x: 2-17
	int x = n + 2;  //x畒夹眖2秨﹍ n: ê糷加单筿辫材碭 (眖0秨﹍)
	int y = setY(fstFloor);
	if (elevatorFloor == fstFloor) {
		outputFloor(nextFloor, x, y);
	} else {
		outputFloor (fstFloor, x, y);
	}
}

void Control::fstFloor(int n, int fstFloor, int nextFloor) { //n秨﹍稱加糷  x: 33-47 (15)
	int x = n + 33; //n琌眖 0 秨﹍眖 x = 33秨﹍
	int y = setY(fstFloor);

	outputFloor (nextFloor, x, y);
}

void Control::printE1(int e1Floor, int usage, int num) { //材筿辫 x: 50-58  + ㄏノ秖, num:筿辫计
	int y = setY(e1Floor);
	move(y, 50);
	printw("|__%d__|",usage);

	if (num > 0) { //筿辫Τ陪ボ计
		move(y - 1, 54);
		attron(A_REVERSE); //ゴ秨はフ
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ
	}
	refresh();
}
void Control::printE2(int e2Floor, int usage, int num) { // 材筿辫 x: 61-69 + ㄏノ秖, num :筿辫计
	int y = setY(e2Floor);
	move(y, 61);
	printw("|__%d__|",usage);
	if (num > 0) { //筿辫Τ陪ボ计
		move(y - 1, 64);
		attron(A_REVERSE); //ゴ秨はフ
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ
	}

	refresh();
}
void Control::printE3(int e3Floor, int usage, int num) { //材筿辫 x: 72-79 + ㄏノ秖, 筿辫计
	int y = setY(e3Floor);
	move(y, 72);
	printw("|__%d__|",usage);
	if (num > 0) { //筿辫Τ陪ボ计
		move(y - 1, 75);
		attron(A_REVERSE); //ゴ秨はフ
		printw("%d", num);
		attroff(A_REVERSE); //闽超はフ
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
	int total_waiting_time = 0;//参璸羆单丁
	int average = 0;//参璸キА单丁
	int usage=0;
	int after_min[3]= {1,1,1};
	int first_max[3] = {1, 1, 1};
	int after_max[3]={1,1,1};
	srand(time(0));
	control.Floor();//︽﹍薄猵
	control.printE1(1, 0, 0);
	control.printE2(1, 0, 0);
	control.printE3(1, 0, 0);
	int elein_peo_count[3]= {}; //璸衡秨﹍Τ碭璶秈(ノㄓ衡筿辫氨痙丁)
	int after_elein_peo_count[3] = {};//ㄓΤ碭璶秈(ノㄓ衡筿辫氨痙丁)
	int floor_counter[12] = {};//癘魁–糷加Τ碭
	bool first=true;//耞﹍匡筿辫
	bool type1[3]= {true,true,true};//耞材Ωassign 结ぉ程 ]
	bool type[3]= {true,true,true};//耞材Ωassign
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
		int oldsize = control.getSize();//眔Ω羆size
		if(control.getSize()<150) { //狦计⊿脄玻ネ
			control.add();//玻ネ∕﹚稱加糷
		}
		if((control.getSize()-oldsize)==0&&first) {
			continue;
		}
		int n = 1;//玻ネ计 ノㄓmove x
		for (int i = oldsize; i<control.getSize(); i++) { //–材Ω匡拒筿辫薄猵 参璸ㄏノ秖籔计
			if(control.assign(control.getFst(i),first)==0) { //秨﹍匡拒筿辫薄猵
				select_ele[0] = true;
				control.Add(0, 1); //琌材筿辫计碞1
				elein_peo_count[0]++;//材筿辫Τㄏノ
				if(type1[0]==true) {
					first_max[0]=control.getFst(i);
					type1[0]=false;
				}
				if (control.getFst(i) > first_max[0]) { //眔娩 
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
				if (control.getFst(i) > first_max[1]) { //眔娩 
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
				if (control.getFst(i) > first_max[2]) { //眔娩 
					first_max[2] = control.getFst(i);
				}
			}
			for (int j = 0; j < 12; j++) { //璸衡璶ê加糷Τ碭
				if(control.getFst(i)==j) {
					floor_counter[j]++;
				}
			}
			n=n+2; 
			control.fstFloor(n,1,control.getFst(i));
			
		}
		Sleep(2000);//虫丁0.5
		first=false;
		clear();
		control.Floor();
		refresh();
		if(elein_peo_count[0]!=0) { //Τ璶ㄏノ材筿辫 move 蛤 cout
			control.waitTime(0, elein_peo_count[0]);//璸衡单丁
			int time = control.getwait_time(0);	 //眔单丁
			total_waiting_time += time; //р单丁
		} else if(elein_peo_count[1]!=0) { //Τ璶ㄏノ材筿辫
			control.waitTime(1, elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(elein_peo_count[2]!=0) { //Τ璶ㄏノ材筿辫
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
			{						 //材Ω匡筿辫薄猵 参璸ノ
				control.setFloor(i); //眔材Ω稱璶加糷
				if (control.assign(control.getSecFloor(i), first) == 0)
				{ //ㄓ匡拒筿辫薄猵
					if (type[0] == true)
					{
						after_min[0] = control.getSecFloor(i);
						type[0] = false;
					}
					control.Add(0, 1); //琌材筿辫计碞1
					after_elein_peo_count[0]++;
					if (control.getSecFloor(i) < after_min[0])
					{ //眔娩 碞琌after_y 材Ω常琌1加┮first_yぃノ
						after_min[0] = control.getSecFloor(i);
					}
					select_ele[0] = true;
					/*if(control.getSecFloor(i)==1)//狦1加筿辫计-1
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
					{ //眔娩 碞琌after_y 材Ω常琌1加┮first_yぃノ
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
					{ //眔娩 碞琌after_y 材Ω常琌1加┮first_yぃノ
						after_min[2] = control.getSecFloor(i);
					}
					select_ele[2] = true;
					/*if(control.getSecFloor(i)==1)
					control.minus(2,1);*/
				}
				for (int j = 0; j < 12; j++)
				{ //璸衡璶ê加糷Τ碭
					if (control.getSecFloor(i) == j)
					{
						floor_counter[j]++;
					}
				}
				if (control.getSecFloor(i) == 1)
				{
					//control.remove(i);//狦1加ア
				}
			}
			control.move_elevator(select_ele[0], select_ele[1], select_ele[2], first_max[0], after_min[0], first_max[1], after_min[1], first_max[2], after_min[2]);
		if(after_elein_peo_count[0]!=0) { //Τ璶ㄏノ材筿辫
			control.waitTime(0, after_elein_peo_count[0]);
			int time = control.getwait_time(0);
			total_waiting_time += time;
		} else if(after_elein_peo_count[1]!=0) { //Τ璶ㄏノ材筿辫
			control.waitTime(1, after_elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(after_elein_peo_count[2]!=0) { //Τ璶ㄏノ材筿辫 
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


