#include <iostream>

using namespace std;

int main()
{
    double weight, height;
    double BMI;


    cout << "Input your weight (kg)." << endl;
    cin >> weight;
    cout << "weight = " <<  weight << endl;
    cout << "Input your height (cm)." << endl;
    cin >> height;
    cout << "height = " <<  height << endl;

    height /= 100;

    BMI = weight/(height*height);
    cout << "BMI is " << BMI << endl;



    return 0;
}
