# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
#include<math.h>
using namespace std;

class student
{
public:
   student()
   {
       size = 0;
   };
   void display();
   void add();
   void remove();
   double getEnglish(int i);
   int getSize();
   private:
       vector<string> ID;
       vector<string> NAME;
       vector<double> YEAR;
       vector<double> HEIGHT;
       vector<double> WEIGHT;
       vector<double> CHINESE;
       vector<double> MATH;
       vector<double> ENGLISH;
       int size;
};
void student :: display()
{
    for (int i = 0; i < size;i++)
       {
           cout << "Number of " << i+1 << " student" << endl;
           cout << "ID:" << ID[i] << endl;
           cout << "NAME:" << NAME[i] << endl;
           cout << "YEAR:" << YEAR[i] << endl;
           cout << "HEIGHT:" << HEIGHT[i] << endl;
           cout << "WEIGHT:" << WEIGHT[i] << endl;
           cout << "CHINESE:" << CHINESE[i] << endl;
           cout << "MATH:" << MATH[i] << endl;
           cout << "ENGLISH:" << ENGLISH[i] << endl;
       }
}
void student::add()
{
    size++;
    string nextID, nextName;
    double nextYear, nextHeight, nextWeight, nextChinese, nextMath, nextEnglish;
    cin >>nextID>>nextName >>nextYear >> nextHeight >> nextWeight >> nextChinese >> nextMath >> nextEnglish;
    ID.push_back(nextID);
    NAME.push_back(nextName);
    YEAR.push_back(nextYear);
    HEIGHT.push_back(nextHeight);
    WEIGHT.push_back(nextWeight);
    CHINESE.push_back(nextChinese);
    MATH.push_back(nextMath);
    ENGLISH.push_back(nextEnglish);
}
void student::remove()
{
    //刪除最後一位同學
    size--;
    ID.pop_back();
    NAME.pop_back();
    YEAR.pop_back();
    HEIGHT.pop_back();
    WEIGHT.pop_back();
    CHINESE.pop_back();
    MATH.pop_back();
    ENGLISH.pop_back();
}
double student::getEnglish(int i)
{
    return ENGLISH[i];
}
int student::getSize()
{
    return size;
}
class average1: public student
{
public:
   average1() : student(){}
   void setAVERAGEYEAR(double);
   double getAVERAGEYEAR() const;

   void setAVERAGEHEIGHT(double);
   double getAVERAGEHEIGHT() const;

   void setAVERAGEWEIGHT(double);
   double getAVERAGEWEIGHT() const;
  
private:
       double AVERAGEYEAR;
       double AVERAGEHEIGHT;
       double AVERAGEWEIGHT;
};

class average2 : public student
{
public:
    average2() : student(){}

   void setAVERAGECHINESE(double);
   double getAVERAGECHINESE() const;

   void setAVERAGEMATH(double);
   double getAVERAGEMATH() const;

   void setAVERAGEENGLISH();
   double getAVERAGEENGLISH() ;

private:
       double AVERAGECHINESE;
       double AVERAGEMATH;
       double averageEng;
};
void average2::setAVERAGEENGLISH()
{
    averageEng = 0;
    for(int i= 0; i < getSize();i++)
        averageEng += getEnglish(i);
    averageEng /= getSize();
}
double average2::getAVERAGEENGLISH()
{
    setAVERAGEENGLISH();
    return averageEng;
}
int main()
{
    average2 ans;
    ans.add();
    ans.add();
    ans.display();
    cout<<"Average of English is"<<ans.getAVERAGEENGLISH();
}
