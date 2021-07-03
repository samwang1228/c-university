#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
   vector<int> ans;
   int n;
   while(cin>>n)
   {
      int size = ans.size()-1;
      if(n==0)
      {
         sort(ans.begin(), ans.end());
         for (int i = 0; i <= size;i++)
            cout << ans[i]<<endl;
            break;
      }
      else if(n>0)
         ans.push_back(n);
      else
      {
         if(abs(n)>size)
            cout << "no" << endl;
         else
         {
         swap(ans[size], ans[abs(n)-1]);
         cout << ans[size] << endl;
         ans.pop_back();
         }
      }
   }
}