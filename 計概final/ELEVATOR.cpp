#include <iostream>
#include <cmath>
using namespace std;
class Elevator{
public:
	Elevator();
	void add(int elevator,int people); //0 1 2 ���@�x�q�� �W�[�h�֤H 
	
	void minus(int elevator,int people); //0 1 2 ���@�x�q�� ��h�h�֤H
	
	void setusage(bool a,bool b,bool c);//a b c �ǤJ�q��O�_���b���� �Y���b�}���Nfalse
										//�C���n�I�s�@�� 
										
	int assign(int floor);//���@�ӼӼh�ݭn�A�� �^��0 1 2(���̪�or�ϥζq�̤֪��q��L�h)
	
	void waitTime(int elevator,int people);//0 1 2���@�x�q��n�X�J�h�֤H
	
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
	//�n�h�@�� ���ϥζq�̤֪� 
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
	//���O�n�h�@�� ���̪� 
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
		eleout[0][2]+=(eleout[0][0]+3)*1;//(���F�h�֤H+3)*���ʤ@�� 
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
	//�p�󵥩�2����2���ɶ� 
	if(time<=2){
		eleout[elevator][5]=2;
		return;
	}
	else{
		//�j��2�B���p�ƵL����i�� 
		if(((int)(time*10)%10)!=0){
			eleout[elevator][5]=(int)time+1;
			return;
		}
		//�j��2�B�L�p�� 
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
