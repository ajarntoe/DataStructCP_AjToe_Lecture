#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{   int size;
    cout << "Input vector size." << endl;
    cin >> size;

    vector<int> v(size);

    for(int i=0; i< size; i++){
        cout << "Input data number " << (i+1) << endl;
        cin >> v[i];
    }

    cout << "Input data you want to find " << endl;
    int data;
    cin >> data;

    vector<int>::iterator i = find(v.begin(),v.end(),data);
    if(i!= v.end()){
        cout << data << " is stored in the vector." << endl;
    }else{
         cout << data << " is not stored in the vector." << endl;
    }
}
