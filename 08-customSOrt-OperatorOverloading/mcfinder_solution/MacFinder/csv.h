#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class CSVLine
{
  private:
    string line;
    string::iterator curr;
    bool inQuote;
  public:
    CSVLine(string line) {
      this->line = line;
      curr = this->line.begin();
      inQuote = false;
    }

    bool hasNext() {
      return curr != line.end();
    }

    string next() {
      string result;
      string s;
      while (curr != line.end()) {
        if (*curr == ',') {
          if (inQuote) 
            result += *curr; 
          else
            break;
        } else if (*curr == '"') {
          inQuote = !inQuote;
        } else if (*curr == '\n') {

        } else {
          result += *curr;
        }
        curr++;
      }
      if (curr != line.end()) curr++; // skip the last ',' 
      return result;
    }
};


