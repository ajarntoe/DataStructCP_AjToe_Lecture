#include <iostream>

using namespace std;

void swapp(int j, int k){
    int tmp = j;
	j = k;
	k= tmp;
}

void swapByRef(int &j, int &k) {
	int tmp = j;
	j = k;
	k = tmp;
}

int main()
{
    int a =1;
    int b=2;
    int c =5;
    int d =6;

    swapp(a,b);
    cout << a << ", " << b << endl;

    swapByRef(c,d);
    cout << c << ", " << d << endl;


    return 0;
}
