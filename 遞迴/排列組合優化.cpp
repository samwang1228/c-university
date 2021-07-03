#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void password(string ans,char*p,int index,int size,bool *test){ 
int i;
    if(index==size){
        for(i=0;i<size;i++)
        {
            cout << ans[i];
        }
        cout << endl;
        return ;
    }
    for(i=1;i<=size;i++){
        if(test[i]==false)
        {
            ans[index] = p[i-1];
            test[i] = true;
            password(ans, p, index + 1, size,test);
            test[i] = false;
        }
    }
}
int main( ) {
    string s;
    cin>>s;
    int size = s.size();
    char *p = new char[s.size()];  
    for (int i = 0; i < s.size();i++)
        p[i] = s[i];
    sort(p, p + s.size());
    bool test[s.size()]={false};
    password(s,p,0,s.size(),test);
    return 0;
}
