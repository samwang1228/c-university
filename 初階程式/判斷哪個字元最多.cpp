#include<fstream>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    ifstream instream;
    ofstream outstream;
    instream.open("1.in.txt");
    outstream.open("1.out.txt");
    string s;
    while(getline(instream,s))
    {
        int max1=0,max2=0,max3=0;
        int counter1[26]={}, counter2[26]={}, counter3[10]={};
        for (int i = 0; i < s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                counter1[s[i] - 'A']++;
            }
             if(s[i]>='a'&&s[i]<='z')
            {
                counter2[s[i] - 'a']++;
            }
             if(s[i]>='0'&&s[i]<='9')
            {
                counter3[s[i] - '0']++;
            }
        }
        for (int j = 0; j < 26;j++)
        {
            if(counter1[j]>counter1[max1])
            {
                max1 = j;
            }
            else if(counter1[j]==counter1[max1]&&j<max1)
            {
                max1 = j;
            }
            if(counter2[j]>counter2[max2])
            {
                max2 = j;
            }
            else if(counter2[j]==counter2[max2]&&j<max2)
            {
                max2 = j;
            }
        }
        for (int i = 0; i < 10;i++)
        {
             if(counter3[i]>counter3[max3])
            {
                max3 = i;
            }
            else if(counter3[i]==counter3[max3]&&i<max3)
            {
                max1 = i;
            }
        }
        char ans1 = max1 + 'A', ans2 = max2 + 'a', ans3 = max3 + '0';
//        if (counter1[max1] > counter1[max2] && counter1[max1] > counter3[max3])
//            outstream << ans1 << "  " << counter1[max1];
//        else if (counter2[max2] > counter1[max1] && counter2[max2] > counter3[max3])
//            outstream << ans2 << "  " << counter2[max2];
//        else if (counter3[max3] > counter1[max1] && counter3[max3] > counter2[max2])
//            outstream << ans3 << "¡@" << counter3[max3];
//        else if (counter1[max1] == counter2[max2] && counter2[max2] == counter3[max3])
//            outstream << ans3 << "¡@" << counter3[max3];
//        else if (counter1[max1] == counter2[max2] && counter1[max1] != counter3[max3])
//            outstream << ans1 << "¡@" << counter3[max3];
//        else if (counter1[max1] == counter3[max3] && counter2[max2] != counter3[max3])
//            outstream << ans3 << "¡@" << counter3[max3];
//        else if (counter3[max3] == counter2[max2] && counter1[max1] != counter3[max3])
//            outstream << ans3 << "¡@" << counter3[max3]; 
         if (counter1[max1] > counter2[max2] && counter1[max1] > counter3[max3])
            outstream << ans1;
        else if (counter2[max2] > counter1[max1] && counter2[max2] > counter3[max3])
            outstream << ans2;
        else if (counter3[max3] > counter1[max1] && counter3[max3] > counter2[max2])
            outstream << ans3;
        else if (counter1[max1] == counter2[max2] && counter2[max2] == counter3[max3])
            outstream << ans3;
        else if (counter1[max1] == counter2[max2] && counter1[max1] != counter3[max3])
            outstream << ans1;
        else if (counter1[max1] == counter3[max3] && counter2[max2] != counter3[max3])
            outstream << ans3;
        else if (counter3[max3] == counter2[max2] && counter1[max1] != counter3[max3])
            outstream << ans3; 
        outstream << endl;
    }
}
