#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class student
{
public:
    student(const char *stName);
    student(const char *stName, const int cal, const int phy, const int ics);
    bool setName(const char *stName);
    bool setCal(const int score);
    bool setPhy(const int score);
    bool setIcs(const int score);
    const char *getName();
    int getCal();
    int getPhy();
    int getIcs();
    double getAverage();
    int Calscore,Physcore,Icsscore;
    char* Name;
};
int main()
{
    student answer1("ok"),answer2("ok",0,0,0);
    int Type_mode,seed,calvalue,phyvalue,icsvalue;
    char *name=NULL;
    string name_;
    bool test_1, test_2, test_3;
    while(cin>>Type_mode)
    {
        if(Type_mode==0)
            break;
        if(Type_mode==1)
        {
            cin >> seed;
            srand(seed);
            cin >> name_;
            name = new char[name_.size()];
            for (int i = 0; i < name_.size();i++)
            {
                name[i] = name_[i];
            }
            answer1 = student(name);
            answer1.Calscore = rand() % 101;
            answer1.Physcore = rand() % 101;
            answer1.Icsscore = rand() % 101;
            cout << answer1.getName() << endl;
            cout << answer1.getCal() << endl;
            cout << answer1.getPhy() << endl;
            cout << answer1.getIcs() << endl;
            cout << answer1.getAverage() << endl;
            answer1.setName(name);
        }
        if(Type_mode==2)
        {
            cin >> name_ >> calvalue >> phyvalue >> icsvalue;
            test_1 = answer2.setCal(calvalue);
            test_2 = answer2.setPhy(phyvalue);
            test_3 = answer2.setIcs(icsvalue);
            if(test_2&&test_3&&test_1)
            {
            name = new char[name_.size()];
            for (int i = 0; i < name_.size();i++)
            {
                name[i] = name_[i];
            }
            answer2 = student(name, calvalue, phyvalue, icsvalue);
            cout << answer2.getName() << endl;
            cout << answer2.getCal() << endl;
            cout << answer2.getPhy() << endl;
            cout << answer2.getIcs() << endl;
            cout << answer2.getAverage() << endl;
            }
            answer2.setName(name);
        }
    }
}
student::student(const char* stName)
{
    Name = new char[strlen(stName)];
    strcpy(Name, stName);
    /*Physcore = rand()%101;
    Icsscore = rand()%101;
    Calscore = rand()%101;*/
}
student:: student(const char *stName, const int cal, const int phy, const int ics)
{
    Name = new char[strlen(stName)];
    strcpy(Name, stName);
    Calscore = cal;
    Physcore = phy;
    Icsscore = ics;
}
const char *student::getName()
{
    return Name;
}
int student::getCal()
{
    return Calscore;
}
int student::getPhy()
{
    return Physcore;
}
int student::getIcs()
{
    return Icsscore;
}
bool student::setCal(const int score)
{
    if(score<0||score>100)
        return false;
    return true;
}
bool student::setPhy(const int score)
{
    if(score<0||score>100)
        return false;
    return true;
}
bool student::setIcs(const int score)
{
    if(score<0||score>100)
        return false;
    return true;
}
bool student::setName(const char*stName)
{
    if(stName==NULL)
        return true;
    else 
    {
        delete []Name;
        return true;
    }
    return false;
}
double student::getAverage()
{
    return (Calscore + Physcore + Icsscore) / 3.0;
}
