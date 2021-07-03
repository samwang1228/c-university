#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
void bigsort(int *s,int size)
{
    for (int i = 0; i <size-1;i++)
    {
        for (int j = 0; j < size - i-1;j++)
        {
            if(s[j+1]>=s[j])
                swap(s[j + 1], s[j]);
        }
    }
}
void smallsort(int *s,int size)
{
    for (int i = 0; i <size-1;i++)
    {
        for (int j = 0; j < size - i-1;j++)
        {
            if(s[j+1]<=s[j])
                swap(s[j + 1], s[j]);
        }
    }
}
void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void print(int *p,int size)
{
    for (int i = 0; i < size;i++)
    {
        cout << p[i];
    }
}
int convert(int *p,int size)
{
    int ans = 0, t = 0;
    for (int i = size - 1; i >= 0;i--)
        {
        ans += p[t]*pow(10, i);
        ++t;
        }
        return ans;
}
int main()
{
    string s;
    int counter ;
    vector<int> a;
    bool test;
    while(cin>>s)
    {
        test = false;
        a.clear();
        if(s=="0")
        break;
		counter=0;
		cout << "The oringal number was " << s<<endl;
		while(true)
        {
        int min[s.size()],max[s.size()];
        for (int i = 0; i < s.size();i++)
        {
            min[i] = s[i] - '0';
            max[i] = s[i] - '0';
        }
        bigsort(max, s.size());
        smallsort(min,s.size());
        cout<<convert(max, s.size())<<" - "<<convert(min, s.size())<<" = ";
        int last = convert(max, s.size()) - convert(min, s.size());
        ++counter;
        cout << last<<endl;
         if(last==0)
        {
            ++counter;
			cout<<"0 - 0 = 0"<<endl;
			cout<<"Chain length "<<counter<<endl;
			break;
        }
        a.push_back(last);
        for (int i = 0; i < a.size()-1;i++)
        {
            if(last==a[i])
            {
                cout<<"Chain length "<<counter<<endl;
                test = true;
                break;
            }
        }
        if(test)
            break;
            string test = to_string(last);
        if(s==test)
        {
             cout<<"Chain length "<<counter<<endl;
			break;
        }
        
        else
        {
            s = test;
        }
    }
}
} 
