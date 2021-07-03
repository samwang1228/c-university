#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    ifstream instream;
    ofstream outstream;
    instream.open("1.in.txt");
    outstream.open("1.out.txt");
    string s;
    int n=0;
    int i = 0;
    int total=0;
    while(instream>>s)//判斷行數
    {
        n++;
        total += s.size();//把每行長度加總
    }
    total = total / n;//平均
    char **p;
    p = new char *[n];//利用此行數配置記憶體空間
    for (int j = 0; j < n; j++)
    {
        p[j] = new char[200];//最大長度200
    }
    instream.close();
    instream.open("1.in.txt");//再次重頭讀取
    while (instream>>s)
    {
        for (int j = 0; j < s.size();j++)
            p[i][j] = s[j];//存取
         if (s.size() >= total)//判斷
            outstream << p[i][0];
        i++;
    }
}