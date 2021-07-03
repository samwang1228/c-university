#include <iostream>
#include <fstream> 
#include <math.h>
using namespace std;
class myDateTime{
public:
 //合理有效時間 就存進去 回傳true 
 //24小時制 
 bool setTime(const int hour,const int min,const int sec);
 bool setDate(const int year,const int month,const int day);
 void tosetTime(int h,int m,int s);
 void tosetDate(int y,int m,int d);
 //輸出1~7
 int whatDate();
 //(12小時制)yyyy-mm-dd
 void output(); 
 //(中文形式)★沒有空白!!!!!!!!!!!!!!!!!!!!! 
 void outputROC();
  
 //設定ㄉ那天已經過了幾秒 (hour*3600+minute*60+second)
 int seconds();
 //是不是閏年 
 bool isLeap(); 
private:
 int year,month,day,hour,min,sec;
};
//★空格 中英文 幾格的數字要填滿  
//不斷輸入 請輸出兩個output+是否閏年+星期幾+換行+該天過了幾秒
//0 0 0 0 0 0結束 
int main(){
 int yearvalue,monthvalue,dayvalue,hourvalue,minvalue,secvalue;
 
 while(cin>>yearvalue>>monthvalue>>dayvalue>>hourvalue>>minvalue>>secvalue){
  
  if(yearvalue==0 && monthvalue==0 && dayvalue==0 && hourvalue==0 && minvalue==0 && secvalue==0){
   break;
  }
  
  myDateTime dateTest;
  int week=0;
  int totalsec=0;
  if(dateTest.setDate(yearvalue,monthvalue,dayvalue) && dateTest.setTime(hourvalue,minvalue,secvalue)){
   dateTest.tosetTime(hourvalue,minvalue,secvalue);
   dateTest.tosetDate(yearvalue,monthvalue,dayvalue);
      week=dateTest.whatDate();
      totalsec=dateTest.seconds();
      //開始輸出囉
   dateTest.output();
   dateTest.outputROC(); 
   if(dateTest.isLeap()){
    cout<<"1";
   }
   else{
    cout<<"0";
   }
   switch(week){
    case 1:
     cout<<"Monday"<<endl;
     break;
    case 2:
     cout<<"Tuesday"<<endl;
     break;
    case 3:
     cout<<"Wednesday"<<endl;
     break;
    case 4:
     cout<<"Thursday"<<endl;
     break;
    case 5:
     cout<<"Friday"<<endl;
     break;
    case 6:
     cout<<"Saturday"<<endl;
     break;
    case 0:
     cout<<"Sunday"<<endl;
     break;
    default:
     break;
   }
   cout<<totalsec<<endl;    
  }
 /**/ 
 }
} 
bool myDateTime::setTime(const int hour,const int min,const int sec){
 if((hour<=24 || hour>=1) && (min<=59 || min>=1) && (sec<=59 || sec>=1)){
  return true;
 }
 else{
  return false;
 }
 
}
bool myDateTime::setDate(const int year,const int month,const int day){
 if(year>=1911 && (month<=12 || month>=1) && (day<=31 || day>=1)){
  if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
   if(day<=31 && day>=1){
    return true;
   }
   else{
    return false;
   } 
  }
  if(month==4 || month==6 || month==9 || month==11){
   if(day<=30 && day>=1){
    return true;
   }
   else{
    return false;
   }
  }
  if(month==2){
   if(year%4==0 && year%100!=0){
    if(day<=29 && day>=1){
     return true;
    }
    else{
     return false;
    }
   }
   else{
    if(day<=28 && day>=1){
     return true;
    } 
    else{
     return false;
    }
    
   }
  }
   
 }
 else{
  return false;
 }
}
void myDateTime::tosetTime(int h,int m,int s){
 hour=h;
 min=m;
 sec=s;
}
void myDateTime::tosetDate(int y,int m,int d){
 year=y;
 month=m;
 day=d;
}
//輸出1~7
int myDateTime::whatDate(){
 int year_,yearbefore,yearafter,month_,day_;
 int w,week;
 //從private輸入 
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
 yearbefore=year_/100;
 yearafter=year_%100;
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
//(12小時制)yyyy-mm-dd
void myDateTime::output(){
 cout<<year<<"-";
 if(month<=9){
  cout<<"0"<<month;
 }
 else{
  cout<<month;
 }
 cout<<"-";
 if(day<=9){
  cout<<"0"<<day;
 }
 else{
  cout<<day;
 }
 cout<<" ";
 if(hour<=11 && hour>=1){
  if(hour<=9){
   cout<<"0"<<hour;
  }
  else{
   cout<<hour;
  }
 }
 else if(hour>=12 && hour<=23){
  if(hour==12){
   cout<<hour;
  }
  else{
   if(hour-12<=9){
    cout<<"0"<<hour-12;
   }
   else{
    cout<<hour-12;
   }
  }
 }
 else{
  ;
 }
 cout<<":";
 if(min<=9){
  cout<<"0"<<min;
 }
 else{
  cout<<min;
 }
 cout<<":";
 if(sec<=9){
  cout<<"0"<<sec;
 }
 else{
  cout<<sec;
 }
 if(hour>=12){
  cout<<" pm";
 }
 else{
  cout<<" am";
 }
 cout<<endl;
} 
//(中文形式)★沒有空白!!!!!!!!!!!!!!!!!!!!! 
void myDateTime::outputROC(){
 if(hour>=12 && hour<=23){
  if(hour==12){
   cout<<"中華民國"<<year-1911<<"年";
   if(month<=9){
    cout<<"0"<<month<<"月";
   }
   else{
    cout<<month<<"月";
   }
   if(day<=9){
    cout<<"0"<<day<<"日下午";
   }
   else{
    cout<<day<<"日下午";
   }
   cout<<hour<<"點";
   if(min<=9){
    cout<<"0"<<min<<"分"; 
   } 
   else{
    cout<<min<<"分";
   }
   if(sec<=9){
    cout<<"0"<<sec<<"秒"<<endl;
   }
   else{
    cout<<sec<<"秒"<<endl;
   }
  }
  else{
   cout<<"中華民國"<<year-1911<<"年";
   if(month<=9){
    cout<<"0"<<month<<"月";
   }
   else{
    cout<<month<<"月";
   }
   if(day<=9){
    cout<<"0"<<day<<"日下午";
   }
   else{
    cout<<day<<"日下午";
   }
   if(hour-12<=9){
    cout<<"0"<<hour-12<<"點"; 
   } 
   else{
    cout<<hour-12<<"點";
   }
   if(min<=9){
    cout<<"0"<<min<<"分"; 
   } 
   else{
    cout<<min<<"分";
   }
   if(sec<=9){
    cout<<"0"<<sec<<"秒"<<endl;
   }
   else{
    cout<<sec<<"秒"<<endl;
   }  
  }
 }  
 if(hour>=1 && hour<=11){
  cout<<"中華民國"<<year-1911<<"年";
  cout.precision(2);
  if(month<=9){
    cout<<"0"<<month<<"月";
   }
   else{
    cout<<month<<"月";
   }
   if(day<=9){
    cout<<"0"<<day<<"日上午"; 
   }
   else{
    cout<<day<<"日上午";
   }
   if(hour<=9){
    cout<<"0"<<hour<<"點";
   } 
   else{
    cout<<hour<<"點"; 
   }
   if(min<=9){
    cout<<"0"<<min<<"分"; 
   } 
   else{
    cout<<min<<"分";
   }
   if(sec<=9){
    cout<<"0"<<sec<<"秒"<<endl;
   }
   else{
    cout<<sec<<"秒"<<endl;
   }  
 }
 
} 
//設定ㄉ那天已經過了幾秒 (hour*3600+minute*60+second)
int myDateTime::seconds(){
 int SEC=hour*3600+min*60+sec;
 return SEC;
}
//是不是閏年 
bool myDateTime::isLeap(){
 if(( (year%4==0) && (year%100!=0) )|| (year%400==0)){
  return true;
 }
 else{
  return false;
 }
}