#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
using namespace std;
void test1()
{
    int a,b,c;
	cout<<"input a:";
	cin>>a;
	cin.ignore(1024, '\n');
	cout<<"input b:";
	cin>>b;
	cin.ignore(1024, '\n');
	cout<<"input c:";
	cin>>c;
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;//如果没有cin.ignore()，可以一次输入3个数，用空格隔开，但是不美观
}
void test_2()
{
    char buf[20];//20个空间输入19个字符，需要留下一个存放'\0',否则自动替换"
	cin.ignore(7);//忽略前七个字符 \n"
	cin.getline(buf,10);//将10个字符提取到buf中,因为第十位需要存放'\ 0',所以实际提取10位，能显示的是九位 \n"
	cout<<buf<<endl;
}
void test_3()
{
    char   str1[30],str2[30],str3[30];  
	cout   <<"your name:";  
	cin>>str1;  
	cout<<"your address:";  
	cin.ignore();  
	cin.getline(str2,30,'a');  
	cout<<"your country:";  
	cin.ignore();  
	cin.getline(str3,30);  
	cout<<str3;  //如果在地址那里输入bcdabcd那么此时流里面剩的是bcd\n,此时cin.ignore();吃掉的就是b了，这是流里还剩下cd\n直接交给cin.getline(str3,30);应为有个\n所以这里getline就直接返回 .

}
int main()
{
    //ignore()可以解決getline的換行問題
    // string s = "Hollo";
    // string s2;
    // istringstream ss(s);
    // while(getline(s,s2,'/'))
    // {

    // }
    // cout << s2;
    //test_3();
    vector<string>arr;                             //設一維陣列arr
    string input;                                      //字串input , token
    string token;
    int c=0;                                             //用來記錄放的陣列位置,每空白放一個,從arr[0]開始
    getline(cin,input);                             //使用者輸入 ex:how are you, 注意只有讀一行
    istringstream delim(input);               //將打好的東西放到字串delim裡,包含空白
    while(getline(delim,token,' '))           //getline(delim[來源位置],token[存入位置],'　'[分割的條件])
    {
        arr.push_back(token);                 //ex:  arr[0] = token ="how"
        c++;                                             //換arr[1]
    }
    for(int j=0;j<c;j++)                             //印出來
    {
        if(j!=c-1)                                        //印到字串最後前一個
            cout <<arr[j]<<' ';
        else
           cout << arr[j]<<endl;                //印最後一個字,換行,這是避免最後是空白,上傳資料會錯誤
    }
}

