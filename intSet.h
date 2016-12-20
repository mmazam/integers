#ifndef __NODE_H__
#define __NODE_H__

struct intSet {
    int *data;
    int size;
    int capacity;
    intSet();
    intSet(const intSet&);
    ~intSet();
    intSet(intSet &&is);
    intSet &operator=(const intSet &is);
    intSet &operator=(intSet &&is);
    intSet operator|(const intSet &other);  // Set union.
    intSet operator&(const intSet &other);  // Set intersection.
    bool operator==(const intSet &other);  // Set equality.
    void realloc(); // Reallocates memory if necessary. 
    bool isSubset(intSet s);  // True if s is a subset of this set.
    bool contains(int e);  // True if e is an element of this set.
    void add(int e); // Adds int e to this set.
    void remove(int e); // Removes int e from this set.
    void swap(intSet &other); // swap
  };

  std::ostream& operator<<(std::ostream& out, const intSet& is);

#endif
