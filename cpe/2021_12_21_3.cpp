#include <iostream>
#include <string>
using namespace std;
// 這題他媽的爛 IF有掉進洞過之後不能再掉一次 第一次掉直接BREAK 且COUT LOST
//NSEW 
//R N->S->E->W->N
//L W->E->S->N->W 
int main()
{
    int in1,in2,x,y,i,t;
    string act,f;
    
    cin>>in1>>in2;//輸入界線 
	int sc[in1+1][in2+1]={0};//判斷是否有標記 
    while(cin>>x>>y>>f>>act)//輸入動作 
    {
    	for(i=0;i<act.length();i++)
    	{
    		string a;
			a=act[i];
			int s=sc[x][y];
			
    		if((y<0||y>in2)||(x<0||x>in1))//死亡 
    		{
    			break;
			}
    		
    		if(a=="R")//向右轉 
    		{
    			if(f=="E")
    			{
					f="S";
    			}
				else if(f=="S")
				{
					f="W";
				}
				else if(f=="W")
				{
					f="N";
				}
				else if(f=="N")
				{
					f="E";
				}	
			}
			else if(a=="L")//向左轉 
    		{
    			if(f=="E")
    			{
					f="N";
    			}
				else if(f=="S")
				{
					f="E";
				}
				else if(f=="W")
				{
					f="S";
				}
				else if(f=="N")
				{
					f="W";
				}
			}
			else if(a=="F")//往前走 
    		{
    			if(f=="E"&&(s!=1||x+1<=in1))//有標記時不能去死 
    			{
					x+=1;
    			}
				else if(f=="S"&&(s!=1||y-1>0))
				{
					y-=1;
				}
				else if(f=="W"&&(s!=1||x-1>0))
				{
					x-=1;
				}
				else if(f=="N"&&(s!=1||y+1<=in2))
				{
					y+=1;
				}
			}
		}
		
		if(x<0)//死亡 
		{
			cout<<x+1<<" "<<y<<" "<<f<<" LOST"<<endl;
			sc[x+1][y]=1;
		}
		else if(y<0)
		{
			cout<<x<<" "<<y+1<<" "<<f<<" LOST"<<endl;
			sc[x][y+1]=1;
		}
		else if(x>in1)
		{
			cout<<x-1<<" "<<y<<" "<<f<<" LOST"<<endl;
			sc[x-1][y]=1;
		}
		else if(y>in2)
		{
			cout<<x<<" "<<y-1<<" "<<f<<" LOST"<<endl;
			sc[x][y-1]=1;
		}
		else//沒死 
		{
			cout<<x<<" "<<y<<" "<<f<<endl;
		}
    } 
    return 0;
}
