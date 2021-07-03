#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class powerdata
{
    public:
        powerdata(int y, int m, int d);
        bool isleap();
        int getweek();
        bool set(const int y, const int m, const int d);
        friend ostream &operator<<(ostream &output, powerdata &t2);
        friend istream &operator>>(istream &input, powerdata &t2);
        powerdata operator[](int x);
    private:
        int year, month, day,week;
};
powerdata::powerdata(int y,int m,int d)
{
    set(y, m, d);
}
bool powerdata::set(const int y,const int m,const int d )
{
    if(y<=0)
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    else if(m<1 || m>12)
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<1||d>31))
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    else if((m==4||m==6||m==9||m==11)&&(d<1||d>30))
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    else if((m==2)&&(d<1||d>29))
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    
    else
    {
        year = y;
        month = m;
        day = d;
    }
    return true;
}
int powerdata::getweek(){//星期公式
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
bool powerdata::isleap()
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
    {
        return true;
    }
    return false;
}
istream &operator>>(istream &input, powerdata &t2)
{
    int y, m, d;
    input >> y >> m >> d;
    t2 = powerdata(y, m, d);
    return input;
}   
ostream &operator<<(ostream &output, powerdata &t2)
{
    output<<"現在日期: "<<t2.year <<"-"<<setw(2) << setfill('0') << t2.month <<"-"<< setw(2) << setfill('0') << t2.day;
    if(t2.isleap())
    {
        cout << "L"<<" ";
    }
    else
        cout << "l"<<" ";
    switch (t2.getweek())          //轉換成英文
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 0:
        cout << "Sunday" << endl;
        break;
        }
    return output;
}
powerdata powerdata::operator[](int n)
{
    day = day + n;
    while(day<=0)
    {
        month--;
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
            if(isleap()==true)
            {
                day +=29;
            }
            else
            {
                day += 28;
            }
        }
    }
    while(day>28)
    {
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if(day>31)
            {
                day = day - 31;
                month++;
            }
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if(day>30)
            {
                day = day - 30;
                month++;
            }
        }
        else
        {
            if(isleap()==true)
            {
                if(day>29)
                {
                    day = day - 29;
                    month++;
                }
            }
            else
            {
               if(day>28)
                {
                    day = day - 28;
                    month++;
                } 
            }
        }
        if(month>12)
        {
            year++;
            month = 1;
        }
    }
    return powerdata(year,month,day);
}
int main()
{
    int type;
    while(cin>>type)
    {
        if(type==0)
        {
            break;
        }
        if(type==1)
        {
            powerdata d1(1900, 1, 1);
            cin >> d1;
            cout << d1;
        }
        if(type==2)
        {
            powerdata d1(1900, 1, 1);
            int n;
            cin >> d1;
            cin >> n;
            d1[n];
            cout << d1;
        }
    }
}