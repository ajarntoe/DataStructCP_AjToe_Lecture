#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void findInMap(map<string, int> &m){
    string input;

    cout << "Please type in the name you want." << endl;
    cin >> input;

    map<string,int>::iterator i = m.find(input);
    if(i!=m.end()){
        cout << "Our data is " << (*i).first << "," << (*i).second << endl;
    }else{
        cout << "There is no such data in our map." << endl;
    }

}



int main() {
    map<string, int> m;
    m["John"] =15;
    m["Mark"] = 12;
    m["Juliet"] = 17;
    m["Samantha"] =9;
    for (map<string,int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " , " << (*it).second << endl;
    }

    findInMap(m);



    return 0;
}
