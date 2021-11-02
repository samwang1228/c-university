#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int *p = new int[5];
    int *q = new int[5];
    for (int i = 0; i < 5;i++)
    {
        p[i] = i;
        q[i] = 2 * i;
    }
    swap(p, q);
    for (int j = 0; j < 5;j++)
    {
        cout <<"p: "<< p[j]<<" q: "<<q[j]<<endl;
    }
}
//     #include<iostream>
// //#include<stdio.h>
// #include<cstring>
// #include<malloc.h>
// using namespace std;
// void swapv(char *&a,char *&b)
// {
//     char *temp = a;
//     a = b;
//     b = temp;
// }
// int main()
// {
//     int x,y,temp=0;//x為字串數量 y為字串長度
//     char* s;
//     cin >> x >> y;
//     char **p;
//     s = new char[y];
//     p = new char*[x];
//     for (int i = 0; i < x;i++)
//         p[i] = new char[y];
//     // char **p = (char **)malloc(x * sizeof(char *));//malloc
//     // for (int i = 0; i < x;i++)
//         // p[i] = (char *)malloc(y * sizeof(char));
//     cin.get(s[temp]);//為了不要讀到換行
//         for (int i = 0; i < x; i++)
//         {
//             temp = 0;
//             while (true)//考慮Input不符合的情況
//             {
//                 cin.get(s[temp]);
//                   ++temp;
//                 if(s[temp-1]=='\n')
//                 {
//                 if(temp-1>y)
//                 {
//                     cout << "Please input again"<<endl;
//                     temp = 0;
//                 }
//                 else if(temp-1<y-1)
//                 {
//                     for (int k = temp; k < y;k++)
//                     {
//                         s[k] = ' ';
//                     }
//                     goto start;
//                 }
//                 if (temp-1==y-1)
//                     break;
//                 }
//                 if(strlen(s)==y)
//                 {
//                     int exsize = temp * 2;
//                     s = (char*)realloc(s, sizeof(char) * exsize);
//                 }
              
//             }
//         start:
//         for (int j = 0; j < y; j++)//符合的字串則存取
//         {
//             p[i][j] = s[j];
//         }
//     }
//     for (int i = 0; i < x-1; i++)//執行bubble sort
//     {
//         for (int j = 0; j < x -1-i;j++)
//         {
//             if(p[j][0]>p[j+1][0])
//             {
//                 swapv(p[j], p[j + 1]);
//             }
//         }
//     }
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = 0; j < y; j++)
//         {
//             cout << p[i][j];
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < x;i++)
//         delete [] p[i];
//     delete[] p;

//     // for (int i = 0; i < x;i++) // release memory of malloc
//     //     free(p[i]);
//     // free(p);
// }

