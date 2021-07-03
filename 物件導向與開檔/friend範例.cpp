#include<iostream>//兩個時間相加小時分秒 小時無限制
#include<cmath>
using namespace std;
class myTime
{
public:
myTime();
myTime(int hr,int mn,int sc);
int getHour(int x)
{
    return x;
}
int getMin(int x) 
{
    return x;
}
friend myTime operator+(const myTime &t1,const myTime &t2);
int getSec(int x) 
{
    return x;
}
friend myTime operator+(const myTime &t1, int sec);
friend myTime operator-(const myTime &t1,const myTime &t2) ;
friend ostream &operator<<(ostream &output, const myTime t2);
friend istream &operator>>(istream &input,  myTime &t2);
private:
int hour;
int min;
int sec;
};
myTime operator+(const myTime &t1,const myTime &t2)
{
    int total = (t1.hour + t2.hour )* 3600 + (t1.min + t2.min )* 60 + t1.sec + t2.sec;
    return myTime(total/3600, total/60%60, total%60);
}
myTime operator-(const myTime &t1,const myTime &t2)
{
    int total1 = t1.hour * 3600 + t1.min * 60 + t1.sec ;
    int total2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
    int total = abs(total1 - total2);
    return myTime(total/3600, total/60%60,total % 60);
}
myTime operator+(const myTime &t1,int sec)
{
    int total = t1.hour * 3600 + t1.min * 60 + t1.sec + sec;
    return myTime(total / 3600, total / 60 % 60,total % 60);
}
ostream &operator<<(ostream &output, const myTime t2)
{
    output << "hr:" << t2.hour << " min:"<<t2.min<<" sec:"<<t2.sec<<endl;
    return output;
}
istream &operator>>(istream &input, myTime &t2)
{
    int h, m, s;
    input >> h >> m >> s;
    /*t2.hour = t2.getHour(h);
    t2.min = t2.getMin(m);
    t2.sec = t2.getSec(s);*/
    t2 = myTime(h, m, s);
    return input;
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
int main()
{
    myTime time1(0, 0, 0), time2(0, 0, 0), time3;
    int a,h1, m1, s1, h2, m2, s2;
    while(cin>>a)
    {
        if(a==1)
        {
            cin >> time1 >> time2;
            cout << time1 << time2;
            //time1 = myTime(h1, m1, s1);
            //time2 = myTime(h2, m2, s2);
            time3 = time1 + time2;
            cout << time3;
        }
        if(a==2)
        {
            cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
            time1 = myTime(h1, m1, s1);
            time2 = myTime(h2, m2, s2);
            time3 = time1 - time2;
            cout << time3;
        }
        if(a==3)
        {
            cin >> h1 >> m1 >> s1;
            time1 = myTime(h1, m1, s1);
            time3 = time1 + s1;
            cout << time3;
        }
        if(a==0)
            break;
    }
}
/*myTime myTime::operator-(myTime t2)
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
}*/
/*int myTime::getHour() const{

return hour;

}

int myTime::getMin() const{

return min;

}

int myTime::getSec() const{

return sec;

}*/
/*void myTime::output(){
cout << "hr:" << hour << " min:"<<min<<" sec:"<<sec<<endl;
}*/
