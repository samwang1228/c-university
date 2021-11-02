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
        double Eval(double x);
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
    if(first[0]==false&&sec.b!=0)
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
istream &operator>>(istream&istr,Quadratic &sec)
{
    double A, B, C;
    istr >> A >> B >> C;
    sec = Quadratic(A, B, C);
    return istr;
}
double Quadratic::Eval(double x){
	double ans;
	ans = a*pow(x,2)+b*x+c;
	return ans;
}
int main()
{
    Quadratic condition1, condition2,condition3;
    int x1,x2;
    cout << "Please enter your number of a,b,c and x of first polynomials"<<endl;
    cin >> condition1>>x1;
    cout << "Please enter your number of a,b,c and x of second polynomials"<<endl;
    cin >> condition2>>x2;
    cout << "Your first polynomials is ";
    cout << condition1;
    cout << "The solution of first polynomials is ";
    cout<<condition1.Eval(x1)<<endl;
    cout << "Your second polynomials is ";
    cout << condition2;
    cout << "The solution of second polynomials is ";
    cout<<condition2.Eval(x2)<<endl;
    condition3 = condition1 + condition2;
    cout << "Adding two polynomials is ";
    cout << condition3;
}