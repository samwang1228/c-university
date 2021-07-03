#include<iostream>
#include<vector>
#include<string>
using namespace std;
    vector<int> findAnagrams(string s, string p) {
    int counts1['z' - 'a' + 1] = {0};
    int counts2['z' - 'a' + 1] = {0};
    int size1 = p.size();
    int size2 = s.size();
    vector<int> ans;
        if(size2==0||size1>size2)
            return ans;
    for (int i = 0; i < size1;i++)
    {
        counts1[p[i] - 'a']++;
    }
      for (int j = 0; j < size1;j++)
        {
            counts2[s[j]-'a']++;
        }
    for (int i = 0; i < size2-size1+1;i++)
    {
        bool test = true;
        for (char c = 'a'; c < 'z';c++)
        {
            if(counts2[c-'a']!=counts1[c-'a'])
            {
                test = false;
                break;
            }
        }
        if(test)
            ans.push_back(i);
        if(size1+i<size2)//把前一個減掉 並加上下一個 並當s2不爆掉時才執行
        {
            counts2[s[i] - 'a']--;
            counts2[s[size1+i] - 'a']++;
        }
    }
    return ans;
    }