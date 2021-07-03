#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <curses.h>
#include <windows.h>
#include <windows.h>
#include <string>
using namespace std;



class elavator{
private:
    int times;
    int ID;
    int numOfPeople;
    int nowFloor;
    int nextFloor;
    int upOrDown;
    int *sequential;
public:
    elavator();
    void setSequential(int new_element,int ela_floor);
    void setId(int id);
    void setUpOrDown(int up_or_down);
    void setNumOfPeople(int people_in_ela);
    void setNowFloor(int now_floor);
    void setNextFloor(int next_floor);
    int getID();
    int getNumOfPeople();
    int getNowFloor();
    int getNextFloor();
    int getLoadCapacity();
    int getUpOrDown();
    bool dirUp();
    
    
};


class people{
private:
    bool is_Move;
    bool state;
    int nowFloor;
    int nextFloor;
    int inWhichEla;
    int stayTime;
public:
    people();
    void setState(bool STATE);
    void setNowFloor(int now_floor);
    void setNextFloor();
    void setStayTime(int setTime);
    void randStayTime();
    void setInWhichEla(int id);
    void setIsMove(bool is_move);
    int getNowFloor();
    int getNextFloor();
    bool getState();
    int getStayTime();
    bool dirUp();
    bool getIsMove();
    int getInWhichEla();

};



class building{
private:
    int floorPeople[12];
public:
    void setFloorPeople(int floor,int people);
    void moveIn(elavator ela[],people p[]);
    void moveOut(elavator ela[],people p[]);
    void setElaNextFloor(elavator ela[],people p[]);
    void stayTimeMinus(people p[]);
    void monitor(elavator ela[],people p[]);
    void elaShow(elavator ela[],people p[]);
    
    
    void elaMove(elavator ela[],people p[]);
};
//24 80
void showFloor();
int returnPosY(int floor);
void setId(elavator ela[]);
void clearEla();


int main(int argc, const char * argv[]) {
    srand(time(0));
    people p[150];
    elavator ela[3];
    for(int i=0;i<150;i++){
        p[i].setNextFloor();
        p[i].setState(false);
        p[i].setIsMove(false);
        p[i].setNowFloor(1);
        p[i].setNextFloor();
        p[i].setInWhichEla(-1);
        p[i].setStayTime(0);
        
    }
    for( int i=0 ; i<3 ; i++ ){
        ela[i].setNumOfPeople(0);
        ela[i].setNowFloor(1);
        ela[i].setUpOrDown(1);
    }
    cout<<"test"; 
    building control;
    setId(ela);
    int i=0;
    
    initscr();
    showFloor();
    while (true) {
    	
        
        p[i].setState(true);
        p[i].setIsMove(true);
        
        
        
        control.moveIn(ela, p);
        
        

        control.moveOut(ela, p);
        
        

        control.elaMove(ela, p);
        
        

        control.elaShow(ela,p);

        

        control.setElaNextFloor(ela, p);

    
        control.stayTimeMinus(p);

        Sleep(1000);
        refresh();
        
        i++;
    }
    //getch();
    endwin();
    
    
}





void building::moveIn(elavator ela[],people p[]){
    
    int i=0;
    int id=3;
    
    while( i<150){
        
        
        if(p[i].getState() && p[i].getIsMove() && p[i].getInWhichEla()==-1){
            
            for(int j=0;j<3;j++){
                if(ela[j].getUpOrDown()==1&&p[i].dirUp()&&ela[j].getNowFloor()==p[i].getNowFloor()&&p[i].getNowFloor()!=p[i].getNextFloor()&&ela[j].getNumOfPeople()<12 && p[i].getInWhichEla()==-1 ){//人跟電梯在同樓層 且都要往上
                    id=j;
                    p[i].setInWhichEla(id);
                    ela[id].setNumOfPeople( ela[id].getNumOfPeople()+1 );
                    
                    break;
                
                }
                else if(ela[j].getUpOrDown()==0&&!p[i].dirUp()&&ela[j].getNowFloor()==p[i].getNowFloor()&&p[i].getNowFloor()!=p[i].getNextFloor()&&ela[j].getNumOfPeople()<12 && p[i].getInWhichEla()==-1){//人跟電梯在同樓層 且都要往下
                    id=j;
                    p[i].setInWhichEla(id);
                    ela[id].setNumOfPeople( ela[id].getNumOfPeople()+1 );
                    
                    break;
                }
                
                
            }

        }
        
        
        i++;
    }
    

}


void building::setElaNextFloor(elavator ela[],people p[]){
    int i=0;
    
    while( p[i].getIsMove() && p[i].getState() && p[i].getInWhichEla()!=-1 && p[i].getNowFloor()!=p[i].getNextFloor() ){
        
        ela[ p[i].getInWhichEla() ].setSequential( p[i].getNextFloor(), ela[ p[i].getInWhichEla() ].getNowFloor() );
        i++;
        
    }
    
}


void building::moveOut(elavator ela[],people p[]){
    int i=0;
    
    while( i<150 ){
        
        if(p[i].getState() && p[i].getIsMove() && p[i].getNowFloor()==p[i].getNextFloor() && p[i].getInWhichEla()!=-1){
            int id=p[i].getInWhichEla();
            ela[id].setNumOfPeople( ela[id].getNumOfPeople()-1 );
            p[i].setInWhichEla(-1);
            p[i].setIsMove(false);
            p[i].randStayTime();
            p[i].setNextFloor();
        }
        i++;
    }
    
    
}


void building::elaMove(elavator ela[],people p[]){
    int i=0;
    for(int j=0;j<3;j++){
        i=0;
        if( ela[j].getUpOrDown()==1 && ela[j].getNumOfPeople()!=0 ){ 
            ela[j].setNowFloor( ela[j].getNowFloor()+1 );
            while( i<150 ){
                if(p[i].getState() && p[i].getIsMove() && p[i].getInWhichEla()==j){
                    p[i].setNowFloor( p[i].getNowFloor()+1 );
                }
                i++;
            }
        }
        else if( ela[j].getUpOrDown()==0 && ela[j].getNumOfPeople()!=0 ){
        
            ela[j].setNowFloor( ela[j].getNowFloor()-1 );
            
            while( i<150 ){
                
                if(p[i].getState() && p[i].getIsMove() && p[i].getInWhichEla()==j){
                    p[i].setNowFloor( p[i].getNowFloor()-1 );
                }
                i++;
            }
        }
        else if ( ela[j].getNumOfPeople()==0 ){
            
            if(ela[j].getNowFloor()!=1){
                ela[j].setUpOrDown(0);
                ela[j].setNowFloor( ela[j].getNowFloor()-1 );
                
            }
            else{
                ela[j].setUpOrDown(1);
                

            }

                
        }
        
     
        
    }
}

void building::stayTimeMinus(people p[]){
    int i=0;
    while(i<150 ){
        if(p[i].getStayTime()!=0 && p[i].getState() && !p[i].getIsMove()){
            p[i].setStayTime( p[i].getStayTime()-1 );
            if( p[i].getStayTime()==0 ){
                p[i].setIsMove(true);
                p[i].setNextFloor();
            }
        }
        i++;
    }
}

void building::elaShow(elavator ela[],people p[]){
    int ss;
    char temp[64];
    char temp1[64];
    int index;
    int posY;
    clearEla();
    
    index=0;
    posY=returnPosY( ela[index].getNowFloor() );
    ss=ela[index].getNumOfPeople();
    sprintf(temp, "%d", ss);
    mvaddstr( posY , 20, "!__________!");
    mvaddstr( posY, 33, "num=");
    mvaddstr( posY, 37, temp);
    for(int i=0;i<150;i++){
        if(p[i].getInWhichEla()==0){
            sprintf(temp, "%d", i);
            sprintf(temp1, "%d", p[i].getNextFloor());
            mvaddstr( posY+1, 37, temp);
            mvaddstr( posY+1, 34, temp1);
            posY++;
        }
    }
    
    
    index=1;
    posY=returnPosY( ela[index].getNowFloor() );
    ss=ela[index].getNumOfPeople();
    sprintf(temp, "%d", ss);
    mvaddstr( posY , 40, "!__________!");
    mvaddstr( posY , 53, "num=");
    mvaddstr( posY , 57, temp);
    for(int i=0;i<150;i++){
        if(p[i].getInWhichEla()==1){
            sprintf(temp, "%d", i);
            sprintf(temp1, "%d", p[i].getNextFloor());

            mvaddstr( posY+1, 57, temp);
            mvaddstr( posY+1, 54, temp1);

            posY++;
        }
    }
    
    
    index=2;
    posY=returnPosY( ela[index].getNowFloor() );
    ss=ela[index].getNumOfPeople();
    sprintf(temp, "%d", ss);
    mvaddstr( posY , 60, "!__________!");
    mvaddstr( posY , 73, "num=");
    mvaddstr( posY , 77, temp);
    for(int i=0;i<150;i++){
        if(p[i].getInWhichEla()==2){
            sprintf(temp, "%d", i);
            sprintf(temp1, "%d", p[i].getNextFloor());

            mvaddstr( posY+1, 77, temp);
            mvaddstr( posY+1, 74, temp1);

            posY++;
        }
    }


}

void elavator::setUpOrDown(int up_or_down){
    upOrDown=up_or_down;
}
int elavator::getUpOrDown(){
    return upOrDown;
}
 

void elavator::setSequential(int new_element,int ela_floor){
    int i=0;
    bool go=true;
    while( go && i<times ){
        if( sequential[i]==new_element ){
            go=false;
            break;
        }
        i++;
    }
    

    if(go){
        int *temp;
        temp=sequential;
        sequential=new int[times+1];
        for(int i=0;i<times;i++){
            sequential[i]=temp[i];
        }
        
        sequential[times]=new_element;
    
        
        times++;
    }
    
    i=0;
    go=false;
    while( !go && i<times ){
        if( sequential[i]==ela_floor ){
            go=true;
            break;
        }
        i++;
    }
    if(go){
        int *temp;
        for(int j=i;j<times-1;j++){
            sequential[j]=sequential[j+1];
        }
        temp=sequential;
        sequential=new int[times-1];
        for(int i=0;i<times-1;i++){
            sequential[i]=temp[i];
        }
    
        delete temp;
        times--;

    }
    for(int i=0;i<times-1;i++){
        for(int j=i+1;j<times;j++){
            if(sequential[i]>sequential[j]){
                int temp=sequential[i];
                sequential[i]=sequential[j];
                sequential[j]=temp;
                continue;
            }
        }
    }
    
    
    
}
void elavator::setId(int id){
    ID=id;
}
void elavator::setNumOfPeople(int people_in_ela){
    numOfPeople=people_in_ela;
}
void elavator::setNowFloor(int now_floor){
    nowFloor=now_floor;
}
void elavator::setNextFloor(int next_floor){
    nextFloor=next_floor;
}
int elavator::getID(){
    return ID;
}
int elavator::getNumOfPeople(){
    return numOfPeople;
}
int elavator::getNowFloor(){
    return nowFloor;
}
int elavator::getNextFloor(){
    
    return nextFloor;
}
int elavator::getLoadCapacity(){
    int load=(numOfPeople+3)*nowFloor;
    return load;
}
bool elavator::dirUp(){
    if(nowFloor>nextFloor){
        return false;
    }
    else
        return true;
}










void people::setState(bool STATE){
    state=STATE;
}
void people::setNowFloor(int now_floor){
    nowFloor=now_floor;
}
void people::setNextFloor(){
    if(nowFloor==1){
        nextFloor=rand()%11+2;
    }
    else{
        do
            nextFloor=rand()%12+1;
        while(nowFloor==nextFloor);
        
    }
    
}
void people::setStayTime(int setTime){
    stayTime=setTime;
}
void people::randStayTime(){
    stayTime=rand()%81+20;
}
void people::setInWhichEla(int id){
    inWhichEla=id;
}
void people::setIsMove(bool is_move){
    is_Move=is_move;
}
int people::getNowFloor(){
    return nowFloor;
}
int people::getNextFloor(){
    return nextFloor;
}
bool people::getState(){
    return state;
}
int people::getStayTime(){
    return stayTime;
}
bool people::dirUp(){
    if(nextFloor>nowFloor){
        return true;
    }
    else
        return false;
    
}
bool people::getIsMove(){
    return is_Move;
}
int people::getInWhichEla(){
    return inWhichEla;
}






void monitor(elavator ela[],people p[]){
    int floor[3];
    floor[0]=ela[0].getNowFloor();
    floor[1]=ela[1].getNowFloor();
    floor[2]=ela[2].getNowFloor();
    
    
}



void showFloor(){
    mvaddstr(22, 0, "1F");
    mvaddstr(20, 0, "2F");
    mvaddstr(18, 0, "3F");
    mvaddstr(16, 0, "4F");
    mvaddstr(14, 0, "5F");
    mvaddstr(12, 0, "6F");
    mvaddstr(10, 0, "7F");
    mvaddstr(8, 0, "8F");
    mvaddstr(6, 0, "9F");
    mvaddstr(4, 0, "10F");
    mvaddstr(2, 0, "11F");
    mvaddstr(0, 0, "12F");

}

int returnPosY(int floor){
    switch (floor) {
        case 1:
            return 22;
            break;
        case 2:
            return 20;
            break;
        case 3:
            return 18;
            break;
        case 4:
            return 16;
            break;
        case 5:
            return 14;
            break;
        case 6:
            return 12;
            break;
        case 7:
            return 10;
            break;
        case 8:
            return 8;
            break;
        case 9:
            return 6;
            break;
        case 10:
            return 4;
            break;
        case 11:
            return 2;
            break;
        case 12:
            return 0;
            break;
            
        default:
            return -1;
            break;
    }
}


elavator::elavator(){
    times=1;
    numOfPeople=0;
    nowFloor=1;
    nextFloor=12;
    upOrDown=1;
    
}
people::people(){
    is_Move=false;
    state=false;
    nowFloor=1;
    nextFloor=rand()%11+2;
    inWhichEla=-1;
    stayTime=0;
}

void setId(elavator ela[]){
    
    ela[0].setId(0);
    ela[1].setId(1);
    ela[2].setId(2);
}



void clearEla(){
    for(int i=20;i<80;i++){
        for(int j=0;j<50;j++){
            mvaddch(j, i, ' ');
        }
    }
}
