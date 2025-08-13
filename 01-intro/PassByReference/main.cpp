#include <iostream>

using namespace std;

void f(int &n) {
	n++;
}

int main() {
	int x = 2;
	f(x);
	cout << x;
}

