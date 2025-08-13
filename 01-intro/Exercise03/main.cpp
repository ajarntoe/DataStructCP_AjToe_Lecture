#include <iostream>
#include <string>

using namespace std;

int main()
{
    int sum =0;
    int value;

    for(int i=1; i<=10; i++){
        cout << "Type in your value number " << i << endl;
       cin >> value;
        sum = sum + value;

    }
    cout << "Sum of 10 values is " << sum << endl;

   // string mystr;
  //  cout << "What's your name? ";
  //  cin >> mystr;
  //  cout << "The name is " << mystr <<endl;

  //  cout << "What's your name, again? ";
  //  getline (cin, mystr); //This will immediately read the rest of the line if there is
                         //anything left from the previous cin
  //  cout << "The name is " << mystr;

    return 0;
}
