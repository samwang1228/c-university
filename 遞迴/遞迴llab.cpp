#include<iostream>
#include<string>
using namespace std;
bool test[100] = {false};
void password(int *n,int index,int size,char p){ 
int i;
    if(index==size){
        for(i=0;i<size;i++)
        {
            for (int j = 0; j <= size; j++)
            {
                if(n[i]==j)
                {
                    cout << char(p+j-1);
                    break;
                }
            }
        }
        cout << endl;
        return ;
    }
    for(i=1;i<=size;i++){
        if(test[i]==false)
        {
        n[index] = i;
        test[i] = true;
        password(n,index+1,size,p);
        test[i] = false;
        }
    }
}
int main( ) {
    int *N;
    string s;
    cin >> s;
    char min = s[0];
    for (int i = 0; i < s.size();i++)
    {
        if(s[i]<=min)
            min = s[i];
    }
    N = new int[s.size()];
    password(N,0,s.size(),min);
    return 0;
}