#include<iostream>
using namespace std;
class intlist 
{
    public:
    intlist();
    intlist(int size);
    void input(double intege);
    int getnumber();//還傳數字
    bool listinterger();//是否整數
    bool insertlist(const int x);//如果還有空間將x插入並回傳true
    bool getinteger(const int pos, int *value);//如果pos有存放整數將值存到value 並為真
    //bool  operator+(const int &b);
    private:
        int n = 0, intsize;
        double*var;
};
int main()
{
    intlist answer1(0),answer2;
    int len,pos;
    double varible;
    cin >> len;
    answer1 = intlist(len);
    while(cin>>varible)
    {
        cout << answer1.getnumber();
        answer1.input(varible);
        cin >> pos;
        bool test_1 = answer1.getinteger(pos, 0);
    }
}
intlist::intlist()
{
    n = 0;
    intsize = 0;
}
intlist::intlist(int size)
{
    intsize = size;
    var = new double[intsize];
}
int intlist::getnumber()
{
    n++;
    return n;
}
bool intlist::getinteger(const int pos,int*value)
{
    int q = var[pos];
    if(var[pos]-q==0)
        return false;
    else
    {
        *value = var[pos];
        return true;
    }
}
void intlist::input(double intege)
{
    var[n] = intege;
}

