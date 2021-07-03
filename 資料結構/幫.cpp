#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//獲得臨時變數的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//獲得臨時變數的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

int main()
{
//     string s;
//     ifstream in;
//     ofstream out;
//     in.open("in.txt");
//     out.open("out.txt");
//     getline(in,s);
//     wchar_t sBuf[25] = {0};
//     wchar_t scopy[25] = {0};
//     for (int i = 0; i < s.size();i++)
//     {
//         scopy[i] = s[i];
//     }
//     wcscpy(sBuf, scopy);
//     //獲取轉換所需的目標快取大小
//     DWORD dBufSize = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, NULL, 0, NULL, FALSE);
//     //分配目標快取
//     char *dBuf = new char[dBufSize];
//     memset(dBuf, 0, dBufSize);
//     //轉換
//     int nRet = WideCharToMultiByte(CP_OEMCP, 0, sBuf, -1, dBuf, dBufSize, NULL, FALSE);
//     if (nRet <= 0)
//     {
//         printf("轉換失敗\n");
// }
// else
// {
// printf("轉換成功\nAfter Convert: %s\n", dBuf);
// out<<dBuf;
// }
// delete []dBuf;
// double a = 0.5 / 12;
// double sol, y=0;
// int a1[5] = { 1, 4, 2, 4, 1 };
// double b[5] = { 0.0, 0.125, 0.25, 0.375, 0.5 };
// for (int i = 0;i<4;i++)
// {
//     sol = a1[i] * (1 / (1 + b[i] * b[i]));
//     y += sol;
// }
// y=y *a;
// cout << y;
int n;
cin >> n;
double weight=0.5/(3*n);
double counter=0;
double hight=0.5/n;
double sol=0;
int a=1;
double temp=0;
int count=0;
cout << a;
while (true)
{
    if (count==n)
        break;
    sol=a*(1/(1+counter*counter));
    temp=temp+sol;
    
    if (count%2==1)
        a=2;
    else
        a = 4;
    counter=counter+hight;
    count=count+1;
    //cout << a<<" ";
}
sol=(1/(1+0.5*0.5));
    temp=weight*(temp+sol);
    cout << temp<<endl;
}