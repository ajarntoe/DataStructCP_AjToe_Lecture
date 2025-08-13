#include <iostream>
#include <assert.h>
#include "list.h"
#include <list>


bool test1() {
  CP::list<int> a;

  CP::list<int>::iterator it,it2;
  it =a.begin();
  it2 = it;
  it2++;
  assert(it == it2);
  a.push_back(10);
  it2++;
  assert(it != it2);
  a.push_back(11);
  a.push_back(12);
  a.push_back(30);
  a.push_back(99);
  a.print();

  a.clear();
  assert(a.size() == 0);
  a.push_front(1);
  a.push_front(2);
  a.push_front(3);
  a.push_front(4);
  a.push_front(5);
  a.pop_front();
  a.pop_back();
  a.print();

  assert(a.front() == 4);
  assert(a.back() == 2);

  return true;
}

bool test2() {
  CP::list<std::string> l,l2;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.push_front("BBB");
  l2 = l;
  CP::list<std::string>::iterator it1,it2;
  it1 = l.begin();
  it2 = l2.begin();
  for (;it1 != l.end();it1++,it2++) {
    assert(*it1 == *it2);
  }
  l2.print();
  return true;
}

bool test3() {
  CP::list<std::pair<std::string,int> > l,l2;
  l.push_back(std::make_pair("A",1));
  l.push_back(std::make_pair("B",2));
  l.push_back(std::make_pair("C",3));
  l.push_back(std::make_pair("D",4));

  CP::list<std::pair<std::string,int> >::iterator it = l.begin();
  it--;it--;

  for (size_t i = 0;i < l.size();i++) {
    l2.push_front(*it);
    it--;
  }

  CP::list<std::pair<std::string,int> >::iterator it2;
  it2 = l2.begin();
  while(it2!=l2.end()) {
    std::cout << it2->first << ":" << it2->second << std::endl;
    it2++;
  }

  return true;
}

bool test4() {
  CP::list<std::string> l,l2;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.push_front("BBB");

  if(l.hasLoopForward()) std::cout << "Forward loop" << std::endl;
  if(l.hasLoopBackward()) std::cout << "Backward loop" << std::endl;

  CP::list<std::string>::mynode *n = l.mHeader;
  n= n->next;
  n= n->next;
  CP::list<std::string>::mynode *m =n;
  n = n->next;

  n->next = m;
  if(l.hasLoopForward()) std::cout << "Forward loop in l" << std::endl;
  if(l.hasLoopBackward()) std::cout << "Backward loop in l" << std::endl;

  l2.push_back("AAA1");
  l2.push_back("AAA2");
  l2.push_back("AAA3");
  l2.push_front("BBB");
  n = l2.mHeader;
  n= n->next;
  n= n->next;
  m =n;
  n = n->next;

  m->prev = n;
  if(l2.hasLoopForward()) std::cout << "Forward loop in l2" << std::endl;
  if(l2.hasLoopBackward()) std::cout << "Backward loop in l2" << std::endl;

  return true;
}

bool test5() {
  CP::list<std::string> l;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.push_front("BBB");
  l.print();
  std::cout << "Now, reversing." << std::endl;

  l.reverse02();
  l.print();
  return true;
}

bool test6() {
  CP::list<std::string> l;
  l.push_back("AAA2");
  l.push_back("AAA2");
  l.push_back("AAA2");
  l.push_back("AAA1");
  l.push_back("AAA1");
  l.push_back("BBB");
  l.push_back("BBB");
  l.push_back("AAA2");
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("BBB");
  l.print();
  std::cout << "Now remove any duplicate data" << std::endl;
  l.unique();

  l.print();

  return true;
}

bool test7() {
  std::cout << "Now printing l" << std::endl;
  CP::list<std::string> l;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.print();

  CP::list<std::string> l2;
  std::cout << "Now printing the l2" << std::endl;
  l2.push_back("AAA4");
  l2.push_back("AAA5");
  l2.push_back("AAA6");
  l2.print();

  std::cout << "Now printing the merge result" << std::endl;
  l.mergeX(l2);

  l.print();
  return true;
}

bool testMerge02() {
  std::cout << "Now printing l" << std::endl;
  CP::list<std::string> l;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.print();

  CP::list<std::string> l2;
  std::cout << "Now printing the l2" << std::endl;
  l2.push_back("AAA4");
  l2.push_back("AAA5");
  l2.push_back("AAA6");
  l2.print();

//  std::cout << "Now printing the merge result" << std::endl;
 // l.mergeX2(l2);

//  std::cout << "Now Prepare for printing." << std::endl;
 // l.print();

  std::cout << "When the first list is empty." << std::endl;
  l.clear();
  std::cout << "Now printing l" << std::endl;
  l.print();
  std::cout << "Now printing the l2" << std::endl;
  l2.print();

  std::cout << "Now printing the merge result" << std::endl;
  l.mergeX2(l2);
  l.print();

  std::cout << "When the second list is empty." << std::endl;
  std::cout << "Now printing l3" << std::endl;
  CP::list<std::string> l3;
  l3.push_back("AAA1");
  l3.push_back("AAA2");
  l3.push_back("AAA3");
  l3.print();

  CP::list<std::string> l4;
  std::cout << "Now printing the l4" << std::endl;
 // l4.push_back("AAA4");
 // l4.push_back("AAA5");
 // l4.push_back("AAA6");
  l4.print();

  std::cout << "Now printing l3" << std::endl;
  l3.print();
  std::cout << "Now printing the l4" << std::endl;
  l4.print();

  std::cout << "Now printing the merge result" << std::endl;
  l3.mergeX2(l4);
  l3.print();

  return true;
}

bool test8() {
  CP::list<std::string> l;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.push_back("AAA2");
  l.push_front("BBB");
  l.push_back("AAA1");
  l.print();

  l.remove("AAA1");
  l.print();





  return true;
}

bool test9() {
  CP::list<std::string> l;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  std::cout << "Now printing the first list." << std::endl;
  l.print();

  CP::list<std::string>::iterator it = l.begin(); ++it; ++it;


  CP::list<std::string> l2;
  l2.push_back("AAA4");
  l2.push_back("AAA5");
  l2.push_back("AAA6");
  std::cout << "Now printing the second list." << std::endl;
  l2.print();

  l.splice(it,l2);
  std::cout << "Now printing the splice result, inserting before last." << std::endl;

  l.print();

  std::cout << "2nd test." << std::endl;
  l.clear();
  l2.clear();
  std::cout << "Now printing the first list." << std::endl;
  l.print();
  l2.push_back("AAA4");
  l2.push_back("AAA5");
  l2.push_back("AAA6");
  std::cout << "Now printing the second list." << std::endl;
  l2.print();
  it = l.end();
  l.splice(it,l2);
  std::cout << "Now printing the splice result, before end()." << std::endl;
  l.print();

  std::cout << "3rd test." << std::endl;
  l.clear();
  l2.clear();
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");

  std::cout << "Now printing the first list." << std::endl;


  l.print();
  l2.push_back("AAA4");
  l2.push_back("AAA5");
  l2.push_back("AAA6");
  std::cout << "Now printing the second list." << std::endl;
  l2.print();
  it = l.end();
  l.splice(it,l2);
  std::cout << "Now printing the splice result, before end()." << std::endl;
  l.print();




  return true;
}




int main() {
 // if (test1()) std::cout << " ------------------------ TEST1 OK -------------------------" << std::endl;
  //if (test2()) std::cout << " ------------------------ TEST2 OK -------------------------" << std::endl;
  //if (test3()) std::cout << " ------------------------ TEST3 OK -------------------------" << std::endl;
 //if (test4()) std::cout << " ------------------------ TEST4 OK -------------------------" << std::endl;
   //if (test5()) std::cout << " ------------------------ TEST5 OK -------------------------" << std::endl;
 // if (test6()) std::cout << " ------------------------ TEST6 OK -------------------------" << std::endl;
 // if (test7()) std::cout << " ------------------------ TEST7 OK -------------------------" << std::endl;
  //if (test8()) std::cout << " ------------------------ TEST8 OK -------------------------" << std::endl;
  if (test9()) std::cout << " ------------------------ TEST9 OK -------------------------" << std::endl;
  //if (testMerge02()) std::cout << " ------------------------ TESTMerge02 OK -------------------------" << std::endl;



}
