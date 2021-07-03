#include<iostream>
#include<string>
using namespace std;
struct student
{
    int number[66];
    char name[66][20];//66代表學生最大人數 20代表名字最大長度
    float grade[66];
};
int main()
{
    student people;
    int n;
    cout << "How many student in class?"<<endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "student's number:" << endl;
        cin >> people.number[i];
        cout << "student's name:" << endl;
        cin >> people.name[i];//輸入一維陣列即可
        cout << "student's grade" << endl;
        cin >> people.grade[i];
    }
    for (int j = 0; j < n-1;j++)
    {
        int min = j;
        for (int i = j+1; i < n ;i++)
        {
            if(people.number[i]<people.number[min])
                min = i;
        }
        if(min!=j)
        {
            int temp = people.number[min];
            people.number[min] = people.number[j];
            people.number[j] = temp;

        }
    }
    for (int i = 0; i < n;i++)
    {
        cout <<"No."<< people.number[i] << " " <<"Name "<< people.name[i] << " "<<"Score "<< people.grade[i] << endl;
    }
}