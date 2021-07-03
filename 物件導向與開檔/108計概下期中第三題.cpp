#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ifstream instream;
    ofstream outstream;
    string file_string;
    int x, y;
    instream.open("1.in");
    outstream.open("1.out");
    char **buffer;
    buffer = new char *[200];
    for (int i = 0; i < 200;i++)
    {
        buffer[i] = new char[100];
    }
        int n=0;
    while(getline(instream,file_string))
    {
        for (int i = 0; i < file_string.size();i++)
            buffer[n][i] = file_string[i];
        if(n==99)
            break;
        n++;
    }
    while(instream>>x>>y)
    {
        outstream << buffer[x - 1][y - 1] << endl;
    }
}