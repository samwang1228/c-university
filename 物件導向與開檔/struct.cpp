#include<iostream>
#include<string>
using namespace std;
/*struct Data
{
    float high;
    float weigh;
};//也可在分號前宣告SAM
int main()
{
    Data sam = {175.6, 58.6};//依序
    cout << sam.high;
    return 0;
}*/
class Data
{
    public:
        void input();//accessor讀入
        void output();//mutator修改
    private://代表接下來的variable只能透過member function去修改
        int month;
        int year;
        string day;
};
int main()
{
    Data sam,gina;
    cout << "please input Sam's birthday"<<endl;
    sam.input();
    cout << "Sam's birthday is ";
    sam.output();
    cout << endl;
    cout << "please input Gina's birthday"<<endl;
    gina.input();
    cout << "Gina's birthday is ";
    gina.output();
}
void Data::input()//因為可能會有好幾個class故要加 class_name
{
    cin >> year >> month >> day;
}
void Data::output()
{
   switch(month)//sam.month 
   {
       case 1:
        cout << year << " " << "January" << " " << day;
        break;
       case 2:
           cout << year << " " << "February" << " " << day;
           break;
       case 3:
           cout << year << " " << "March" << " " << day;
            break;
       case 4:
           cout << year << " " << "April" << " " << day;
            break;
       case 5:
           cout << year << " " << "May" << " " << day;
            break;
       case 6:
           cout << year << " " << "June" << " " << day;
            break;
       case 7:
           cout << year << " " << "July" << " " << day;
            break;
       case 8:
           cout << year << " " << "August" << " " << day;
            break;
       case 9:
           cout << year << " " << "September" << " " << day;
            break;
       case 10:
           cout << year << " " << "October" << " " << day;
            break;
       case 11:
           cout << year << " " << "November" << " " << day;
            break;
       case 12:
           cout << year << " " << "December" << " " << day;
            break;
   }
}