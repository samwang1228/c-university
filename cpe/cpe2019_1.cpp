#include<iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    for (int t = 0; t < m;t++)
    {
        char a, b;
        long long int n;
        cin >> a >> b >> n;
        long long int matrix[n][n];
        bool  test1 = true, test2 = true;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cin >> matrix[i][j];
                if(matrix[i][j]<0)
                {
                    test1=false;
                }
            }
        }
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
             {
                 if (matrix[i][j]!=matrix[n-1-i][n-j-1])
                 {
                     test2=false;
                     goto end;
                 }
             }
        }
        end:
        if(test1&&test2)
        {
            cout << "Test #" << t + 1 << ": Symmetric."<<endl;
        }
        else
            cout << "Test #" << t + 1 << ": Non-symmetric."<<endl;
    }
}