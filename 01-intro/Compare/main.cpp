#include <iostream>
#include <fstream>
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE */

using namespace std;

void compare(istream &in1, istream &in2, ostream &out){
    char ch1, ch2;
    while (in1.get(ch1)) {
        if (!in2.get(ch2) || (ch1 != ch2)) {
            out << "not equal";
            return;
        }
    }
    // here when no more characters in in1
    // input files are the same iff there are also no more characters in in2
    if (!in2.get(ch2)) out << "equal";
    else out << "not equal";
}

int main()
{
  ifstream inFile1, inFile2;
  inFile1.open("Input1.txt");
  if (inFile1.fail()) {
      cerr << "unable to open file Input1 for reading" << endl;
      return 1;
  }
  inFile2.open("Input2.txt");
  if (inFile2.fail()) {
      cerr << "unable to open file Input2 for reading" << endl;
      return 1;
  }
  compare(inFile1, inFile2, cout);
  return 0;
  //exit(1);
}
