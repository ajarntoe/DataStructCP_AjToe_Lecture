#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string>
#include <vector>

bool myfunction (int i,int j) { return (i<j); }


int main()
{
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // sort using the default operator<
    std::sort(s.begin(), s.end());
    for (auto a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';


    std::array<int, 10> s2 = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    // sort using a standard library compare function object
    std::sort(s2.begin(), s2.end(), std::greater<int>());
    for (auto a : s2) {
        std::cout << a << " ";
    }
    std::cout << '\n';


     std::array<int, 10> s3 = {9, 6, 2, 1, 4, 5, 3};
    // sort using a custom function object
    struct {
        bool operator()(int a, int b)
        {
            return a < b;
        }
    } customLess;

    std::sort(s3.begin(), s3.end(), customLess);
    for (auto a : s3) {
        std::cout << a << " ";
    }
    std::cout << '\n';


     std::array<int, 10> s4 = {9, 8, 2, 1, 7, 5, 3};
    // sort using a lambda expression
    std::sort(s4.begin(), s4.end(), [](int a, int b) {
        return b < a;
    });
    for (auto a : s4) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    std::array<int, 10> s5 = {9, 8, 2, 1, 7, 5, 3};
    //sort using function

    std::sort (s5.begin(), s5.end(), myfunction);
    for (auto a : s5) {
        std::cout << a << " ";
    }
    std::cout << '\n';

}
