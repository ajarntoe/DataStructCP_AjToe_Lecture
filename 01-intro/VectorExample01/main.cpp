#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v(1);
    v[0] = 10;
    v.resize(2*v.size());


    v[1] = 20;
    v.resize(1);


    for(int i=0; i<v.size();i++){
        cout << v[i] << endl;
    }
    cout << v[1] << endl;
    return 0;
}
