#include<iostream>
using namespace std;
class Dayofyear
{
    public:
        Dayofyear(int newmonth, int newday);
        Dayofyear(int newmonth);
        void input();
        void output();
        int getday();
        private:
            int month;
            int day;
            void test();
};
int main(){
    Dayofyear data_1(12, 28), data_2(8);
    data_1.output();
    cout << endl;
    data_2.output();
    cout << endl;
    data_1 = Dayofyear(8, 7);
    cout << "data_1 reset to the following:\n";
    data_1.output();
}
