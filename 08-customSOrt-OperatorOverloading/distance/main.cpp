#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
    int feet;      // 0 to infinite
    int inches;    // 0 to 12

public:
    // Required constructors
    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    // Method to display distance
    void displayDistance()
    {
        cout << "F: " << feet << " I: " << inches << endl;
    }

    // Overloaded minus (-) operator (corrected version)
    Distance operator-()
    {
        feet = -feet;
        inches = -inches;
        return Distance(-feet, -inches);
    }
};

int main()
{
    Distance D1(11,10);
    -D1;
    D1.displayDistance();

    Distance D2(-5,11);
    -D2;
    D2.displayDistance();

    return 0;
}
