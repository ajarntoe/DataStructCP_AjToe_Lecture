#include <iostream>

using namespace std;

int main()
{
    string s;
    cout << "Type in a sentence" << endl;
    //cin >> s;

    getline(cin,s);
    cout << "The sentence is " << s << endl;


    return 0;
}
