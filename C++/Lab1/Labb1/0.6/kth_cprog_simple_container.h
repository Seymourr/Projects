#include <iostream>
#include <stdexcept>

class UIntVector {
int elemAmnt; //Antalet element i vår vektor
int capability; //Hur mycket vi kan lagra i vår vektor
unsigned int *vek; //Pekare till vår vektor (Array vi dynamiskt uppdaterar)

	public:
	     ~UIntVector() {}
	     
		 UIntVector() {}
	
		 explicit UIntVector(std::size_t const amount) {}
	
		 UIntVector (const UIntVector & src) {}
  		
  		 UIntVector (UIntVector && src) {}
  		
  		
  		 explicit UIntVector (const std::initializer_list<unsigned int> & src) {}
  		
  		
  		UIntVector & operator= (const UIntVector & src) {}
  		
  		UIntVector & operator= (UIntVector && src) {}
  		
  		unsigned int & operator[] (const unsigned int index) const {}
	
  		void reset() {}

  		std::size_t size() const {}
  		
};		




