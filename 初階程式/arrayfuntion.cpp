#include<iostream>
using namespace std;
void input(int a[],int size)
{
    for (int i = 0; i < size;i++)
    {
        cin >> a[i];
    }
}
void swap(int a[],int size)
{
    for (int i = 0; i < size-1;i++)
    {
        for (int j = 0; j < size-1-i;j++)
        {
            if(a[j]>=a[j+1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
void output(int a[],int size)
{
    cout << a[0];
    for (int i = 1; i < size;i++)
    {
        cout<< " "<<a[i];
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    input(a, n);
    swap(a, n);
    output(a, n);
}