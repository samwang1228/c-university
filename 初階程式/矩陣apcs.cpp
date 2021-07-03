#include<iostream>
using namespace std;
int x[10][10];
void mirror(int r,int c)
{
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < c; j++)
        {
            x[i][j] = x[r - i - 1][j];
        }
    }
}
void rotate(int r,int c)//順時針旋轉90度 想法是先畫出所有座標在考慮切記"邊長"是重點
{
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < c;j++)
        {
            x[j][i] = x[r - 1 - i][j];
        }
    }
}
int main()
{
    int r, c, m;
    int option[10];
    while (cin >> r >> c >> m)
    {
        for (int i = 0; i < r;i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> x[i][j];
            }
        }
        for (int i = 0; i < m;i++)
        {
            cin >> option[i];
            if(option[i]==0){
                rotate(r, c);
                int temp = r;
                r = c;
                c = temp;
            }
                else{
                    mirror(r, c);
                }
        }
      	 cout<< r << " " <<c;
        for (int i = 0; i < r;i++)
        {
            for (int j = 0; j < c;j++)
            {
                if (i == r-1&&j==c-1)
                {
                    cout << x[i][j]<<endl;
                    break;
                }
                    cout << x[i][j] << " ";
            }
            cout << endl;
        }
    }
}
