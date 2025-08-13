#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class WordCompare{
public:
    bool operator () (const pair<string,int>& a, const pair<string,int>& b) const {
        if (a.second > b.second) return true;
        if (a.second < b.second) return false;
        return a.first < b.first;
    }
};



string processString(string& s) {
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))) {
            tmp += toupper(s[i]);
        }
    }
    return tmp;
}
int main() {
    typedef map<string, int> WORD_TYPE;
    vector<WORD_TYPE> words(26);
    ifstream fin("TomSawyer.txt");
    string w;
    while (fin>>w) {
        w = processString(w);
        if (w.length() > 0) {
            words[w[0]-'A'][w]++;
        }
    }
    fin.close();

    for (int i = 0; i < 26; i++) {
        cout<<(char)('A' + i)<<" - ";
        vector<pair<string, int> > vec;
        for (WORD_TYPE::iterator it = words[i].begin(); it != words[i].end(); it++) {
            vec.push_back(*it);
        }
        sort(vec.begin(), vec.end(), WordCompare());
        for (size_t j = 0; j < min(5u, vec.size()); j++) {
            if (j != 0) cout<<", ";
            cout<<vec[j].first<<" : "<<vec[j].second;
        }
        cout<<endl;
    }
    return 0;
}
