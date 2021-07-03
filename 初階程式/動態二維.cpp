#include<iostream>
using namespace std;
void change(int *p[],int n)//此為動態二維的buble sort
{
     for (int i = 0; i < 4;i++)
        {
            for (int j = 0; j < 5 - i - 1; j++)
            {
                if (p[n][j] > p[n][j + 1]){
                    int temp = p[n][j];
                    p[n][j] = p[n][j + 1];
                    p[n][j + 1] = temp;
                }
            }
        }
}
int main(){
    int n, **p, *ans,total=0,cost;
    cin >> n;
    cost = n * 50;
    int counter;
    p = new int *[n];//一維動態陣列使用
    ans = new int[5];//二為動態陣列使用
    for (int i = 0; i < n;i++)//切記是i<n 才能依序使用每個二維
        p[i] = new int[5];
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < 5;j++)
        {
            cin >> p[i][j];
        }
    }
    for (int t = 0; t < n; t++)
    {
        change(p, t);
    }
        for (int i = 0; i < 5; i++)
            cin >> ans[i];
            for (int i = 0; i < n; i++)
            {
                counter = 0;
                for (int j = 0; j < 5; j++)
                {
                    for (int t = 0; t < 5; t++)
                    {
                        if (p[i][j] == ans[t])
                        {
                            counter++;
                        }
                    }
                }
                switch (counter)
                {
                case 2:
                    total += 50;
                     cout<<50;
					 for (int j = 0; j < 5;j++)
                     cout << " " << p[i][j] ;
                     cout << endl;
                    break;
                case 3:
                    total += 300;
                     cout<<300;
					 for (int j = 0; j < 5;j++)
                     cout << " " << p[i][j] ;
                     cout << endl;
                    break;
                case 4:
                    total += 20000;
                    cout<<20000;
                      for (int j = 0; j < 5;j++)
                     cout << " " << p[i][j] ;
                      cout << endl;
                    break;
                case 5:
                    total += 8000000;
                    cout<<8000000;
                      for (int j = 0; j < 5;j++)
                     cout << " " << p[i][j] ;
                      cout << endl;
                    break;
                }
     }
     cout << total - cost << endl;
}

