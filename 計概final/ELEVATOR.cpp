#include <iostream>
#include <cmath>
using namespace std;
class Elevator{
public:
	Elevator();
	void add(int elevator,int people); //0 1 2 哪一台電梯 增加多少人 
	
	void minus(int elevator,int people); //0 1 2 哪一台電梯 減去多少人
	
	void setusage(bool a,bool b,bool c);//a b c 傳入電梯是否正在移動 若正在開門就false
										//每秒都要呼叫一次 
										
	int assign(int floor);//哪一個樓層需要服務 回傳0 1 2(派最近的or使用量最少的電梯過去)
	
	void waitTime(int elevator,int people);//0 1 2哪一台電梯要出入多少人
	
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
Elevator::Elevator(){
	for(int i=0;i<3;i++){
		eleout[i][0]=0; 
		eleout[i][1]=1;
		eleout[i][2]=0;
		//eleout[i][3]=;
		//eleout[i][4]=;
		eleout[i][5]=0;
		eleout[i][6]=-1; 
		eleout[i][7]=-1;
		for(int j=0;j<12;j++){
			elein[i][j]=0;
		} 
	}
} 

void Elevator::add(int elevator,int people){
	eleout[elevator][0]+=people;
	if(eleout[elevator][0]==10){
		eleout[elevator][6]=1;
	}
}
void Elevator::minus(int elevator,int people){
	if(eleout[elevator][0]==10){
		eleout[elevator][6]=-1;
		eleout[elevator][7]=1;
	}
	eleout[elevator][0]-=people;
}
int Elevator::assign(int floor){
	//要去一樓 派使用量最少的 
	if(floor==1){ 
		int elevator;
		int min=5000000;
		for(int i=0;i<3;i++){
			if( eleout[i][2]<min && eleout[i][6]==-1 && eleout[i][7]==-1){
				min=eleout[i][2];
				elevator=i;
			}
		}
		return elevator;
	}
	//不是要去一樓 派最近的 
	else{
		int min=13;
		int elevator;
		for(int i=0;i<3;i++){
			if(abs(eleout[i][1]-floor)<=min && eleout[i][6]==-1 && eleout[i][7]==-1){
				min=abs(eleout[i][1]-floor);
				elevator=i;
			}
		}
		return elevator;
	}
}
void Elevator::setusage(bool a,bool b,bool c){
	if(a==true){
		eleout[0][2]+=(eleout[0][0]+3)*1;//(載了多少人+3)*移動一樓 
	}
	if(b==true){
		eleout[1][2]+=(eleout[1][0]+3)*1;
	}
	if(c==true){
		eleout[2][2]+=(eleout[2][0]+3)*1;
	}
}
void Elevator::waitTime(int elevator,int people){
	eleout[elevator][7]=1;
	double time=people*0.7;
	//小於等於2直接2單位時間 
	if(time<=2){
		eleout[elevator][5]=2;
		return;
	}
	else{
		//大於2且有小數無條件進位 
		if(((int)(time*10)%10)!=0){
			eleout[elevator][5]=(int)time+1;
			return;
		}
		//大於2且無小數 
		else{
			eleout[elevator][5]=(int)time;
			return;
		}
	} 
} 
void Elevator::settime(){
	for(int i=0;i<3;i++){
		if(eleout[i][5]>0){
			eleout[i][5]-=1;
		}
		if(eleout[i][5]==0){
			eleout[i][7]=-1;
		}
	}	
} 
