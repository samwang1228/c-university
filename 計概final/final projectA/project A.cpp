#include<iostream>
#include<cstdlib>
#include<ctime>
#include <curses.h>
#include <windows.h>

#define Boundary_Color 1 
#define GameName_Color 2
#define Consumer_Color 3
#define Producer_Color 4 
#define BoundarySpeed 15 
#define ConsumerTurn 3 
#define ConsumerIsEat 0
#define ProducerTurn 2
#define Max_capactiy 1920 

static int Consumer_Number=1000,Productor_Number=1000,Total_Turn = 0; // set
static int timeSpeed;												  // change frequenze
static int field[26][82] = {{0},{0}};								  // 1 is producer, 2 is consumer 9 is wall 
const int Word_Speed = 3000;										  // ms			

using namespace std;

void Start_Maping();
void Keep_map();
void initMap();
void initInfor();
bool isEnterType();

class base{
    public :								
		bool check(int posY,int posX);						//	查看附近的位置是否有東西(在移動或複製時使用)  
        void move(int posX,int posY,int object);			//  移動
};
bool base::check(int posY,int posX){
        if(	field[posY-1][posX-1]==0 && posY-1>0 && posX-1>0)
			return true;	 
		else if (field[posY][posX-1]==0 && posX-1>0)
			return true;
		else if (field[posY+1][posX-1]==0 && posY+1 <25 && posX-1>0)
			return true;
		else if (field[posY-1][posX]==0 && posY-1>0  )
			return true;
		else if (field[posY+1][posX]==0 && posY+1<25 )
			return true; 
        else if (field[posY-1][posX+1]==0 && posY-1>0 && posX+1 < 81)
			return true;
		else if (field[posY][posX+1]==0 && posX+1 < 81)
			return true;
		else if (field[posY+1][posX+1]==0 && posY+1 < 25 && posX+1 < 81)
			return true; 
		else 
            return false;				
}
void base::move(int posY,int posX,int object){
    bool isMoveFinish = false; 										
    int Case; 											
    while( !isMoveFinish && check(posY, posX))				
    {
        Case = rand() % 8;																		
        switch(Case)
        {
            case 0:
            {
                if (posX - 1>0 && posY-1 >0 && field[posY - 1][posX - 1] == 0)
                {
                    field[posY][posX] = 0; 
                    field[posY - 1][posX - 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 1:
            {
                if (posX-1 > 0 && field[posY][posX - 1] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY][posX - 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 2:
            {
                if (posX-1 > 0 && posY + 1 < 25 && field[posY + 1][posX - 1] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY + 1][posX - 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 3:
            {
                if (posY+1 < 25 && field[posY + 1][posX] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY + 1][posX] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 4:
            {
                if (posY+1<25 && posX+1 < 81 && field[posY + 1][posX + 1] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY + 1][posX + 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 5:
            {
                if (posX+1< 81 && field[posY][posX + 1] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY][posX + 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 6:
            {
                if (posY-1>0 && posX+1 <81 && field[posY - 1][posX + 1] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY - 1][posX + 1] = object;
                    isMoveFinish = true;
                }
                break;
            }
            case 7:
            {
                if (posY-1>0 && field[posY - 1][posX] == 0)
                {
                    field[posY][posX] = 0;
                    field[posY - 1][posX] = object;
                    isMoveFinish = true;
                }
                break;
            }
        }   
    }
}
class consumer:public base{
	public:
		consumer(int number);								// 	消費者剛開始的數目
		void copy(int which,int posY,int posX);	
		void dead();										// 	殺掉消費者 
		void LivingTime();									// 	decrease Consumer lifespan 
		int  getSum();
		int  getXpos(int which);
		int  getYpos(int which);
		void setPos(int which,int Ypos,int Xpos);
		bool eating(int which,int Ypos,int Xpos);			// eating has priority
		bool isAdd();
		void setConsumer(int x);
	private:
		int sum;											// 還有多少個消費者  
		int TotalConsumer[Max_capactiy][4] = {{0},{0}};		// 每一個消費者各自生存的回合數,位置  
};
class producer:public base{
	public:
		producer(int p);					
		void copy(int turn,int posX,int posY);		 
		void setPos(int which,int Ypos ,int Xpos);
		int  getXpos(int which);
		int  getYpos(int which); 
		int  getSum();
		void setSum(int x);
		void setProducer(int x);
		bool isAdd();
	private:
		int sum;
		int TotalProducer[Max_capactiy][3] = {{0},{0}};
};
consumer::consumer(int number){
	int x,y;
	sum = number;
	for (int i=0 ; i<sum ; i++){
		x = rand()%80+1;
		y = rand()%24+1;
		if (field[y][x] == 0){
			TotalConsumer[i][0] = x;				// x postion
			TotalConsumer[i][1] = y;				// y postion
			TotalConsumer[i][2] = ConsumerIsEat;	// have energy to copy
			TotalConsumer[i][3] = ConsumerTurn;		// lifespan
			field[y][x] = 2 ;
		}
		else{
			i--;
		}
	}
}
producer::producer(int number){
	int x,y;
	sum = number;
	for (int i=0 ; i<sum ; i++){
		x = rand()%80+1;
		y = rand()%24+1;
		if (field[y][x] == 0){
			field[y][x] = 1 ;
		}
		else{
			i--;
		}
	}
}
void consumer::setPos(int which,int Ypos,int Xpos){
	TotalConsumer[which][0] = Xpos;
	TotalConsumer[which][1] = Ypos;
}
void producer::setPos(int which ,int Ypos,int Xpos){
	TotalProducer[which][0] = Xpos;
	TotalProducer[which][1] = Ypos;
}
int consumer::getXpos(int which){
	return TotalConsumer[which][0];
}
int producer::getXpos(int which){
	return TotalProducer[which][0];
}
int consumer::getYpos(int which){
	return TotalConsumer[which][1];
}
int producer::getYpos(int which){
	return TotalProducer[which][1];
}
int consumer::getSum(){
	return sum ;
}
int producer::getSum(){
	return sum;
}
void consumer::copy(int which,int posY,int posX){
	if (check(posY,posX)){
		TotalConsumer[which][2] = 0;
		TotalConsumer[which][3] += 3;
		bool x = true ;
		while(x)
		{
			int pos = rand()%8;
			switch(pos)
            {
                case 0:
                {
                    if (posY-1 >0 && posX -1 > 0 && field[posY-1][posX-1] == 0 )
                    {
                        field[posY - 1][posX - 1] = 2;
                        TotalConsumer[sum][0] = posX - 1;
                        TotalConsumer[sum][1] = posY - 1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
                        x=false;
                    }
                    break;
                }
                case 1:
                {
                    if (posX-1>0 && field[posY][posX-1] == 0 )
                    {	
                        field[posY][posX-1] = 2;
                        TotalConsumer[sum][0] = posX-1;
                        TotalConsumer[sum][1] = posY ;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x=false;
                    }
                    break;
                }
                case 2:
                {
                    if (posY+1 < 25 && posX-1 >0 && field[posY + 1][posX - 1] == 0 )
                    {	
                    	field[posY+1][posX-1] = 2;
                        TotalConsumer[sum][0] = posX - 1;
                        TotalConsumer[sum][1] = posY + 1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x=false;
                    }
                    break;
                }
                case 3:
                {
                    if (posY+1 < 25 && field[posY + 1][posX] == 0 )
					{	
                    	field[posY+1][posX] = 2;
                        TotalConsumer[sum][0] = posX ;
                        TotalConsumer[sum][1] = posY + 1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                       	sum++;
					    x=false;
                    }
                    break;
                }
                case 4:
                {
                    if (posY+1 < 25 && posX+1 < 81 && field[posY+1][posX+1] == 0 )
                    {
                    	field[posY+1][posX+1 ] = 2;
                        TotalConsumer[sum][0] = posX+1 ;
                        TotalConsumer[sum][1] = posY+1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x=false;
                    }
                    break;
                }
                case 5:
                {
                    if (posX+1<81 && field[posY][posX+1] == 0 )
                    {
                    	field[posY][posX+1] = 2;
                        TotalConsumer[sum][0] = posX+1;
                        TotalConsumer[sum][1] = posY;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x = false;
                    }
                    break;
                }
                case 6:
                {
                    if (posY-1>0 && posX+1<81 && field[posY-1][posX+1] == 0 )
                    {
                    	field[posY-1][posX+1] = 2;
                        TotalConsumer[sum][0] = posX+1 ;
                        TotalConsumer[sum][1] = posY-1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x = false;
                    }
                    break;
                }
                case 7:
                {
                    if (posY-1>0 && field[posY-1][posX] == 0 )
                    {
                    	field[posY-1][posX] = 2;
                        TotalConsumer[sum][0] = posX ;
                        TotalConsumer[sum][1] = posY-1;
                        TotalConsumer[sum][2] = ConsumerIsEat;
                        TotalConsumer[sum][3] = ConsumerTurn;
                        sum++;
						x = false;
                    }
                    break;
                }
            }
        }
	}
}
void producer::copy(int turn,int posY,int posX){
	if (turn>=ProducerTurn && turn%ProducerTurn==0  && check(posY,posX)){
		int x = 0 ;
		while(x==0)
		{
			int pos = rand() % 8;
			switch(pos)
            {
                case 0:
                {
                    if (posX-1 >0 && posY-1 > 0 && field[posY - 1][posX - 1] == 0 )
                    {
                        field[posY - 1][posX - 1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 1:
                {
                    if (posX -1 >0 && field[posY][posX - 1] == 0 )
                    {
                        field[posY][posX - 1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 2:
                {
                    if (posY+1<25 && posX-1 >0 && field[posY + 1][posX - 1] == 0 )
                    {
                    	field[posY+1][posX-1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 3:
                {
                    if (posY+1<25 && field[posY + 1][posX] == 0 )
					{
                    	field[posY + 1][posX ] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 4:
                {
                    if (posY+1 < 25 && posX+1 < 81 && field[posY + 1][posX + 1] == 0 )
                    {
                    	field[posY+1][posX+1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 5:
                {
                    if (posX+1<81 && field[posY][posX+1] == 0 )
                    {
                    	field[posY][posX+1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 6:
                {
                    if (posY-1>0 && posX+1<81 && field[posY - 1][posX + 1] == 0 )
                    {
                    	field[posY-1][posX+1] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
                case 7:
                {
                    if (posY-1>0 && field[posY-1][posX] == 0 )
                    {
                    	field[posY-1][posX] = 1;
                        sum++;
                        x=1;
                    }
                    break;
                }
            }
        }	
	}
}
void consumer::dead(){
	for(int i=0 ; i<sum ; i++)
	{
		if(TotalConsumer[i][3] == 0)
		{	
			if (i==sum-1){
				int x = getXpos(i);
				int y = getYpos(i);
				field[y][x] = 0;
			}
			else{
				int x = getXpos(i);
				int y = getYpos(i);
				field[y][x] = 0;
				for (int j=i ; j<sum ; j++){
					TotalConsumer[j][0] = TotalConsumer[j+1][0];
					TotalConsumer[j][1] = TotalConsumer[j+1][1];
					TotalConsumer[j][2] = TotalConsumer[j+1][2];
					TotalConsumer[j][3] = TotalConsumer[j+1][3];
				}
				i-- ; 	   									 
			}
			sum-- ;											 
		} 
	}
}
bool consumer::eating(int which,int posY,int posX){
	if(	field[posY-1][posX-1]==1 && posY-1>0 && posX-1>0){
		TotalConsumer[which][0]= posX-1;
		TotalConsumer[which][1]= posY-1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY-1][posX-1] = 2;
		return true;
	}		 
	else if (field[posY][posX-1]==1 && posX-1>0){
		TotalConsumer[which][0]= posX-1;
		TotalConsumer[which][1]= posY;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY][posX-1] = 2;
		return true;
	}
	else if (field[posY+1][posX-1]==1 && posY+1 <25 && posX-1>0){
		TotalConsumer[which][0]= posX-1;
		TotalConsumer[which][1]= posY+1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY+1][posX-1] = 2;
		return true;
	}
	else if (field[posY-1][posX]==1 && posY-1>0  ){
		TotalConsumer[which][0]= posX;
		TotalConsumer[which][1]= posY-1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY-1][posX] = 2;
		return true;	
	}
	else if (field[posY+1][posX]==1 && posY+1<25 ){
		TotalConsumer[which][0]= posX;
		TotalConsumer[which][1]= posY+1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY+1][posX] = 2;
		return true;
	}
    else if (field[posY-1][posX+1]==1 && posY-1>0 && posX+1 < 80){
    	TotalConsumer[which][0]= posX+1;
		TotalConsumer[which][1]= posY-1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY-1][posX+1] = 2;
		return true;
	}
	else if (field[posY][posX+1]==1 && posX+1 < 80){
		TotalConsumer[which][0]= posX+1;
		TotalConsumer[which][1]= posY;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY][posX+1] = 2;
		return true;
	}
	else if (field[posY+1][posX+1]==1 && posY+1 < 25 && posX+1 < 80){
		TotalConsumer[which][0]= posX+1;
		TotalConsumer[which][1]= posY+1;
		TotalConsumer[which][2]= 1;
		field[posY][posX] = 0;
		field[posY+1][posX+1] = 2;
		return true;
	}
	else 
        return false; 
}
void consumer::LivingTime(){
	for(int i=0 ; i<sum ; i++)
	{
		TotalConsumer[i][3]-=1; 							// 壽命減少 
	}
}
void producer::setSum(int x){
	sum = x ;
}
void producer::setProducer(int x){
	int xpos,ypos;
	for (int i=0 ; i<x ; i++){
		xpos = rand()%80+1;
		ypos = rand()%24+1;
		if (field[ypos][xpos] == 0){
			field[ypos][xpos] = 1 ;
			sum++;
		}
		else{
			i--;
		}
	}
	Keep_map();
	refresh();	
}
bool producer::isAdd(){
	int ch=getch();
	bool isAdd = false;
	if (sum == 0){
		beep();
		return  true;
	}
	if(ch == 49){	// 1
		beep();
		ungetch(ch);
	  	return  true;
	}
	else{
	  	return  false;
	}
}
bool consumer::isAdd(){
	int ch=getch();
	bool isAdd = false;
	if (sum == 0){
		beep();
		return  true;
	}
	if(ch == 50){	// 2
		beep();
		ungetch(ch);
	  	return  true;
	}
	else{
	  	return  false;
	}
}
void consumer::setConsumer(int x){
	int xpos,ypos;
	int number = sum;
	for (int i=number ; i<number+x ; i++){
		xpos = rand()%80+1;
		ypos = rand()%24+1;
		if (field[ypos][xpos] == 0){
			TotalConsumer[i][0] = xpos;				// x postion
			TotalConsumer[i][1] = ypos;				// y postion
			TotalConsumer[i][2] = ConsumerIsEat;	// have energy to copy
			TotalConsumer[i][3] = ConsumerTurn;		// lifespan
			field[ypos][xpos] = 2 ;
			sum++;
		}
		else{
			i--;
		}
	}
	Keep_map();
	refresh();
}

int main(){
	initMap();															//setting  information
	initInfor();
	consumer C(Consumer_Number);
	producer P(Productor_Number);									
	while(true){		
		Keep_map();
		WINDOW *Data;													//another interface information	
		Data = newwin(26,35,0,82);
		wprintw(Data,"\n [information]\n\n");
		wprintw(Data,"  Sum of Producer(*): %d\n",P.getSum());
		wprintw(Data,"  Sum of Consumer(C): %d\n",C.getSum());
		wprintw(Data,"  Pass of time: %d\n\n",timeSpeed*Total_Turn/1000);
		wprintw(Data,"  TimeSpeed-> %f",timeSpeed/1000.0);
		wprintw(Data,"(s)\n");
		if(P.isAdd() || C.isAdd()){
			bool p = P.isAdd();
			bool c = C.isAdd();
			if (p){
				wprintw(Data,"input producer you want add");
				wrefresh(Data);
				scanw("%d",&Productor_Number);
				clear();
				P.setProducer(Productor_Number);
			}
			else{
				wprintw(Data,"input consumer you want add");
				wrefresh(Data);
				scanw("%d",&Consumer_Number);
				clear();
				C.setConsumer(Consumer_Number);
			}
			Data = newwin(26,35,0,82);
			wprintw(Data,"\n [information]\n\n");
			wprintw(Data,"  Sum of Producer(*): %d\n",P.getSum());
			wprintw(Data,"  Sum of Consumer(C): %d\n",C.getSum());
			wprintw(Data,"  Pass of time: %d\n\n",timeSpeed*Total_Turn/1000);
			wprintw(Data,"  TimeSpeed-> %f",timeSpeed/1000.0);
			wprintw(Data,"(s)\n");
			wrefresh(Data);
			Sleep(1000);
		}
		int Xpos,Ypos;
		int temp1 = C.getSum();
		int temp2 = P.getSum();
		int l=0,k=0;
		for(int i=0; i<temp1 ; i++){									// consumer is first
			Xpos = C.getXpos(i);
			Ypos = C.getYpos(i);
			if(C.eating(i,Ypos,Xpos)){							
				temp2 -- ;
				Xpos = C.getXpos(i);
				Ypos = C.getYpos(i);
				C.copy(i,Ypos,Xpos);
			}
			else{
				C.move(Ypos,Xpos,2);
			}
		}		
		for (int i=1; i<26 ; i++){										// producer move
			for(int j=1 ; j<81 ; j ++){
				if (field[i][j] == 1){
					P.move(i,j,1);
				}
			} 
		}
		for (int i=0; i<26 ; i++){										// new producer set 
			for(int j=0 ; j<82 ; j ++){									
				if (field[i][j] == 1){
					P.setPos(l,i,j);
					l++;
				}
			} 
		}
		l = 0;
		P.setSum(temp2);
		temp2 = P.getSum();
		for (int i=0 ; i<temp2 ; i++){									// producer copy
			Xpos = P.getXpos(i);
			Ypos = P.getYpos(i);
			P.copy(Total_Turn,Ypos,Xpos);
		}
		for (int i=0; i<26 ; i++){										// set new consumer and producer		
			for (int j=0 ; j<82 ; j++){
				if (field[i][j] == 2){
					C.setPos(k,i,j);
					k++;
				}
				else if (field[i][j] == 1){
					P.setPos(l,i,j);
					l++;
				}
			}
		}
		C.dead();
		C.LivingTime();
		Total_Turn ++;
		refresh();
		wrefresh(Data);
		Sleep(timeSpeed);
		clear();
	
	}
	endwin();
}
void initMap(){
	for (int i=0 ; i < 82 ; i ++ ){
		field[25][i] = 9;
		field[0][i] =9;
	}
	for (int j=0 ; j < 26 ; j++){
		field[j][81] = 9;
		field[j][0] = 9;
	}
}
bool isEnterType(){
	int ch=getch();
	if(ch == 32){
		beep();
		ungetch(ch);
	  	return true;
	}
	else{
	  	return false;
	}
}
void initInfor(){
	initscr();
	cbreak();
 	nonl();
 	noecho();
 	nodelay(stdscr,TRUE);
 	intrflush(stdscr,FALSE);
 	keypad(stdscr,TRUE);
	curs_set(0);
	mvaddstr(14,32 ,"Welcome to final project A");
	refresh();
	Sleep(Word_Speed/1.5);
	mvaddstr(15,32 ,"In this case");
	refresh();
	Sleep(Word_Speed/2);
	mvaddstr(16,32,"We will show the relationship between Consumer and Producer");
	refresh();
	Sleep(Word_Speed);
	clear();
	while(true){
	 	if(isEnterType()){
			break;
		}
		if(true){
			Sleep(Word_Speed/15);
			mvaddstr(14,32,"Please enter space to enter the game");
			refresh();
			Sleep(Word_Speed/5);
			clear();
		}
	}
	Sleep(Word_Speed/3);
	endwin();
	while(Consumer_Number + Productor_Number > 80*24){
		cout << "Input information !!\n\n--> How many of Porductor you want (*):";
		cin >> Productor_Number;
		
		cout << "--> How many of Consumer you want (C):";
		cin >> Consumer_Number;
		
		cout << "--> Set TimeSpeed(ms):";
		cin >> timeSpeed;
	}
	initscr();
	cbreak();
 	nonl();
 	noecho();
 	nodelay(stdscr,TRUE);
 	intrflush(stdscr,FALSE);
 	keypad(stdscr,TRUE);
	curs_set(0);
	refresh();
	srand(time(NULL));
	start_color();											
	init_pair(Boundary_Color, COLOR_BLUE, COLOR_BLACK);	
	init_pair(GameName_Color, COLOR_RED, COLOR_BLACK);
	init_pair(Consumer_Color,COLOR_RED, COLOR_BLACK);
	init_pair(Producer_Color,COLOR_GREEN,COLOR_BLACK);
}
void Start_Maping(){
	for(int a=0 ; a<26 ; a++){
		mvaddch(a,0,'$');
		Sleep(BoundarySpeed);
		mvaddch(a,81,'$');
		refresh();
	}
	for(int a=1 ; a<80 ; a++){
		mvaddch(0,a,'~');
		Sleep(BoundarySpeed);
		mvaddch(25,a,'~');
		if (a>32 && a<45 ){
			mvaddch(0,a,' ');
		}
		refresh();
	}
	attron(COLOR_PAIR(Boundary_Color));	
	Start_Maping();
	attroff(COLOR_PAIR(Boundary_Color));
	attron(COLOR_PAIR(GameName_Color));	
	mvaddstr(0,32,"<Hungry game>");
	refresh();
	attroff(COLOR_PAIR(GameName_Color));
}
void Keep_map(){
	attron(COLOR_PAIR(Boundary_Color));					
	for(int a=0 ; a<26 ; a++){
		mvaddch(a,0,'$');
		mvaddch(a,81,'$');
	}
	for(int a=1 ; a<82 ; a++){
		mvaddch(0,a,'~');
		mvaddch(25,a,'~');
		if (a>32 && a<45 ){
			mvaddch(0,a,' ');
		}
	}
	attroff(COLOR_PAIR(Boundary_Color));
	attron(COLOR_PAIR(GameName_Color));	
	mvaddstr(0,32,"<Hungry game>");
	attroff(COLOR_PAIR(GameName_Color));
	attron(COLOR_PAIR(Consumer_Color));	
	for (int i=1 ; i<26 ; i++){
		for (int j=1 ; j<81 ; j++){
			if (field[i][j] == 2){
				mvaddch(i,j,'C');
			}
		}
	}
	attroff(COLOR_PAIR(Consumer_Color));
	attron(COLOR_PAIR(Producer_Color));
	for (int i=1 ; i<26 ; i++){
		for (int j=1 ; j<81 ; j++){
			if (field[i][j] == 1){
				mvaddch(i,j,'*');
			}
		}
	}
	attroff(COLOR_PAIR(Producer_Color));
	refresh();
}

