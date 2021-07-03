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
        cout << double((96 * 6 + 92 * 3 + 91 * 3 + 95 * 2 + 89 * 2 + 90 * 3 + 81 * 3 + 90 * 3)/25);
    }