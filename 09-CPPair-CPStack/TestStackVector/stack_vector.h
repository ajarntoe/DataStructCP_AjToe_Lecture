#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <vector>
//#pragma once

namespace CP {

template <typename T>
class stack
{
  protected:
    std::vector<T> v;

  public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
      v = a.v;
    }

    // default constructor
    stack() { }

    ~stack() { }

    //------------- capacity function -------------------
    bool empty() {
      return v.empty();
    }

    size_t size() {
      return v.size();
    }

    //----------------- access -----------------
    const T& top() {
     if (v.size() == 0) throw std::out_of_range("index of out range") ;
      return v[v.size()-1];
    }


    //----------------- modifier -------------
    void push(const T& element) {
      v.push_back(element);
    }

    void pop() {
      if (v.size() == 0) throw std::out_of_range("index of out range") ;
      v.pop_back();
      //v.erase(v.begin()+v.size()-1);
    }

};

}

#endif


