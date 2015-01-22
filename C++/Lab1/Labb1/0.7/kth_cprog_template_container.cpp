#include <iostream>
#include <stdexcept>
#include <type_traits>

template <class T>
class Vector {
  int elemAmnt; //Antalet element i vår vektor
  int capability; //Hur mycket vi kan lagra i vår vektor
  T *vek; //Pekare till vår vektor (Array vi dynamiskt uppdaterar)

public:
  ~Vector() {
    delete[] vek;
  }
	     
  Vector() {
    static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
    vek = new T[0];
    elemAmnt = 0;
    capability = 0;
  }
	
  explicit Vector(std::size_t const amount, T initialValue = T()) {
    static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
    vek = new T[amount]();
    for(int i = 0; i < amount; i++) {
    	vek[i] = initialValue;
    }
    elemAmnt = amount;
    capability = amount * 2;
  }
		
		
  Vector (const Vector & src) {
    static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
    capability = src.size() * 2;
    elemAmnt = src.size();
		
    vek = new T[capability];
     	
    for(int i = 0; i < src.size(); ++i) {
      vek[i] = src[i];
    }
  }
  		
  		
  Vector (Vector && src) {
    vek = src.vek;
    elemAmnt = src.elemAmnt; 
    capability = src.capability;
    
    src.vek = nullptr;	 
    src.elemAmnt = 0;
    src.capability = 0;
  }
  		
  		
  explicit Vector (const std::initializer_list<T> & src) {
    static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
    elemAmnt = src.size();
    capability = src.size() * 2;
    int i = 0;
    vek = new T[capability];
    for(auto x : src) {
      vek[i] = x;
      i++;
    }
     		
     		
  }		
  		
  Vector & operator= (const Vector & src) {
    if(src.size() > capability) {
      capability = src.size() * 2;
      elemAmnt = src.size();
      vek = new T[capability];
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
  		
  Vector & operator= (Vector && src) {
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
  		
  T & operator[] (const int index) const {
    if(index < 0 || index >= elemAmnt) {
      throw std::out_of_range("Out of range.. pity");
    }
    return vek[index];
  		 	
  }
  		  
  		
  		
	void reset() {
	for(int i = 0; i < elemAmnt; i++) {
	  vek[i] = T(); 
	}
	}
  
	void push_back(T const newValue) {
		if(capability == 0) {
			capability = 10; //standardvärde i detta fall
			delete[] vek;
			vek = nullptr;
			vek = new T[capability];
		} else if(elemAmnt == capability) {
		capability = capability * 2;
	
		T * tmpCopy = vek;
		vek = nullptr;
		vek = new T[capability];
		 	
		for(int i = 0; i < size(); ++i) {
		vek[i] = tmpCopy[i];
			}
		delete[] tmpCopy;
		}
		vek[elemAmnt] = newValue;
		elemAmnt = elemAmnt + 1;
	}
  	
  	
	//Insert AFTER, not BEFORE. If kattis klagar, fix
	void insert(std::size_t index, T const newValue) {
	if(index < 0 || index >= size()) {
		throw std::out_of_range("Move closer!");
	} else if(index == size() - 1) {
	  			T lastValue = vek[size()-1];
	  			vek[size()-1] = newValue;
	  			push_back(lastValue);
	} else {
  		if(elemAmnt == capability) {
  			capability = capability * 2;
  			}
  			elemAmnt = elemAmnt + 1;
  			T * tmpCopy = vek;
   	 		vek = nullptr;
   			vek = new T[capability];
   			int j = 0;
			for(int i = 0; i < elemAmnt; ++i) {
	
				if(i == index - 1) {
				
					//Tryck in nytt element här, inkrementera i!
					vek[i] = newValue;
	} else {
		
 			vek[i] = tmpCopy[j];
 			j++;
 			}
 				}	
 			delete[] tmpCopy;
			}
	}
  
  void clear() {
  	elemAmnt = 0;
  	delete[] vek;
  	vek = nullptr;
  }
  
  //Ev räknefel i j++
  void erase(std::size_t const index) {
  if(index < 0 || index >= elemAmnt) {
  		throw std::out_of_range("Move closer!");
  	} else {	
  			int oldElAmnt = elemAmnt;
  			elemAmnt = elemAmnt - 1;
  			T * tmpCopy = vek;
  			vek = nullptr;
   			vek = new T[capability]();
   			int j = 0;
    		for(int i = 0; i < oldElAmnt; ++i) {   //Fråga på labben: Varför måste .begin variabeln vara efter förändringen? (genom erase)
     			if(i == index -1) {
    			// do nothing
    			} else {
    			 vek[j] = tmpCopy[i];
    			 j++;
    			}
   	 	}
   	 	delete[] tmpCopy;
    }
   	
  
  }
  
  std::size_t capacity() const {
  	return capability;
  }
  std::size_t size() const {
    return elemAmnt;
  }
  
  T* begin() const {
  if(size() == 0) {
  		throw std::out_of_range("No elements in the container");
  	} 
  	return &vek[0];
  }
  
  T* end() const {
  if(size() == 0) {
  		throw std::out_of_range("No elements in the container");
  	} 
  	return &vek[elemAmnt -1];
  }
  
  T* find(T const& value) const {
  	bool hasBeenFound = false;
  	int indexOfFound = -1;
  	T* refer = nullptr;
  	if(size() == 0) {
  		throw std::out_of_range("No elements in the container");
  	} else {
  		for(int i = 0; i < elemAmnt; ++i) {
  			if(vek[i] == value) {
  				hasBeenFound = true;
  				indexOfFound = i;
  				break;
  			}
  		}
  		
  		if(hasBeenFound) {
  			refer = &vek[indexOfFound];
  		} else {
  			refer = end();
  		}
  	}
  
  	return refer;
  }
  
  
  
  	
  		
};		
