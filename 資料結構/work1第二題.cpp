#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<malloc.h>
using namespace std;
void swapv(char *&a,char *&b)
{
    char *temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x;//x為字串數量 y為字串長度
    cin >> x ;
    string s;
    char t;
    int max=0;
    int curr_adress;
    int temp_adress=5;
    int test_fir_space;
    int ans_adress[x];
    // p = new char*[x];
    // for (int i = 0; i < x;i++)
    //     p[i] = new char[temp_adress];
        char **p = (char **)malloc(x * sizeof(char *));//malloc
        for (int i = 0; i < x;i++)
        p[i] = (char *)malloc(temp_adress * sizeof(char));
        cin.get(t);
    for (int i = 0; i < x; i++)//find max size of string and adress of space
    {
        curr_adress=0;
        test_fir_space = 0;
        while (cin.get(t))
        {
            
            if(curr_adress>temp_adress-1) //expand size of pointer
                {
                    temp_adress = curr_adress+1;
                    p[i] = (char *)realloc(p[i],sizeof(char)*temp_adress );
                }
            if(t=='\n')
                break;
            if(t==' '&&test_fir_space==0&&curr_adress>max)//判斷要對齊的位置 且為第一次的空格
                {
                     test_fir_space++;
                    max = curr_adress;
                }
                p[i][curr_adress] = t;
                ++curr_adress;
        }
        ans_adress[i] = curr_adress;
    }
     int distance;
     for (int i = 0; i < x; i++)
     {
         for (int j = 0; j <= max; j++)
         {
             if (p[i][j] == ' ')
             {
                 distance = max - j;
                 break;
             }
         }
         for (int k = 0; k < distance; k++)
             cout << " ";
         for (int ans = 0; ans < ans_adress[i]; ans++)
             cout << p[i][ans];
         cout << endl;
    }
    //     for (int i = 0; i < x; i++)
    //         delete[] p[i];
    // delete[] p;

    for (int i = 0; i < x;i++) // release memory of malloc
        free(p[i]);
    free(p);
}
