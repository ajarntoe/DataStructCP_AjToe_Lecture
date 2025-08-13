#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<float> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    //vector<float> v1(10);
   // print_vector(v1);

   // vector<float> v2(5,3.55);
   // print_vector(v2);
   // vector<float> v3(v2);
   // print_vector(v3);

    vector<int> v = {9,-1,3,7,5,2,1,4};
    int x =5;
    /*if(find(v.begin(), v.end(), x) != v.end()){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }

    if(find(v.begin(), v.begin()+3,3) != v.begin()+3)
        cout << "found" <<endl;
*/
//how many "YES" will be printed? (CHEAT QUESTION)
   // if(find(v.begin(), v.begin()+2,x) != v.end())
     //   cout << "YES" <<endl;
    //if(find(v.begin(), v.begin()+4,x) != v.end())
      //  cout << "YES" <<endl;

    //if(find(v.begin()+3, v.begin()+2,x) != v.end())
     //   cout << "YES" <<endl;
    //if(find(v.begin()+5, v.begin()+8,x) != v.end())
      //  cout << "YES" <<endl;


}

