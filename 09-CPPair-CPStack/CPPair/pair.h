#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

#include <stdexcept>
#include <iostream>
//#pragma once
using namespace std;
namespace CP {

template <typename T1,typename T2>
class pair
{
  public:
    T1  first;
    T2  second;

    // copy constructor
    pair(const pair<T1,T2>& a) {
      first = a.first;
      second = a.second;
      cout << "copy" << endl;

    }

    // default constructor, using initializer list
    pair() : first() , second() {
        cout << "default" << endl;

    }

    // custom constructor, using initializer list
    pair(const T1 &a,const T2 &b) : first(a), second(b) {
        cout << "custom" << endl;
    }

    // we have no destructor

    // copy assignment operator using traditional assignment
    pair<T1,T2>& operator=(const pair<T1,T2>& other) {
      first = other.first;
      second = other.second;
      return *this;
    }

    // equality operator
    bool operator==(const pair<T1,T2> &other) {
      return (first == other.first && second == other.second);
    }

    // comparison operator
    bool operator<(const pair<T1,T2>& other) const {
      return ((first < other.first) ||
              (first == other.first && second < other.second));
    }

};


}



#endif // PAIR_H_INCLUDED
