#include <fstream>
#include <iostream>
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE */
using namespace std;

int main(){
    ifstream inFile;

    inFile.open("input.dat");
    if(inFile.fail()){
        cerr << "error" << endl;
        exit(1);
    }

    int n, sum =0;
        while(inFile >> n){
            sum = sum+n;
    }
    cout << sum;

    inFile.close();

}

