#include <iostream>
#include <string>

#include "solution.h"
 


int main() {


    std::string s("test_string");
    int count = 18;

    std::cout << stringStat(s.c_str(), 7, &count) << std::endl;
    std::cout << count << std::endl;

    return 0;
}