#include <iostream>

using namespace std;


void Mystery( int & a, int & b, int c ) {
	a = b + c;
	b = 0;
	c = 0;
}

void Print() {
 	int x = 0, y = 1, z = 2;
	Mystery(x, y, z);
	cout << x << " " << y << " " << z << endl;
	Mystery(x, y, z);
	cout << x << " " << y << " " << z << endl;
}



int main()
{
    Print();
    return 0;
}
