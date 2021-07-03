#include<iostream>
#include<string>
#include<cstdlib>
#include<limits>
using namespace std;
//題目: 給定1~n 以及isBadVersion() 如果是壞的版本會回傳true else false 
//找出第一個壞的版本
//時間換取空間
// ex Given n = 5, and version = 4 is the first bad version.

// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true

// Then 4 is the first bad version. 
bool isBadVersion(int n)
{
    int number = rand() % INT_MAX+1;
    if(n>=number)
        return true;
    return false;
}
 int firstBadVersion(int n) { //暴力解
        int ans;
        if(isBadVersion(1)==true)
            return 1;
        else
        {
            for(int i=1;i<=n;++i)
        {
            if(isBadVersion(i)==false&&isBadVersion(i+1)==true)
            {
                ans=i+1;
            }
        }
        return ans;
        }
    }
    long long int binaryserach(long long int first, long long int last)
    {
        long long int mid = first + (last - first) / 2;  //因為後面==lenght 如果用mid=(first+last)/2 可能發生溢位
        if(isBadVersion(mid)==false&&isBadVersion(mid+1)==true)
            return mid + 1;
        else if(!isBadVersion(mid))
            return binaryserach(mid + 1, last);
        return binaryserach(first, mid - 1);
    }
    int secmention(int n)
    {
        long long int ans = binaryserach(1,(long long int)n);
        return ans;
    }
    int not_recusive(int n)
    {
        int first = 1, last = n+1;
        while(true)
        {
            int mid = first + (last - first) / 2;
            if(isBadVersion(n)&&!isBadVersion(n-1))
            {
                return mid;
            }
            else if(!isBadVersion(mid))
                first = mid + 1;
            else
                last = mid; //因為只到n
        }
        return 0;
    }