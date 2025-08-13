#ifndef _CP_VECTOR_INCLUDED_
#define _CP_VECTOR_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

using namespace std;
namespace CP {

template <typename T>
class vector
{
  public:
    typedef T* iterator;

  protected:
    T *mData;
    size_t mCap; //unsigned int that can be the size of any object
    size_t mSize;

    void rangeCheck(int n) {
      if (n < 0 || (size_t)n >= mSize) {
        throw std::out_of_range("index of out range") ;
      }
    }

    void expand(size_t capacity) { //resize the array to the given size
      T *arr = new T[capacity];
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2*mCap) ? capacity : 2*mCap;
        expand(s);
      }
    }

  public:
    //-------------- constructor ----------

    // copy constructor
    vector(const vector<T>& a) { //a copy constructor
      mData = new T[a.capacity()];
      mCap = a.capacity();
      mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a[i];
      }
    }

    // default constructor
    vector() {
      int cap = 1;
      mData = new T[cap];
      mCap = cap;
      mSize = 0;

    }

    // constructor with initial size
    vector(size_t cap) {
      mData = new T[cap];
      mCap = cap;
      mSize = cap;
    }


    ~vector() {
      clear();
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() {
      return mSize == 0;
    }

    size_t size() {
      return mSize;
    }

    size_t capacity() {
      return mCap;
    }

    void resize(size_t n) {
      if (n > mCap)
        expand(n);

      mSize = n;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return &mData[0];
    }

    iterator end() {
      return begin()+mSize;

    }
    //----------------- access -----------------
    T& at(int index) {
      rangeCheck(index);
      return mData[index];
    }

    T& operator[](int index) {
      return at(index);
    }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void pop_back() {
      mSize--;
    }

    void insert(iterator it,const T& element) {
      size_t pos = it - begin();
      ensureCapacity(mSize + 1);
      for(size_t i = mSize;i > pos;i--) {
        mData[i] = mData[i-1];
      }
      mData[pos] = element;
      mSize++;
    }

    void erase(iterator it) {
      while((it+1)!=end()) {
        *it = *(it+1);
        it++;
      }
      mSize--;
    }

    void clear() {
      mSize = 0;
    }


    //-------------- extra (unlike STL) ------------------
    void insertAA(iterator it, const T& element) {
		ensureCapacity(mSize + 1);
		
		for(iterator i = end(); i != it; i--) {
			cout << "\t" << *i;
			*i = *(i-1);
		}
		*it = element;
		mSize++;
	}

	void insert(size_t it,const T& element) {
      insert(begin()+it,element);
    }

    void erase_by_pos(int index) {
      erase(begin()+index);
    }

    void erase(const T& element) {
      int i = index_of(element);
      if (i != -1) erase_by_pos(i);
    }

    bool contains(const T& element) {
      return index_of(element) != -1;
    }

    int index_of(const T& element) {
      for (int i = 0;i < mSize;i++) {
        if (mData[i] == element) {
          return i;
        }
      }
      return -1;
    }
};

}

#endif


