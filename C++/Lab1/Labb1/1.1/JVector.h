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
 
 
                                 
public:
  ~Vector() {};
          
  explicit Vector() { };
     
  explicit Vector(std::size_t const amount, T initialValue = T()) {};
         
         
    Vector (const Vector & src) {};
         
         
  Vector (Vector && src) {};
         
         
  Vector (const std::initializer_list<T> & src) {};    
         
  Vector & operator= (const Vector & src) {};
         
  Vector & operator= (Vector && src) {};
           
   T & operator[] (const unsigned int index) const {};       
         
    void reset() {};
   
    void push_back(T const newValue) {};
     
     
    void insert(std::size_t index, T const newValue) {};
   
  void clear() {};
   

   void erase(std::size_t const index) {};
     
   
  std::size_t capacity() const { };
  std::size_t size() const {};
   
  T* begin() const {};
   
  T* end() const {};
   
  T* find(T const& value) const {};
   
   
   
     
         
};  
