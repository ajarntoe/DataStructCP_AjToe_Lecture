#include <iostream>
using namespace std;

class complx
{
    double real, imag;
public:
    complx(double real = 0., double imag = 0.);
    // Declare friend function
    friend complx operator+(const complx& c1, const complx& c2);
    // Add getter functions to access private members
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// Define constructor
complx::complx(double r, double i)
{
    real = r;
    imag = i;
}

// Define friend function - can access private members directly
complx operator+(const complx& c1, const complx& c2)
{
    return complx(c1.real + c2.real, c1.imag + c2.imag);
}

int main()
{
    complx x(4,4);
    complx y(6,6);
    complx z = x + y; // calls operator+()
    cout << z.getReal() << "," << z.getImag() << endl;
    complx zz = 2 + y;
    cout << zz.getReal() << "," << zz.getImag() << endl;

    return 0;
}
