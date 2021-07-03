#include <iostream>
#include <string.h> 
#include <algorithm>
using namespace std;
int main(){
    string str1;
    cin>>str1;
    int len=str1.length();
    int b[len];
    for(int i=0;i<len;i++){
        b[i] = (int)str1[i];
    }
    sort(b,b+len);
    do{
        for(int i = 0;i<len;i++){
            str1[i] = (char)b[i];
            cout<<str1[i];
        }
        cout<<endl;
    }while (next_permutation(b,b+len) );//前面為陣列名字 後面是此陣列你想要排到哪
}