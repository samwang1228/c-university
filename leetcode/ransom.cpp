#include<iostream>
using namespace std;
// 題目:
// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
//注意 已經出現過得要delete 且無順序 ex ransinNote=abc magazing=cba true 

//暴力解
bool canConstruct(string ransomNote, string magazine) {
    bool test;
        for(int i=0;i<ransomNote.size();i++)
        { 
            test=false;
            //第三種 if rancount>magcount false  else true
            // int rancount=0; //ransomNote[i]在ransomnote的次數
            // for(int j=0;j<ransomNote.size();j++)
            // {
            //     if (ransomNote[i]==ransomNote[j])
            //     rancount++;
            // }
            // int magcount=0; //ransomNote[i]在magazing的次數
            // for(int j=0;j<magazine.size();j++)
            // {
            //     if (ransomNote[i]==magazine[j])
            //     {
            //         magcount++;
            //     }
            // }
            for(int j=0;j<magazine.size();j++)
            { 
                if (ransomNote[i]==magazine[j])
                {
                    //第一個方法 取代製沒在範圍的char
                    test=true;
                    magazine[j]='-';
                    // 第二種 swap 但上面要int j=i
                    // char temp=magazine[j];
                    // magazine[j]=magazine[i];
                    // magazine[i]=temp;
                    break;
                }
            }
            if (!test)
                return false;
        }
        return true;
    }
//空間換時間
//abgda
//cgbhjaa
bool canConstruct2(string ransomNote, string magazine) {
   int diffcount[26]={0}; //a~z
   for(int i=0;i<ransomNote.size();i++)
   {
       diffcount[ransomNote[i]-'a']++;
   }
   for(int j=0;j<magazine.size();j++)
   {
       diffcount[magazine[j]-'a']--;
   }
   for(int t=0;t<ransomNote.size();t++)
   {
       if(diffcount[ransomNote[t]-'a']>0)
       return false;
   }
   return true;
}             
//時間換空間
//利用qsort 在一個個比對      