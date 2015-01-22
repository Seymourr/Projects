#include <iostream>

class A {
public:
   A () {
     std::cout << "default-constructor" << std::endl;
   }

   A (A const& src) {
     std::cout << "copy-constructor" << std::endl;
   }

  ~A () {
    std::cout << "destructor" << std::endl;
  }

   A(char const* s) {
      std::cout << "some other constructor" << std::endl;
   }

   A& operator= (A const& src) {
     std::cout << "the assignment operator" << std::endl;
     return *this;
   }
};

void no_ref(A a) {
std::cout << "Now1" << "\n" << std::endl;
}
void with_ref(const A & a) { std::cout << "Now2" << "\n" << std::endl;}

int main()
{
    A a("my name is a");

    A b = a;          // what is the difference
    A c(a);           // between these three
    A d;              // forms of initialization?

    d = a;
	std::cout << "Now" << std::endl;
      no_ref (a);     // will this copy the value of `a`?
    with_ref (a);     // will this copy the value of `a`?

    A *aa = new A[5];
    delete[] aa;        // what will happen?
    std::cout << "Now3" << std::endl;
    
    return 0;
}
