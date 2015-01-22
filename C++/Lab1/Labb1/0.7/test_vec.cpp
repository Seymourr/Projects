#include <iostream>
#include <stdexcept>
#include "UIntVector.h"     // inkludera din headerfil här


int main()
{
    // Några saker som ska fungera:
    UIntVector omega = UIntVector();
    UIntVector a(7);           // initiering med 7 element
    UIntVector b(a);           // kopieringskonstruktor 
    UIntVector c = a;          // kopieringskonstruktor 
	UIntVector d(std::move(c)); 	//Movekonstruktor
	d = std::move(b);
    a = d;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    const UIntVector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const körs
    i = a[0];              // vektorn är nollindexerad
    i = a[5];              // int oper[](int) körs
    
    a[5]++;                // öka värdet till 8
	
    try {
        i = e[10];             // försöker hämta element som ligger utanför e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
	
    return 0;
}


