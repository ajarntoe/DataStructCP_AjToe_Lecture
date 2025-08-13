#include <iostream>
using namespace std;

template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}

template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

int main ()
{
  if (are_equal(10,10.0)) //Does not need to specify the type.
    cout << "x and y are equal\n";
  else
    cout << "x and y are not equal\n";

  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j); //Does not need to specify the type.
  h=sum<double>(f,g); //Does not need to specify the type.
  cout << k << '\n';
  cout << h << '\n';

   return 0;
}
