// link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 題目:給定一個array這個array為股票的每日價格，此時要算出哪天買進與哪天賣出價產生的最高利益
// 注意一定要先買進後才能賣出若利益return 0
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
#include<iostream>
#include<string>
#include <sstream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
// TTL
class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int size=prices.size()-1;
        int counter=0;
        for(int i=size;i>=0;i--)
        {
            ++counter;
            for(int j=0;j<size-counter+1;j++)
            {
                if(prices[i]-prices[j]>max)
                    max=prices[i]-prices[j];
            }
        }
        return (max!=0)? max:0;
    }
};
// DP
class SolutionMID {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minValue=prices[0];
        int size=prices.size();
        for(int i=0;i<size;i++)
        {
            minValue=min(minValue,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minValue);
        }
        return (maxProfit!=0)? maxProfit:0;
    }
};
// 牛鬼蛇神
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string s; getline(cin, s); cout << '\n') {
        int ans = 0, mn = INT_MAX;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            mn = min(mn, v);
            ans = max(ans, v - mn);
        }
        cout << ans;
    }
    exit(0);
    return 0;
}();

class SolutionBest {
public:
    int maxProfit(vector<int>) { return 0; }
};