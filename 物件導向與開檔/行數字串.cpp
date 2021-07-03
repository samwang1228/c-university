#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(){
    string filename;
    string file_string;
    cin >> filename;
    int n = 0;
    string **p;
    p = new string *[1];
    for (int i = 0; i < 1;i++)
    {
        p[i] = new string[80];
    }
    ifstream instream;
    filename += ".txt";
    instream.open(filename.c_str());
    while(getline(instream,file_string))
    {
        p[0][n] = file_string;
        n++;
    }
    int answer;
    while(cin>>answer)
    {
        if(answer<0)
            break;
        if(answer>n)
            break;
        cout << p[0][answer-1];
    }
       
      
}