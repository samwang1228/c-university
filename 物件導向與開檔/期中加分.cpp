#include<iostream>//兩個時間相加小時分秒 小時無限制
#include<cmath>
using namespace std;
class myTime
{
public:
myTime();
myTime(int hr,int mn,int sc);
int getHour() const;
int getMin() const;
myTime operator+(myTime);
int getSec() const;
myTime operator+(int sec);
myTime operator-(myTime);
void output();
private:
int hour;
int min;
int sec;
};
/*const myTime operator+(const myTime &t1,const myTime &t2)
{
    int total = t1.getHour() * 3600 + t2.getHour() * 3600 + t1.getMin() * 60 + t2.getMin() * 60 + t1.getSec() + t2.getSec();
    int s = total % 60;
    int m = total / 60 % 60;
    int h = total / 3600;
    return myTime(h, m, s);
}*/
/*const myTime operator-(const myTime &t1,const myTime &t2)
{
    int total1 = t1.getHour() * 3600 + t1.getMin() * 60 + t1.getSec() ;
    int total2 = t2.getHour() * 3600 + t2.getMin() * 60 + t2.getSec();
    int total = abs(total1 - total2);
    int s = total % 60;
    int m = total / 60 % 60;
    int h = total / 3600;
    return myTime(h, m, s);
}*/
/*const myTime operator+(const myTime &t1,int sec)
{
    int total = t1.getHour() * 3600 + t1.getMin() * 60 + t1.getSec() + sec;
    int s = total % 60;
    int m = total / 60 % 60;
    int h = total / 3600;
    return myTime(h, m, s);
}*/
myTime myTime::operator-(myTime t2)
{
    int total1 = hour * 3600 + min * 60 + sec ;
    int total2 = t2.getHour() * 3600 + t2.getMin() * 60 + t2.getSec();
    int total = abs(total1 - total2);
    int s = total % 60;
    int m = total / 60 % 60;
    int h = total / 3600;
    return myTime(h, m, s);
}
myTime myTime::operator+(int x)
{
    int total = hour * 3600 + min * 60 + sec + x;
    int s = total % 60;
    int m = total / 60 % 60;
    int h = total / 3600;
    return myTime(h, m, s);
}
myTime myTime::operator+(myTime t2)
{
    int total = (hour + t2.getHour()) * 3600 + min * 60 + t2.getMin() * 60 + sec + t2.getSec();
    int h = total / 3600;
    int m = total / 60 % 60;
    int s = total % 60;
    myTime t3(h,m,s);
    return t3;
}

myTime::myTime(int hr,int mn,int sc){

hour = hr;

min = mn;

sec = sc;

}

myTime::myTime(){

hour = 0;

min = 0;

sec = 0;

}

int myTime::getHour() const{

return hour;

}

int myTime::getMin() const{

return min;

}

int myTime::getSec() const{

return sec;

}

void myTime::output(){
cout << "hr:" << hour << " min:"<<min<<" sec:"<<sec<<endl;
}
int main()
{
    myTime time1(0, 0, 0), time2(0, 0, 0), time3;
    int a,h1, m1, s1, h2, m2, s2;
    while(cin>>a)
    {
        if(a==1)
        {
            cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
            time1 = myTime(h1, m1, s1);
            time2 = myTime(h2, m2, s2);
            time3 = time1 + time2;
            time3.output();
        }
        if(a==2)
        {
            cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
            time1 = myTime(h1, m1, s1);
            time2 = myTime(h2, m2, s2);
            time3 = time1 - time2;
            time3.output();
        }
        if(a==3)
        {
            cin >> h1 >> m1 >> s1;
            time1 = myTime(h1, m1, s1);
            time3 = time1 + s1;
            time3.output();
        }
        if(a==0)
            break;
    }
}