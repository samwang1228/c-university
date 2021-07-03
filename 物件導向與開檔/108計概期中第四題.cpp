#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char x;
    int mom = 0;
    int total = 0;
    ifstream instream;
    ofstream outstream;
    instream.open("1.in");
    outstream.open("1.out");
    while(instream.get(x))
    {
        if(x=='\n')
        {
            break;
        }
        for (int i = 97; i <= 122;i++)
        {
            if(i==x)
            {
                total++;
                break;
            }
        }
        for (int j = 65; j <= 90;j++)
        {
            if(j==x)
            {
                total++;
                break;
            }
        }
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            {
                mom++;
            }
    }
    outstream << mom << endl << total-mom << endl;
    instream.close();
    outstream.close();
    return 0;
}