#include<iostream>
#include<cmath>
using namespace std;
class BankAcc
{
    public:
        void output();
        BankAcc operator+( BankAcc bankacc1 );
        BankAcc operator-(BankAcc bankacc1 );
        BankAcc operator%(BankAcc bankacc1 );
        BankAcc operator*(BankAcc bankacc1 );
        BankAcc operator/(BankAcc bankacc1);
        BankAcc(double ntd, double usd, double eud);
        BankAcc();
        double valueInNTD();
        double valueInUSD();
        double valueInEUD();
        double getNTD(){
            return NTD;
        }
        double getusd(){
            return USD;
        }
        double getEUd()
        {
            return Eud;
        }
        bool set1(double ntd, double usd, double eud);
    private:
        double NTD;
        double USD;
        double Eud;
};
int main()
{
    BankAcc bankacc1(0,0,0),bankacc2(0,0,0),bankacc3;
    double ntdvalue1, usdvalue1, eudvalue1, ntdvalue2, usdvalue2, eudvalue2;
    cin >> ntdvalue1 >> usdvalue1 >> eudvalue1 >> ntdvalue2 >> usdvalue2 >> eudvalue2;
    bool test_1 = bankacc1.set1(ntdvalue1, usdvalue1, eudvalue1);
    bool test_2 = bankacc2.set1(ntdvalue2, usdvalue2, eudvalue2);
    if(test_1&&test_2)
    {
    bankacc1 = BankAcc(ntdvalue1, usdvalue1, eudvalue1);
    bankacc2 = BankAcc(ntdvalue2, usdvalue2, eudvalue2);
    bankacc1.output();
    bankacc2.output();
    bankacc3 = bankacc1 + bankacc2;
    cout << "+:";
    bankacc3.output();
    bankacc3 = bankacc1 - bankacc2;
    cout << "-:";
    bankacc3.output();
    bankacc3 = bankacc1 % bankacc2;
    cout << "%:";
    bankacc3.output();
    bankacc3 = bankacc1 * bankacc2;
    cout << "*:";
    bankacc3.output();
    bankacc3 = bankacc1 / bankacc2;
    cout << "/:";
    bankacc3.output();
    }
}
BankAcc::BankAcc()
{
    NTD = 0;
    USD = 0;
    Eud = 0;
}
bool BankAcc::set1(double ntd,double usd,double eud)
{
    if(ntd<0||usd<0||eud<0)
        return false;
    return true;
}
BankAcc::BankAcc(double ntd, double usd, double eud)
{
    NTD = ntd;
    USD = usd;
    Eud = eud;
}
double BankAcc::valueInNTD()
{
    double totalntd = NTD + USD * 30.0 + Eud * 40.0;
    return totalntd;
}
double BankAcc::valueInUSD()
{
    double totalusd = NTD / 30.0 + USD + Eud * 40.0 / 30.0;
    return totalusd;
}
double BankAcc::valueInEUD()
{
    double totaleud = NTD / 40.0 + USD * 30.0 / 40.0 + Eud;
    return totaleud;
}
BankAcc BankAcc:: operator+( BankAcc bankacc2 )
{
    BankAcc bankacc3(NTD +bankacc2.getNTD(),USD+bankacc2.getusd() ,Eud + bankacc2.getEUd());
    return bankacc3;
}
void BankAcc::output()
{
    cout << "NTD:" << valueInNTD() << " USD:" << valueInUSD() << " EUD:" << valueInEUD() << endl;
}
BankAcc BankAcc ::operator-(BankAcc bankacc2)
{
    BankAcc bankacc3(NTD -bankacc2.getNTD(),USD-bankacc2.getusd() ,Eud - bankacc2.getEUd());
    return bankacc3;
}
BankAcc BankAcc:: operator%(BankAcc bankacc2)
{
    
    BankAcc bankacc3 (fabs(NTD -bankacc2.getNTD()), fabs(USD-bankacc2.getusd()), fabs(Eud - bankacc2.getEUd()));
    return bankacc3;
}
BankAcc BankAcc:: operator*(BankAcc bankacc2)
{ 
    BankAcc bankacc3(NTD +bankacc2.getNTD()*0.99, USD+bankacc2.getusd()*0.99, Eud + bankacc2.getEUd()*0.99);
    return bankacc3;
}
BankAcc BankAcc:: operator/(BankAcc bankacc2)
{
    BankAcc bankacc3(NTD-bankacc2.getNTD()*1.01, USD -bankacc2.getusd()*1.01, Eud-bankacc2.getEUd()*1.01);
    return bankacc3;
}