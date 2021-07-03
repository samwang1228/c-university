#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
template <class T>
class Set
{
public:
    Set(T st);
    void display() {
        cout << t << endl;
    }
    private:
    T t;
};

// Normal class, Not-template class
class Set_int
{
    int t;
public:
    Set_int(int st): t(st) {}

    void display() {
        cout << setw(10) << setfill('0')
            << t << endl;
    }
};

// Specialized class template
template <> class Set<int>
{
    int t;
public:
    Set(int st) {
        t = st;
    }

    void display() {
        std::cout << std::setw(10) << std::setfill('o')
            << t << std::endl;
    }
};

int main() {
    Set<int> a(7);
    Set_int b(2);  // User needs to know there is a non-template class.
    Set<int> c(9); // User doesn't need to know there is a non-template class.
    string s;
    int h = 5;
    //cin >> s;
    a = Set(h);
    a.display();
    b.display();
    c.display();
    return 0;
}
template<class T>
Set<T>::Set(T st)
{
    t = st;
}