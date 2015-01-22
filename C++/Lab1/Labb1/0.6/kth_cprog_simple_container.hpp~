#include <iostream>
#include <stdexcept>

class UIntVector {
int elemAmnt; //Antalet element i vår vektor
int capability; //Hur mycket vi kan lagra i vår vektor
unsigned int *vek; //Pekare till vår vektor (Array vi dynamiskt uppdaterar)

	public:
	     ~UIntVector() {
	     	delete[] vek;
	     }
	     
		 UIntVector() {
		 vek = new unsigned int[0];
		 elemAmnt = 0;
		 capability = 0;
		}
	
		 explicit UIntVector(std::size_t const amount) {
		 vek = new unsigned int[amount]();
		 elemAmnt = amount;
		 capability = amount * 2;
		}
		
		 UIntVector (const UIntVector & src) {
		 capability = src.size();
		 elemAmnt = src.size();
		
     	 vek = new unsigned int[capability];
     	
     	 for(int i = 0; i < src.size(); ++i) {
     	 	vek[i] = src[i];
     	 }
  		}
  		
  		 UIntVector (UIntVector && src) {
  		 vek = src.vek;
     	 elemAmnt = src.elemAmnt; 
     	 capability = src.capability;
     	 
     	 src.vek = nullptr;
     	 src.elemAmnt = 0;
     	 src.capability = 0;
  		}
  		
  		 explicit UIntVector (const std::initializer_list<unsigned int> & src) {
     	 elemAmnt = src.size();
     	 capability = src.size() * 2;
     	 int i = 0;
     	 vek = new unsigned int[capability];
     	 for(auto x : src) {
     		vek[i] = x;
     		 i++;
     		}
  		}
  		
  		UIntVector & operator= (const UIntVector & src) {
  			if(src.size() > capability) {
  			capability = src.size() * 2;
  			elemAmnt = src.size();
  			vek = new unsigned int[capability];
  			for(int i = 0; i < src.size(); ++i) {
  				vek[i] = src[i];
  			}
  			} else if(vek == src.vek) {
				//Do nothing
  			} else {
  				reset();
  				elemAmnt = src.size();
  				for(int i = 0; i < src.size(); ++i) {
  				vek[i] = src[i];
  			}
  			}
  			
  		}
  		
  		UIntVector & operator= (UIntVector && src) {
  		if(vek != src.vek) {
  			delete[] vek;
  			vek = src.vek;
  			elemAmnt = src.elemAmnt;
  			capability = src.capability;
  			src.elemAmnt = 0;
  			src.capability = 0;
  			src.vek = nullptr;
  		}
  		}
  		
  		unsigned int & operator[] (const unsigned int index) const {
  		if(index >= elemAmnt) {
  			throw std::out_of_range("Out of range.. pity.");
  		}
  		return vek[index];
  		 	
  		 }
  		
  		void reset() {
  			for(int i = 0; i < elemAmnt; i++) {
  				vek[i] = 0;
  			}
  		}
  		
  		
  		std::size_t size() const {
  		 return elemAmnt;
  		}
  		
};	

