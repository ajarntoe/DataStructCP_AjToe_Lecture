#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
    vector<int>::iterator i;
    for(i=v.begin(); i!= v.end(); i++){
        cout << *i << " ";
    }
}

void printVector02(vector<int> v){
    vector<int>::iterator i;
    for(i=v.begin(); i!= v.end(); advance(i,1)){
        cout << *i << " ";
    }
}

void printVectorReverse(vector<int> v){
    vector<int>::iterator i;
    for(i=v.end()-1; i!= v.begin(); i--){
        cout << *i << " ";
    }
    cout << *i;
}

void printVectorReverse2(vector<int> v){
    vector<int>::reverse_iterator i;
    for(i=v.rbegin(); i!= v.rend(); i++){
        cout << *i << " ";
    }
}


int main()
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    printVector(v);
    cout << endl;
    printVectorReverse(v);
    return 0;

}
