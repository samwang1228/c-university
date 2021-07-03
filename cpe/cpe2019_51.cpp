#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,digit;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> digit;
        int binary[digit];
         bool test=true;
        for (int t = 0; t < digit;t++)
            cin >> binary[t];
        for (int i = 0; i < 1000;i++)
        {
            int temp = binary[0];
            for (int j = 0; j < digit - 1; j++)
            {
                binary[j] = abs(binary[j] - binary[j + 1]);
            }
            binary[digit - 1] = abs(binary[digit - 1] - temp);
        }
            for (int s = 0; s < digit;s++)
            {
                if(binary[s]!=0){
                    test = false;
                    break;
                }
            }
          if(test)
                cout <<"ZERO"<<endl;
            else
                cout << "LOOP"<<endl;

    }
}