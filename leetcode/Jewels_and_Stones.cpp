#include<iostream>
#include<string>
using namespace std;
//題目: if J="Aa" s="Aaaab" return 4 if J="bb" s="sa" return 0
//時間換取空間
int numJewelsInStones(string J, string S) {
        int count=0;
        for(int i=0;i<J.size();i++)
        {
            for(int t=0;t<S.size();t++)
            {
                if(J[i]==S[t])
                {
                    count++;
                }
            }
        }
        return count;
    }
//空間換取時間
 int other(string J,string S)
 {
     int count[123] = {0}; //因為Z=122
     for (int i = 0; i < J.size();i++)//去得到J的字元
     {
         count[J[i]]++;
     }
     int answer = 0;
     for (int j = 0; j < S.size();j++)
     {
         if(count[S[j]]>0)//如果index=s[j] 不為0代表兩個都有
             answer++;
     }
     return answer;
 }