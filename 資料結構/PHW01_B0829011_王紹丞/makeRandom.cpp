#include<cstdlib>
#include<fstream>
#include<ctime>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    //cout<<"Please input number of size: ";
    ofstream input;
    stringstream ss;
    //ofstream output;
    input.open("input.txt");
    srand(time(0));
    // int num;
    for (int i = 0; i < 1000;i++)
    {
        int temp=(long long)(( double)(rand()*49999)/RAND_MAX)+1;
        input << temp<<" ";
    }

}