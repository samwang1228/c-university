#include<iostream>
#include<vector>
using namespace std;
// 題目:
// In a town, there are N people labelled(被貼上標籤) from 1 to N.  
// There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

// If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

// Example :

// Input: N = 2, trust = [[1,2]] 代表1相信2 且2不相信任何人 故為town judge
// Output: 2
// Example 2:

// Input: N = 3, trust = [[1,3],[2,3]]
// Output: 3
// Example 3:

// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1
// Example 4:

// Input: N = 3, trust = [[1,2],[2,3]]
// Output: -1
// Example 5:

// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
// Output: 3
 

// Constraints:

// 1 <= N <= 1000
// 0 <= trust.length <= 10^4
// trust[i].length == 2
// trust[i] are all different
// trust[i][0] != trust[i][1]
// 1 <= trust[i][0], trust[i][1] <= N

//時間換空間
int findJudge(int N, vector<vector<int>>& trust) {
    int believed_judge ;//計算相信i的人數
    bool test_judge;//檢驗i是否不相信任何人
    for (int i = 1; i <= N;i++)
    {
        believed_judge = 0;
        test_judge = true;
        for (int j = 0; j < trust.size();j++)
        {
            if(i==trust[j][1])
            {
                believed_judge++;
            }
            if(i==trust[j][0])
            {
                test_judge = false;
                break;
            }
        }
        if(test_judge==true&&believed_judge==N-1)
            return i;
    }
    return -1;
}

//空間換時間
int findJudge2(int N, vector<vector<int>>& trust) {
    int believed_judge[N];//計算相信i的人數
    int test_judge[N];//計算i相信幾個人
    for (int j = 0; j <N;j++)
    {
        believed_judge[j] = 0;
        test_judge[j] = 0;
    }
    int a,b;
    for (int i = 0; i < trust.size();i++)
    {
        //trust[i][0-1]=[a,b]
        a = trust[i][0]-1;
        test_judge[a]++;
        b = trust[i][1]-1;
        believed_judge[b]++;
    }
    
    for (int i = 1; i <= N;i++)
    {
        if(test_judge[i-1]==0&&believed_judge[i-1]==N-1)
            return i;
    }
    return -1;
}

//更省
//想法當被相信的人數=N-1&&相信的人數=0 也就相減==N-1時成立(0-(N-1))=N-1
int findJudge3(int N, vector<vector<int>>& trust) {
    int diff[N];
    for (int j = 0; j <N;j++)
    {
        diff[j] = 0;
    }
    int a,b;
    for (int i = 0; i < trust.size();i++)
    {
        //trust[i][0-1]=[a,b]
        a = trust[i][0]-1;
        diff[a]--;
        b = trust[i][1]-1;
        diff[b]++;
    }
    
    for (int i = 1; i <= N;i++)
    {
        if(diff[i-1]==N-1)
            return i;
    }
    return -1;
}