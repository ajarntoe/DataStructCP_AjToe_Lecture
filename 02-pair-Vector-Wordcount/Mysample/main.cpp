#include <iostream>

int main() {
    std::pair<int,float> x;
    std::pair<int,float> y;

    x.first = 10;
    x.second = 20.65;

    std::cout << x.first << " ";
              std::cout << x.second << std::endl;

    y = x;

    std::cout << y.first << " ";
              std::cout << y.second << std::endl;

    y.second = 5;

    std::cout << y.second << std::endl;
    std::cout << x.second << std::endl;


}
