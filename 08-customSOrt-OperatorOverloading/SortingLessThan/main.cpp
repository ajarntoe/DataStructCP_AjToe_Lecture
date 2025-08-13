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

  //ordering, method 1.1
  bool operator<(const WordFreq &other) const
  {
    return this->count < other.count;
  }
};

//ordering, method 2
bool comparator(WordFreq a,WordFreq b) {
  if (a.word < b.word) return true;
  return false;
}

void testComparator() {
  vector<WordFreq> test;
  test.push_back(WordFreq("somchai",999));
  test.push_back(WordFreq("AAA",10));
  test.push_back(WordFreq("ZZZ",100));
  test.push_back(WordFreq("AA",10));
  test.push_back(WordFreq("AAA",100));

  //use method 2 in comparison
  cout << "Comparison result =  " << comparator(test[2],test[1]) << endl;
  //use method 1.* in comparison
  cout << "Comparison result =  " << (test[2] < test[1]) << endl;

  sort(test.begin(),test.end());

  for (unsigned i = 0;i < test.size();i++) {
    cout << test[i].word << ":" << test[i].count << endl;
  }
}

typedef map<WordFreq,int> MapType;


int main() {
  testComparator();

}
