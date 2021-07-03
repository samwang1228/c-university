#include<iostream>
using namespace std;
int counter = 0;
bool binarySearch(int arr[], int L, int H, int x)
{
    if ( H < L )
        return false;
    else
    {
        int mid = L+( H - L ) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] > x)
        {
            counter++;
            return binarySearch(arr,L,H=mid-1,x);
        }
         else 
         {
             counter++;
             return binarySearch(arr, L = mid + 1, H, x);
         }
    }
}
int main()
{
    int size, n,*p;
    cin >> size;
    p = new int[size];
    for (int i = 0; i < size;i++)
    {
        cin >> p[i];
    }
    while(cin>>n)
    {
        counter = 0;
        if(n<0)
            break;
        if(binarySearch(p, 0, size, n))
            cout << "True"<<endl<<counter<<endl;
        else
            cout << "False"<<endl<<counter<<endl;
    }
}