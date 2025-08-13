#include <iostream>
#include <vector>

using namespace std;

void Expand(vector<int> &v){
    v.resize(2*v.size(),0);  //fill the rest with zeros.
    cout << "The last element after expansion is" << v[v.size()-1] << endl;

}


int main()
{
    vector<int>  v(1);

    for (int k = 1; k <= 16; k++) {
        if (v.size() < k) {
            cout << "vector size before calling Expand: " << v.size() << endl;
            Expand(v);
            cout << "vector size after calling Expand: " << v.size() << endl;
        }
        v[k-1] = k;
    }
    cout << "[ ";
    for (int k = 0; k < v.size(); k++) {
        cout << v[k] << ' ';
    }
    cout << "]\n";
    return 0;
}
