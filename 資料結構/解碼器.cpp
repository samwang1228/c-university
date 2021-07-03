#include <iostream>
#include<string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
 string x;
 getline(cin,x);
 for(int i=0;i<x.size();i++)
 {
  if(x[i]==' ')
  cout<<27<<" ";
  else
  cout<<x[i]-'A'+1<<" ";
 }
 return 0;
}