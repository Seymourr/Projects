#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <string>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
 
template <class T>
class Vector {
  int elemAmnt; //Antalet element i vår vektor
  int capability; //Hur mycket vi kan lagra i vår vektor
  T *vek; //Pekare till vår vektor (Array vi dynamiskt uppdaterar)
 
 
 static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
                  
                  
public:
  ~Vector() {
    delete[] vek;
  }
          
  explicit Vector() { 
    vek = nullptr;
    elemAmnt = 0;
    capability = 0;
  }
     
  explicit Vector(std::size_t const amount, T initialValue = T()) {
 	elemAmnt = amount;
    capability = amount * 2;
    vek = new T[capability]();
    for(int i = 0; i < amount; i++) {
        vek[i] = initialValue;
    }
    
  }
         
         
    Vector (const Vector & src) {
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
         
         
    Vector (const std::initializer_list<T> & src) {
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
  	std::cout << "Enter Copy Assignment" << std::endl;
    if(src.size() > capability) {
      std::cout << "3" << std::endl;
      capability = src.size() * 2;
      elemAmnt = src.size();
      std::cout << "2" << std::endl;
      delete[]vek;
      vek = nullptr;
      vek = new T[capability];
      std::cout << "2" << std::endl;
      for(int i = 0; i < src.size(); ++i) {
      vek[i] = src[i];
      std::cout << "2" << std::endl;
    }
    } else if(vek == src.vek) {
        std::cout << "same" << std::endl;
    } else {
    std::cout << "else" << std::endl;
      reset();
      std::cout << "else1" << std::endl;
      elemAmnt = src.size();
      std::cout << "else2" << std::endl;
      for(int i = 0; i < src.size(); ++i) {
          vek[i] = src[i];
        }
        std::cout << "else3" << std::endl;
    }
   }
         
  Vector & operator= (Vector && src) {
  if(vek != src.vek) {
    if(begin() == end()) {
    	vek = nullptr;
    	
    }
    delete[] vek;
    vek = src.vek;
    elemAmnt = src.elemAmnt;
    capability = src.capability;
    src.elemAmnt = 0;
    src.capability = 0;
    src.vek = nullptr;
    }
  }
         
  T & operator[] (const unsigned int index) const {
    if(index >= size()) {
      throw std::out_of_range("Out of range.. pity");
    }
    return vek[index];
             
  }
           empty[1] 
         
         
    void reset() {
    for(int i = 0; i < elemAmnt; i++) {
      vek[i] = T(); 
    }
    }
   
    void push_back(T const newValue) {
        if(capability == 0 || (begin() == end())) {
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
         
        vek[size()] = newValue;
        elemAmnt = elemAmnt + 1;
    }
     
     
    void insert(std::size_t index, T const newValue) {
    if(index < 0 || index > size()) {
        throw std::out_of_range("Move closer!");
   	 }else if(index == size()) {
        	 push_back(newValue);          
   	 } else {
		    if(elemAmnt == capability) {
		        capability = capability * 2;
		        }
		        elemAmnt = elemAmnt + 1;
		        T * tmpCopy = vek;
		       
		        vek = new T[capability];
		        int j = 0;
		        for(int i = 0; i < elemAmnt; ++i) {
		            if(i == index) {
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
   

   void erase(std::size_t const index) {
	if(index < 0 || index >= size()) {
        throw std::out_of_range("Move closer!");
    } else {    
            int oldElAmnt = elemAmnt;
            elemAmnt = elemAmnt - 1;
            T * tmpCopy = vek;
            
            vek = nullptr;
            vek = new T[capability]();
            int j = 0;
             
            for(int i = 0; i < oldElAmnt; ++i) {   
                if(i == index) { 
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
    return &vek[0];
  }
   
  T* end() const {
    return &vek[elemAmnt];
  }
   
  T* find(T const& value) const {
    bool hasBeenFound = false;
    int indexOfFound = 0;
    T* refer = end();
    if(size() == 0) {
       // do nothing
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
        } 
    }
   
    return refer;
  }
   
   
   
     
         
};  
 
int main() {
	
	
    Vector<int> empty = Vector<int>();
    
    assert(empty.size() == 0);
    assert(empty.capacity() == 0);
    
    assert(empty.begin() == empty.end());
    std::cout << "1" << std::endl;
    empty.clear();
    empty.find(1337);
     
    empty.insert(0, 0);
    empty.erase(0);
    
    empty.push_back(1336);
    
    assert(empty[0] == 1336);
    empty.clear();
     
    assert(empty.size() == 0),
	std::cout << "1" << std::endl;
    assert(empty.begin() == empty.end());
    std::cout << "1" << std::endl;
    Vector<int> test8 = Vector<int>(100, 1024);
    std::cout << "here" << std::endl;
    test8.push_back(2048);
     std::cout << "here2" << std::endl;
    test8.insert(0, 123);
     std::cout << "or here" << std::endl;
    test8.insert(2,1337);
    test8.insert(5, 123);
 
 
   
  
    Vector<std::string> str = Vector<std::string>();
    str.push_back("hello");
    std::cout << str[0] << std::endl;
    std::cout << "1" << std::endl;
    Vector<int> givenSize(5);
    givenSize.push_back(2);
    givenSize.erase(1);
    givenSize.find(5);
    std::cout << "1" << std::endl;
    givenSize.insert(0, 1);
    givenSize.clear();
    givenSize.reset();
    std::cout << "1" << std::endl;
    givenSize.insert(0,0);
    Vector<int> givenValue(10,10);
    std::cout << "1" << std::endl;
    givenSize = givenValue;
    
    std::cout << "1" << std::endl;
    int * val = givenSize.find(10);
    std::cout << "1" << std::endl;
  	std::cout << *val << std::endl;
  	std::cout << "bv" << std::endl;
    Vector<int> copyOf = givenSize;
    std::cout << "1" << std::endl;
    Vector<int> movedTo = empty;
   
    Vector<int> movedWithValues = givenValue;
    Vector<int> listed({1,2,3,4,5,6});
    listed.clear();
    std::cout << "pointend" << std::endl;
     std::cout << "1" << std::endl;
    listed = Vector<int>(3,3);
    
    std::cout << "1" << std::endl;
    Vector<int> listed2 = Vector<int>(4,4);
    std::cout << "1" << std::endl;
    listed = std::move(listed2);
    
    Vector<int> movd = std::move(listed);
  std::cout << "END" << std::endl;
   
    
 
}
