#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <string>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
 
template <class T>
class JVector {
  int elemAmnt; //Antalet element i vår vektor
  int capability; //Hur mycket vi kan lagra i vår vektor
  T *vek; //Pekare till vår vektor (Array vi dynamiskt uppdaterar)
 
 
 static_assert(std::is_move_constructible<T>::value,
                  "Your type requires moving");
    static_assert(std::is_move_assignable<T>::value,
                  "Your type requires moving");
                  
                  
public:
  ~JVector() {
    delete[] vek;
  }
          
  explicit JVector() { 
    vek = nullptr;
    elemAmnt = 0;
    capability = 0;
  }
     
  explicit JVector(std::size_t const amount, T initialValue = T()) {
  elemAmnt = amount;
    capability = amount * 2;
    vek = new T[capability]();
    for(int i = 0; i < amount; i++) {
        vek[i] = initialValue;
    }
    
  }
         
         
    JVector (const JVector & src) {
    capability = src.size() * 2;
    elemAmnt = src.size();
         
    vek = new T[capability];
         
    for(int i = 0; i < src.size(); ++i) {
      vek[i] = src[i];
    }
  }
         
         
  JVector (JVector && src) {
    vek = src.vek;
    elemAmnt = src.elemAmnt; 
    capability = src.capability;
     
    src.vek = nullptr;   
    src.elemAmnt = 0;
    src.capability = 0;
  }
         
         
    JVector (const std::initializer_list<T> & src) {
    elemAmnt = src.size();
    capability = src.size() * 2;
    int i = 0;
    vek = new T[capability];
    for(auto x : src) {
      vek[i] = x;
      i++;
    }
             
             
  }     
         
  JVector & operator= (const JVector & src) {
 
    if(src.size() > capability) {

      capability = src.size() * 2;
      elemAmnt = src.size();
    
    
      delete[]vek;
      vek = nullptr;
      vek = new T[capability];

      for(int i = 0; i < src.size(); ++i) {
      vek[i] = src[i];

    }
    } else if(vek == src.vek) {

    } else {

      reset();

      elemAmnt = src.size();
 
      for(int i = 0; i < src.size(); ++i) {
          vek[i] = src[i];
        }

    }
   }
         
  JVector & operator= (JVector && src) {
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
  
   T & operator[] (std::size_t index) {
    if(index >= size()) {
      throw std::out_of_range("Out of range.. pity");
    }
    return vek[index];
             
  }

  const T & operator[] (std::size_t index) const {
    if(index >= size()) {
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
   

   const T* begin() const {
    return &vek[0];
  }

  T* begin( ){
    return &vek[0];
  }
   

   const T* end() const {
    return &vek[elemAmnt];
  }
  
  T* end() {
    return &vek[elemAmnt];
  }

 
   
 
   
  T* find(T & value) {
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
   

   const T* find(T const& value) const {
    bool hasBeenFound = false;
    int indexOfFound = 0;
    const T* refer = end();
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

