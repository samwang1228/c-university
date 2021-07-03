#include<iostream>
using namespace std;
//判斷一個集合只出現過一次的數 此集合只會有一個數只有一個 其他皆會重複 且重複成對 
// xor a^a=0
//     a^0=a;
//     a^b=b^a;
// num[0]=*(num+0);
int singlenumber(int *num,int numsize)
{
    int n = num[0];
    for (int i = 1; i < numsize;i++)
    {
        n = n ^ num[i];
    }
    return n;
}
int main()
{
    int *set,size;
    cin >> size;
    set = new int[size];
    for (int i = 0; i < size;i++)
    {
        cin >> set[i];
    }
    cout << singlenumber(set,size);
}