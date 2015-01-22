#include "Vector.h"
#include <iostream>


int main() {
	Vector<int> v =  Vector<int>(4, 4);
	int a = v[0];
	std::cout << a << std::endl;
}