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
		void setFirst(int n);  //一開始要去哪一樓
		void setFloor(int n); //第一次之後要去那些樓
		void setTime(int n); // 停在該樓時間
		void remove(int n);  //  回到一樓之後消失
		void add(); // 每隔一段時間出現的人(0~2)
		int getFst(int n) {
			return person[n][0];
		}  //return 一開始去哪一樓
		int getSecFloor(int n) {
			return person[n][2];    //return 後來去哪一樓
		}
		int getSize() {
			return sizeUsed;   // return 有多少人
		}
		int get_people_wait_time(int people) {
			return person[people][1];
		}

	private:

		int person[150][3]; //紀錄[a][0~2] a人一開始到哪裡; 停留多久; 之後要去哪一樓
		int sizeUsed; //紀錄人數
};



People::People() {

	for(int i=0; i<150; i++) {
		for(int j=0; j<3; j++) {
			person[i][j]=0;
		}
	}
	/*person = new int *[150];   //最多150個人

	for (int i = 0; i<150; i++) {
		person[i] = new int[3]; // person[n][0] : n人一開始要去哪一樓 ; [n][1]: 停在那樓的時間; person[n][2]: 再來要去哪一樓
	}*/

	sizeUsed = 0;   //一開始還沒有人

}
void People::setFirst(int n) { //一開始要去哪一樓
	//srand(time(0));
	int f = rand() % 11 + 2; //隨機前往 2 ~ 12樓
	person[n][0] = f;
}
void People::setFloor(int n) {
	int floor = person[n][0]; //設定為原本的樓層
	//srand(time(0));
	//int f = rand() % 100 + 1;
	while (floor == person[n][0]) { //避免又到同一樓 例:如果有一個人原本在2樓，就不要讓他又到2樓
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
void People::setTime(int n) { //設定停留時間
	int time = rand() % 81 + 20;
	person[n][1] = time;
}
void People::remove(int n) { //回到一樓後消失
	for (int i = 0; 3 > i; i++) {
		person[n][i] = person[sizeUsed - 1][i];  //把最後一個人移到消失那個人的位置
	}
	sizeUsed--;
}
void People::add() {
	//srand(time(0));
	int num = rand() % 3;  //隨機出現0~2人
	while (num > 0) {
		if (sizeUsed == 150) { //如果已經150就不要在加人
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
		void Add(int elevator,int people); //0 1 2 哪一台電梯 增加多少人

		void minus(int elevator,int people); //0 1 2 哪一台電梯 減去多少人

		void setusage(bool a,bool b,bool c);//a b c 傳入電梯是否正在移動 若正在開門就false
		//每秒都要呼叫一次

		int assign(int floor,bool first);//哪一個樓層需要服務 回傳0 1 2(派最近的or使用量最少的電梯過去)

		void waitTime(int elevator,int people);//0 1 2哪一台電梯要出入多少人
		int getUse(int n) { //回傳使用量
			return eleout[n][2];
		}
		int getwait_time(int n) {
			return eleout[n][5];
		}
		int get_elevator_floor_number(int n) {
			return eleout[n][0];
		}
		void settime();//每秒都要呼叫一次 一直減到0為止
	private:
		//eleout  記錄整台電梯的資訊
		int eleout[3][8]; //[0][] [1][] [2][]左到右的三台電梯
		//[][0]現在有幾個人
		//[][1]現在在哪一樓
		//[][2]使用量
		//[][3]下一樓要去哪
		//[][4]現在在往上(為1)還往下(為-1) 還停止(為0)
		//[][5]正在等待的話等待的時間
		//[][6]客滿與否(客滿1,非客滿-1)
		//[][7]等待與否(正在等待1,否則-1)

		//elein  紀錄電梯裡面的情況
		int elein[3][12]; //[0][] [1][] [2][]左到右的三台電梯
		//[][N] 該電梯內要去N+1樓的有幾個人
		//比如[1][5] 記錄著中間那台電梯要去6樓的有幾個人

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
	//要去一樓 派使用量最少的
	//rand(time(0));
	if(first==true)//第一次
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
	//不是要去一樓 派最近的
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
		eleout[0][2]+=(eleout[0][0]+3)*1;//(載了多少人+3)*移動一樓
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
	//小於等於2直接2單位時間
	if(time<=2) {
		eleout[elevator][5]=2;
		return;
	} else {
		//大於2且有小數無條件進位
		if(((int)(time*10)%10)!=0) {
			eleout[elevator][5]=(int)time+1;
			return;
		}
		//大於2且無小數
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
		int setY(int floor); //設定各樓層y的座標
		void Floor(); //印出1~12樓  x: 0-1
		void waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor); //印出各樓層等待電梯的人 x: 2-17
		void fstFloor(int n, int fstFloor, int nextFloor); //印出n人一開始想去的樓層  x: 33-47 (15格)
		void outputFloor(int floor, int x, int y);		   //印出樓層
		void printE1(int e1Floor, int usage, int num);	   //第一台電梯 x: 50-58  + 使用量, num:電梯人數
		void printE2(int e2Floor, int usage, int num);	   // 第二台電梯 x: 61-69 + 使用量, num :電梯人數
		void printE3(int e3Floor, int usage, int num);	   //第三台電梯 x: 72-79 + 使用量, 電梯人數
		void selectele(int select,int y,int use,int number,int no_move_1,int no_move_2);
		void move_elevator(bool a, bool b, bool c, int first_y1, int after_y1, int first_y2, int after_y2, int first_y3, int after_y3);

	private:
		int wait_people_floor;//樓層等待時間
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
	if(first_y1>after_y1)//向下
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
	if(first_y2>after_y2)//向下
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
	if(first_y3>after_y3)//向下
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
	if(first_y1>after_y1)//向下
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
	if(first_y2>after_y2)//向下
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
	if(first_y1>after_y1)//向下
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
	if(first_y3>after_y3)//向下
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
	if(first_y2>after_y2)//向下
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
	if(first_y3>after_y3)//向下
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
			if(first_y1>after_y1)//向下
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
		if(first_y2>after_y2)//向下
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
		if(first_y3>after_y3)//向下
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
	Sleep((People::get_people_wait_time(i))*500);//開始等待人到樓層的時間
	fstFloor(x, y, People::getSecFloor(i));//移動人
}
int Control::setY(int floor) { //設定各樓層y的座標
	int y;
	if (floor == 1) {
		y = 22; //一樓 y:22
	} else if (floor == 2) {
		y = 20; //2樓 y:20
	} else if (floor == 3) {
		y = 18; //3樓 y:18
	} else if (floor == 4) {
		y = 16; //4樓 y:16
	} else if (floor == 5) {
		y = 14; //5樓 y:14
	} else if (floor == 6) {
		y = 12; //6樓 y:12
	} else if (floor == 7) {
		y = 10; //7樓 y:10
	} else if (floor == 8) {
		y = 8; //8樓 y:8
	} else if (floor == 9) {
		y = 6; //9樓 y:6
	} else if (floor == 10) {
		y = 4; //10樓 y:4
	} else if (floor == 11) {
		y = 2; //11樓 y:2
	} else if (floor == 12) {
		y = 0; //12樓 y:0
	}
	return y;
}

void Control::outputFloor(int floor, int x, int y) { //印出樓層
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

void Control::Floor() { //印出1~12樓  x: 0-1
	attron(A_REVERSE); //打開反白
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
	attroff(A_REVERSE); //關閉反白
	refresh();
}

void Control::waitEle(int n, int fstFloor, int nextFloor, int elevatorFloor) { //印出各樓層等待電梯的人 x: 2-17
	int x = n + 2;  //x座標從2開始， n: 那層樓等待電梯的第幾人 (從0開始)
	int y = setY(fstFloor);
	if (elevatorFloor == fstFloor) {
		outputFloor(nextFloor, x, y);
	} else {
		outputFloor (fstFloor, x, y);
	}
}

void Control::fstFloor(int n, int fstFloor, int nextFloor) { //印出n人一開始想去的樓層  x: 33-47 (15格)
	int x = n + 33; //n是從 0 開始，從 x = 33開始印
	int y = setY(fstFloor);

	outputFloor (nextFloor, x, y);
}

void Control::printE1(int e1Floor, int usage, int num) { //第一台電梯 x: 50-58  + 使用量, num:電梯人數
	int y = setY(e1Floor);
	move(y, 50);
	printw("|__%d__|",usage);

	if (num > 0) { //電梯有人才顯示人數
		move(y - 1, 54);
		attron(A_REVERSE); //打開反白
		printw("%d", num);
		attroff(A_REVERSE); //關閉反白
	}
	refresh();
}
void Control::printE2(int e2Floor, int usage, int num) { // 第二台電梯 x: 61-69 + 使用量, num :電梯人數
	int y = setY(e2Floor);
	move(y, 61);
	printw("|__%d__|",usage);
	if (num > 0) { //電梯有人才顯示人數
		move(y - 1, 64);
		attron(A_REVERSE); //打開反白
		printw("%d", num);
		attroff(A_REVERSE); //關閉反白
	}

	refresh();
}
void Control::printE3(int e3Floor, int usage, int num) { //第三台電梯 x: 72-79 + 使用量, 電梯人數
	int y = setY(e3Floor);
	move(y, 72);
	printw("|__%d__|",usage);
	if (num > 0) { //電梯有人才顯示人數
		move(y - 1, 75);
		attron(A_REVERSE); //打開反白
		printw("%d", num);
		attroff(A_REVERSE); //關閉反白
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
	int total_waiting_time = 0;//統計總等待時間
	int average = 0;//統計平均等待時間
	int usage=0;
	int after_min[3]= {1,1,1};
	int first_max[3] = {1, 1, 1};
	int after_max[3]={1,1,1};
	srand(time(0));
	control.Floor();//此四行為初始情況
	control.printE1(1, 0, 0);
	control.printE2(1, 0, 0);
	control.printE3(1, 0, 0);
	int elein_peo_count[3]= {}; //計算一開始有幾人要進去(用來算電梯的停留時間)
	int after_elein_peo_count[3] = {};//後來有幾個人要進去(用來算電梯的停留時間)
	int floor_counter[12] = {};//記錄每層樓有幾人
	bool first=true;//判斷初始選電梯
	bool type1[3]= {true,true,true};//判斷第一次的assign 賦予最大值 ]
	bool type[3]= {true,true,true};//判斷第一次的assign
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
		int oldsize = control.getSize();//得到上一次的總size
		if(control.getSize()<150) { //如果人數沒爆產生人
			control.add();//產生人並決定出想去的樓層
		}
		if((control.getSize()-oldsize)==0&&first) {
			continue;
		}
		int n = 1;//產生的人數 用來move 人的x
		for (int i = oldsize; i<control.getSize(); i++) { //每個人第一次選擇電梯的情況 統計使用量與人數
			if(control.assign(control.getFst(i),first)==0) { //一開始選擇電梯的情況
				select_ele[0] = true;
				control.Add(0, 1); //是第一個電梯人數就加1
				elein_peo_count[0]++;//代表第一電梯有人使用
				if(type1[0]==true) {
					first_max[0]=control.getFst(i);
					type1[0]=false;
				}
				if (control.getFst(i) > first_max[0]) { //為了得到邊界值 
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
				if (control.getFst(i) > first_max[1]) { //為了得到邊界值 
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
				if (control.getFst(i) > first_max[2]) { //為了得到邊界值 
					first_max[2] = control.getFst(i);
				}
			}
			for (int j = 0; j < 12; j++) { //計算要去那樓層的人有幾人
				if(control.getFst(i)==j) {
					floor_counter[j]++;
				}
			}
			n=n+2; 
			control.fstFloor(n,1,control.getFst(i));
			
		}
		Sleep(2000);//單位時間為0.5秒
		first=false;
		clear();
		control.Floor();
		refresh();
		if(elein_peo_count[0]!=0) { //代表有人要使用第一個電梯 move 跟 cout
			control.waitTime(0, elein_peo_count[0]);//計算等待時間
			int time = control.getwait_time(0);	 //得到等待時間
			total_waiting_time += time; //把等待時間加入
		} else if(elein_peo_count[1]!=0) { //代表有人要使用第二個電梯
			control.waitTime(1, elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(elein_peo_count[2]!=0) { //代表有人要使用第三個電梯
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
			{						 //第二次選電梯的情況 統計用
				control.setFloor(i); //先得到第二次想要去的樓層
				if (control.assign(control.getSecFloor(i), first) == 0)
				{ //後來選擇電梯的情況
					if (type[0] == true)
					{
						after_min[0] = control.getSecFloor(i);
						type[0] = false;
					}
					control.Add(0, 1); //是第一個電梯人數就加1
					after_elein_peo_count[0]++;
					if (control.getSecFloor(i) < after_min[0])
					{ //為了得到邊界值 也就是after_y 因為第一次都是1樓所以first_y不用
						after_min[0] = control.getSecFloor(i);
					}
					select_ele[0] = true;
					/*if(control.getSecFloor(i)==1)//如果此人回到1樓此電梯人數-1
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
					{ //為了得到邊界值 也就是after_y 因為第一次都是1樓所以first_y不用
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
					{ //為了得到邊界值 也就是after_y 因為第一次都是1樓所以first_y不用
						after_min[2] = control.getSecFloor(i);
					}
					select_ele[2] = true;
					/*if(control.getSecFloor(i)==1)
					control.minus(2,1);*/
				}
				for (int j = 0; j < 12; j++)
				{ //計算要去那樓層的人有幾人
					if (control.getSecFloor(i) == j)
					{
						floor_counter[j]++;
					}
				}
				if (control.getSecFloor(i) == 1)
				{
					//control.remove(i);//如果1樓此人消失
				}
			}
			control.move_elevator(select_ele[0], select_ele[1], select_ele[2], first_max[0], after_min[0], first_max[1], after_min[1], first_max[2], after_min[2]);
		if(after_elein_peo_count[0]!=0) { //代表有人要使用第一個電梯
			control.waitTime(0, after_elein_peo_count[0]);
			int time = control.getwait_time(0);
			total_waiting_time += time;
		} else if(after_elein_peo_count[1]!=0) { //代表有人要使用第二個電梯
			control.waitTime(1, after_elein_peo_count[1]);
			int time = control.getwait_time(1);
			total_waiting_time += time;
		} else if(after_elein_peo_count[2]!=0) { //代表有人要使用第三個電梯 
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


