#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void alphaSort(char m[],string str,int start,int size);
void coutString(char m[],int size);
void copyString(char m[],string s);

int main(){
    char *m;
    string s,str="";
    s = "abcd";
    m = new char [s.size()];
    copyString(m,s);
    sort(m,m + s.size());
    alphaSort(m,str,0,s.size());
    delete [] m;
}

void alphaSort(char m[],string s,int start,int size){// size = m[] size
    if (start == size){ 
        cout << s << endl;
    }
    else{
        for (int i = 0 ; i < size ; i++){
        	if (s.size()==0){
        		alphaSort(m,s+m[i],start+1,size);
        	}
	        else{
			    for(int j = 0 ; j < s.size() ; j++){
	              if (m[i] == s[j])
	                break;
	              else if(j == s.size()-1 && m[i] != s[j] )
	                  alphaSort(m,s+m[i],start+1,size);
	            }
	        }
        }
    } 
}
void coutString(char m[],int size){
    for (int i=0;i<size;i++){
        cout << m[i];
    }
    cout << endl;
}
void copyString(char m[],string s){
    for (int i=0 ; i<s.size() ; i++){
        m[i] = s[i];
    }
}
