#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class WordFreq {
public:
  string word;
  int count;

  //a constructor
  WordFreq(string a,int b) {
    this->word = a;
    this->count = b;
  }

  //the default constructor
  WordFreq() {
    this->word = "";
    this->count = 0;
  }

/*
 // ordering, method 1.1
  bool operator<(const WordFreq &other) const
  {
    return this->count < other.count;
  }
*/
/*
  //ordering, method 1.2
  friend bool operator<(const WordFreq &a, const WordFreq &b) {
    return a.count > b.count;
  }
*/
};

//ordering, method 2

/*
bool comparator(WordFreq a,WordFreq b) {
  if (a.word < b.word) return true;
  return false;
}
*/



//ordering, method 3
class ComparatorClass {
public:
  bool operator()(const WordFreq &a,const WordFreq &b) {
    if (a.count > b.count) return true;
    return false;
  }

};


//typedef map<WordFreq,int> MapType;


int main() {
vector<WordFreq> test;
  test.push_back(WordFreq("somchai",999));
  test.push_back(WordFreq("AB",10));
  test.push_back(WordFreq("Z",102));
  test.push_back(WordFreq("B",19));
  test.push_back(WordFreq("A",204));

   //sort(test.begin(),test.end());
   //sort(test.begin(),test.end(), comparator);
   sort(test.begin(),test.end(), ComparatorClass());

  int count = 0;
  for (vector<WordFreq>::iterator it = test.begin(); it != test.end() ;it++) {
    cout << "[" << it->word << "] [" << it->count << "]" << endl;
  }


}
