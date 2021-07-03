#include<iostream>
using namespace std;
int main()
{
    int *p, *q;
    q = new int;
    p = new int;
    *p = 7;
    *q = 5;
    cout << *p << " " << *q<<endl;//7 5
    *p = *q;
    cout << *p << " " << *q<<endl;//5 5
    p = new int;
    *p = 9;
     cout << *p << " " << *q<<endl;//9 5
      int array[10]={0,1,2,3,4,5,6,7,8,9};
    int *ptr;
    int value;
    ptr = &array[0];
    cout << ptr << " ";//[0]
    value = *ptr;
    cout << value << " ";//0
    cout << ptr++ << " ";//[0]
    cout << ++ptr << " ";//[2]
    value = *ptr;
    cout << value << " ";//2
    ++(*ptr);
    value = *ptr;
    cout << value << " " << ptr;//3 [2]
    /*int *p,*q,t=5;
    p = new int[t];
    q = new int[t];
    for (int i = 0; i < t;i++)
    {
        p[i] = i;
        q[i] = i*i;
    }
    cout << p[0] + 1<<" "<<p[3]-q[2]<<endl;//p[1]的值 p[3]的值-q[2]的值
    cout << &p[0] <<" "<<&p[0] + 1;//p[0]的位置 p[1]的位置*/
}