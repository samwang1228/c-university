#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    srand(time(0));
    int N;
    cin >> N;
    int ans[N][N];
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
            ans[i][j] = (long long)(double)rand()*1000000/RAND_MAX;
    }
    cout << "initial array"<<endl;
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
            cout << setw(7)<<ans[i][j]<<" ";
        cout << endl;
    }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int x = 0; x < N; x++)
                {
                    for (int y = 0; y < N; y++)
                    {
                        if(ans[i][j]<=ans[x][y])
                            swap(ans[i][j], ans[x][y]);
                    }
                }    
            }
        }
    cout << "sorting array" << endl;
    for (int i = 0; i < N; i++)
    {
        if(i%2==0)
        {
		for (int j = 0; j < N; j++)
            cout <<setw(7) <<ans[i][j] << " ";
   		}
   		else
   		{
   		for (int j = N-1; j >=0; j--)
            cout <<setw(7) <<ans[i][j] << " ";	
		}
        cout << endl;
    }
}

