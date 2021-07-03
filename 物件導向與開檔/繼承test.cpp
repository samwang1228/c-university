#include <iostream>
using namespace std;
class Point2D { 
public: 
    Point2D() {
        _x = 0;
        _y = 0;
    }
    Point2D(int x, int y) : _x(x), _y(y)//初始化 x=_x
    {
    }
    int x() {return _x;}//若要讓繼承的class能輸出自己的變數要在主程式的函示前加上virtual 
    int y() {return _y;} 
    void x(int x) {
        _x = x;
    }
    void y(int y) {
        _y = y;
    }
private://這裡繼承的class無法使用 若要得到要用protected: 此代表only繼承class能看到
    int _x;
    int _y;
}; 
class Point3D : public Point2D { 
public: 
    Point3D() { 
        _z = 0; 
    }
    Point3D(int x, int y, int z) : Point2D(x, y), _z(z) //一樣是初始化 要先初始化上面才能用
    { 
    } 
    int z() {return _z;}
    void z(int z) {_z = z;}
    //若要在這裡寫主class的member function不能直接寫要透過新函式來呼叫主class 
    //之所以要用到主class的member function是因為變數為private 當然直接改成protected就好(變數)
private:
    int _z;
}; 
int main() {
    Point3D p1(1, 3, 4);
    Point3D p2;
    Point2D *p3[2];//物件指標
    p3[0]= new Point2D(3,4);//使用物件指標能讓每個空間都指向不同的class 並在for做指向
    p3[1] = new Point3D(6,7,8);
    for (int i = 0; i <2;i++)
    {
        cout << p3[i]->x() << endl; //指向函式
    }
    cout << "p1: (" 
         << p1.x() << ", " 
         << p1.y() << ", " 
         << p1.z() << ")"
         << endl;
    cout << 2;
    p2.x(5);
    p2.y(7);
    p2.z(8);
    cout << "p2: (" 
         << p2.x() << ", " 
         << p2.y() << ", " 
         << p2.z() << ")"
         << endl;
 
    return 0;
}