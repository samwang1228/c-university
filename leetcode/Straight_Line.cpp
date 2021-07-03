#include<iostream>
#include<vector>
using namespace std;
// 題目:
// 檢查所給的點是否在同一條線 (斜率相等)
// Hint: 1.不要用除法因為分母可能為0 利用分配律轉換 
//       2.兩個int相除可能為float 但相乘不會 int 3/2=1/1
//       3.每個點為unique
 bool checkStraightLine(vector<vector<int>>& coordinates) {
      int dy=coordinates[1][1]-coordinates[0][1];
      int dx=coordinates[1][0]-coordinates[0][0];
        for(int i=1;i<coordinates.size()-1;i=i+2)
        { 
            int y=coordinates[i+1][1]-coordinates[i][1];
            int x=coordinates[i+1][0]-coordinates[i][0];
            if(dy*x!=y*dx)
            { 
                return false;
            }
        }
        return true;
    }