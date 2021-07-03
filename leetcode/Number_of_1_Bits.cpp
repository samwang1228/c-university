#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>
using namespace std;
// 題目:
// Input: n = 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
class Solution {
public:
    int hammingWeight(uint32_t n) {//type 為binary的變數
        int counter=0;
        while(n)//n>0
        {
            if((n&1)==1)//跟1做and同等於n%2==1
                counter++;
            n=n>>1;//往右位移
        }
        return counter;
    }
};
int main()
{
    //uint32_t n;
    //Solution b;
    double a=5;
    cout << a / 2;
    // cin >> n;
    // cout<<b.hammingWeight(n);
}