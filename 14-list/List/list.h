#ifndef _CP_LIST_INCLUDED_
#define _CP_LIST_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP {

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
        node *prev;
        node *next;

        node() :
          data( T() ), prev( this ), next( this ) { }

        node(const T& data,node* prev, node* next) :
          data ( T(data) ), prev( prev ), next( next ) { }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() {
          ptr = ptr->next;
          return (*this);
        }

        list_iterator& operator--() {
          ptr = ptr->prev;
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;

        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;
    typedef node mynode;

  //protected:
    node *mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(list<T>& a) :
      mHeader( new node() ), mSize( 0 ) {
      for (iterator it = a.begin();it != a.end();it++) {
        push_back(*it);
      }
    }

    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) { }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element) {
      node *n = new node(element,it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    bool hasLoopForward() {
        iterator it = begin();
        int counter =0;
        while(it != end()){
            counter++;
            it++;
            if (counter > mSize) return true;
        }
        return counter != mSize;
    }

    bool hasLoopBackward() {
        iterator it = end();
        int counter =0;
        while(it != begin()){
            counter++;
            it--;
            if (counter > mSize) return true;
        }
        return counter != mSize;
    }

    bool hasLoop(){
        return hasLoopBackward() || hasLoopForward();
    }

    void reverse01(){
        iterator it = begin();
        T& currentData = *it;
        while(it != end()){
            currentData = *it;
            it = erase(it);
            push_front(currentData);
        }
    }

    void reverse02(){
        list<T> l;
        iterator it = begin();
        T& currentData = *it;
        while(it != end()){
            currentData = *it;
            l.push_front(currentData);
            ++it;
        }
        *this = l;


    }

    void unique(){
        iterator it = begin();
        while(it != end()){
            iterator it2 = begin();
            while(it2 != end()){
                if(it == it2) ++it2;//do nothing
                else if(*it2 != *it)  ++it2;// do nothing
                else {
                   it2 = erase(it2);
                }
            }
            ++it;
        }
    }

    void mergeX(list<T> x){
            iterator it = x.begin();
            //std::cout << "Start checking iterator." << std::endl;
            //if(it == end()) {
                //std::cout << "list 2 has no member." << std::endl;
            //    return;
            //}

            while(it != x.end()){
                //std::cout << "Inside while loop" << std::endl;
                push_back(*it);
               // std::cout << "Incrementing iterator." << std::endl;
                ++it;
            }
           // std::cout << "Finally, loop exit." << std::endl;

    }

    void mergeX2(list<T>& secondList){
            mSize = mSize + secondList.mSize;
            iterator itrSecondListStart = secondList.begin();
            std::cout << "Start checking iterator of list 2." << std::endl;
            if(itrSecondListStart == secondList.end()) {
                std::cout << "list 2 has no member." << std::endl;
                return;
            }
            std::cout << "Start checking iterator of list 1." << std::endl;
            iterator itrFirstListStart = begin();
            if(itrFirstListStart == end()){
                std::cout << "list 1 has no member." << std::endl;
                *this = secondList;
                return;
            }


            iterator itrFirstListEnd = end(); --itrFirstListEnd;
            iterator itrSecondListEnd = secondList.end(); --itrSecondListEnd;
            std::cout << "Now changing pointer itrSecondListStart.ptr->prev" << std::endl;
            itrSecondListStart.ptr->prev = itrFirstListEnd.ptr;

            std::cout << "Now changing pointer itrFirstListEnd.ptr->next" << std::endl;
            itrFirstListEnd.ptr->next = itrSecondListStart.ptr;

            std::cout << "Now changing iterator --itrFirstListStart" << std::endl;
            --itrFirstListStart;
            if(itrFirstListStart == end()){
                std::cout << "Correctly change iteraror." << std::endl;
            }
            std::cout << "Now changing pointer  itrSecondListEnd.ptr->next" << std::endl;
            itrSecondListEnd.ptr->next = itrFirstListStart.ptr;

            std::cout << "Now changing pointer  itrFirstListStart.ptr->prev" << std::endl;
            itrFirstListStart.ptr->prev = itrSecondListEnd.ptr;

            std::cout << "Finish merge." << std::endl;
            mHeader = itrFirstListStart.ptr;
            std::cout << "Finish setting up header." << std::endl;

    }


    void remove(T val){
        iterator it = begin();
        while(it != end()){
              if(val == *it){
                it = erase(it);
              } else{
                ++it;
              }
        }
    }

   // void removeAll(const value_type& val){




   // }

    void splice(iterator position, list& x){
        iterator it = position;
        iterator it2 = x.begin();

        while(it2 != x.end()){
            it= insert(it,*it2);
            ++it;
            ++it2;
        }
    }


    void print() {
      std::cout << " Header address = " << (mHeader) << std::endl;
      int i=0;
      iterator before;
      //std::cout << "Now printing the merge result" << std::endl;
      for (iterator it = begin();it!=end();before = it, it++,i++) {
        std::cout << "Node " << i << ": " << *it;
        std::cout << " (prev = " << it.ptr->prev << ", I'm at " << it.ptr << ", next = " << it.ptr->next << ")" <<  std:: endl;
      }
    }

};

}

#endif


