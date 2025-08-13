#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {10,20};

    auto it = v1.end()-1; // this point to 20
// we resize (enlarge) v1, now [it] is invalidated
    v1.resize(10);

//this might not crash
//but it actually points to somewhere not in v1
    cout << "HAAAA" << endl;
    cout << *it << endl;
cout << "HOOOOO" << endl;
//this will crash the program
    v1.insert(it,99);
    for (auto &x: v1) {
        cout << x << " ";
    }

}
