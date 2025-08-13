#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> NonEmpty(vector<string> v){

    //int count =0;
    vector<string> v2;

    for (int i=0; i< v.size() ; i++){
        if (v[i] != "") v2.push_back(v[i]);
    }
    return v2;

}

int main()
{
    vector<string> a1 = {"hello","","bye","","","!"};
    //a1[0] = "hello";
   // a1[1] = "";
    //a1[2] = "bye";
    //a1[3] = "";
    //a1[4] = "";
    //a1[5] = "!";

    vector<string> a2 = NonEmpty(a1);

    cout << "Size of new vector is " << a2.size() << endl;
    for (int i=0; i< a2.size(); i++){
        cout << a2[i] << endl;
    }

}
