#include<iostream>
using namespace std;
class Base {
public:
  const Base& operator=(const Base& rhs) { 
    /* Assume implementation is 
        given and correct */ 
   return *this;
  }
   // --- more methods, constructors, and destructor --
private:
  // Some data
};

class Derived : public Base {
public:
  const Derived& operator=(const Derived& rhs) {    
  if( this != &rhs ) {
    Base::operator=(rhs);
    delete str;
    str = rhs.str ? new std::string(*rhs.str) : nullptr;
  }
  return *this;
}
  /*
     Overload assignment operator.
  */

   // --- more methods, constructors, and destructor --
private:
  std::string* str = nullptr;
};
