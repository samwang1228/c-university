#include<fstream>
using namespace std;
int main()
{
    ifstream instream;
    ofstream outstream;
    instream.open("1.in");
    outstream.open("1.out");
    char x;
    while(instream.get(x))
    {
        if(x=='\n')
        {
           break;
        }
        char t = x ^ 'a';
        outstream << t;
    }
    outstream << endl;
}