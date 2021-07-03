#include<iostream>
using namespace std;
bool test[26] = {false};//一定要使用陣列 因為要對比當下的N[index]
void password(int *n,int index,int size){ //index代表要填哪一格
int i;
    if(index==size){//當達到最後輸出剛剛所限制的陣列元素
        for(i=0;i<size;i++)
            cout << n[i];
        cout << endl;
        return ;
    }
    for(i=1;i<=size;i++){
        if(test[i]==false)
        {
        n[index] = i;//儲存i值
        test[i] = true;//當存入此變數=true 因為不能重複
        password(n,index+1,size);//呼叫下一項 注意每呼叫下一項i會重新從1開始
        test[i] = false;//初始 且注意當遞迴返回時才會執行這裡index=4輸出後返回呼叫password(3)返回時會儲存當下的i test[3]=false
        }//故當時password(3)的i以來到3執行會直接終止for 所以再返回password(2) test[2]=false並之後i++=3存入N[2] test[3]=true 回到原點再次呼叫password(3)
    }
}
int main( ) {
    int size, *N;
    cin >> size;
    N = new int[size];
    password(N,0,size);
    return 0;
}