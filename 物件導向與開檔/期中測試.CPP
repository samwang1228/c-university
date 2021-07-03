#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    ifstream file;
    string filename,file_string;
    int length,i=0,n=0;
    cin >> filename>>length;
    char assign_string[80][length];
    filename += ".txt";
    file.open(filename);
    string file_max, file_min;
    int max, min;
    while(getline(file,file_string))
    {
        if(n==0)
        {
         max= file_string.size();
         min = file_string.size();
         file_max = file_string;
         file_min = file_string;
        }
        if(file_string.size()>max)
        {
            file_max = file_string;
            max = file_string.size();
        }
            if (file_string.size() < min)
            {    
                file_min = file_string;
                min = file_string.size();
            }
                if (file_string.size() == length)
                {
                    for (int j = 0; j < length; j++)
                    {
                        assign_string[i][j] = file_string[j];
                    }
                    i++;
        }
        n++;
    }
    cout << n << endl<< file_max << endl
         << file_min << endl;
    for (int t = 0; t < i;t++)
    {
        for (int j = 0; j < length;j++)
        {
            cout << assign_string[t][j];
        }
        cout << endl;
    }

}