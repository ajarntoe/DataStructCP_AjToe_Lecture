#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> split(string& text) {
    char* t;
    const char* delims = " \"\'[](){},.!@#$%^&|~-=<>?;:+-*_/\\\n";
    t = strtok((char*)text.c_str(), delims);
    vector<string> tokens;
    while (t != NULL) {
        tokens.push_back(t);
        t = strtok(NULL, delims);
    }
    return tokens;
}
//--------------------------------------------------------
map<string,int> wordFreq(string filename) {
    ifstream infile;
    infile.open(filename.c_str());
    map<string, int> freq;
    string line;
    while (getline(infile,line)) {
        for (string w : split(line)) {
            transform(w.begin(), w.end(), w.begin(), ::tolower);
            freq[w]++;
        }
    }
    infile.close();
    return freq;
}
//-------------------------------------------------------------
typedef pair<int,string> Int_String;

vector<string> top(map<string,int> freq, int n) {
    priority_queue<Int_String, vector<Int_String>, greater<Int_String>> topfreq;
    int i = 0;
    for (auto& kv : freq) {
        if (i++ < n)
            topfreq.push( make_pair(kv.second,kv.first) );
        else
            if (kv.second > topfreq.top().first) {
                topfreq.pop();
                topfreq.push( make_pair(kv.second,kv.first) );
            }
    }
    vector<string> topN;
    while (!topfreq.empty()) {
        topN.push_back(topfreq.top().second);
        topfreq.pop();
    }
    reverse(topN.begin(), topN.end());
    return topN;
}
//------------------------------------------------------------
int main() {
    map<string,int> freq = wordFreq("data.txt");
    cout << "#unique words = " << freq.size() << endl;
    vector<string> top10 = top(freq,10);
    for (string w : top10)
        cout << freq[w] << " --> " << w << endl;
}