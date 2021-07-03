#include<iostream>
#include<cmath>
#include <iomanip>//使用stew()與setfill()
#include<string>
using namespace std;
class Dayofyear
{
    public://member function 裡的parmater只會在該區域裡生效意思是取相同名字不影響
        bool settime(const int hour, const int minute, const int sec);//判斷格式 hour minute sec
        bool setdata(const int year, const int month, const int day);//判斷格式 year month day
        int whatdata();//判斷星期幾
        void input_1(int h,int m,int s);//格式對就存到private的變數裡
        void input_2(int y, int m, int d);//格式對就存到private的變數裡
        void output();
        void outputroc();
        int second();//總total second
        bool isleap();//判斷是否為閏年
    private:
        int year, month, day, hour, min, sec;//此變數只能在member function 裡使用
};
int main(){
    Dayofyear answer;
    int c,yearvalue,monthvalue,dayvalue,hourvalue,minvalue,secvalue;
    bool test_1, test_2;
    while(cin>>yearvalue>>monthvalue>>dayvalue>>hourvalue>>minvalue>>secvalue)
    {
        if(yearvalue==0&&monthvalue==0&&dayvalue==0&&hourvalue==0&&minvalue==0&&secvalue==0)
            break;
        test_1=answer.settime( hourvalue,  minvalue,  secvalue);
        test_2 = answer.setdata( yearvalue,  monthvalue,  dayvalue);
        if(test_1&&test_2)//如果格是正確則開始以下運算
        {
            answer.input_1(hourvalue,minvalue,secvalue);//存取
            answer.input_2(yearvalue, monthvalue, dayvalue);//存取
            answer.output();//輸出西元
            answer.outputroc();//輸出民國
            cout << answer.isleap();//是否閏年
            c = answer.whatdata();//星期幾
            switch (c)//轉換成英文
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
        cout<<answer.second()<<endl;
        }
    }
}
void Dayofyear::input_1(int h,int m,int s)//交換
{
    hour = h;
    min = m;
    sec = s;
}
void Dayofyear::input_2(int y,int m,int d)//交換
{
    year = y;
    month = m;
    day = d;
}
void Dayofyear::output()
{
    int newhour=hour;//為了不要改到private的值
	if(hour>12)
    {
    newhour-=12;//setw(x) x為你要的位置ex 20等於兩個位置 setfill(y) y則是你要補的東西 ex 2為一個位置所以會自動補0
    cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " << setw(2) << setfill('0') <<newhour << ":" << setw(2) << setfill('0') << min << ":"<< setw(2) << setfill('0') << sec<<" pm"<<endl;
	}
	else if(hour<12)
    cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":"<< setw(2) << setfill('0') << sec<<" am"<<endl;
	else if(hour==12)
    cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":"<< setw(2) << setfill('0') << sec<<" pm"<<endl;
}
int Dayofyear::second()
{
    int totalsecond;
    totalsecond = hour * 3600 +  min * 60 + sec;
    return totalsecond;
}
int Dayofyear::whatdata(){//星期公式
 int year_,yearbefore,yearafter,month_,day_;
 int w,week;
 year_=year;
 month_=month;
 day_=day;
 if(month_==1){
  month_=13;
  year_=year_-1;
 }
 if(month_==2){
  month_=14;
  year_=year_-1;
 }
 yearbefore=year_/100;//前兩位
 yearafter=year_%100;//後兩位
 w=(int)(yearafter+floor(yearafter/4)+floor(yearbefore/4)-2*yearbefore+floor(26*(month_+1)/10)+day_-1);
 if(w<0)
 {
  week=((w%7+7)%7);
 }
 else{
  week=(w%7);
 }
 return week;
}
    
bool Dayofyear::isleap()
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
    {
        return true;
    }
    return false;
}
void Dayofyear::outputroc()
{
    int newyear = year;
    int newhour=hour;
    newyear -= 1911;
    if(hour>12)
    {
	newhour-=12;
    cout <<"中華民國"<<setw(3)<<setfill('0')<< newyear << "年" << setw(2) << setfill('0') << month << "月" << setw(2) << setfill('0') << day << "日"<<"下午" << setw(2) << setfill('0') << newhour << "點" << setw(2) << setfill('0') << min << "分"<< setw(2) << setfill('0') << sec<<"秒"<<endl;
	}
	else if(hour<12)  
    cout <<"中華民國"<<setw(3)<<setfill('0')<< newyear << "年" << setw(2) << setfill('0') << month << "月" << setw(2) << setfill('0') << day << "日"<<"上午" << setw(2) << setfill('0') << hour << "點" << setw(2) << setfill('0') << min << "分"<< setw(2) << setfill('0') << sec<<"秒"<<endl;
	if(hour==12)
    cout <<"中華民國"<<setw(3)<<setfill('0')<< newyear << "年" << setw(2) << setfill('0') << month << "月" << setw(2) << setfill('0') << day << "日" <<"下午"<< setw(2) << setfill('0') << hour << "點" << setw(2) << setfill('0') << min << "分"<< setw(2) << setfill('0') << sec<<"秒"<<endl; 
}
bool Dayofyear::settime(const int hour, const int min, const int sec)
{
    if(hour>=24||min>=60||sec>=60)
        return false;
    else
        return true;
}
bool Dayofyear::setdata(const int year, const int month, const int day)
{
    if(month>=13)
        return false;//月份只到12
    else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>=32))
        return false;//只到31天
    else if((month==4||month==6||month==9||month==11)&&(day>=31))
        return false;//只到30天
    else if(month==2)//二月單獨討論
    {
        int test = isleap();//判斷是否閏年
        if(test&&day>29)
            return false;
        else if(test==false&&day>28)
            return false;
    }
    return true;
        
}