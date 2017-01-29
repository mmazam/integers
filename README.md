# integers

A class which stores a set of integers and defines methods to perform operations on intSets

-> Bitwise or, Bitwise and, Equality and Output operators have been overloaded to represent
  set union, set intersection, set quality and printing a set.
  
-> The copy constructor and assigment operators perform deep copies so that each intSet has
  it's own indepedent data.
  
-> isSubset(intSet s) returns true if every element in s is a element of the set the method 
  was invoked on
  
-> contains(int i) returns true if the integer i is an element of the set the method was
  invoked on
  
-> add(int i) adds integer i to the set the method was invoked on if i is not already in the set

-> remove(int i) removes the integer i from the set the method was invoked on
