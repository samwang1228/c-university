# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
#include<math.h>
using namespace std;

int f (int n, int x) 
{
    if(x == 0 || x >= n) return 1;
   else return f(n - 1, x - 1) + f(n - 1, x); 
}
int main()
    {
        string s ="think";
        cout << s.substr(2, 3);
    }