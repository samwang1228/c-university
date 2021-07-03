#include<iostream>
#include<cmath>
using namespace std;
//題目:
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Constraints:

// The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
// num >= 1
// You could assume no leading zero bit in the integer’s binary representation.

// ex
// 0000 0000 0011
// 1111 1111 1111 mask =~0 (not 0)
//--------------- AND
// 0000 0000 0011 
// new mask     1111 1111 0110
// result mask  1111 1111 1100
// not mask     0000 0000 0011 that is you want   
 int findComplement(int num) {
    unsigned int mask=~0;
    while((num&mask)!=0){
     mask<<=1;
    }  
    return num^~mask;   
}


// 00000000 00000000 00000|101 origin
// 00000000 00000000 00000|111 mask
// ----------------------------XOR 跟1做=complement
// 00000000 00000000 00000|010 ans 
// 想法會把原數的第一個1每次右移作or因此new mask會一直出現1
// 最後result mask =  00000000 00000000 00000|111
int flip(int num)
{
    int mask=num;
    for(int i=1;i<=30;i++)
    { 
        mask|=mask>>1;
    }
    return mask^num; 
}

//每次or會新增2倍個1
int complement(int num)
{
    int mask=num;
    mask|=mask>>1;
    mask|=mask>>2;
    mask|=mask>>4;
    mask|=mask>>8;
    mask|=mask>>16;
    return mask^num;
}
    int main()
    {
        int t,p;
        cin>>t;
        //0000 0000 1111         0000 0000 1000
        //0000 0000 0001         0000 0000 0001
        //--------------------------------------AND
        //0000 0000 0001 >>odd   0000 0000 0000 >>even 這種方法更快
        if((t&1)== 0)
            cout<<"This number is even";
        else 
           cout<<"This number is odd";
         //cout<<flip(t);
        p=t<<1; //左移 同等於 *2 且速度更快
        cout<<p;
    }