#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    cout << "Size of v1 is " << v1.size() << endl;

    vector<int> v2 = {2,3,4};

    cout << v2[1] << endl;
    v1 = v2;
    v1[0] = 20;



    v1.push_back(99);
    cout << v1.size() << endl;
    cout << v2.size() << endl;

    cout << v1[0] << ", " << v1[1] << ", " << v1[2] << ", " << v1[3] << endl;
    cout << v2[0] << ", " << v2[1] << ", " << v2[2] << ", " << v2[3] << endl;
}
