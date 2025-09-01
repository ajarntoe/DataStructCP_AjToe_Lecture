#include <iostream>
using namespace std;

class complx
{
    double real,
           imag;
public:
    complx(double real = 0., double imag = 0.); // constructor
    complx operator+(const complx&) const;      // operator+()
    int getReal(){ return real;}
    int getImag(){return imag;}


};

// define constructor
complx::complx(double r, double i)
{
    real = r; imag = i;
}

// define overloaded + (plus) operator
complx complx::operator+(const complx& c) const
{
    complx result;
    result.real = (this->real + c.real);
    result.imag = (this->imag + c.imag);
    return result;
}



int main()
{
    complx x(4,4);
    complx y(6,6);
    complx z = x + y; // calls complx::operator+()
    cout << z.getReal() << "," << z.getImag() << endl;

}
