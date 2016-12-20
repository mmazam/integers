#include <iostream>
#include "intSet.h"
using namespace std;

ostream& operator<< (ostream& out, const intSet& is) {

  cout << "(";
  for (int i = 0; i < is.size; ++i) {   
    if (i+1 == is.size) 
      cout << is.data[i];
    else
      cout << is.data[i] << ",";
  }
  cout << ")";
  return out;
}

intSet& intSet::operator= (intSet &&other) {
    using std::swap;
    swap(size, other.size);
    swap(capacity, other.capacity);
    swap(data, other.data);
    return *this;
}

intSet::intSet (intSet &&is) {
     using std::swap;
     swap(size, is.size);
     swap(capacity, is.capacity);
     swap(data, is.data);
     is.data = nullptr;
}

intSet intSet::operator| (const intSet &other) {

   intSet t{other};
   for (int i = 0; i < size; ++i) {
       if (contains(data[i]))
           t.add(data[i]);
   }
   return t;
}

intSet& intSet::operator= (const intSet &is) {

   if (this == &is) 
      return *this;
   size = 0;
   capacity = 0;
   delete [] data;
   for (int i = 0; i < is.size; ++i) 
      add(is.data[i]);
   return *this;
}

intSet::intSet ()  {
  size = 0;
  capacity = 0;
  data = nullptr;
}

intSet::~intSet () {
   delete [] data;
}

intSet::intSet (const intSet& s) {
   size = 0;
   capacity = 0;  
   data = nullptr;
   for (int i = 0; i < size; ++i) 
       add(s.data[i]);
}

intSet intSet::operator& (const intSet &other) {

   intSet s;
   for (int i = 0; i < other.size; ++i) {
       if (contains(other.data[i]))
            s.add(other.data[i]);
   }
   return s;
}

bool intSet::operator== (const intSet &other) {

  if (size != other.size) 
     return false;
  else {
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) 
           return false;
    }
    return true; 
  }
}

bool intSet::contains(int e) {
  
  for (int i = 0; i < size; ++i) {
     if (data[i] == e) return true;
  }
  return false;
}

void intSet::realloc() {

    int oldCap = capacity;
    if (capacity == 0) {
       capacity = 5;
       data = new int [capacity];
    } else 
       capacity *= 2;
    int *temp = new int [capacity];
    for (int i = 0; i < oldCap; ++i) 
       temp[i] = data[i];    
    delete [] data;
    data = temp;
 }    
    

void intSet::add(int e) {

  if (!contains(e)) {
     
     if (size == capacity) realloc();
     bool added = false;
     for (int i = size-1; i >= 0; i -= 1) {
       if (data[i] < e) {
         data[i+1] = e;
         added = true;
         break;
       } else if (data[i] > e) {
         data[i+1] = data[i];
       }
    }
    if (!added) 
     data[0] = e;
    ++size;
  }
}

void intSet::remove(int e) {

   if (contains(e)) {
     for (int i = 0; i < size; ++i) {
       if (data[i] >= e) 
         data[i] = data[i+1];      
    }
   size -= 1;
  }
}

bool intSet::isSubset(intSet s) {

   for (int i = 0; i < s.size; ++i) {
     if(!contains(s.data[i]))
        return false;
  }
  return true;
}
