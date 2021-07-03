#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class Quadratic
{
    private:
        double a, b, c;
    public:
        Quadratic();
        Quadratic(double A, double B, double C);
        Quadratic operator+(Quadratic &sec);
        friend ostream& operator<<(ostream& ostr,Quadratic & sec); //矩陣的輸出過載函式
	    friend istream& operator>>(istream& istr,Quadratic & sec); //矩陣的輸入過載函式
        void Eval();
};
Quadratic ::Quadratic()
{
    a = b = c = 0;
}
Quadratic ::Quadratic(double A,double B,double C)
{
    a = A;
    b = B;
    c = C;
}
Quadratic Quadratic::operator+(Quadratic &sec)
{
    int ansA, ansB, ansC;
    ansA = a + sec.a;
    ansB = b + sec.b;
    ansC = c + sec.c;
    return Quadratic(ansA, ansB, ansC);
}
ostream &operator<<(ostream &ostr,Quadratic & sec)
{
    bool first[2]={false,false};
    if(sec.a!=0)
        first[0] = true;
    if(first[0]==false)
        first[1] = true;
    if(sec.a<0)
        ostr << sec.a << "x^2";
    else if (sec.a == 1)
            ostr<< "x^2";
    else if(sec.a>1)
        ostr << sec.a << "x^2";
    if (sec.b < 0)
        ostr << sec.b << "x";
    else if(sec.b==1&&first[0])
        ostr << "+x";
    else if(sec.b==1&&first[0]==false)
        ostr << sec.b << "x";
    else if(first[0]&&sec.b>1)
        ostr <<"+"<< sec.b << "x";
    else if(first[0]==false&&sec.b>1)
        ostr << sec.b << "x";
    if (sec.c < 0)
        ostr << sec.c;
    else if(sec.c>=1&&(first[1]==true||first[0]==true))
        ostr << "+" << sec.c;
    else if(sec.c>=1&&first[0]==false&&first[1]==false)
        ostr << sec.c;
    ostr << endl;
    return ostr;
}
// istream &operator>>(istream& istr,Quadratic &sec)
// {
//     string s;
//     bool
//     int A=0, B=0, C=0;
//     istr >> s;
//     // for (int i = 0; i < s.size();i++)
//     // {
//     //     if(s[i]=='x')
//     //     {
//     //         mod = false;
//     //         break;
//     //     }
//     // }
//     // if(mod)

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '^' && s[i + 1] == '2')
//         {
//             for (int j = i - 2; j >= 0; j--)
//             {
//                 int k = 0;
//                 A += (s[j] - '\0') * pow(10, k);
//                 ++k;
//             }
//         }
//         if(s[i]=='x'&&(s[i-1]<='9'&&s[i-1]>='0'))
//         {
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 if(s[j]=='+'||s[j]=='-') 
//                 {
//                     break;
//                 }
//                 int k = 0;
//                 B += (s[j] - '\0') * pow(10, k);
//                 ++k;
//             }
//         }
//         if()
//     }
// }
istream &operator>>(istream&istr,Quadratic &sec)
{
    double A, B, C;
    istr >> A >> B >> C;
    sec = Quadratic(A, B, C);
    return istr;
}
void Quadratic::Eval()
{
    double solution1,solution2;
    if(b*b-4*a*c==0)
    {
        solution1 = -b / (2 * a);
        cout << " x = "<<solution1<<endl;
    }
    else if(a==0&&c!=0)
    {
        solution1 = -c / b;
        cout << " x= " << solution1<<endl;
    }
    else if(c==0&&a==0)
    {
        cout << " x = 0 "<<endl;
    }
    else if(b*b-4*a*c>0)
    {
        solution1 = (-b + sqrt((b * b) - 4 * a * c)) / (2*a);
        solution2 = (-b - sqrt((b * b) - 4 * a * c)) / (2*a);
        cout << " x= " << solution1 << " or " << solution2 << endl;
    }
    else
        cout << " no solution" << endl;
}
int main()
{
    Quadratic condition1, condition2,condition3;
    cout << "Please enter your number of a,b,and c of first polynomials"<<endl;
    cin >> condition1;
    cout << "Please enter your number of a,b,and c of second polynomials"<<endl;
    cin >> condition2;
    cout << "Your first polynomials is ";
    cout << condition1;
    cout << "The solution of  first polynomials is ";
    condition1.Eval();
    cout << "Your second polynomials is ";
    cout << condition2;
    cout << "The solution of  second polynomials is ";
    condition2.Eval();
    condition3 = condition1 + condition2;
    cout << "Adding two polynomials is ";
    cout << condition3;
    cout << "The solution of adding two polynomials is ";
    condition3.Eval();
}