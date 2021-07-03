#include<iostream>
#include<cmath>
using namespace std;
class myDate 
{
	public://月日改1 時分秒改0
		myDate(const int y, const int m, const int d);
        int getYear() const { return year; }
        int getMonth() const {return month;}
        int getDay() const { return day; }
        bool isleap()const ;
        bool isleap2(int n) const;
        int getWeek(); //0~6 蔡勒公式
		bool setDate(const int y, const int m, const int d );
		void output(); //輸出 year-month-day (week)
	private:
		int year; 
		int month;
		int day;
		int week;
};
class myDateTime:public myDate
{
	public:
        myDateTime(const int y, const int m, const int d, const int h, const int min, const int s);
        int getHour()const {return hour;}
        int getMinute()const { return minute; }
        int getSecond()const { return second; }
        bool setDateTime(const int y, const int m, const int d, const int h, const int min, const int s);
        void output2(); //輸出 year-month-day (week) hour:minute:second
    private:
		int hour; 
		int minute;
		int second;
};
const myDateTime operator + ( const myDateTime & dt, const long long int s) //dt+s秒
{
    int day2 = s / 86400;
    int s_ =s% 86400;
    int day = dt.getDay();
    int year = dt.getYear();
    int month = dt.getMonth();
     int anss = dt.getSecond()+(s_ % 60);
    int ansmin = dt.getMinute()+(s_ / 60 % 60);
    int ansh = dt.getHour()+(s_/60 / 60 % 24);
    if(anss>=60)
    {
        anss %= 60;
        ansmin++;
    }
    if(ansmin>=60)
    {
        ansmin %= 60;
        ansh++;
    }
    if(ansh>24)
    {
        ansh %= 24;
        day++;
    }
    if(ansh==24)
    {
        ansh = 0;
        day++;
    }
    day = day + day2;
    while(day>28)
    {
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if(day>31)
            {
                day = day - 31;
                month++;
            }
            else 
                break;
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if(day>30)
            {
                day = day - 30;
                month++;
            }
            else 
                break;
        }
        else if(month==2)
        {
            if(dt.isleap2(year)==true)
            {
                if(day>29)
                {
                    day = day - 29;
                    month++;
                }
                else if(day==29)
                    break;
            }
            else
            {
               if(day>28)
                {
                    day = day - 28;
                    month++;
                } 
                else if(day==28)
                    break;
            }
        }
        if(month>12)
        {
            year++;
            month = 1;
        }
    }
    return myDateTime(year,month,day,ansh,ansmin,anss);
}
const myDateTime operator - ( const myDateTime & dt, const long long int s) //dt-s秒
{
    int day2 = (-s) / 86400;
    int s_ =(-s)% 86400;
    int day = dt.getDay();
    int year = dt.getYear();
    int month = dt.getMonth();
    int anss = dt.getSecond()-(s_ % 60);
    int ansmin = dt.getMinute()-(s_ / 60 % 60);
    int ansh = dt.getHour()-(s_/60 / 60 % 24);
    if(anss<0)
    {
        anss =60-abs(anss);
        ansmin--;
    }
    if(ansmin<0)
    {
        ansmin =60-abs(ansmin);
        --ansh;
    }
    if(ansh<0)
    {
        ansh =24-abs(ansh);
        --day;
    }
    if(ansh==24)
    {
        ansh = 0;
        day++;
    }
    day = day - day2;
    while (day <= 0)//天的運算
    {
        --month;
        if(month<1)
        {
            year--;
            month = 12;
        }
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            day += 31;
        else if(month==4||month==6||month==9||month==11)
            day += 30;
        else
        {
            if(dt.isleap2(year)==true)
            {
                day +=29;
            }
            else
            {
                day += 28;
            }
        }
    }
    
    return myDateTime(year,month,day,ansh,ansmin,anss);
}

int main()
{
    int year, month, day, hour , min , sec;
    long long int x;
    myDateTime ans(0,0,0,0,0,0);
    cin >> year >> month >> day >> hour >> min >> sec;
    ans = myDateTime(year, month, day,hour,min,sec);
    while (cin >> x) 
    {
        if(x==0)
            break;
        else if(x>0)
        {
            ans=ans + x;
            ans.output2();
        }
        else 
        {
            ans = ans - x;
            ans.output2();
        }
    }
}
    
int myDate::getWeek(){//星期公式
    int newyear,yearbefore,yearafter,newmonth,newday;
    int w;
    newyear=year;
    newmonth=month;
    newday=day;
    if(newmonth==1){
    newmonth=13;
    newyear=newyear-1;
    }
    if(newmonth==2){
    newmonth=14;
    newyear=newyear-1;
    }
    yearbefore=newyear/100;//前兩位
    yearafter=newyear%100;//後兩位
    w=yearafter+yearafter/4+yearbefore/4-2*yearbefore+26*(newmonth+1)/10+newday-1;
    if(w<0)
    {
    week=((w%7+7)%7);
    }
    else{
    week=(w%7);
    }
    return week;
}
myDate::myDate(const int y, const int m, const int d)
{
    setDate(y, m, d);
}
bool myDate::setDate(const int y,const int m,const int d )
{
    if(y<=0)
    {
        year = 1;
    }
    else if(m<1 || m>12)
        month = 1;
    else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<1||d>31))
        day = 1;
    else if((m==4||m==6||m==9||m==11)&&(d<1||d>30))
        day = 1;
    else if((m==2)&&(d<1||d>29)&&isleap()==true)
        day = 1;
    else if((m==2)&&(d<1||d>28)&&isleap()==false)
        day = 1;
    else
    {
        year = y;
        month = m;
        day = d;
    }
    return true;
}
void myDate::output()
{
    cout << year << "-" << month << "-" << day << " (" << getWeek() << ") ";
}
bool myDate::isleap() const
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
    {
        return true;
    }
    return false;
}
bool myDate::isleap2(int n)const
{
     if(((n%4==0)&&(n%100!=0))||(n%400==0))
    {
        return true;
    }
    return false;
}
bool myDateTime::setDateTime(const int y, const int m, const int d, const int h, const int min, const int s )
{
    setDate(y, m, d);
    if(h>24||h<0)
        hour = 0;
    else
        hour = h;
    if(min>60||min<0)
        minute = 0;
    else
        minute = min;
    if(s>60||s<0)
        second = 0;
    else
        second = s;
    return true;
}
myDateTime:: myDateTime(const int y, const int m, const int d, const int h, const int min, const int s):myDate (y,m,d),hour(h),minute(min),second(s)
{
    setDateTime(y, m, d, h, min, s);
}
void myDateTime::output2()
{
    output();
    cout << hour << ":" << minute << ":" <<second<<endl;
}